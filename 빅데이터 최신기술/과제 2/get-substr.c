/*
 * 텍스트 파일에서 "substring" 또는 어절을 포함하는 문장들만 출력
 *	C> a.exe "substring" input.txt
 *	<주의> 한글 텍스트는 "KS 완성형"이어야 할까요?
 * 국민대학교 소프트웨어학부 강승식 (nlpkang@gmail.com)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX	8192

char* del_SS_SE_spaces(unsigned char line[])
{
	int i, len;
	
	len = strlen(line);
	// 문장 끝 space 문자 제거
	while (len > 1 && (line[len-1] & 0x80)==0 &&
		(line[len-1] == '\n' || line[len-1] == '\r' ||
		line[len-1] == ' ' || line[len-1] == '\t')) {
		line[--len] = '\0';
	}

	for (i=0; i < len; i++) {
		if ((line[i] & 0x80) == 0) {
			if (line[i] == '\n' || line[i] == '\r' ||
				line[i] == ' ' || line[i] == '\t')
				;
			else break;
		} else {	// DBCS 문자
			if (line[i] == 0xA1 && line[i+1] == 0xA1)
				i++;	// DBCS 공백문자
			else break;
		}
	}
	return line+i;
}
			
int main(int argc, char *argv[]) {
	unsigned char line[MAX], *p, *str, *q;
	int len, sentlen, n=0;
	int i=0, flag_word = 0;	// word(어절 탐색)
	FILE *fp;

	if (argc < 3) {
		printf("C> a.exe [-w] \"substring\" corpus.txt\n");
		return 0;
	}

	if (argc == 4) { i = 1; flag_word = 1; }
	str = argv[i+1]; len = strlen(str);
	fp = fopen(argv[i+2], "rb");	// "rb"와 "r" 구분해야...
	if (fp == NULL) { printf("File not found -- <%s>\n", argv[i+2]); return -1; }

	while (fgets(line, MAX-1, fp)) {
		p = del_SS_SE_spaces(line);
		if (*p == 0) continue;

		len = strlen(str);
		if ((q=strstr(p, str)) == NULL) continue;

		if (flag_word == 0) {	// 모든 substring 출력
			printf("[%d] <%s>\n", ++n, p);
			continue;
		}

/*
		if ((q-p) == 0)	// 첫 단어
			printf("[%d] <%s>\n", ++n, p);

		if (*(q+len) == '\0')	// 마지막 단어
			printf("[%d] <%s>\n", ++n, p);

		if ((q-p) > 0 && *(q-1) == ' ')	// 공백문자+단어
			printf("[%d] <%s>\n", ++n, p);

		if (*(q+len) == ' ')	// 단어+공백문자
			printf("[%d] <%s>\n", ++n, p);
*/
/*
		if ((q-p) == 0 || (q-p) > 0 && *(q-1) == ' ')	// 첫 단어 or 공백문자+단어
			printf("[%d] <%s>\n", ++n, p);

		if (*(q+len) == '\0' || *(q+len) == ' ')	// 마지막 단어 or 단어+공백문자
			printf("[%d] <%s>\n", ++n, p);
*/
		if ((q-p) == 0 || (q-p) > 0 && *(q-1) == ' ') {	// 첫 단어 or 공백문자+단어
			if (*(q+len) == '\0' || *(q+len) == ' ')	// 마지막 단어 or 단어+공백문자
				printf("[%d] <%s>\n", ++n, p);
		}
	}
	fprintf(stderr, "-----\nTotal %d lines of <%s> are found!\n", n, str);
	
	fclose(fp);
	return 0;
}
