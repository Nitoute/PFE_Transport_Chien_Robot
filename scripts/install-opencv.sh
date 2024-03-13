cd /src/opencv
rm -rf build && mkdir build
cd build

ln -s /usr/include/eigen3/Eigen /usr/include/Eigen
cmake .. -DCMAKE_BUILD_TYPE=Debug #-DENABLE_GNU_STL_DEBUG:BOOL=ON
make install -j24 -l24 # this will install opencv
ldconfig -v # updates the shared library cache