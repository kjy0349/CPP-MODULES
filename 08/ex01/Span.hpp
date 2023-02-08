#ifndef SPAN_HPP
# define SPAN_HPP
# pragma once

# include <iostream>
# include <vector>

class Span {
    private:
        size_t value_;
        std::vector<int> nums_;
        Span(void);
    public:
        Span(Span &obj);
        Span(unsigned int value);
        Span& operator=(Span &obj);
        ~Span(void);
        void addNumber(int value);
        size_t shortestSpan(void);
        size_t longestSpan(void);
        size_t getValue(void);
        std::vector<int> getNums(void);
};

#endif