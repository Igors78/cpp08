#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>

template <class T, class Container = std::deque<T>>

class MutantStack
	: public std::stack<T, Container>
{

public:
	MutantStack(): std::stack<T, Container>() {}
	MutantStack(MutantStack<T, Container> const &src)
		: std::stack<T, Container>()
	{
		*this = src;
	}
	~MutantStack() {}

	MutantStack<T, Container> &operator=(MutantStack<T, Container> const &rhs)
	{
		if (*this != rhs)
		{
			this->c = rhs.c;
		}
		return *this;
	}

	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	iterator begin()
	{
		return (this->c.begin());
	}

	iterator end()
	{
		return (this->c.end());
	}
};

#endif /* ***************************************************** MUTANTSTACK_H */