#include "real_number.hpp"

#include <cmath>

#include "../exception/number_exception.hpp"
#include "../exception/calculation_exception.hpp"

#include "../converter/converter_decimal_to_p.hpp"
#include "../converter/converter_p_to_decimal.hpp"

void checkBase(const RealNumber& lhs, const RealNumber& rhs)
{
    if (lhs.base() != rhs.base())
    {
        throw NumberException{"operands got different base"};
    }
}

void checkZero(const RealNumber& lhs)
{
    if (lhs.value() == 0.)
    {
        throw CalculationException{"operand is equals zero"};
    }
}

RealNumber::RealNumber(const std::string& value, int base, int accuracy):
    m_value{value.find(".") == std::string::npos ?
              ConverterP2Decimal::pToInt(value, base) :
              ConverterP2Decimal::pToFloat(value, base)},
    m_base{base},
    m_accuracy{accuracy}
{}

RealNumber::RealNumber(double value, int base, int accuracy):
    m_value{value},
    m_base{base},
    m_accuracy{accuracy}
{}

int RealNumber::accuracy() const
{
    return m_accuracy;
}

int RealNumber::base() const
{
    return m_base;
}

double RealNumber::value() const
{
    return m_value;
}

std::string RealNumber::string() const
{
    return ConverterDecimal2P::floatToP(m_value, m_base, m_accuracy);
}

RealNumber RealNumber::square() const
{
    return RealNumber{m_value * m_value, m_base, m_accuracy};
}

RealNumber RealNumber::reverse() const
{
    checkZero(*this);
    return RealNumber{1. / m_value, m_base, m_accuracy};
}

RealNumber RealNumber::operator+(const RealNumber& rhs) const
{
    checkBase(*this, rhs);
    return RealNumber{m_value + rhs.m_value, m_base , m_accuracy};
}

RealNumber RealNumber::operator-(const RealNumber& rhs) const
{
    checkBase(*this, rhs);
    return RealNumber{m_value - rhs.m_value, m_base, m_accuracy};
}

RealNumber RealNumber::operator*(const RealNumber& rhs) const
{
    checkBase(*this, rhs);
    return RealNumber{m_value * rhs.m_value, m_base, m_accuracy};
}

RealNumber RealNumber::operator/(const RealNumber& rhs) const
{
    checkBase(*this, rhs);
    checkZero(rhs);
    return RealNumber{m_value / rhs.m_value, m_base, m_accuracy};
}
