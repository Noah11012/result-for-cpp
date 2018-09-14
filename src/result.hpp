#include <functional>
#include <optional>

namespace rust
{
    template<typename T, typename E>
    class Result
    {
    public:
        Result() = default;
        ~Result() = default;

        Result(T value);
        static Result<T, E> from_error(E error);

        bool is_ok() const { return m_t_contains_value; }
        bool is_err() const { return !m_t_contains_value; }

        std::optional<T> ok();
        std::optional<T> err();

        Result<T, E> or_else(std::function<Result<T, E>(E)> op);

        Result<T, E> and_then(std::function<Result<T, E>(T)> op);

        T unwrap_or(T optb);

        T unwrap_or_else(std::function<T(E)> op);
    private:
        T m_value;
        E m_error;

        bool m_t_contains_value;
    };
}