#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include "../number/real_number.hpp"

class Processor
{
public:
    enum class Operator
    {
        None,
        Plus,
        Minus,
        Multiply,
        Division,
        Square,
        Reverse
    };

private:
    Processor() = default;
    ~Processor() = default;

public:
    static Processor* getInstance() noexcept;

public:
    void setOperator(Operator op);
    void setLhs(const RealNumber& lhs);
    void setRhs(const RealNumber& rhs);
    RealNumber execute();

private:
    Operator   m_operator {Operator::None};
    RealNumber m_lhs      {0., 0, 0};
    RealNumber m_rhs      {0., 0, 0};
};

#endif // PROCESSOR_HPP
