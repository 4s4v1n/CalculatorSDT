#ifndef REAL_NUMBER_HPP
#define REAL_NUMBER_HPP

#include <string>

class RealNumber
{
public:
    RealNumber(const std::string& value, int base, int accuracy);
    RealNumber(double value, int base, int accuracy);

public:
    RealNumber operator+(const RealNumber& rhs) const;
    RealNumber operator-(const RealNumber& rhs) const;
    RealNumber operator*(const RealNumber& rhs) const;
    RealNumber operator/(const RealNumber& rhs) const;

    friend RealNumber operator/(double lhs, const RealNumber& rhs);

    int accuracy() const;
    int base() const ;
    double value() const;
    std::string string() const;

private:
    double m_value    {0.};
    int    m_base     {0};
    int    m_accuracy {0};
};

#endif // REAL_NUMBER_HPP
