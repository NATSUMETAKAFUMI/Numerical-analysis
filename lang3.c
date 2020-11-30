#include<stdio.h>

int main() {

	FILE *fp1, *fp2;
	int c, alpha, count, table[728] = {};
	int num = 0;

	if ((fp1 = fopen("infile.txt","r")) == NULL) { //読み込み用オープン
		fprintf(fp1,"infile.txtは見つかりませんでした\n");
	}
	
	if ((fp2 = fopen("outalpha.txt","w")) == NULL) { //書き込み用オープン
                fprintf(fp2,"outfile.txtは見つかりませんでした\n");
	}

	alpha = fgetc(fp1);

	while((c = fgetc(fp1)) != EOF) { //ファイルの中身がEOFになるまで続ける

	if ((c == ' ') || (c == '\n')) {  //spaceの場合２７番目の要素を＋１
 		c = 26;
		num = c + alpha;
		table[num]++;
	} else if (c >= 97 && c <= 122) {
		c = c - 97;
		num = c + alpha;
		table[num]++;
		alpha = c * 26;
	}

	alpha = c * 27;

	}

	for (count = 0; count < 728; count++) {
		if((count >= 702) && (count <= 728)) {
			fprintf(fp2, "%d : _'%c'\n", table[count], count - 605);
	} else if ((count % 27) == 26) {
		fprintf(fp2, "%d : '%c_'\n", table[count], count / 27 + 97);
	} else {
		fprintf(fp2, "%d : '%c%c'\n", table[count], count / 27 + 97, count % 27 + 97);
		}
	}	 
	
	fclose(fp1); //読み込み用クローズ
	fclose(fp2); //書き込み用クローズ

	printf("outalpha.txtに出力しました\n");
	return 0;
}
