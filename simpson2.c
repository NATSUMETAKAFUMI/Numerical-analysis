#include<stdio.h>

double get_y1 (double x1)
{
        return (1 / x1);
}

double get_y2 (double x2)
{
        return (1 / x2);
}

double get_y3 ((double x3)
{
        return (1 / x3);
}


int main(void) {

        double x1, x2, x3;
        double y1, y2, y3;
        double n, fx, dfx, sumy;

        printf("f(x) = 1 / x [1,2]をシンプソン法で計算します\n");
        printf("積分区間をn等分します\n");
        printf("nの値を入力してください\n");
        scanf("%lf",&n);

	fx = 1 / n; //各変数の初期値の設定
        x1 = 1;
        x3 = 1 + fx;
        x2 = (x1 + x3) / 2;
        sumy = 0;

        while(1) {
                y1 = get_y1(x1);
                y2 = get_y2(x2);
                y3 = get_y3(x3);

                sumy = sumy + y1 +(4 * y2) + y3; //yの合計の計算

                if (x3 >= 2) {
                        break;
                }

                x1 = x1 * fx;
                x3 = x3 * fx;
                x2 = (x1 + x3) / 2;

        }

        dfx = fx * sumy / 6; //解の計算

        printf("deltax = %f\n", fx);
        printf("解 = %lf\n", dfx);

        return 0;
}
