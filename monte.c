#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 100000  //試行回数

int main() {
	
	int i;
	int count = 0; 
	double x, y, z, pi;

	srand((unsigned)time(NULL));  //乱数の初期化

	for (i = 0; i < max; i++) {
		x = (double)rand() / RAND_MAX;  //xの乱数
		y = (double)rand() / RAND_MAX;  //yの乱数
		z = x * x + y * y;  //円の方程式
		if (z < 1) 
			count++;
	}

	pi = (double)count / max * 4; //円周率の近似式
	printf("%f\n", pi);  //

	return 0;

}
