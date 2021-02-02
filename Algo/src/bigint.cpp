#include "bigint.h"

namespace math
{
	char* strdup(const char* src, bool flip) {
		auto len = strlen(src);
		if (len == 0)
			throw 

		// Destination character array
		char* dst = (char*)malloc(sizeof(char) * (len + 1));
		// Cap the string with null
		dst[len] = 0;
		if (flip)
			// Copy the source into destination in reverse
			for (size_t i = len; i > 0; i--)
				dst[i - 1] = src[len - i];
		else
			for (size_t i = 0; i <= len; i++)
				dst[i] = src[len];
		return dst;
	}
	BigInt::BigInt() {
		this->value = strdup("0", 0);
	}
	BigInt::BigInt(const char* value, const bool flip)
	{
		this->value = strdup(value, flip);
	}

	BigInt::~BigInt()
	{
		_freea(this->value);
	}

	BigInt::BigInt(const BigInt& original)
	{
		this->value = strdup(original.value, 0);
	}

	char& BigInt::operator[](size_t index)
	{
		return this->value[index];
	}

	BigInt BigInt::operator+(const BigInt& operand)
	{
		char* shorter = operand.value;
		auto sn = strlen(shorter);
		char* longer = this->value;
		auto ln = strlen(longer);
		// If shorter is longer than longer
		if (sn > ln)
		{
			// Swap values
			shorter = this->value;
			longer = operand.value;
			// Swap lengths
			auto t = sn;
			sn = ln;
			ln = t;
		}

		// Allocate mem for result. Will be freed with ~BigInt.
		char* result = (char*)_malloca(sizeof(char) * (ln + 1 + 1)); // +1 for NULL, +1 for carry
		bool carry = 0;
		char digit;
		// Iterate through the positions of shorter
		for (size_t i = 0; i < ln; i++)
		{
			digit = (longer[i] - 48) + carry;
			if (i < sn)
				digit += (shorter[i] - 48);

			result[i] = digit % 10 + 48;
			carry = digit / 10;
		}

		if (carry != 0)
		{
			result[ln] = '1';
			result[ln + 1] = NULL;
			carry = 0;
		}
		else
		{
			result[ln] = NULL;
		}

		return BigInt(result);
	}

	std::ostream& operator<<(std::ostream& os, const BigInt& bi)
	{
		for (size_t i = strlen(bi.value); i > 0; i--)
			os << bi.value[i - 1];
		return os;
	}
}