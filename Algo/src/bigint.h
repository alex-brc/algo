#pragma once

#include <string>
#include <iostream>

namespace math {
	class BigInt {
	public:
		BigInt();
		BigInt(const char* value, const bool flip = true);
		~BigInt();
		BigInt(const BigInt&);

		BigInt operator+(const BigInt&);
		char& operator[](size_t);
		friend std::ostream& operator<<(std::ostream&, const BigInt&);
		 
	private:
		char* value;
	};
}