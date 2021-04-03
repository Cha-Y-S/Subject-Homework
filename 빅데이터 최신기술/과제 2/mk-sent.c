// Generate EUC-KR sentences by combining words in dic[].
#include <stdio.h>
#include <string.h>

char *dic1[3][20] = {
{ "나는", "너는", "노는", "나눈", "내는", "누는", "누난", "난은", "넌은", "눈은", "논은", NULL },
{ "밥을", "법을", "바블", "밤을", "범을", "밥은", "법은", "밥울", "법운", "밥운", NULL },
{ "좋아했다", "조하했다", "조아햇다", "좋아햇따", "조아햇따", "조하해따", "조하햇다", "즣아했다", "졸아했다", "졸아햇다", NULL }
};

char *dic2[4][20] = {
{ "사진을", "서진을", "소진을", "사전을", "사진울", "사딘을" },
{ "찍으러", "찍으로", "찍으라", "찍우러", "짝으로", "짝으러" },
{ "공원에", "공원애", "공언에", "공운에", "공뭔에", "곰원에" },
{ "갔다", "갔따", "갓따", "갓다", "겄다", "것따", "깄다", "샀다", "닸다" }
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
