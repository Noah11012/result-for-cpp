[![Build Status](https://api.cirrus-ci.com/github/Noah11012/result-for-cpp.svg)](https://cirrus-ci.com/github/Noah11012/result-for-cpp)

# C++ Result
Result for C++ an implementation of Rust's Enum type `Result`. This C++ implementation
tries to be as close to the original thing as possible. Of course, it won't be because of the
language difference between the two.

### Differences
* `and()` and `or()` are called `and_()` and `or_()` in this implementation
because `and` and `or` are keywords in C++.
* To create an Err `Result` use the static member `from_error()`.
* A panic is a `std::runtime_error`.
* `unwrap()`, `unwrap_err()` and `expect()` do not display the error value or the okay value
when they panic. This is because it might not be possible to convert the type into a string.

## Warning
The ability to check for equality between a `Result` and a value was added. However, one problem
arose when this feature was added. If the template types are the same
(for example `Result<int, int>` or `Result<std::string, std::string>`) then a compiler
error will be displayed if equality checking is used. This bug will have to be fixed in the near future. If anyone has an idea how to remedy this problem it will be greatly appreciated.

## Quick Start
This library contains a header and a source file. Just include the header and add the source file to your list of files to build. Result for C++ uses some C++ 17 library features so you will need a compiler that supports C++ 17.

Compile with `clang++ -o program main.cpp other_file.cpp -std=c++17`

In other_file.cpp:

```cpp
#include "result.hpp"

...
```

## Documentation
Currently, no documentation exist at the moment. The best source of documentation is at the [Rust STD Documentation](https://doc.rust-lang.org/std/result/enum.Result.html) website.
