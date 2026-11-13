# Add path to link with SDL3 when compiling for windows

build-dir: ; @mkdir -p ./build/
	 @mkdir -p ./build/web/
	 @mkdir -p ./build/dev/
	 @mkdir -p ./build/linux/
	 @mkdir -p ./build/windows/

test: build-dir ; @em++ -std=c++26 main.cpp -o ./build/dev/out.html -Wall -Wextra -sUSE_SDL=3

web: build-dir ; @em++ -std=c++26 main.cpp -o ./build/web/out.js -Wall -Wextra -sUSE_SDL=3 -O2

linux: build-dir ; @g++ -x c++ -std=c++26 -O2 -Wall -Wextra main.cpp -o ./build/linux/out

windows: build-dir ; @clang++ -std=c++26 -O2 -Wall -Wextra main.cpp -o ./build/windows/out.exe
