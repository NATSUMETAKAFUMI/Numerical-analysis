#include<stdio.h>
#include<math.h>

int main(void) {

	double y, y0, y1, dx, x, x0, deltax;

	y0 = 0.0;
	x0 = 0.0;
	dx = 1.0;
	deltax = 1.0;

	for (int i = 1; i <= 10; i++) {
		x = i * dx;
		y1 = (y0 + dx * x * x0) - deltax;

	y = x * x;

	printf("x = %.4f : y0 = %.4f :  y = %.4f\n", x, y + y0, y);

	y0 = y1;

	}
}
