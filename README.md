llvm-mini-Passes-build-cmake and flofli
=========
source base on https://github.com/banach-space/llvm-tutor .

# What is the flofli
flofli is an opensource project which aims to protect your software easily.
flofli is the abbreviation for free llvm obuscator for llvm ir.
It will let your software hard to analyse. But obuscation may let your software slow.

# plan
1. I will dissect other famous llvm obuscator to let the obfuscator model compile easylily.
2. The project can compile all obfuscator independently. Other obfuscator need compile all llvm and clang source code.

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

## bogus control flow
Note: bogus control flow need cfg which have two or more blocks.
```
clang-11 -c -emit-llvm test.c -o test.bc
opt-11 -load ./libBogusControlFlow.so --boguscf --bcf_prob=100 ./test_split.ll -o ./test_bogus.bc
opt-11 --view-cfg ./test_bogus.bc
```
![](https://github.com/lyciumlee/lyciumlee.github.io/blob/master/img/other_pics/3.png)