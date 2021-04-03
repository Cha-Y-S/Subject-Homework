// Generate EUC-KR sentences by combining words in dic[].
#include <stdio.h>
#include <string.h>

char *dic1[3][20] = {
{ "����", "�ʴ�", "���", "����", "����", "����", "����", "����", "����", "����", "����", NULL },
{ "����", "����", "�ٺ�", "����", "����", "����", "����", "���", "����", "���", NULL },
{ "�����ߴ�", "�����ߴ�", "�����޴�", "�����޵�", "�����޵�", "�����ص�", "�����޴�", "�o���ߴ�", "�����ߴ�", "�����޴�", NULL }
};

char *dic2[4][20] = {
{ "������", "������", "������", "������", "������", "�����" },
{ "������", "������", "������", "��췯", "¦����", "¦����" },
{ "������", "������", "����", "���", "������", "������" },
{ "����", "����", "����", "����", "�δ�", "�͵�", "����", "���", "���" }
};

// Get next sentece for word combinations in dic1[].
char *get_sent_dic1() {
	static int i=0;
	static int j=0;
	static int k=0;
	static char sent[1024];

	if (dic1[2][k] == NULL) { j++; k = 0; }
	if (dic1[1][j] == NULL) { i++; j = k = 0; }
	if (dic1[0][i] == NULL) return NULL;

	//printf("%d %d %d : ", i,j,k);
	strcpy(sent, dic1[0][i]);
	strcat(sent, " ");
	strcat(sent, dic1[1][j]);
	strcat(sent, " ");
	strcat(sent, dic1[2][k++]);

	//puts(sent);
	return sent;
}

// Get next sentece for word combinations in dic2[].
char *get_sent_dic2() {
	static int i=0;
	static int j=0;
	static int k=0;
	static int l=0;
	static char sent[1024];

	if (dic2[3][l] == NULL) { k++; l = 0; }
	if (dic2[2][k] == NULL) { j++; k = 0; }
	if (dic2[1][j] == NULL) { i++; j = k = 0; }
	if (dic2[0][i] == NULL) return NULL;

	strcpy(sent, dic2[0][i]);
	strcat(sent, " ");
	strcat(sent, dic2[1][j]);
	strcat(sent, " ");
	strcat(sent, dic2[2][k]);
	strcat(sent, " ");
	strcat(sent, dic2[3][l++]);

	return sent;
}

int main() {
	char *p;
	int n=0;

	while ((p=get_sent_dic1()) != NULL) {
		puts(p);
		n++;
	}

	fprintf(stderr, "Total %d sentences are generated!\n", n);
	return 0;
}
