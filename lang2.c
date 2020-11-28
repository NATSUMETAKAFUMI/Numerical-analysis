#include<stdio.h>

int main() {

	FILE *fp1, *fp2;
	int c, num = 0, count;
	int table[27] = {};

	if ((fp1 = fopen("infile.txt","r")) == NULL) {
		fprintf(fp1,"infile.txtは見つかりませんでした\n");
	}
	
	if ((fp2 = fopen("outfile.txt","w")) == NULL) {
                fprintf(fp2,"outfile.txtは見つかりませんでした\n");
	}

	while((c = fgetc(fp1)) != EOF) {

		if (c == ' ') {
			table[26] = table[26] + 1;
	}else if(c >= 97 && c <= 127) {
			table[c - 97] = table[c - 97] + 1;
		}
	num++;
	}

	for(count = 0; count < 27; count++) {
		if(count == 26) {
			fprintf(fp2, "%d : space\n", table[26]);
		} else {
			fprintf(fp2, "%d : %c\n", table[count], count + 97);
		}
	}

	fclose(fp1);
	fclose(fp2);

	printf("outfile.txtに出力しました\n");
	return 0;
}
