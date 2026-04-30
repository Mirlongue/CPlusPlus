## [cpp-stub](https://github.com/Mirlongue/cpp-stub)

```shell
# in stub.h, modify private part of the Stub class to protected

-fno-access-control	# private parts can be controlled externally
-fno-inline			# inline access prohibited


mkdir build
cd build
cmake ../ -G Ninja
cmake --build .
./demo.exe
```

