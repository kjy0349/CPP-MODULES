#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class Array {
	private:
		std::size_t len;
		T *array;
	public:
		Array(void);
		Array(std::size_t n);
		Array(const Array& obj);
		Array& operator=(const Array& obj);
		~Array(void);
		std::size_t size(void) const;
		T& operator[] (std::size_t i);
		const T& operator[] (std::size_t i) const;
};

# include "Array.tpp"

#endif