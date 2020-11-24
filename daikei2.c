#include<stdio.h>

double get_y1 (double x1)
{
	        return (1 / x1);
}

double get_y2 (double x2)
{
	        return (1 / x2);
}

int main(void) {

	 double x1, x2;
	 double y1, y2;
	 double n, fx, dfx, sumy;

	 printf("f(x) = 1 / x  [1,2]を台形法で計算します\n");
	 printf("積分区間をn等分します\n");
	 printf("nの値を入力してください\n");
	 scanf("%lf",&n);

	 fx = 1 / n; //各変数の初期値の設定
	 x1 = 1;
	 x2 = 1 + fx;
	 sumy = 0;

	 while(1) {
		 y1 = get_y1(x1);
		 y2 = get_y2(x2);
		
		 sumy = sumy + y1 + y2; //yの合計の計算

		 if (x2 >= 2) {
			 break;
		 }

		 x1 = x1 * fx;
		 x2 = x2 * fx;

		 }

	 dfx = fx * sumy / 2; //解の計算

	 printf("deltax = %f\n", fx);
	 printf("解 = %lf\n", dfx);

	 return 0;
}

