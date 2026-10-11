## template

```shell
mkdir build
cd build
cmake ../ -G Ninja
cmake --build .
./demo.exe
```

### cas_0

**template functions** do not generate functions while **explicit specialization** & **explicit instantiation**

`trick\template\cas_0\cas_0.cpp:8` 
set `int` explicit specialization
set `double` explicit instantiation
set `float`  failure case

### cas_1

return value type

### cas_2

specialized extraction
