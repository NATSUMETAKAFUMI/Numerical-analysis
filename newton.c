#include <stdio.h>
#include <math.h>

double f( double x ) { //f(x)の定義

	return ( 3 * x * x + 2 * x - 5 );
}
　
double df( double x ) { //f'(x)の定義

	return ( 6 * x + 2 );
}

int main(void) {

	int n = 0; //関数定義
	int nmax;
	double x, delta;
	double eps;

	printf ("初期値xを入力してください\n");
	scanf ("%lf", &x);
	printf ("小さい数epsを入力してください\n");
	scanf ("%lf", &eps);
	printf ("最大繰り返し回数nmaxを入力してください\n");
	scanf ("%d", &nmax);
	
	do {
		delta = -f(x) / df(x);
		x = x + delta
		n++;
		printf ("誤差 = %f x = %f\n", delta, x); //誤差と計算結果の表示
	}
	while ( fabs(delta) > eps && n <= nmax );
	if ( n == nmax)	{
		printf ( "解が見つからない\n"); //n=nmaxのとき解が見つからない
	} else {
		printf ( " x = %fで収束\n" , x);　//n=nmaxでないとき収束
	}
	
	return 0;

}

