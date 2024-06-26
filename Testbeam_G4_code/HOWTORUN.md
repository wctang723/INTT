# How to run
The procedure to start this simulation application is explained in this document.

## What you need
- Linux or Mac (Windows Subsystem for Linux also fine)
- C++ compiler (for example, g++)
- CMake (tool to build Geant4 and this application)
- Geant4 (installation explained)
- Qt5
- ROOT (shortly explained)

## General explanation
These simulation application uses Geant4 and ROOT. You need to install both of them on your PC. ROOT is easier to install so the explanation for that is short.

## Installation
### [CMake](https://cmake.org/)
Basically, you just visit [the download page](https://cmake.org/download/) and take a suitable version for you.
For more explanation for Linux users, see [How to Install CMake on Ubuntu 20.04 LTS](https://vitux.com/how-to-install-cmake-on-ubuntu/).
If you use Linux but not Debian or distribution based on Debian, [it](https://www.osradar.com/how-to-install-cmake-on-centos-8/) may help you.
For Mac Users, you just download the dmg file from the official download page and install as usual.

### [ROOT](https://root.cern/)
There is [a nice official introduction](https://root.cern/install/).
**ROOT6 is strongly recommended.**

### Qt5
Qt is a tool for GUI. In this simulation application, Qt is used to visualize the setup. Some other tools are fine for visualization, but Qt seems to be better.
Let me postpone this...

### [Geant4](https://geant4.web.cern.ch/node/1)
1. Download the latest version
2. Move to somewhere you like and unzip the file
  - ```$ unzip [the_file.zip]```
  - ```$ tar fvxz [the_file.tar.gz]```
  - here, [the_file.zip] and [the_file_tar.gz] are the name of the file you downloaded. You don't need to type "$".
3. Make a build directory, go to the directory
  - ```$ mkdir build```
  - ```$ cd build```
4. Try cmake
  - ```$ cmake -DCMAKE_INSTALL_PREFIX=[install_directory] -DGEANT4_INSTALL_DATA=ON -DGEANT4_BUILD_MULTITHREADED=ON ../[the_unzipped_fdirectory]```
  -  here, you can choose [install_directory] as you want. Anywhere is OK basically.
  -  [the_unzipped_directory] is the name of the directory you got after unzipping. It is, for example, geant4.10.07.p02.
  -  the "GEANT4_INSTALL_DATA" option allows installing data, which are used in physics processes calculation. If you have already had the data on your PC, you can specify the path to the directory.
  -  the "GEANT4_BUILD_MULTITHREADED" option enables Geant4 to process the simulation in multi-thread mode. It's good to use it in principle.
5. If you have no error, let's make it!
  - ```$ make -j [number_of_process]```
  - here, [number_of_process] should be the same or less than the number of your CPU. For example, in the case of Intel Core-i5 1035G1(Ice Lake), it has 4 cores. 8 threads are available. So you can give "8" or less to the option.
6. Compilation was done if you see such outputs at the end of compilation:
```CXX object source/CMakeFiles/G4physicslists.dir/physics_lists/util/src/G4HadParticles.cc.o
[100%] Building CXX object source/CMakeFiles/G4physicslists.dir/physics_lists/util/src/G4HadProcesses.cc.o
[100%] Building CXX object source/CMakeFiles/G4physicslists.dir/physics_lists/util/src/G4PhysListUtil.cc.o
[100%] Building CXX object source/CMakeFiles/G4physicslists.dir/physics_lists/util/src/G4WarnPLStatus.cc.o
[100%] Linking CXX shared library ../BuildProducts/lib/libG4physicslists.dylib
[100%] Built target G4physicslists
/Applications/CMake.app/Contents/bin/cmake -E cmake_progress_start /Users/genki/soft/Geant4/4.10.7.p02/build3/CMakeFiles 0
```
  - it took 18 min with Intel Core-i7 (6 cores, 12 threads) and ```-j 10```.
7. Install Geant4
  - ```$ make install```
8. Installation is basically done. You also need to set some environmental variables by executing the geant4.sh (or gean4.csh fr C-Shell users):
  - ```source [install_directory]/bin/geant4.(c)sh```
9. Test it
  - ```$ geant4-config```
  - if you see something but they are not an error, installation of Geant4 was done.
10. It's good to modify the ${HOME}/.bashrc (it depends on which shell you use. It may be .cshrc for C-Shell users or .zshrc for Z-Shell users ( the default shell of Mac is Z-Shell)).
  - Add ```source [install_directory]/bin/geant4.(c)sh``` to your .bashrc
  - If you use Z-Shell (it's Mac's default), you need to move to the direcory, therefore
```
cd [install_directory]/bin
source geant4.sh
cd ${HOME}
```
should be OK.

### Compiling this simulation application
1. Download codes
  - ```$ git clone git@github.com:sPHENIX-Collaboration/INTT.git```
2. Make a build directory and move to there
  - ```mkdir build```
  - ```cd build```
3. Try cmake
  - ```cmake ../INTT/Testbeam_G4_code/session7_solution/```
  - the path to the source codes depends on where you made the build directory
4. If you have no error, make it!
  - ```make -j```
5. Let's run GUI
  - ```$ ./exampleED```
  - if GUI starts successfully, the compiling was done.

## FAQ

I entered below command.

```cmake -DCMAKE_INSTALL_PREFIX=../install -DGEANT4_INSTALL_DATA=ON -DGEANT4_BUILD_MULTITHREADED=ON -DGEANT4_USE_INVENTOR_QT:BOOL=ON -DGEANT4_USE_QT:BOOL=ON  ../geant4_10_07_p03```


Error message　is below

```
  CMake Error at cmake/Modules/G4InterfaceOptions.cmake:114 (find_package):
  By not providing "FindCoin.cmake" in CMAKE_MODULE_PATH this project has
  asked CMake to find a package configuration file provided by "Coin", but
  CMake did not find one.

  Could not find a package configuration file provided by "Coin" (requested
  version 4.0.0) with any of the following names:

    CoinConfig.cmake
    coin-config.cmake

  Add the installation prefix of "Coin" to CMAKE_PREFIX_PATH or set
  "Coin_DIR" to a directory containing one of the above files.  If "Coin"
  provides a separate development package or SDK, be sure it has been
  installed.
Call Stack (most recent call first):
  cmake/Modules/G4CMakeMain.cmake:64 (include)
  CMakeLists.txt:51 (include)


-- Configuring incomplete, errors occurred!
See also "/Users/hikaru/Desktop/Geant4/bulid/CMakeFiles/CMakeOutput.log".
See also "/Users/hikaru/Desktop/Geant4/bulid/CMakeFiles/CMakeError.log".
```



by H.Imai

