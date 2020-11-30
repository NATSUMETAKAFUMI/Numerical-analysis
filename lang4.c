#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

	FILE *fp1, *fp2;
	int c, count, randnum;
	int maxnum = 0;

	if ((fp1 = fopen("infile.txt","r")) == NULL) { //読み込み用オープン
		fprintf(fp1,"infile.txtは見つかりませんでした\n");
	}
	
	if ((fp2 = fopen("strgene.txt","w")) == NULL) { //書き込み用オープン
                fprintf(fp2,"outfile.txtは見つかりませんでした\n");
	}

	while((c = fgetc(fp1)) != EOF) { //ファイルの中身がEOFになるまで続ける	
		maxnum++; //テキストファイル全体のカウント
	}

	rewind(fp1); //テキストファイルの位置を先頭に戻す

	char str[maxnum];

	for (count = 0; count < maxnum; count++) {
		fscanf(fp1, "%c", &str[count]); //テキストファイルから１文字ずつ配列に格納
	}

	for(count = 0; count < 100; count++) {
		randnum = rand() % maxnum; //乱数の生成
		fprintf(fp2, "%c", str[randnum]);
	}

	fclose(fp1); //読み込み用クローズ
	fclose(fp2); //書き込み用クローズ

	printf("strgene.txtに出力しました\n");
	return 0;
}

