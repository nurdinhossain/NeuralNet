#include "matrix.h"
#include <chrono>

int main()
{
	auto start = chrono::high_resolution_clock::now();
	Matrix<int> m(3, 2);
	m(0, 0) = 1;
	m(0, 1) = 2;
	m(1, 0) = 3;
	m(1, 1) = 4;
	m(2, 0) = 5;
	m(2, 1) = 6;
	for (int i = 0; i < 1000; i++)
	{
		Matrix<int> m2 = m + m;
	}
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cout << "This code took " << duration.count() << " microseconds to run" << endl;

	return 0;
}