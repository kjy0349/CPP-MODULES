#include "Span.hpp"
//     size_t value_;
//     std::vector<int> nums_;
//     Span(void);
// public:
//     Span(Span &obj);
//     Span(int value);
//     Span& operator=(Span &obj);
//     ~Span(void);
//     void addNumber(int value);
//     size_t shortestSpan(void);
//     size_t longestSpan(void);
//     size_t getValue(void);
//     std::vector<int> getNums(void);

Span::Span(void) : value_(0), nums_(NULL)
{
}
Span::Span(Span &obj)
{
    this->value_ = obj.getValue();
    this->nums_ = obj.getNums();
}
Span::Span(unsigned int value)
{
    nums_ = std::vector<int>(value);
}
