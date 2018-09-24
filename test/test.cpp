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

int test4()
{
    rust::Result<int, std::string> r(100);
    rust::Result<int, double> r2(200);
    
    if(r.or_(r2).unwrap_or(-1) != 100)
        return -1;
    
    rust::Result<int, std::string> r3 = rust::Result<int, std::string>::from_error("An error");
    rust::Result<int, double> r4(300);
    
    if(r3.or_(r4).unwrap_or(-1) != 300)
        return -1;
    
    rust::Result<int, std::string> r5(400);
    rust::Result<double, std::string> r6(500.75);
    
    if(r5.and_(r6).unwrap_or(-1) != 500.75)
        return -1;
    
    rust::Result<int, std::string> r7 = rust::Result<int, std::string>::from_error("An error");
    rust::Result<double, std::string> r8(600.90);

    if(r7.and_(r8).err() != std::string("An error"))
        return -1;
    
    return 0;
}

int main()
{
    if(test1() != 0)
        return -1;

    if(test2() != 0)
        return -1;
    
    if(test3() != 0)
        return -1;

    if(test4() != 0)
        return -1;

    return 0;
}