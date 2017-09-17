#include <iostream>
#include "BloomFilter.hpp"

int main()
{
	BloomFilter bf(10,3);
	bf.Add("filter");
	bf.Add("pet");
	if(bf.Check("pet")) std::cout << "An element may be contained in a set" << std::endl;
	else                std::cout << "The element is not contained in the set" << std::endl;
	bf.PrintBits();

	return 0;
}