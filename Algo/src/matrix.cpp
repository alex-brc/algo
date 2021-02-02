#include "matrix.h"
#include "bigint.h"

namespace math
{
	namespace matrix
	{
		template<typename T>
		Matrix2<T>::Matrix2(T t)
		{
			T values [4] = { t, t, t, t };
			set<T>(this->m, values);
		}
		template<typename T>
		Matrix2<T>::Matrix2(T a, T b, T c, T d)
		{
			T values [4] = { a, b, c, d };
			set<T>(this->m, values);
		}
		template<typename T>
		Matrix2<T> Matrix2<T>::operator+(const Matrix2<T>& operand)
		{
			return Matrix2<T>(
				this->m[0] + operand.m[0],
				this->m[1] + operand.m[1],
				this->m[2] + operand.m[2],
				this->m[3] + operand.m[3]
				);
		}
		template<typename T>
		Matrix2<T> Matrix2<T>::operator+=(const Matrix2<T>& operand)
		{
			this->m[0] = this->m[0] + operand.m[0];
			this->m[1] = this->m[1] + operand.m[1];
			this->m[2] = this->m[2] + operand.m[2];
			this->m[3] = this->m[3] + operand.m[3];
			return (*this);
		}
		template<typename T>
		Matrix2<T> Matrix2<T>::operator*(const Matrix2<T>& operand)
		{
			return Matrix2<T>(T());
		}
		template<typename T>
		Matrix2<T> Matrix2<T>::operator*=(const Matrix2<T>& operand)
		{
			return Matrix2<T>(T());
		}

		template class Matrix2<int>;
		template class Matrix2<BigInt>;

		template<typename T>
		void set(T arr[], T values[]) {
			arr[0] = values[0];
			arr[1] = values[1];
			arr[2] = values[2];
			arr[3] = values[3];
		}
	}
}