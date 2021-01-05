llvm-mini-Passes-build-cmake
=========
source https://github.com/banach-space/llvm-tutor

This project aims to protect your software easily.
It will let your software hard to analyse. But it may let your software slow.

# env
llvm 11
cmake
make


# How to build
```
mkdir build
cd build
cmake ../{Project Name}
make
```


# How to use


## split basic block
```
clang-11 -c -emit-llvm test.c -o test.bc
opt-11 -load ./libSplitBlocks.so --split_num=3 --splitbbl < test.bc -o test_split.bc
opt-11 --view-cfg ./test_split.bc
```

![](https://github.com/lyciumlee/lyciumlee.github.io/blob/master/img/other_pics/1.png)

## Flattening
Note: Flattening need cfg which have two or more blocks.
```
clang-11 -c -emit-llvm test.c -o test.bc
opt-11 -load ./libFlattening.so --flattening < test.bc -o test_split.bc
opt-11 --view-cfg ./test_split.bc
```
![](https://github.com/lyciumlee/lyciumlee.github.io/blob/master/img/other_pics/2.png)