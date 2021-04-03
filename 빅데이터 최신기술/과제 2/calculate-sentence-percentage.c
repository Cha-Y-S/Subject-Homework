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

int bigramCnt[94][94][94][94];
int cntBlank[94][94];
int cntBlankStart[94][94];

char *dic1[3][20] = {
{ "나는", "너는", "노는", "나눈", "내는", "누는", "누난", "난은", "넌은", "눈은", "논은", NULL },
{ "밥을", "법을", "바블", "밤을", "범을", "밥은", "법은", "밥울", "법운", "밥운", NULL },
{ "좋아했다", "조하했다", "조아햇다", "좋아햇따", "조아햇따", "조하해따", "조하햇다", "즣아했다", "졸아했다", "졸아햇다", NULL }
};

char *dic2[4][20] = {
{ "사진을", "서진을", "소진을", "사전을", "사진울", "사딘을" },
{ "찍으러", "찍으로", "찍으라", "찍우러", "짝으로", "짝으러" },
{ "공원에", "공원애", "공언에", "공운에", "공뭔에", "곰원에" },
{ "갔다", "갔따", "갓따", "갓다", "겄다", "것따", "샀다", "닸다" }
};

long countFreqBigram(char *fname);
double calSentencePer(char *input);
double calBlankStartPer(int i1, int i2);
double calBlankPer(int i1, int i2);
double calBigramPer(int i1, int i2, int j1, int j2);
char *get_sent_dic1();
char *get_sent_dic2();

int main(int argc, char *argv[]) {
	int n;
	char input[BUFSIZ];

	if (argc < 2) { puts("$> a.exe corpus.txt"); return 0;}
	
	printf("\n========== Counting Bigram's Frequency is proceeding ==========\n");
	n = countFreqBigram(argv[1]);
	printf("========== Counting Bigram's Frequency is complete ==========\n\n");

	printf("===== Homework 2-1 =====\n\n");
	while(1){
		// printf("Enter a sentence for calculating percentage to make sentence\n");
		printf(">> ");
		gets(input);
		if(strcmp(input, "q") == 0){
			break;
		}
		strcat(input, "$");
		double per = calSentencePer(input);
		printf("Sentence Percentage: %e\n\n", per);
	}

	printf("===== Homework 2-2 =====\n");

	double maxPer = 0;
	double per;
	char *sentence;
	char maxSentence[BUFSIZ];
	
	// printf("where1\n");
	while((sentence=get_sent_dic1()) != NULL) {
		// printf("%s \t", sentence);
		// printf("where1-1\n");
		strcat(sentence, "$");
		// printf("where1-2\n");
		per = calSentencePer(sentence);
		// printf("%e\n",per);
		// printf("where1-3\n");
		if(per > maxPer){
			strcpy(maxSentence, sentence);
			maxPer = per;
			printf("\n%s\t%e\n", sentence, per);
		}
	}
	// printf("where2");
	printf("\n----- 2-1 Highest Percentage Sentence -----\n");
	printf("\n>> %s,\t%e\n\n", maxSentence, maxPer);

	maxPer = 0;
	maxSentence[0] = '\0';

	// printf("where3");
	while((sentence=get_sent_dic2()) != NULL) {
		// printf("%s \t", sentence);
		// printf("where1-1\n");
		strcat(sentence, "$");
		// printf("where1-2\n");
		per = calSentencePer(sentence);
		// printf("%e\n",per);
		if(per > maxPer){
			strcpy(maxSentence, sentence);
			maxPer = per;
			printf("%s\t%e\n", sentence, per);
		}
	}
	// printf("where4");
	printf("\n----- 2-2 Highest Percentage Sentence -----\n");
	printf("\n>> %s,\t%e\n", maxSentence, maxPer);

	return 0;
}

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

