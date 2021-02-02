#pragma once

#include <ostream>

namespace math
{
	namespace matrix
	{
		template<typename T>
		class Matrix2
		{
		public:
			Matrix2(T);
			Matrix2(T, T, T, T);

			Matrix2<T> operator+(const Matrix2<T>&);
			Matrix2<T> operator*(const Matrix2<T>&);
			Matrix2<T> operator+=(const Matrix2<T>&);
			Matrix2<T> operator*=(const Matrix2<T>&);

			friend std::ostream& operator<<(std::ostream& os, const Matrix2<T>& mat)
			{
				os << "{" << mat.m[0] << ", " << mat.m[1] << ", " << mat.m[2] << ", " << mat.m[3] << "}";
				return os;
			}

			T m[4];

		};

		template<typename T>
		void set(T* arr, T* values);
	}
}
