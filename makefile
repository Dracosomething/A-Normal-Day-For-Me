# Add path to link with SDL3 when compiling for windows

build-dir: ; mkdir ./bin

test: build-dir ; mkdir ./bin/dev/
    em++ -std=c++26 main.cpp -o ./bin/dev/out.html -Wall -Wextra -sUSE_SDL=3

web: build-dir ; mkdir ./bin/web/
    em++ -std=c++26 main.cpp -o ./bin/web/out.js -Wall -Wextra -sUSE_SDL=3 -O2

linux: build-dir ; mkdir ./bin/linux/
    g++ -x c++ -std=c++26 -O2 -Wall -Wextra main.cpp -o ./bin/linux/out
