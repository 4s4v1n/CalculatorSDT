#include "editor.hpp"

#include "../exception/number_exception.hpp"

void Editor::setBase(const int base)
{
    if (base < 2 || base > 16)
    {
        throw NumberException{"base is out of range"};
    }
    if (m_base != base)
    {
        m_base = base;
    }
}

int Editor::getBase() const
{
    return m_base;
}

std::string Editor::getExpression() const
{
    return m_expression;
}

void Editor::addExpression(const std::string &expression)
{
    if (!m_valid_expressions.contains(expression))
    {
        throw NumberException{"symbol is out of range"};
    }
    m_expression += expression;
}

void Editor::clearEntry()
{
    m_expression.pop_back();
}

void Editor::clearAll()
{
    m_expression.clear();
}

void Editor::resetExpression(const std::string& expression)
{
    for (const auto& token : expression)
    {
        if (!m_valid_expressions.contains(std::string{token}))
        {
            throw NumberException{"symbol is out of range"};
        }
    }
    m_expression = expression;
}
