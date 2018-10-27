#include <functional>
#include <optional>

namespace rust
{
    template<typename T>
    struct Ok
    {
        Ok() = default;
        ~Ok() = default;

        explicit Ok(const T &value);

        T m_value;
    };

    template<typename E>
    struct Err
    {
        Err() = default;
        ~Err() = default;

        explicit Err(const E &error);

        E m_error;
    };


    template<typename T, typename E>
    class Result
    {
    public:

        Result() = default;
        ~Result() = default;

        bool operator ==(Ok<T> const &value);
        bool operator ==(Ok<T> const &value) const;

        bool operator ==(Err<E> const &error);
        bool operator ==(Err<E> const &error) const;

        bool operator !=(Ok<T> const &value);
        bool operator !=(Ok<T> const &value) const;

        bool operator !=(Err<E> const &error);
        bool operator !=(Err<E> const &error) const;

        explicit Result(T value);
        static Result<T, E> from_error(E error);

        bool &is_ok() { return m_t_contains_value; }
        bool const &is_ok() const { return m_t_contains_value; }

        bool is_err() { return !m_t_contains_value; }
        bool const is_err() const { return !m_t_contains_value; }

        std::optional<T> ok();
        std::optional<T> ok() const;

        std::optional<E> err();
        std::optional<E> err() const;

        template<typename F>
        Result<T, F> or_(Result<T, F> res);

        template<typename U>
        Result<U, E> and_(Result<U, E> res);

        template<typename U>
        Result<U, E> map(std::function<U(T)> op);

        template<typename F>
        Result<T, F> map_err(std::function<F(E)> op);

        Result<T, E> or_else(std::function<Result<T, E>(E)> op);

        Result<T, E> and_then(std::function<Result<T, E>(T)> op);

        T &expect(char const *msg);
        T const &expect(char const *msg) const;

        T &expect(std::string const &msg);
        T const &expect(std::string const &msg) const;

        E &unwrap_err();
        E const &unwrap_err() const;

        T &unwrap();
        T const &unwrap() const;

        T &unwrap_or(T &optb);
        T const &unwrap_or(T const &optb) const;

        T &unwrap_or_else(std::function<T(E)> op);
        T const &unwrap_or_else(std::function<T(E)> op) const;

    private:
        Ok<T> m_okay_value;
        Err<E> m_error_value;

        bool m_t_contains_value;
    };
}
