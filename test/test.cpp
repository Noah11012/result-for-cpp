#include "../src/result.cpp"
#include <iostream>
#include <string>

int test1()
{
    rust::Result<int, std::string> r(100);

    if(!r.is_ok())
        return -1;
    
    rust::Result<int, std::string> r2 = rust::Result<int, std::string>::from_error("An error");

    if(r.is_err())
        return -1;
    
    return 0;
}

int main()
{
    int status = 0;

    status = test1();

    return status;
}