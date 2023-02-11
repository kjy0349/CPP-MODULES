#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span {
    private:
        std::vector<int> nums_;
        Span(void);
    public:
        Span(const Span& obj);
        Span& operator=(const Span& obj);
        ~Span(void);
        Span(std::size_t i);
        void addNumber(std::size_t value);
        void addRange(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);
        std::size_t shortestSpan() const;
        std::size_t longestSpan() const;
        std::size_t getSize() const;
        std::vector<int> getVector() const;
};

#endif
