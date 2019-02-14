# RSHELL
This is a linux shell emulator written in C++. 

## Dependencies
This project requires a linux OS, as well as g++ and CMake to compile.
g++ comes pre-installed on almost all linux distributions, but if yours does not have it, it can be installed using
```
sudo apt-get install g++
```
CMake can be installed using
```
sudo apt-get install cmake
```

## Installing
To run the code, you first need to clone the repository.
```
git clone https://github.com/abdelrahim-hentabli/rshell
```

Then you need to call
```
cmake .
make
```
in the rshell directory.

Finally, you can run the shell or the test files using 
```
./rshell 
./test
```
