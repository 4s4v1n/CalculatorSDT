#include "converter_decimal_to_p.hpp"

#include <cmath>
#include <limits>
#include <list>

#include "../exception/conversion_exception.hpp"

std::string ConverterDecimal2P::floatToP(double value, int notation, int accuracy)
{
    if (notation < 2 || notation > 16)
    {
        std::string exception_message {"got invalid number notation " + std::to_string(notation)};
        throw ConversionException{exception_message.c_str()};
    }

    auto integer_part{0.};
    auto fractional_part    {std::modf(value, &integer_part)};

    std::string integer_str    {intToP(static_cast<int>(integer_part), notation)};
    std::string fractional_str {};

    if (fractional_part < 0)
    {
        if (integer_str == "0")
        {
            integer_str.insert(0, "-");
        }
        fractional_part *= -1;
    }

    auto current_accuracy {0};
    while (fractional_part > std::numeric_limits<double>::epsilon() && current_accuracy < accuracy)
    {
        fractional_part *= notation;
        fractional_part = std::modf(fractional_part, &integer_part);

        fractional_str.push_back(intToChar(static_cast<int>(integer_part)));

        ++current_accuracy;
    }

    while (fractional_str.back() == '0')
    {
        fractional_str.pop_back();
    }

    if (fractional_str.empty())
    {
        return integer_str;
    }
    return (integer_str + "." + fractional_str);
}

std::string ConverterDecimal2P::intToP(int value, const int notation)
{
    if (notation < 2 || notation > 16)
    {
        std::string exception_message {"got invalid number notation " + std::to_string(notation)};
        throw ConversionException{exception_message.c_str()};
    }

    auto is_negative {false};
    if (value < 0)
    {
        is_negative = true;
        value *= -1;
    }

    std::list<int> remainder_list {};
    do
    {
        remainder_list.push_front(value % notation);
        value /= notation;
    }
    while (value != 0);

    std::string result {is_negative ? "-" : ""};
    for (const auto& reminder : remainder_list)
    {
        result.push_back(intToChar(reminder));
    }
    return result;
}

char ConverterDecimal2P::intToChar(const int value)
{
    if (value < 0 || value > 16)
    {
        std::string exception_message {"got invalid expression " + std::to_string(value)};
        throw ConversionException{exception_message.c_str()};
    }

    if (value <= 9)
    {
        return static_cast<char>(value + 48);
    }
    return static_cast<char>(value + 55);
}
