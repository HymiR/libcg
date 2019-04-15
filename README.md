# libcg - library of several useful utilities for developing with OpenGL and glm
All the utilities braught to you with this library are packed into one
dynamic library which is installed to $(prefix)/lib, which defaults to /usr.
This library also contains header files which are installed to $(prefix)/include/libcglutils,
which defaults to /usr/include/libcglutils.

---

## Requirements
Following packages have to be installed on your system to build and use libcglutils:

1. **OpenGL** - the rendering pipeline, for example Mesa
2. **[glm](http://glm.g-truc.net/0.9.7/index.html)** - header-only math library for matrix operations
   *minimum required version: 0.9.7*
3. **[glm-obj](http://devernay.free.fr/hacks/glm/)** - Wavefront OBJ file library
4. **lib3ds** - for loading 3DsMax models
   *minimum required version: 2.0*
5. **DevIL** - Texture loading library
6. **[GLew](http://glew.sourceforge.net/)** - extension handling library
   *minimum required version: 1.11*


## Building the library
Unpack the library and in your terminal do following:
```bash
cd ./libcg-version
cmake -DCMAKE_INSTALL_PREFIX='<whatever_you_want>'
make
make install
```

__To add your own CXXFLAGS, you can pass them to cmake:__
```bash
	-DCMAKE_CXX_FLAGS='-march=core2 -fomit-frame-pointer -pipe -O2 -flto -fmerge-constants -freorder-blocks'
```

__To use another compiler, pass it to cmake as following:__
```bash
	-DCMAKE_CXX_COMPILER='clang++'
```

__If this packages fails building because of headers it can't locate, you can pass
the top-level directory to the corresponding header sources as following:__
```bash
	cmake -DCMAKE_CXX_FLAGS='-I<path-where-header-folder-resides>'
```

__The same you can do on libs cmake can't locate:__
```bash
	-DCMAKE_LINKER_FLAGS='-l<your-fucking-lib> -l<yet-another-shitty-lib>'
	-DCMAKE_CXX_FLAGS='-L<path-to-your-abstruse-libdir>'
```

If this library still fucking refuses to build and complains about headers or libs
you should check the requrements once more, dude!
If this seem OK, you could check whether the needed libs have compiled-in the needed features.

__On dynamic libraries for example, you can list all it's symols by hitting:__
```bash
	nm -D <full/path/to/the/lib.so>
```

If that still doesn't help... uhm... upgrade your fucking system!
And your're done.


## Modules and namespaces
The library is organised into several modules:
+ **oogl** - contains classes for model-loading (OpenGL and 3DsMax) and texture loading from image files
+ **util** - several helper stuff like math functions, logger, timer...
+ **io** - io structures, currently only stream operators for pretty-printing.
+ **ger** - gerfrieds new model loader architecture

__Your are able to include the needed headers according the module structure, like__
```c++
	#include <cg/io/glm_ostream.hpp>
	#include <cg/oogl/model/Model3Ds.hpp>
	#include <cg/oogl/Navigator.hpp>
```

__There are following namespaces defined:__
+ **cg::io** - io stuff, stream operators
+ **cg::oogl** - oogl specific stuff
+ **cg::oogl::model** Model loading extensions
+ **cg::util** - several utilities, e.g. math stuff.
+ **cg::ger** - gerfrieds new model loader architecture


## TODO
__Following things have to be done as soon as possible:__
+ Add FORSAKEN model loader (see oogl module and the forsaken-git porject) :)
+ Add target for doxygen documentation generation.
+ Add test rutines to ensure correctness
+ Add more useful functionality ;-)

