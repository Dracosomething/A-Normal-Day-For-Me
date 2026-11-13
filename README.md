# A-Normal-Day-For-Me

1. [Build](#build)
	- [Tools](#build.tools)
		- [Windows](#build.tools.windows)
		- [Linux](#build.tools.linux)
		- [Web](#build.tools.web)
	- [Make](#build.make)
2. (Testing)[#test]

<h2 id="build">Build</h2>
Building the project can be done in multiple ways.
When building without make do make sure that the build directories exist.
<h3 id="build.tools">Tools</h3>
Building this project requires a couple of tools, these can differ depending on OS.
It is also possible to build using gnumake.
<h4 id="build.tools.windows">Windows</h4>
Building for windows requires the following.
- clang
<h4 id="build.tools.linux">Linux</h4>
Building on linux requires:
- g++
<h4 id="build.tools.web">Web</h4>
To build the project for web you need:
- emscripten
<h3 id="build.make">Make</h3>
To build the project for the web using make simply run `make web`, for linux run `make linux` and for windows run `make windows`.
This does require some way to use make.

To build on Windows you need to run the following command `clang++ -std=c++26 -O2 -Wall -Wextra main.cpp -o ./build/windows/out.exe`.

To build on Linux you need to run `clang++ -std=c++26 -O2 -Wall -Wextra main.cpp -o ./build/windows/out.exe`.

To build for web run `em++ -std=c++26 main.cpp -o ./build/web/out.js -Wall -Wextra -sUSE_SDL=3 -O2`.

<h2 id="test">Testing</h2>
For creating a test build you can eather use Make and run `make test` or without make run `em++ -std=c++26 main.cpp -o ./build/dev/out.html -Wall -Wextra -sUSE_SDL=3`.
