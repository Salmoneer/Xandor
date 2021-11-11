#include <variant>
#include <optional>
#include <string_view>
#include <ostream>
#include "bit.cpp"

namespace xandor
{
    enum struct reserved_token
    {
        bitwise_not,
        bitwise_and,
        bitwise_or,
        bitwise_xor,

        comma,
        num,
    };

    struct identifier
    {
        std::string name;
    };

    struct eof
    {
    };

    using token_value = std::variant<reserved_token, identifier, bit, eof>;

    class token
    {
    private:
        token_value _value;
        size_t _line_number;
        size_t _char_index;

    public:
        token(token_value, size_t line_number, size_t char_index);

        bool is_reserved_token() const;
        bool is_identifier() const;
        bool is_bit() const;
        bool is_eof() const;

        reserved_token get_reserved_token() const;
        const identifier& get_identifier() const;
        bit get_bit() const;
        const token_value& get_value() const;

        size_t get_line_number() const;
        size_t get_char_index() const;

        bool has_value(const token_value& value) const;
    };
}

namespace std {
    std::string to_string(xandor::reserved_token t);
    std::string to_string(const xandor::token_value& t);
}