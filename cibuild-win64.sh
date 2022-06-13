mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
mkdir dist
cp pic_22.exe dist

zip -r deploy-win.zip dist