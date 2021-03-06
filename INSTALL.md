Contents
--------

1. [Introduction](#1-introduction)

2. [Building with autoconf/automake](#2-building-with-autoconfautomake)
    
    2.1. [Building JSBSim libraries](#21-building-jsbsim-libraries)

3. [Building with cmake](#3-building-with-cmake)   
	
	3.1. [Linux](#31-linux)

	3.2. [Windows MinGW](#32-windows-mingw)

	3.3. [Windows MSVC 2010](#33-windows-msvc-2010)

	3.4. [Windows MSVC 2011](#34-windows-msvc-2011)

4. [Contact](#4-contact)


# 1. Introduction

JSBSim is a multi-platform, general purpose object-oriented Flight Dynamics Model (FDM) written in C++. Jon Berndt and Tony Peden began about mid-1998 writing JSBSim. As of this writing it is the default FDM for FlightGear. JSBSim can also be run in a standalone batch mode for testing and study. More information on JSBSim can be found at the JSBSim home page [here](http://www.jsbsim.org).


# 2. Building with autoconf/automake


Unpack the distribution tarball (if needed - CVS users will have downloaded the code directly) using your preferred method, and change to the working directory. For example :

```bash
$ tar xvfz JSBSim-0.1.2.tar.gz
$ cd JSBSim-0.1.2
```

__NOTE for CVS users__: If you are using JSBSim from a CVS checkout, or snapshot, you will need to create the initial configure script. The commands to do this have been included in the `autogen.sh` script, so just :

```bash
$ ./autogen.sh [--no-configure]
```

If you wish to customise your version of JSBSim, use the following to determine any build-time options you may be interested in.

```bash
$ ./configure --help
```

Then :

```bash
$ ./configure
```

This will check your system platform, compiler and other local configuration variables needed to build JSBSim, and generates the necessary Makefiles. Next :

```bash
$ make
```

Will compile the various classes, and build the JSBSim application.


### 2.1. Building JSBSim libraries


By default, the JSBSim libraries are not built. To build and install the libraries, use:

```bash
$ ./autogen.sh --enable-libraries [--disable-static] [--enable-shared]
```

The configure options can be used to select what libraries to build.

```bash
$ make install
```

Unless specified otherwise (with `--prefix` configure option), this will install JSBSim libraries into `/usr/local/lib` and JSBSim headers into `/usr/local/include/JSBSim`.


# 3. Building with cmake


Unpack the distribution tarball (if needed - CVS users will have downloaded the code directly) using your preferred method, and change to the working directory. For example :

```bash
$ tar xvfz JSBSim-x.y.z.tar.gz
$ cd JSBSim-x-y-z
```

The following usages of cmake consist in :
 - making a build directory : cmake can build out of src tree. It's very convenient in order to let the sources tree clean.
 - invoking cmake : cmake has several front-ends. In the examples we call the command line, but you can invoke the ncurses (ccmake) or the QT GUI (cmake-gui).
 - call the selected build toolchain.

Optionally, shared libraries can be built by invoking the parameter `BUILD_SHARED_LIBS`.

To be able to execute the tests written in Python, it is necessary to create a virtual environment where you can install __[cython](http://cython.org/)__ and the JSBSim Python bindings. After environment setup, build with the parameter `INSTALL_PYTHON_MODULE`. The method for this is described only for Linux.

The `..` means parent directory, it shouldn't be omitted.

### 3.1. Linux

Run the following commands :

```bash
$ mkdir build_linux
$ cd build_linux
$ cmake .. [-DBUILD_SHARED_LIBS]
$ make
$ make install [DESTDIR=_install]
```

#### Environment setup for Python module

We use __[virtualenvwrapper](https://virtualenvwrapper.readthedocs.io/en/latest/)__. After installing and configuring it, create a new virtual environment by doing this:

```bash
$ mkvirtualenv -p $(which python2.7) jsbsim_venv
```

A new environment is created and activated right away. Then install cython:

```
(jsbsim_venv) $ pip install Cython
```

Finally you can build and install the Python module to be able to run the tests:

```
(jsbsim_venv) $ mkdir build_linux
(jsbsim_venv) $ cd build_linux
(jsbsim_venv) $ cmake .. [-DBUILD_SHARED_LIBS=ON] -DINSTALL_PYTHON_MODULE=ON
(jsbsim_venv) $ make
(jsbsim_venv) $ _install=/path/where/to/install/jsbsim/libs/and/binaries
(jsbsim_venv) $ make install [DESTDIR=$_install]
```

To run the tests, you must first install the python required packages:

```
(jsbsim_venv) $ pip install -r tests/requirements.txt
```

For now, only __[pandas](pandas.pydata.org)__ is required.
Then run the tests by calling this:

```
(jsbsim_venv) $ make test
```

To uninstall you can call :
```bash
$ xargs rm < install_manifest.txt
```

To get rid of the python environment, do this:
```
(jsbsim_venv) $ deactivate
$ rmvirtualenv jsbsim_venv
```


### 3.2. Windows MinGW

Tested with MinGW of __CodeBlocks 12.11__.

```bash
$ mkdir build_mingw
$ cd build_mingw
$ "c:\Program Files\CodeBlocks\MinGW\mingwvars.bat"
$ cmake -G "MinGW Makefiles" ..  [-DBUILD_SHARED_LIBS]
$ mingw32-make
$ mingw32-make install [DESTDIR=_install]
```


### 3.3. Windows MSVC 2010

Tested with __MSVC 2010 express SP1__.

```bash
$ mkdir build_msvc_10
$ cd build_msvc_10
$ "c:\Program Files\Microsoft Visual Studio 10.0\VC\bin\vcvars32.bat"
$ cmake -G "Visual Studio 10" ..  [-DBUILD_SHARED_LIBS]
$ msbuild jsbsim.sln
```

You can also open `jsbsim.sln` with visual studio IDE.


### 3.4. Windows MSVC 2011

Tested with __MSVC 2012 express__.

```bash
$ mkdir build_msvc_11
$ cd build_msvc_11
$ "c:\Program Files\Microsoft Visual Studio 11.0\VC\bin\vcvars32.bat"
$ cmake -G "Visual Studio 11" ..  [-DBUILD_SHARED_LIBS]
$ msbuild jsbsim.sln
```

You can also open `jsbsim.sln` with visual studio IDE.


# 4. Contact

For more information on JSBSim contact Jon Berndt at jon@jsbsim.org.


