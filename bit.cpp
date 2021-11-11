#include "bit.hpp"

namespace xandor {
    bit::bit(int int_value) :
        _int_value(int_value),
        _bool_value((bool)int_value)
    {
    }

    bit::bit(bool bool_value) :
        _int_value(bool_value ? 1 : 0),
        _bool_value(bool_value)
    {
    }
}