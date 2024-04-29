#include "processor.hpp"

auto Processor::getInstance() noexcept -> Processor*
{
    static Processor instance {};
    return &instance;
}

void Processor::setOperator(const Operator op)
{
    m_operator = op;
}

void Processor::setLhs(const RealNumber& lhs)
{
    m_lhs = lhs;
}

void Processor::setRhs(const RealNumber& rhs)
{
    m_rhs = rhs;
}

RealNumber Processor::execute()
{
    switch (m_operator)
    {
        case Operator::None:     return RealNumber{0., 0, 0};
        case Operator::Plus:     return m_lhs + m_rhs;
        case Operator::Minus:    return m_lhs - m_rhs;
        case Operator::Multiply: return m_lhs * m_rhs;
        case Operator::Division: return m_lhs / m_rhs;
        case Operator::Square:   return m_lhs.square();
        case Operator::Reverse:  return m_lhs.reverse();
    }
}
