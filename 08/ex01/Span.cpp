#include "Span.hpp"

Span::Span()
{
	value_ = 0;
};

Span::Span(unsigned int n)
{
	value_ = n;
}

Span::Span(Span const &other)
{
	value_ = other.size();
	nums_ = other.getValues();
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		value_ = other.size();
		nums_ = other.getValues();
	}
	return *this;
}

Span::~Span()
{
}

unsigned int Span::size() const
{
	return value_;
}

std::vector<int> const &Span::getValues() const
{
	return nums_;
}

void Span::addNumber(int n)
{
	if (nums_.size() >= value_)
		throw Span::FullException();
	nums_.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end)
{
	int size = std::distance(begin, end);
	if (size > static_cast<int>(value_))
		throw Span::FullException();
	nums_.insert(nums_.end(), begin, end);
}

long Span::shortestSpan() const
{
	if (nums_.size() < 2)
		throw Span::CantSearchException();
	std::vector<int> copy = nums_;

	std::sort(copy.begin(), copy.end());
	std::vector<int>::iterator prev_it = copy.begin();
	std::vector<int>::iterator next_it = ++copy.begin();
	long minSpan = *next_it - *prev_it;

	while (next_it != copy.end())
	{
		if ((long)*next_it - *prev_it < minSpan)
			minSpan = (long)*next_it - *prev_it;
		prev_it = next_it;
		next_it++;
	}
	return minSpan;
}

long Span::longestSpan() const
{
	if (nums_.size() < 2)
		throw Span::CantSearchException();
	std::vector<int> copy = nums_;

	std::sort(copy.begin(), copy.end());

	return ((long)copy.back() - copy.front());
}
