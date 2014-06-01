# libcgutils - library of several useful utilities for developing with OpenGL and glm
All the utilities braught to you with this library are packed into one
dynamic library which is installed to $(prefix)/lib, which defaults to /usr.
This library also contains header files which are installed to $(prefix)/include/libcglutils,
which defaults to /usr/include/libcglutils.

---

## Requirements
Following packages have to be installed on your system to build and use libcglutils:
1. OpenGL - the rendering pipeline, for example Mesa
2. glm - header-only math library for matrix operations [http://glm.g-truc.net/0.9.5/index.html]
..* minimum required version: glm-0.9.5.1*
3. glm-obj - Wavefront OBJ file library [http://devernay.free.fr/hacks/glm/]
4. lib3ds - for loading 3DsMax models
5. DevIL - Texture loading library
6. GLee - extension handling library [http://sourceforge.net/projects/glee/]


## Building the library
Unpack the library and in your terminal do following:
`	$>  cd ./libcglutil-version
	$>  cmake -DCMAKE_INSTALL_PREFIX=<whatever_you_want>
	$>  make
	$>  make install
`

__To add your own CXXFLAGS, you can pass them to cmake:__
`
	-DCMAKE_CXX_FLAGS='-march=core2 -fomit-frame-pointer -pipe -O2 -flto -fmerge-constants -freorder-blocks'
`

__To use another compiler, pass it to cmake as following:__
`
	-DCMAKE_CXX_COMPILER=clang++
`

__If this packages fails building because of headers it can't locate, you can pass
the top-level directory to the corresponding header sources as following:__
`
	cmake -DCMAKE_CXX_FLAGS='-I<path-where-header-folder-resides>'
`

__The same you can do on libs cmake can't locate:__
`
	-DCMAKE_LINKER_FLAGS='-l<your-fucking-lib> -l<yet-another-shitty-lib>'
	-DCMAKE_CXX_FLAGS='-L<path-to-your-abstruse-libdir>'
`

If this library still fucking refuses to build and complains about headers or libs
you should check the requrements once more, dude!
If this seem OK, you could check whether the needed libs have compiled-in the needed features.

__On dynamic libraries for example, you can list all it's symols by hitting:__
`
	nm -D <full/path/to/the/lib.so>
`

If that still doesn't help... uhm... upgrade your fucking system!
And your're done.


## Modules and namespaces
The library is organised into several "submodules":
1. oogl - contains classes for model-loading (OpenGL and 3DsMax) and texture loading from image files
2. cglutil - several helper stuff like math functions, logger, timer...
3. glm - glm-related stuff and extensions. currently only stream operators for pretty-printing.

__Your are able to include the needed headers according the module structure, like__
`
	#include <glm/glm_ostream.hpp>
	#include <oogl/model/Model3Ds.hpp>
	#include <oogl/Navigator.hpp>
`

__There are following namespaces defined:__
+ glm - extensions for the glm library
+ oogl - oogl specific stuff
+ oogl::model Model loading extensions
+ cgutil - several utilities


## TODO
__Following things have to be done as soon as possible:__
+ Change all glm functions of the oogl module which take angles as parameter
  to radians as the new parameter as angle parameters are deprecated now. See build warnings.
+ Porting from GLee to glew librar as the Glee library is outdated and unmaintained now.
+ Add distinct build targets for RELEASE and DEBUG, having their specific CXXFLAGS.
  (see cmake -DCMAKE BUILD TYPE=<RELEASE|DEBUG> switch)
+ Add FORSAKEN model loader (see oogl module and the forsaken-git porject) :)
+ Add target for doxygen documentation generation.
+ Add test rutines to ensure correctness
+ Add more useful functionality ;-)

