apt update

apt install openjdk-8-jdk -y
update-alternatives --set javac /usr/lib/jvm/java-8-openjdk-amd64/bin/javac

cd
unzip PFE_Transport_Chien_Robot/lcm-1.4.0.zip
cd ../lcm-1.4.0
mkdir build && cd build
cmake ..
make install -j24 # this will install lcm
ldconfig # updates the shared library cache
# after this, revert back to the previous version of openjdk: