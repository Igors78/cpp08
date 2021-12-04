#include "MutantStack.hpp"
#include <list>

int main(void)
{
	std::cout << "------Int--------" << std::endl;
	MutantStack<int> mstack;
	std::cout << "Add: " << 5 << std::endl;
	mstack.push(5);
	std::cout << "Add: " << 17 << std::endl;
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size of stack: " << mstack.size() << std::endl;
	std::cout << "Delete top element" << std::endl;
	mstack.pop();
	std::cout << "Size of stack: " << mstack.size() << std::endl;
	std::cout << "Add: " << 3 << std::endl;
	mstack.push(3);
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Add: " << 5 << std::endl;
	mstack.push(5);
	std::cout << "Add: " << 737 << std::endl;
	mstack.push(737);
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Delete top element" << std::endl;
	mstack.pop();
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Add: " << 0 << std::endl;
	mstack.push(0);
	std::cout << "Size of stack: " << mstack.size() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " | ";
		++it;
	}
	std::cout << std::endl;
	std::cout << "------Copy stack--------" << std::endl;
	MutantStack<int> s(mstack);
	MutantStack<int>::iterator its = s.begin();
	MutantStack<int>::iterator itse = s.end();
	while (its != itse)
	{
		std::cout << *its << " | ";
		++its;
	}
	std::cout << std::endl;

	std::cout << "------ EMPTY TEST ------" << std::endl;

	MutantStack<int> estack;

	if (estack.empty())
		std::cout << "stack is empty" << std::endl;
	
	std::cout << "------ PUSH TEST ------" << std::endl;

	for (int i = 0; i < 5; i++){
		estack.push(i);
	}
	it = estack.begin();
	ite = estack.end();
	while (it != ite){
		std::cout << *it << std::endl;
		++it;
	}
}