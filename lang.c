#include<stdio.h>
#include<ctype.h>

int main(void) {

	FILE *fp1, *fp2; //ファイル構造体へのポインタを宣言、読み込み用、書き込み用それぞれ宣言する
	int i;

	if((fp1 = fopen("text.txt","r" )) == NULL) { //読み込み用オープン
		fprintf (fp1,"text.txtは見つかりませんでした\n");
	}
	
	if((fp2 = fopen("text2.txt","w" )) == NULL) { //書き込み用オープン
		fprintf(fp2, "text2.txtは見つかりませんでした\n");
	}

	while ((i = fgetc(fp1)) != EOF) { //ファイルの中身がEOFになるまで続ける
		if (isalpha(i)) {
			fputc(i, fp2);
		} else if( i == ' ' ) {
			fputc(i, fp1);
		} else if(i == '\n')  {
			fputc(' ',fp2);
		} else {
			fputc(' ' ,fp2);
		}
	}
			
	fclose(fp1); //読み込み用クローズ
	fclose(fp2); //書き込み用クローズ

	printf("text2.txtに出力しました \n");
	return 0;
}
	
