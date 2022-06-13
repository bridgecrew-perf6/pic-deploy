cmake_minimum_required(VERSION 3.21)
project(pic_22)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(dishlib)

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs

find_package(Boost 1.67.0 COMPONENTS program_options REQUIRED)

add_executable(pic_22 main.cpp)

if(WIN32)
    target_link_libraries(pic_22 -static ${Boost_LIBRARIES})
else() #linux, mac etc?!
    target_link_libraries(pic_22 ${Boost_LIBRARIES})
endif()

target_link_libraries(pic_22 dishlib)
# install
install(TARGETS pic_22 RUNTIME DESTINATION .)

# package generation
set(CPACK_GENERATOR "ZIP")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "pic-22")
SET(CPACK_PACKAGE_VENDOR "pic")
#SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/readme.md")
#SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/../LICENSE")

SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "9")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
#SET(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_SYSTEM_NAME}")
include(CPack)