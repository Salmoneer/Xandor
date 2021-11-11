#include <map>
#include <string>
#include "tokens.hpp"

namespace xandor {
    namespace {
        std::map<std::string, reserved_token> token_map = {
            { "not", reserved_token::bitwise_not },
            { "and", reserved_token::bitwise_and },
            { "or",  reserved_token::bitwise_or  },
            { "xor", reserved_token::bitwise_xor },
            { ",",   reserved_token::comma       },
        };

        reserved_token get_token(std::string s) {
            auto it = token_map.find(s);
            return it->second;
        }
    }

    token::token(token_value value, size_t line_number, size_t char_index) :
        _value(std::move(value)),
        _line_number(line_number),
        _char_index(char_index)
    {
    }

    bool token::is_reserved_token() const {
        return std::holds_alternative<reserved_token>(_value);
    }

    bool token::is_identifier() const {
        return std::holds_alternative<identifier>(_value);
    }

    bool token::is_bit() const {
        return std::holds_alternative<bit>(_value);
    }

    bool token::is_eof() const {
        return std::holds_alternative<eof>(_value);
    }

    reserved_token token::get_reserved_token() const {
        return std::get<reserved_token>(_value);
    }

    const identifier& token::get_identifier() const {
        return std::get<identifier>(_value);
    }

    bit token::get_bit() const {
        return std::get<bit>(_value);
    }

    const token_value& token::get_value() const {
		return _value;
	}
	
	size_t token::get_line_number() const {
		return _line_number;
	}

	size_t token::get_char_index() const {
		return _char_index;
	}
	
	bool token::has_value(const token_value& value) const {
		return _value == value;
	}



    bit bitwise_not(bit a) {
        return bit(!a.get_bool());
    }

    bit bitwise_and(bit a, bit b) {
        return bit(a.get_bool()&&b.get_bool());
    }

    bit bitwise_or(bit a, bit b) {
        return bit(a.get_bool()||b.get_bool());
    }

    bit bitwise_xor(bit a, bit b) {
        return bit(a.get_bool()^b.get_bool());
    }
}