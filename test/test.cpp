#include "../src/result.cpp"
#include <iostream>
#include <string>


int main()
{
    rust::Result<int, std::string> result_test(100);

    if(!result_test.is_ok())
    {
        return 1;
    }

    return 0;
}