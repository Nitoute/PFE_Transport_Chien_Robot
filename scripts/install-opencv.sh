cd /src/opencv
rm -rf build && mkdir build
cd build

ln -s /usr/include/eigen3/Eigen /usr/include/Eigen
cmake ..
make install -j24 # this will install opencv
ldconfig # updates the shared library cache