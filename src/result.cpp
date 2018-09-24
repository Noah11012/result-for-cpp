#include "result.hpp"

namespace rust
{
    template<typename T, typename E>
    Result<T, E>::Result(T value): m_value{value}, m_error{}, m_t_contains_value{true}
    {
        
    }

    template<typename T, typename E>
    Result<T, E> Result<T, E>::from_error(E error)
    {
        Result<T, E> result;

        result.m_value = T{};
        result.m_error = error;
        result.m_t_contains_value = false;

        return result;
    }

    template<typename T, typename E>
    std::optional<T> Result<T, E>::ok()
    {
        if(m_t_contains_value)
            return std::make_optional<T>(m_value);
        else
            return std::nullopt;
    }
    
    template<typename T, typename E>
    template<typename F>
    Result<T, F> Result<T, E>::or_(Result<T, F> res)
    {
        if(!m_t_contains_value)
            return res;
        else
            return m_value;
    }
    
    template<typename T, typename E>
    template<typename U>
    Result<U, E> Result<T, E>::and_(Result<U, E> res)
    {
        if(m_t_contains_value)
            return res;
        else
            return Result<U, E>::from_error(m_error);
    }

    template<typename T, typename E>
    std::optional<E> Result<T, E>::err()
    {
        if(!m_t_contains_value)
            return std::make_optional<E>(m_error);
        else
            return std::nullopt;
    }

    template<typename T, typename E>
    Result<T, E> Result<T, E>::or_else(std::function<Result<T, E>(E)> op)
    {
        if(!m_t_contains_value)
            return op(m_error);
        else
            return Result(m_value);
    }

    template<typename T, typename E>
    Result<T, E> Result<T, E>::and_then(std::function<Result<T, E>(T)> f)
    {
        if(m_t_contains_value)
            return f(m_value);
        else
            return Result(m_error);
    }

    template<typename T, typename E>
    T Result<T, E>::unwrap_or(T optb)
    {
        if(m_t_contains_value)
            return m_value;
        else
            return optb;
    }

    template<typename T, typename E>
    T Result<T, E>::unwrap_or_else(std::function<T(E)> op)
    {
        if(m_t_contains_value)
            return m_value;
        else
            return op(m_error);
    }
}