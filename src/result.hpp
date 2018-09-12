#include <functional>

namespace rust
{
    template<typename T, typename E>
    class Result
    {
    public:
        Result() = default;
        ~Result() = default;

        Result(T value);
        Result(E error);

        bool is_ok() const { return m_t_contains_value; }
        bool is_err() const { return !m_t_contains_value; }

        template<typename F>
        Result<T, E> or_else(std::function<F> f);

        template<typename F>
        Result<T, E> and_then(std::function<F> f);

        T unwrap_or(T optb);

        T unwrap_or_else(std::function<T(E)> op);
    private:
        T m_value;
        E m_error;

        bool m_t_contains_value;
    };
}