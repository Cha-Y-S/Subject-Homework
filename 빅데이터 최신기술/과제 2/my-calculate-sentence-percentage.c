/*
* This program calculate percentage to create sentence base on bigram syllable
*	$gcc -o calculate-sentence-percentage calculate-sentence-percentage.c
*	$calculate-sentence-percentage corpus.txt
*		Input
*			corpus.txt: lines of Korean syllable bigram
*		Char. code
*			KS C 5601-1987 Hangul/Hanjs/2byte-symbol
*		Output
*			Percetage of created sentence
*
*	Process
*		1. When counting bigram syllable is done, enter a sentence for calculating percentage
*		2. When input sentence is "q", input process will be done
*		3. Then, program create sentence using dic1, dic2, and calculate it's sentence
*		4. Print highest percentage sentence & percentage and terminate process
*
* Written by Cha Yoonsung, 20163162, vaite714@gmail.com
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>

int bigramCnt[94][94][94][94];
int cntBlank[94][94];
int cntBlankStart[94][94];

typedef struct _PerSentence{
	int i, j, k, l;
	double percentage;
} PerSentence;

char *dic1[3][20] = {
{ "나는", "너는", "노는", "나눈", "내는", "누는", "누난", "난은", "넌은", "눈은", "논은", NULL },
{ "밥을", "법을", "바블", "밤을", "범을", "밥은", "법은", "밥울", "법운", "밥운", NULL },
{ "좋아했다", "조하했다", "조아햇다", "좋아햇따", "조아햇따", "조하해따", "조하햇다", "졸아했다", "졸아햇다", NULL }
};

char *dic2[4][20] = {
{ "사진을", "서진을", "소진을", "사전을", "사진울", "사딘을", NULL },
{ "찍으러", "찍으로", "찍으라", "찍우러", "짝으로", "짝으러", NULL },
{ "공원에", "공원애", "공언에", "공운에", "공뭔에", "곰원에", NULL },
{ "갔다", "갔따", "갓따", "갓다", "겄다", "것따", "샀다", "닸다", NULL }
};

int compare(const void *a, const void *b);
void printArrDic1(PerSentence *arr, int size);
void printArrDic2(PerSentence *arr, int size);
void countFreqBigram(char *fname);
double calSentencePer(char *input);
double calBlankStartPer(int i1, int i2);
double calBlankPer(int i1, int i2);
double calBigramPer(int i1, int i2, int j1, int j2);
char *get_sent_dic1(int *i1, int *i2, int *i3);
char *get_sent_dic2(int *i1, int *i2, int *i3, int *i4);

int main(int argc, char *argv[]) {
	int n;
	char input[BUFSIZ];

	if (argc < 2) { puts("$> a.exe corpus.txt"); return 0;}
	
	printf("\n========== Counting Bigram's Frequency is proceeding ==========\n");
	countFreqBigram(argv[1]);
	printf("========== Counting Bigram's Frequency is complete ==========\n\n");

	printf("===== Homework 2-1 =====\n\n");
	while(1){
		printf(">> ");
		gets(input);
		if(strcmp(input, "q") == 0){
			break;
		}
		strcat(input, "$");
		double per = calSentencePer(input);
		per = per ? per : DBL_MIN;
		printf("Sentence Percentage: %e\n\n", per);
	}

	printf("===== Homework 2-2 =====\n");

	double per;
	char *sentence;
	PerSentence dic1Sen[2000];
	PerSentence dic2Sen[2000];
	int i1, i2, i3, i4;

	long index = 0;

	while((sentence=get_sent_dic1(&i1, &i2, &i3)) != NULL) {
		
		PerSentence temp;
		strcat(sentence, "$");
		// printf("%s\n", sentence);
		per = calSentencePer(sentence);
		temp.i = i1;
		temp.j = i2;
		temp.k = i3;
		temp.percentage = per ? per : DBL_MIN;
		dic1Sen[index] = temp;
		// printf("%ld\n", i);
		index++;
	}
	
	qsort(dic1Sen, index, sizeof(PerSentence), compare);
	printf("\n----- 2-1 Highest Percentage Sentence -----\n");
	printArrDic1(dic1Sen, index);

	index = 0;
	
	while((sentence=get_sent_dic2(&i1, &i2, &i3, &i4)) != NULL) {
		PerSentence temp;
		strcat(sentence, "$");
		// printf("%s\n", sentence);
		per = calSentencePer(sentence);
		temp.i = i1;
		temp.j = i2;
		temp.k = i3;
		temp.l = i4;
		temp.percentage = per ? per : DBL_MIN;
		dic2Sen[index] = temp;
		// printf("%ld\n", index);
		index++;
	}
	printf("\n----- 2-2 Highest Percentage Sentence -----\n");
	qsort(dic2Sen, index, sizeof(PerSentence), compare);
	printArrDic2(dic2Sen, index);

	return 0;
}

int compare(const void *a, const void *b){
	PerSentence *pa = (PerSentence *)a;
	PerSentence *pb = (PerSentence *)b;

	if(pa->percentage < pb->percentage)
		return 1;
	else if(pa->percentage > pb->percentage)
		return -1;
	else
		return 0;
}

void printArrDic1(PerSentence *arr, int size){
	for(int a = 0; a < size; a++){
		char sentence[1024] = {0, };
		if(arr[a].percentage > DBL_MIN){
			strcpy(sentence, dic1[0][arr[a].i]);
			strcat(sentence, " ");
			strcat(sentence, dic1[1][arr[a].j]);
			strcat(sentence, " ");
			strcat(sentence, dic1[2][arr[a].k]);
			printf("%s\t%e\n", sentence, arr[a].percentage);
		}
		

	}
	printf("\n");
}

void printArrDic2(PerSentence *arr, int size){
	char sentence[1024];
	for(int a = 0; a < size; a++){
		if(arr[a].percentage > DBL_MIN){
			strcpy(sentence, dic2[0][arr[a].i]);
			strcat(sentence, " ");
			strcat(sentence, dic2[1][arr[a].j]);
			strcat(sentence, " ");
			strcat(sentence, dic2[2][arr[a].k]);
			strcat(sentence, " ");
			strcat(sentence, dic2[3][arr[a].l]);
			printf("%s\t%e\n", sentence, arr[a].percentage);
		}
	}
	printf("\n");
}

char *get_sent_dic1(int *i1, int *i2, int *i3) {
	static int i=0;
	static int j=0;
	static int k=0;
	static char sent[1024];

	if (dic1[2][k] == NULL) { j++; k = 0; }
	if (dic1[1][j] == NULL) { i++; j = k = 0; }
	if (dic1[0][i] == NULL) return NULL;

	*i1 = i;
	*i2 = j;
	*i3 = k;

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
char *get_sent_dic2(int *i1, int *i2, int *i3, int *i4) {
	static int i=0;
	static int j=0;
	static int k=0;
	static int l=0;
	static char sent[1024];

	if (dic2[3][l] == NULL) { k++; l = 0; }
	if (dic2[2][k] == NULL) { j++; k = 0; }
	if (dic2[1][j] == NULL) { i++; j = k = 0; }
	if (dic2[0][i] == NULL) return NULL;

	*i1 = i;
	*i2 = j;
	*i3 = k;
	*i4 = l;

	strcpy(sent, dic2[0][i]);
	strcat(sent, " ");
	strcat(sent, dic2[1][j]);
	strcat(sent, " ");
	strcat(sent, dic2[2][k]);
	strcat(sent, " ");
	strcat(sent, dic2[3][l++]);


	return sent;
}

double calSentencePer(char *input){
	int i = 0;
	int i1, i2, j1, j2;
	double result = 1;

	while(input[i+2] != '$'){
		if((input[i] & 0x80) == 0){
			if(input[i] == ' '){
				i1 = (input[i+1] & 0x00FF) - 0x00A1;
				i2 = (input[i+2] & 0x00FF) - 0x00A1;
				double temp = calBlankStartPer(i1, i2);
				temp = temp ? temp : DBL_MIN;
				result *= temp;
				i++;
			}
		} else if((input[i+2] & 0x80) == 0){
			if(input[i+2] == ' '){
				i1 = (input[i+0] & 0x00FF) - 0x00A1;
				i2 = (input[i+1] & 0x00FF) - 0x00A1;
				double temp = calBlankPer(i1, i2);
				temp = temp ? temp : DBL_MIN;
				result *= temp;
				i += 2;
			}
		} else {
			i1 = (input[i+0] & 0x00FF) - 0x00A1;
			i2 = (input[i+1] & 0x00FF) - 0x00A1;
			j1 = (input[i+2] & 0x00FF) - 0x00A1;
			j2 = (input[i+3] & 0x00FF) - 0x00A1;
			double temp = calBigramPer(i1, i2, j1, j2);
			temp = temp ? temp : DBL_MIN;
			result *= temp;
			i += 2;
		}
	}

	return result;
}

double calBlankStartPer(int i1, int i2){ 
	int total = 0;
	for(int i = 15; i < 40; i++){
		for(int j = 0; j < 94; j++){
			total += cntBlankStart[i][j];
		}
	}
	return (double)cntBlankStart[i1][i2] / total;
}

double calBlankPer(int i1, int i2){
	int total = 0;
	for(int i = 15; i < 40; i++){
		for(int j = 0; j < 94; j++){
			total += cntBlank[i][j];
		}
	}
	return (double)cntBlank[i1][i2] / total;
}

double calBigramPer(int i1, int i2, int j1, int j2){
	int total = 0;
	for(int i = 15; i < 40; i++){
		for(int j = 0; j < 94; j++){
			total += bigramCnt[i1][i2][i][j];
		}
	}
	return (double)bigramCnt[i1][i2][j1][j2] / total;
}

void countFreqBigram(char *fname) {
	int i, len;
	int i1, i2, j1, j2;
	char line[BUFSIZ];
	long n = 0;
	FILE *fp;

	fp = fopen(fname, "r");
	while (!feof(fp)) {
		fgets(line, BUFSIZ - 1, fp);
		len = strlen(line) - 1;

		for (i=0; len-i > 3; ) {
			if ((line[i+0] & 0x80) == 0) {
				if (line[i+0] == ' '){
					if((line[i+1] & 0x80) == 0) {
						i += 2;
						continue;
					}
					i1 = (line[i+1] & 0x00FF) - 0x00A1;
					i2 = (line[i+2] & 0x00FF) - 0x00A1;
					if(i1 < 0 || i2 < 0){
						;
					} else {
						cntBlankStart[i1][i2]++;	// blank + syllable
					}
					
				}
				i++;
				continue;	// ASCII char
			} else if ((line[i+2] & 0x80) == 0) {
				if (line[i+2] == ' '){
					i1 = (line[i+0] & 0x00FF) - 0x00A1;
					i2 = (line[i+1] & 0x00FF) - 0x00A1;
					if(i1 < 0 || i2 < 0){
						;
					} else {
						cntBlank[i1][i2]++;	// syllable + blank
					}
					
				}
				i += 2;
				continue;	// ASCII char
			} else {
				i1 = (line[i+0] & 0x00FF) - 0x00A1;
				i2 = (line[i+1] & 0x00FF) - 0x00A1;
				j1 = (line[i+2] & 0x00FF) - 0x00A1;
				j2 = (line[i+3] & 0x00FF) - 0x00A1;
				if (i1 < 0 || i2 < 0 || j1 < 0 || j2 < 0) {
					;	// non-KS C 5601 -- cp949 syllables
				} else {
					bigramCnt[i1][i2][j1][j2]++;
					n++;
				}
				i += 2;
			}
		}
	}
	fclose(fp);
	return;
}