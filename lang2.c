#include<stdio.h>

int main() {

	FILE *fp1, *fp2;
	int c, num = 0, count;
	int table[27] = {};

	if ((fp1 = fopen("infile.txt","r")) == NULL) { //読み込み用オープン
		fprintf(fp1,"infile.txtは見つかりませんでした\n");
	}
	
	if ((fp2 = fopen("outfile.txt","w")) == NULL) { //書き込み用オープン
                fprintf(fp2,"outfile.txtは見つかりませんでした\n");
	}

	while((c = fgetc(fp1)) != EOF) { //ファイルの中身がEOFになるまで続ける

		if (c == ' ') {
			table[26] = table[26] + 1; //spaceの場合２７番目の要素＋１
	}else if(c >= 97 && c <= 127) {
			table[c - 97] = table[c - 97] + 1;
		}
	num++;
	}

	for(count = 0; count < 27; count++) {
		if(count == 26) { //spaceの時の入力
			fprintf(fp2, "%d : space\n", table[26]);
		} else {
			fprintf(fp2, "%d : %c\n", table[count], count + 97);
		}
	}

	fclose(fp1); //読み込み用クローズ
	fclose(fp2); //書き込み用クローズ

	printf("outfile.txtに出力しました\n");
	return 0;
}
