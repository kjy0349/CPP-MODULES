template <typename T>
T& Array<T>::operator[] (std::size_t i)
{
	if (i >= len)
	{
		throw std::out_of_range("parameter is over the this array size ");
	}
	return (array[i]);
}

template <typename T>
const T& Array<T>::operator[] (std::size_t i) const
{
	if (i >= len)
	{
		throw std::out_of_range("parameter is over the this array size ");
	}
	return (array[i]);
}

template <typename T>
Array<T>::Array(void) : len(0), array(NULL)
{
}

template <typename T>
Array<T>::Array(std::size_t n)
{
	this->len = n;
	this->array = new T[n];
}

template <typename T>
Array<T>::Array(const Array& obj)
{
	this->len = obj.size();
	this->array = new T[this->len];
	for(std::size_t i = 0; i < len; i++)
	{
		array[i] = obj[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
	if (this != &obj) 
	{
		delete [] this->array;
		this->array = NULL;
		this->len = obj.size();
		this->array = new T[this->len];
		for(std::size_t i = 0; i < len; i++)
		{
			array[i] = obj[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] this->array;
	this->array = NULL;
}

template <typename T>
std::size_t Array<T>::size(void) const
{
	return (this->len);
}