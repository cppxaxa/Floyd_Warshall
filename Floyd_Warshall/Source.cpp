#include <iostream>
#include <conio.h>
#include <algorithm>
#include <omp.h>

using namespace std;

int main(){
	unsigned int a[4][4] = {
		{0, 5, INT_MAX, 10},
		{INT_MAX, 0, 3, INT_MAX},
		{INT_MAX, INT_MAX, 0, 1},
		{INT_MAX, INT_MAX, INT_MAX, 0}
	};

	unsigned int b[4][4];

#pragma omp parallel
	{
		for (int k = 0; k < 4; k++){
#pragma omp for
			for (int i = 0; i < 16; i++)
				b[i / 4][i % 4] = min(a[i / 4][i % 4], a[i / 4][k] + a[k][i % 4]);

#pragma omp for
			for (int i = 0; i < 16; i++)
				a[i / 4][i % 4] = b[i / 4][i % 4];
		}
	}

	cout << a[0][3];
	_getch();
	return 0;
}