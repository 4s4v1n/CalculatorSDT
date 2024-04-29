#include "controller.hpp"

#include <algorithm>
#include <iostream>

#include "model/converter/converter_p_to_decimal.hpp"
#include "model/converter/converter_decimal_to_p.hpp"

#include "model/processor/processor.hpp"

#include "model/number/real_number.hpp"

#include "model/exception/conversion_exception.hpp"

Controller* Controller::getInstance()
{
    static Controller instance {};
    return &instance;
}

QString Controller::calculate()
{
    auto expression {m_editor.getExpression()};

    // TODO split for two expression by operator lexem and remove while loop

    std::string result {};

    while (iter != expression.end())
    {
        while (std::isxdigit(*iter) || *iter == '.')
        {
            ++iter;
        }

        RealNumber lhs {0., 0, 0};
        try
        {
            lhs = RealNumber{expression.substr(0, std::distance(expression.begin(), iter)),
                             m_editor.getBase(), 2};
        }
        catch (const ConversionException& ex)
        {
            qWarning() << ex.what();
            return "";
        }

        switch (*iter++)
        {
            case '+':
            {
                Processor::getInstance()->setOperator(Processor::Operator::Plus);
                break;
            }
            case '-':
            {
                Processor::getInstance()->setOperator(Processor::Operator::Minus);
                break;
            }
            case '*':
            {
                Processor::getInstance()->setOperator(Processor::Operator::Multiply);
                break;
            }
            case '/':
            {
                Processor::getInstance()->setOperator(Processor::Operator::Division);
                break;
            }
            default:
            {
                break;
            }
        }

        RealNumber rhs {expression.substr(std::distance(iter, expression.begin()),
                                          expression.size()), m_editor.getBase(), 2};

        Processor::getInstance()->setLhs(lhs);
        Processor::getInstance()->setRhs(rhs);

        result = Processor::getInstance()->execute().string();

        m_editor.resetExpression(result);
    }

    return QString::fromStdString(result);
}

void Controller::setBase(const int base)
{
    try
    {
        m_editor.setBase(base);
    }
    catch (const std::invalid_argument& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}


void Controller::addExpression(const QString& text)
{
    try
    {
        m_editor.addExpression(text.toStdString());
    }
    catch (const std::invalid_argument& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void Controller::clearEntry()
{
    m_editor.clearEntry();
}

void Controller::clearAll()
{
    m_editor.clearAll();
}
