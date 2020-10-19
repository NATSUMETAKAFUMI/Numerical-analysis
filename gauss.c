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
	int i, j;

	x1 = x2 = x3 = 1.0;

	for (i = 0; i < 20; i++ ) {

		for (j = 1; j < 20; j++ ) {
 		x1 = get_x1( x2, x3 );
		x2 = get_x2( x1, x3 );
		x3 = get_x3( x1, x2 );
	   	if(i > j) {	
		printf( "[round: %d] x1 = %.10f, x2 = %.10f, x3 = %.10f\n", i + 1, x1, x2, x3 ); //出力結果表示
		} else {
		printf( "収束せず\n", x1, x2, x3 );

		}
		
	}	
}
	return 0;

}
