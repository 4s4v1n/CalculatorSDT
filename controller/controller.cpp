#include "controller.hpp"

#include <algorithm>
#include <array>
#include <iostream>

#include "model/converter/converter_p_to_decimal.hpp"
#include "model/converter/converter_decimal_to_p.hpp"

#include "model/processor/processor.hpp"

#include "model/number/real_number.hpp"

// #include "model/exception/conversion_exception.hpp"

Controller* Controller::getInstance()
{
    static Controller instance {};
    return &instance;
}

QString Controller::calculate()
{
    static std::array<std::string, 6> delimeters {"+", "-", "*", "/",
                                                  "square", "reverse"};

    auto expression {m_editor.getExpression()};

    for (const auto& delimeter : delimeters)
    {
        auto pos {expression.find(delimeter)};
        if (pos == std::string::npos || pos == 0 && delimeter == "-")
        {
            continue;
        }

        try
        {
            auto lhs {expression.substr(0, pos)};

            Processor::getInstance()->setLhs({lhs, m_editor.getBase(), m_editor.getAccuracy()});
            Processor::getInstance()->setOperator(delimeter);

            if (pos + delimeter.size() < expression.size())
            {
                auto rhs {expression.substr(pos + delimeter.size(), expression.size())};
                Processor::getInstance()->setRhs({rhs, m_editor.getBase(), m_editor.getAccuracy()});
            }
        }
        catch (const std::exception& ex)
        {
            qWarning() << ex.what();
        }
        break;
    }

    auto result {Processor::getInstance()->execute().string()};
    m_editor.resetExpression(result);

    return QString::fromStdString(result);
}

void Controller::setBase(const int base)
{
    try
    {
        m_editor.setBase(base);
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void Controller::setAccuracy(const int accuracy)
{
    try
    {
        m_editor.setAccuracy(accuracy);
    }
    catch(const std::exception& ex)
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
