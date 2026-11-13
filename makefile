# Add path to link with SDL3 when compiling for windows

build-dir: ; mkdir ./build/
	 mkdir ./build/web/
	 mkdir ./build/dev/
	 mkdir ./build/linux/
	 mkdir ./build/windows/

test: build-dir ; em++ -std=c++26 main.cpp -o ./build/dev/out.html -Wall -Wextra -sUSE_SDL=3

web: build-dir ; em++ -std=c++26 main.cpp -o ./build/web/out.js -Wall -Wextra -sUSE_SDL=3 -O2

linux: build-dir ; g++ -x c++ -std=c++26 -O2 -Wall -Wextra main.cpp -o ./build/linux/out
