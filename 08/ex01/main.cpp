#include "Span.hpp"
int main()
{
    Span sp = Span(5);
    Span test = Span(10000);
    std::vector<int> test2;
    std::vector<int>::iterator start;
    std::vector<int>::iterator end;

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    for (int i = 0; i < 10000; i++) test2.push_back(i);
    start = test2.begin();
    end = test2.end();
    test.addRange(start, end);
    std::cout << test.shortestSpan() << std::endl;
    std::cout << test.longestSpan() << std::endl;
    Span test1 = Span(1);
    try
    {
        test1.addRange(start, end);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    return 0;
}
