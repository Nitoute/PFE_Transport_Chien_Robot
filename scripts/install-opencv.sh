mv opencv ..
cd ../opencv
mkdir build
cd build

sudo ln -s /usr/include/eigen3/Eigen /usr/include/Eigen
cmake ..
make install # this will install opencv
ldconfig -v # updates the shared library cache 