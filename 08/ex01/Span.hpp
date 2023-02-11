#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span {
    private:
        unsigned int value_;
        std::vector<int> nums_;
        Span(void);
    public:
        Span(unsigned int value);
        Span(Span const &obj);
        Span& operator=(Span const &obj);
        int &operator[](int i);
        ~Span(void);

        unsigned int size() const;
	    std::vector<int> const &getValues() const;

        void addNumber(int value);
        void addNumber(std::vector<int>::iterator const &, std::vector<int>::iterator const &);
        long shortestSpan() const;
        long longestSpan() const;

        class OutOfRangeException : public std::exception
        {
        public:
            const char *what() const throw()
            {
                return ("Out of range");
            }
        };
        class FullException : public std::exception
        {
        public:
            const char *what() const throw()
            {
                return ("Buffer is already full");
            }
        };
        class CantSearchException : public std::exception
        {
        public:
            const char *what() const throw()
            {
                return ("Can't search");
            }
        };
};

#endif
