#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "model/editor/editor.hpp"
#include "model/history/history.hpp"

class Controller : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(Controller);

public:
    Q_INVOKABLE void setBase(int base);
    Q_INVOKABLE void setAccuracy(int accuracy);
    Q_INVOKABLE void addExpression(const QString& text);
    Q_INVOKABLE void clearEntry();
    Q_INVOKABLE void clearAll();
    Q_INVOKABLE QString calculate();

public:
    static Controller* getInstance();

private:
    Controller() = default;
    ~Controller() override = default;

private:
    Editor m_editor {};
};

#endif // CONTROLLER_HPP
