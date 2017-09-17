#ifndef BLOOMFILTER__
#define BLOOMFILTER__

#include <iostream>
#include <string>
#include <vector>

class BloomFilter
{

private:
	std::vector<bool> bits;
	int size, numHashes;

public:
	BloomFilter(int, int);
	unsigned long int Hash(std::string, int);
	void Add(std::string);
	bool Check(std::string);
	void PrintBits();
};

#endif