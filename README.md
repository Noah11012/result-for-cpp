[![Build Status](https://api.cirrus-ci.com/github/Noah11012/result-for-cpp.svg)](https://cirrus-ci.com/github/Noah11012/result-for-cpp)

# C++ Result
This is an implementation in C++ of Rust's Result. This is a WIP so not all methods found on Rust's Result type will be here at first. If you would like to help and implement the methods found in Rust's Result, that would be appreciated.

### List of methods to implement
* `iter()`
* `map_err()`


## Quick Start
This library contains a header and a source file. Just include the header and add the source file to your list of files to build. Result for C++ uses some C++ 17 library features so you will need a compiler that supports C++ 17.

Compile with `clang++ -o program main.cpp other_file.cpp -std=c++17`

In other_file.cpp:

```cpp
#include "result.hpp"

...
```