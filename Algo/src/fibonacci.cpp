#include "fibonacci.h"

#include <iostream>

namespace algorithm {

	math::BigInt fibonacci::dynamic_get(int n)
	{
		if (n < 2)
			throw std::out_of_range{ "fibonacci::dynamic_get(int) - n must be >=2" };
		
		// Establish first two terms
		auto previous = math::BigInt("0");
		auto current = math::BigInt("1");
		auto temp = current;

		// Iterate
		for (int i = 2; i < n; i++)
		{
			current = current + previous;
			previous = temp;
			temp = current;
		}

		return current;
	}

	math::BigInt fibonacci::exponentiation_get(int n)
	{
		// Create A matrix

		// Compute (n-1)th power of A
		

		return math::BigInt("0");
	}
}