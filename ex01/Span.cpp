#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
	: _n(1)
{
	this->_v.reserve(_n);
}

Span::Span(uint n)
	: _n(n)
{
	if (_n == 0)
		throw Span::NoElementException();
	this->_v.reserve(_n);
}

Span::Span(const Span &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_n = rhs._n;
		(this->_v).assign((rhs._v).begin(), (rhs._v).end());
	}
	return *this;
}

// std::ostream &operator<<(std::ostream &o, Span const &i)
// {
// 	o << "Value = " << i.getValue();
// 	return o;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/
char const *Span::NoSpaceException::what() const throw()
{
	return ("Not enough space to place element");
}

char const *Span::NoElementException::what() const throw()
{
	return ("Vector is empty or contains one element only");
}

int Span::longestSpan() const
{
	if (this->_v.size() < 2)
	{
		throw Span::NoElementException();
	}
	std::vector<int>::const_iterator max =
		std::max_element(this->_v.begin(), this->_v.end());
	std::vector<int>::const_iterator min =
		std::min_element(this->_v.begin(), this->_v.end());
	return (*max - *min);
}

int Span::shortestSpan(void) const
{
	if (this->_v.size() < 2)
		throw Span::NoElementException();
	std::vector<int> copy = this->_v;
	std::sort(copy.begin(), copy.end());
	std::vector<int>::const_iterator min =
		std::min_element(copy.begin(), copy.end());
	return (*(min + 1) - *min);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
void Span::addNumber(int num)
{
	if (this->_v.size() < this->_n)
		this->_v.push_back(num);
	else
		throw NoSpaceException();
}

void Span::addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	for (; start < end; start++)
	{
		if (this->_v.size() == this->_n)
			throw NoSpaceException();
		this->_v.push_back(*start);
	}
}
/* ************************************************************************** */