double calSentencePer(char *input){
	// printf("%s", input);
	int i = 0;
	int i1, i2, j1, j2;
	double result = 1;

	while(input[i+2] != '$'){
		// printf("percentage: %e\n", result);
		// printf("%c%c\n", input[i],input[i+1]);
		if((input[i] & 0x80) == 0){
			if(input[i] == ' '){
				i1 = (input[i+1] & 0x00FF) - 0x00A1;
				i2 = (input[i+2] & 0x00FF) - 0x00A1;
				result *= calBlankStartPer(i1, i2);
				i++;
			}
		} else if((input[i+2] & 0x80) == 0){
			if(input[i+2] == ' '){
				i1 = (input[i+0] & 0x00FF) - 0x00A1;
				i2 = (input[i+1] & 0x00FF) - 0x00A1;
				result *= calBlankPer(i1, i2);
				i += 2;
			}
		} else {
			i1 = (input[i+0] & 0x00FF) - 0x00A1;
			i2 = (input[i+1] & 0x00FF) - 0x00A1;
			j1 = (input[i+2] & 0x00FF) - 0x00A1;
			j2 = (input[i+3] & 0x00FF) - 0x00A1;
			result *= calBigramPer(i1, i2, j1, j2);
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
	// printf("%e\n", (double)cntBlankStart[i1][i2] / total);
	return (double)cntBlankStart[i1][i2] / total;
}

double calBlankPer(int i1, int i2){
	int total = 0;
	for(int i = 15; i < 40; i++){
		for(int j = 0; j < 94; j++){
			total += cntBlank[i][j];
		}
	}
	// printf("%e\n", (double)cntBlank[i1][i2] / total);
	return (double)cntBlank[i1][i2] / total;
}

double calBigramPer(int i1, int i2, int j1, int j2){
	int total = 0;
	for(int i = 15; i < 40; i++){
		for(int j = 0; j < 94; j++){
			total += bigramCnt[i1][i2][i][j];
		}
	}
	// printf("%e\n", (double)bigramCnt[i1][i2][j1][j2] / total);
	return (double)bigramCnt[i1][i2][j1][j2] / total;
}

long countFreqBigram(char *fname) {
	int i, len;
	int i1, i2, j1, j2;
	char line[BUFSIZ];
	long n = 0;
	FILE *fp;

	fp = fopen(fname, "r");
	// printf("Where 1\n");
	while (!feof(fp)) {
		fgets(line, BUFSIZ - 1, fp);
		len = strlen(line) - 1;

		// printf("%s\n", line);

		for (i=0; len-i > 3; ) {
			if ((line[i+0] & 0x80) == 0) {
				if (line[i+0] == ' '){
					if((line[i+1] & 0x80) == 0) {
						// printf("Except: %c %c\n", line[i+0], line[i+1]);
						i += 2;
						continue;
					}
					// printf("Where 3\n");
					// printf("3: %c %c%c\n", line[i+0], line[i+1], line[i+2]);
					i1 = (line[i+1] & 0x00FF) - 0x00A1;
					i2 = (line[i+2] & 0x00FF) - 0x00A1;
					cntBlankStart[i1][i2]++;	// blank + '?쓬?젅'
				}
				i++;
				continue;	// ASCII char
			} else if ((line[i+2] & 0x80) == 0) {
				if (line[i+2] == ' '){
					// printf("4: %c%c %c\n", line[i+0], line[i+1], line[i+2]);
					// printf("Where 4\n");
					i1 = (line[i+0] & 0x00FF) - 0x00A1;
					i2 = (line[i+1] & 0x00FF) - 0x00A1;	
					cntBlank[i1][i2]++;	// '?쓬?젅' + blank
				}
				i += 2;
				continue;	// ASCII char
			} else {
				// printf("Where 5\n");
				// printf("5: %c%c %c%c\n", line[i+0], line[i+1], line[i+2], line[i+3]);


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
	// printf("Where 2\n");
	fclose(fp);
	return n;
}