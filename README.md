# Build Instructions

```
cd godot-cpp
scons target=debug generate_bindings=true
```

```
cd ..
clang++ -fPIC -o src/register_types.o -c src/register_types.cpp -g -O3 -std=c++17 -I godot-cpp/gen/include -I godot-cpp/include -I godot-cpp/include/core -I godot-cpp/include/gen -I godot-cpp/godot-headers
```

```
clang++ -o bin/ffmpegmediadecoder.so -shared src/register_types.o -L godot-cpp/bin/libgodot-cpp.linux.debug.64.a
```
