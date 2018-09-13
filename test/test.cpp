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

    rust::Result<int, std::string> result_test2 = rust::Result<int, std::string>::from_error("An error has occurred");
    

    if(!result_test2.is_err())
    {
        return 1;
    }

    return 0;
}