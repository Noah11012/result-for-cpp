#include "result.hpp"

namespace rust
{
    template<typename T, typename E>
    Result<T, E>::Result(T value): m_value{value}, m_error{}, m_t_contains_value{true}
    {

    }

    template<typename T, typename E>
    Result<T, E>::Result(E error): m_value{}, m_error{error}, m_t_contains_value{false}
    {
        
    }

    template<typename T, typename E>
    template<typename F>
    Result<T, E> Result<T, E>::or_else(std::function<F> f)
    {
        if(is_err())
            f();
        else
            return Result(m_value);
    }

    template<typename T, typename E>
    template<typename F>
    Result<T, E> Result<T, E>::and_then(std::function<F> f)
    {
        if(is_ok())
            f();
        else
            return Result(m_error);
    }
}