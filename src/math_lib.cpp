//
// Created by mengh04 on 25-4-1.
//

class MathCalculator {
    double m_result;

public:
    MathCalculator() : m_result(0) {}

    void add(double val) { m_result += val; }
    void subtract(double val) { m_result -= val; }
    void multiply(double val) { m_result *= val; }
    void divide(double val) { m_result /= val; }

    double getResult() const { return m_result; }
};