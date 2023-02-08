#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# pragma once

# include <iostream>
# include <vector>
# include <list>
# include <deque>

template<typename T>
typename T::iterator easyfind(T &container, int target)
{
    typename T::iterator iter;

    iter = std::find(container.begin(), container.end(), target);
    if (iter == container.end())
    {
        throw std::runtime_error("can not find target.");
    }
    return (iter);
}

template<typename T>
typename T::const_iterator easyfind(T const &container, int target)
{
    typename T::const_iterator iter;

    iter = std::find(container.begin(), container.end(), target);
    if (iter == container.end())
    {
        throw std::runtime_error("can not find target.");
    }
    return (iter);
}

#endif