#include <iostream>
#include <string>
#include <cstring>

class CxxCalculator
{
public:
    CxxCalculator(const char *person = "World") : person_(person) {}

    void say_hello() const
    {
        std::cout << "Hello " << person_ << "!\n";
    }

    /**
     * CxxCalc Implementation of Addition
     *
     * @param a first summand
     * @param b second summand
     * @return sum (a+b)
     */
    static double cxx_add(double a, double b)
    {
        return (a + b);
    }

    /**
     * CxxCalc Implementation of Subtraction
     *
     * @param a minuend
     * @param b subtrahend
     * @return difference (a-b)
     */
    static double cxx_subtract(double a, double b)
    {
        return (a - b);
    }

    /**
     * CxxCalc Implementation of Multiplication

     * @param a first factor
     * @param b second factor
     * @return product (a*b)
     */
    static double cxx_multiply(double a, double b)
    {
        return (a * b);
    }

    /**
     * CxxCalc Implementation of Division
     *
     * @param a dividend
     * @param b divisor
     * @return quotient of (a/b)
     */
    static double cxx_divide(double a, double b)
    {
        return (a / b);
    }

    static double add(double a, double b)
    {
        return (a + b);
    }

private:
    std::string person_;
};

int main(int ac, const char *argv[])
{
    std::cout << "CxxCalc: Hello, World!" << std::endl;

    const char *command = argv[1];
    double a = std::stod(argv[2]);
    double b = std::stod(argv[3]);
    double c;

    if (!strcmp(command, "add"))
    {
        c = CxxCalculator::cxx_add(a, b);
    }
    else if (!strcmp(command, "subtract"))
    {
        c = CxxCalculator::cxx_subtract(a, b);
    }
    else if (!strcmp(command, "multiply"))
    {
        c = CxxCalculator::cxx_multiply(a, b);
    }
    else if (!strcmp(command, "divide"))
    {
        c = CxxCalculator::cxx_divide(a, b);
    }
    else
    {
        std::cout << "Error: Command not valid" << std::endl;
        return (1);
    }

    std::cout << c << std::endl;
}