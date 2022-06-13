#include <iostream>
#include <AbstractDish.h>
#include <DishFactory.h>

#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;

int main(int argc, char** argv){
    po::options_description desc(string(argv[0]) + " options");
    po::variables_map vm;
    string dishType = "";
    try {
        desc.add_options()
                ("help,h", "this help message")
                ("dish,d", po::value<string>(&dishType)->required(),
                 "dish type e.g. VegetableSoup");

        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help")) {
            cout << desc << "\n";
            return 1;
        }
    } catch (const boost::program_options::required_option &e) {
        std::cout << desc << std::endl;
        return 1;
    }
    unique_ptr<dishlib::AbstractDish> dish = dishlib::DishFactory::Create(dishType);
    if(nullptr == dish){
        cerr << "Error, dish not available" << endl;
        return -1;
    }
    dish->Cook();
}