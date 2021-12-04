#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Span
{

public:
	Span();
	Span(uint n);
	Span(Span const &src);
	~Span();

	Span &operator=(Span const &rhs);

	class NoSpaceException
		: public std::exception
	{
	public:
		char const *what() const throw();
	};
	class NoElementException
		: public std::exception
	{
	public:
		char const *what() const throw();
	};

	void addNumber(int num);
	void addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);
	int shortestSpan() const;
	int longestSpan() const;

private:
	uint _n;
	std::vector<int> _v;
};

//std::ostream &operator<<(std::ostream &o, Span const &i);

#endif /* ************************************************************ SPAN_H */