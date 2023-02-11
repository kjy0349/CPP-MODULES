#include "Span.hpp"

Span::Span(const Span& obj)
{
	nums_ = obj.getVector();
}

Span& Span::operator=(const Span& obj)
{
	if(this == &obj) return *this;
	nums_ = obj.getVector();
	return (*this);
}

Span::~Span(void)
{
	nums_.clear();
	std::vector<int>().swap(nums_);
}

Span::Span(std::size_t i)
{
	nums_.reserve(i);
}

void Span::addNumber(std::size_t value)
{
	if (nums_.capacity() <= nums_.size()) 
	{
		throw std::length_error("size over");
	}
	nums_.push_back(value);
}

void Span::addRange(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end)
{
	if (nums_.capacity() < nums_.size() + std::distance(begin, end)) 
	{
		throw std::length_error("size over");
	}
	nums_.insert(nums_.end(), begin, end);
}

std::size_t Span::shortestSpan() const
{
	if (nums_.size() <= 2)
	{
		throw std::logic_error("vector size is not over 2");
	}
	long ret = LONG_MAX;
	int prev;
	std::vector<int> tmp = nums_;

	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::iterator iter = tmp.begin(); iter != tmp.end(); iter++) 
	{
		if (iter == tmp.begin()) 
		{
			prev = *iter;
		}
		else 
		{
			if (ret > *iter - prev) 
			{
				ret = *iter - prev;
			}
			prev = *iter;
		}
	}
	return static_cast<std::size_t>(ret);
}

std::size_t Span::longestSpan() const
{
	if (nums_.size() <= 2)
	{
		throw std::logic_error("vector size is not over 2");
	}
	return (*std::max_element(nums_.begin(), nums_.end()) - *std::min_element(nums_.begin(), nums_.end()) );
}


std::size_t Span::getSize() const
{
	return (nums_.size());
}

std::vector<int> Span::getVector() const
{
	return (this->nums_);
}