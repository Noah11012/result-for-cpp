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

int test2()
{
    rust::Result<int, std::string> r(100);

    std::optional<int> op = r.ok();

    if(!op.has_value())
        return -1;
    
    rust::Result<int, std::string> r2 = rust::Result<int, std::string>::from_error("An error");

    std::optional<std::string> op2 = r2.err();

    if(!op2.has_value())
        return -1;

    return 0;
}

rust::Result<int, std::string> test_function1(std::string s)
{
    std::cout << s << "\n";
    return rust::Result<int, std::string>(1000);
}

int test3()
{
    rust::Result<int, std::string> r(100);

    int number = r.or_else(test_function1).unwrap_or(-1);

    if(number != 100)
        return -1;
    
    rust::Result<int, std::string> r2 = rust::Result<int, std::string>::from_error("An error");

    rust::Result<int, std::string> r3 = r2.or_else(test_function1);

    number = r3.unwrap_or(-1);

    if(number != 1000)
        return -1;

    return 0;
}

int main()
{
    int status = 0;

    status = test1();
    status = test2();
    status = test3();

    return status;
}