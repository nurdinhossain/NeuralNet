#pragma once
#include <vector>
#include <iostream>
using namespace std;

// declaration
template <typename T> class Matrix
{
	int rows;
	int cols;
	vector<T> mat; 
public:
	// constructor and basic setters/getters/prints
	Matrix(int r, int c);
	~Matrix() {}
	T& operator()(int r, int c);
	T operator()(int r, int c) const;
	void print();

	// operator overloads
	Matrix<T> operator+(Matrix<T> const& mat2);
	Matrix<T> operator-(Matrix<T> const& mat2);
};

// implementation
template <typename T> Matrix<T>::Matrix(int r, int c)
{
	rows = r;
	cols = c;

	// init arr with 0s
	for (int i = 0; i < rows * cols; i++)
	{
		mat.push_back(0);
	}
}

template <typename T> T& Matrix<T>::operator()(int r, int c)
{
	return mat[r * cols + c];
}

template <typename T> T Matrix<T>::operator()(int r, int c) const
{
	return mat[r * cols + c];
}

template <typename T> void Matrix<T>::print()
{
	for (int i = 0; i < mat.size(); i++)
	{
		cout << mat[i] << "\t";
		if ((i + 1) % cols == 0) cout << endl;
	}
	cout << endl;
}

template <typename T> Matrix<T> Matrix<T>::operator+(Matrix<T> const& mat2)
{
	Matrix<T> output(rows, cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			output(i, j) = (*this)(i, j) + mat2(i, j);
		}
	}

	return output;
}
