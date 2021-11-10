# cse474

A minimal Pascal Subset Compiler Front-end that outputs 3 address code

# Usage:



```
cmake -Bbuild -H. -DCMAKE_BUILD_TYPE=debug 

cmake --build build --target all

./build/CSE474 {-p} {-d} input
```

# Require:
Cmake
Flex
Bison
