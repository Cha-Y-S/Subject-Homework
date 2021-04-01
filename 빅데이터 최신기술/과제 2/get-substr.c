/*
 * �ؽ�Ʈ ���Ͽ��� "substring" �Ǵ� ������ �����ϴ� ����鸸 ���
 *	C> a.exe "substring" input.txt
 *	<����> �ѱ� �ؽ�Ʈ�� "KS �ϼ���"�̾�� �ұ��?
 * ���δ��б� ����Ʈ�����к� ���½� (nlpkang@gmail.com)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX	8192

char* del_SS_SE_spaces(unsigned char line[])
{
	int i, len;
	
	len = strlen(line);
	// ���� �� space ���� ����
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
		} else {	// DBCS ����
			if (line[i] == 0xA1 && line[i+1] == 0xA1)
				i++;	// DBCS ���鹮��
			else break;
		}
	}
	return line+i;
}
			
int main(int argc, char *argv[]) {
	unsigned char line[MAX], *p, *str, *q;
	int len, sentlen, n=0;
	int i=0, flag_word = 0;	// word(���� Ž��)
	FILE *fp;

	if (argc < 3) {
		printf("C> a.exe [-w] \"substring\" corpus.txt\n");
		return 0;
	}

	if (argc == 4) { i = 1; flag_word = 1; }
	str = argv[i+1]; len = strlen(str);
	fp = fopen(argv[i+2], "rb");	// "rb"�� "r" �����ؾ�...
	if (fp == NULL) { printf("File not found -- <%s>\n", argv[i+2]); return -1; }

	while (fgets(line, MAX-1, fp)) {
		p = del_SS_SE_spaces(line);
		if (*p == 0) continue;

		len = strlen(str);
		if ((q=strstr(p, str)) == NULL) continue;

		if (flag_word == 0) {	// ��� substring ���
			printf("[%d] <%s>\n", ++n, p);
			continue;
		}

/*
		if ((q-p) == 0)	// ù �ܾ�
			printf("[%d] <%s>\n", ++n, p);

		if (*(q+len) == '\0')	// ������ �ܾ�
			printf("[%d] <%s>\n", ++n, p);

		if ((q-p) > 0 && *(q-1) == ' ')	// ���鹮��+�ܾ�
			printf("[%d] <%s>\n", ++n, p);

		if (*(q+len) == ' ')	// �ܾ�+���鹮��
			printf("[%d] <%s>\n", ++n, p);
*/
/*
		if ((q-p) == 0 || (q-p) > 0 && *(q-1) == ' ')	// ù �ܾ� or ���鹮��+�ܾ�
			printf("[%d] <%s>\n", ++n, p);

		if (*(q+len) == '\0' || *(q+len) == ' ')	// ������ �ܾ� or �ܾ�+���鹮��
			printf("[%d] <%s>\n", ++n, p);
*/
		if ((q-p) == 0 || (q-p) > 0 && *(q-1) == ' ') {	// ù �ܾ� or ���鹮��+�ܾ�
			if (*(q+len) == '\0' || *(q+len) == ' ')	// ������ �ܾ� or �ܾ�+���鹮��
				printf("[%d] <%s>\n", ++n, p);
		}
	}
	fprintf(stderr, "-----\nTotal %d lines of <%s> are found!\n", n, str);
	
	fclose(fp);
	return 0;
}
