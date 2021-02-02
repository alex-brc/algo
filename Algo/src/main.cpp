#include "fibonacci.h"

#include <iostream>


int main() {

	auto bi = math::BigInt("506");
	auto b = math::matrix::Matrix2<math::BigInt>(bi); 
	auto c = math::matrix::Matrix2<math::BigInt>(math::BigInt("1"), math::BigInt("2"), math::BigInt("3"), math::BigInt("4"));
	auto a = b + c;


	std::cout << b << " + " << c << " = " << a << std::endl;

	std::cout << algorithm::fibonacci::exponentiation_get(100);
}