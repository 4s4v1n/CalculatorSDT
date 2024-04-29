#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <set>
#include <string>

class Editor
{
public:
    void setBase(int base);
    int getBase() const;
    std::string getExpression() const;
    void addExpression(const std::string &expression);
    void clearEntry();
    void clearAll();
    void resetExpression(const std::string& expression);

private:
    const std::set<std::string> m_valid_expressions {"0", "1", "2", "3",
                                                     "4", "5", "6", "7",
                                                     "8", "9", "A", "B",
                                                     "C", "D", "E", "F",
                                                     "a", "b", "c", "d",
                                                     "e", "f", ".", "-",
                                                     "+", "*", "/", "square",
                                                     "reverse"};
private:
    std::string m_expression {};
    int         m_base       {2};
};

#endif // EDITOR_HPP
