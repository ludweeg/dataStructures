#include "BloomFilter.hpp"

BloomFilter::BloomFilter(int size, int numHashes)
	: size(size), numHashes(numHashes)
{
	bits.resize(this->size);
}

unsigned long int BloomFilter::Hash(std::string str, int n)
{
	unsigned long int result = 0;

	for(int i = 0; i < str.length(); i++)
	{
		result = result * n + ((int)str[i] - 48);
	}
	return result;
}

 void BloomFilter::Add(std::string str)
 {
 	for(int i = 0; i < numHashes; i++)
 	{
 		int n = this->Hash(str, i) % this->size;
 		this->bits[n] = 1;
 	}
 }

 bool BloomFilter::Check(std::string str)
 {
  	for(int i = 0; i < numHashes; i++)
 	{
 		int n = this->Hash(str, i) % this->size;
 		if(!bits[n]) 
		{
 			return false;
 		}
 	}
 	return true;	
 }

 void BloomFilter::PrintBits()
 {
 	for(int i = 0; i < this->size; i++)
 	{
 		std::cout << bits[i];
 	}
 	std::cout << std::endl;
 }

