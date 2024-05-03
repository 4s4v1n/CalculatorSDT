#ifndef MEMORY_HPP
#define MEMORY_HPP

template <typename T>
class Memory
{
public:
    void setValue(const T& value);
    T getValue() const;
    void on();
    void off();
    void clear();
    bool isActive() const;

private:
    enum State
    {
        On  = 0,
        Off = 1
    };

private:
    T     m_value {};
    State m_state {State::Off};
};

#endif // MEMORY_HPP
