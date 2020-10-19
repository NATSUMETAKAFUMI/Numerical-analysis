#include <stdio.h>

double get_x1( double x2, double x3) {   //x1の式の関数定義

	return( ( 10.0 - x2 - x3) / 5.0);
}

double get_x2( double x1, double x3) {   //x2の式の関数定義

	return( ( 12.0 - x1 - x3 ) / 4.0);
}

double get_x3( double x1, double x2) {   //x3の式の関数定義
	
	return( (13.0 - 2.0 * x1 - x2) / 3.0);
}

int main() {

	double x1, x2, x3; //変数定義
      double xx1, xx2, xx3;
	double difx1, difx2, difx3;
	int i;

	x1 = x2 = x3 = 1.0;
	xx1 = xx2 = xx3 = 0.0;
	difx1 = difx2 = difx3 = 0.0;

	for (i = 0; i < 20; i++ ) {

 		x1 = get_x1( x2, x3 );
		x2 = get_x2( x1, x3 );
		x3 = get_x3( x1, x2 );

		difx1 = x1 - xx1; //n回目とn-1回目の変数の差をdif変数に入れる
		difx2 = x2 - xx2;
		difx3 = x3 - xx3;

		printf( "[round: %d] x1 = %.10f, x2 = %.10f, x3 = %.10f\n", i + 1, x1, x2, x3 ); //出力結果表示

		if (( difx1 > -0.00001) && ( difx1 < 0.00001) && ( difx2 > -0.00001) && ( difx2 < 0.00001) && ( difx3 > -0.00001) && (difx3 < 0.00001)) {

		printf("収束\n"); //if内の条件を満たしたときに収束と表示する。

		i = 20;

		}
		
	      xx1 = x1;
		xx2 = x2;
		xx3 = x3;
}
	return 0;

}
