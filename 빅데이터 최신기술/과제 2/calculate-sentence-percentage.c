/*
 * 텍스트 파일에서 "character ngram" 추출 프로그램
 *	C> a.exe -n < input.txt > output.txt
 *		(n = 1, 2, 3, 4, ...)
 *	<참고> 공백문자는 '_'로 대치, 첫끝 문자 추가(SS='^', SE='$')
 *	<주의> 한글 텍스트는 "KS 완성형"이어야 함!
 * 국민대학교 소프트웨어학부 강승식 (nlpkang@gmail.com)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int setBlank2Underbar(char *p, int n);

int main(int argc, char *argv[]) {
    char *p, line[BUFSIZ];
    int n, ngram = 2;
    
    line[0] = '^';
    while (fgets(line+1, BUFSIZ-2, stdin)) {
        n = strlen(line);
        n = setBlank2Underbar(line, n);

        put_ngram(line, ngram);
    }
}

int setBlank2Underbar(char *p, int n){
    int i;

	for (i=0; i < n; i++) {
		if (p[i] == 0) return i;
		if (p[i] == '\r' || p[i] == '\n' || p[i] =='.') {
			p[i++] = '$'; p[i++] = '\0';	// 끝문자 '$' 추가
			return i+1;
		}

		if ((p[i] & 0x80) == 0) {
			if (p[i] == ' ' || p[i] == '\t')	// 공백문자, 탭문자
				p[i] = '_';
		} else if (p[i+1] == 0) return i;
		else i++;
	}
	return i+1;
}