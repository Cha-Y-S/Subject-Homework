/*
 * Make a syllable trigram header file for trigram.c
 * C> a.exe -minFreq trigram.txt
 *    tigram.txt -- "freq trigram-string" pair in a line
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

struct Freq {
	char *str;
	int freq;
	double prob;
};

typedef struct _PerSentence{
	char str[100];
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

struct Freq *DF;
char *MEMpool;	// memory pool for 'str'
long N_data;	// number of data(ngram or word)

int set_blank2underbar(char *p, int n) {
	int i;

	for (i=0; i < n; i++) {
		if (p[i] == 0) return i;
		if (p[i] == '\r' || p[i] == '\n') {
			p[i++] = '$'; p[i++] = '\0';	// ?????? '$' ???
			return i+1;
		}

		if ((p[i] & 0x80) == 0) {
			if (p[i] == ' ' || p[i] == '\t')	// ??????, ?????
				p[i] = '_';
		} else if (p[i+1] == 0) return i;
		else i++;
	}
	return i+1;
}

// ASCII char. --> 2 byte by adding '_' as a second byte
void normalize(char *p) {
	char temp[BUFSIZ], *q=temp;

	strcpy(temp, p);
	while (*q) {
		if ((*q & 0x80) == 0) {	// ASCII code
			if (*q == '\\' || *q == '\"' || *q == '\'')
				*p++ = '\\';	// escape char is needed
			*p++ = *q++;
			*p++ = '_';
		} else {
			*p++ = *q++;
			*p++ = *q++;
		}
	}
	*p = '\0';
}

char *NextPtr;
char *mem_pool(char *token) {	// 'token' is saved in MEMpool
	char *p=NextPtr;

	strcpy(p, token);
	NextPtr += strlen(token)+1;
	return p;
}

// print all data and freq. in DF[]
void put_freq(int minfreq) {
	int i;

	for (i=0; i < N_data; i++) {
		if (DF[i].freq >= minfreq)
			printf("freq(%s) = %d (%.2f)\n", DF[i].str, DF[i].freq, DF[i].prob);
	}
}

// Ngram search -- freq. for 'data[]'
int get_freq(char data[]) {
	int i;

	for (i=0; i < N_data; i++) {
		if (strcmp(data, DF[i].str) == 0) {
			return i;
		}
	}

	return -1;	// 'data[]' is not found in DF[].str
}

// Ngram search -- index of the highest freq. for '(n-1)gram'
//	n -- (n-gram * 2)
int get_freq_min(char data[], int n) {
	int i, minfreq=INT_MAX, minindex=-1;

	for (i=0; i < N_data; i++) {
		if (DF[i].str[n-2] &&	// Check ngram size error -- ',' and '.' may be dropped!
			strncmp(DF[i].str, data, n-2) == 0) {	// (n-1) syllables are matched
			if (DF[i].freq < minfreq) {	// higher freq. is found
				minfreq = DF[i].freq;
				minindex = i;
			}
		}
	}

	return minindex;	// index of the highest freq. for 'data'
}

// Load ngram data from freq. text file
int load_ngram_data(char *fname, int minfreq) {
	FILE *fp;
	long filesize;
	int n_data;	// max. number of ngrams
	char line[BUFSIZ], *p;
	char token[BUFSIZ];

	int freq;

	fp = fopen(fname, "r");
	if (!fp) { printf("File not found <%s>.", fname); return -1; }

	fseek(fp, 0, SEEK_END);
	filesize = ftell(fp);;
	n_data = filesize / 15;	// rough number of ngrams

	// memory pool for char. string(ngram data)
	NextPtr = MEMpool = (char *) malloc(filesize);
	if (MEMpool == NULL) {
		printf("Memory pool alloc. failed -- %ld bytes\n", filesize);
		return 1;
	}

	// array for <data, freq>
	DF = (struct Freq *) calloc(n_data, sizeof(struct Freq));
	if (DF == NULL) {
		printf("Data freq mem. alloc. failed -- %ld bytes\n",
			sizeof(struct Freq) * n_data);
		return 2;
	}

	fseek(fp, 0, SEEK_SET);
	N_data = 0;
	while ( (p=fgets(line, BUFSIZ-1, fp)) != NULL ) {
		sscanf(line, "%d%s", &freq, token);
		normalize(token);
		if (freq >= minfreq) {
			//printf("%6d,\t\"%s\",\n", freq, token);
			DF[N_data].freq = freq;
			p = mem_pool(token);	// 'token' is saved in MEMpool
			DF[N_data].str = p;
			N_data++;
		}
	}

	fclose(fp);
	return 0;
}

int index_ending_ngram(int start, char data[], int n)
{
	int i;

	for (i=start; i < N_data; i++) {
		if (DF[i].str[n-2] == 0) continue;	// Check ngram size error -- ',' and '.' may be dropped!
		//printf("index ending -- %s : %s\n", data, DF[i].str);
		if (strncmp(DF[i].str, data, n-2) == 0)	// (n-1) ngram is matched
			continue;
		else return i;	// index of the next (n-1) gram
	}

	return i;
}

// freq. summation for (n-1)grams
int set_prob_n1gram(int start, int end)
{
	int i;
	double sum=0.0;

	for (i=start; i < end; i++)
		sum += DF[i].freq;
	// printf("Sum(%d~%d) = %.2f\n", start, end, sum);

	for (i=start; i < end; i++)
		DF[i].prob = DF[i].freq / sum;

	return sum;
}

void set_prob_ngram() {
	int i, maxfreq=0, maxindex=-1;
	int j, n, sum;
	char data[100];

	strcpy(data, DF[0].str);	// 1st data of n-gram
	n = strlen(data);	// length of (n-1) gram
	data[n-2] = '\0';	// (n-1) gram 

	i = 0;
	while (i < N_data) {
		if (DF[i].str[n-2] == 0) i++;	// Check ngram size error -- ',' and '.' may be dropped!
		j = index_ending_ngram(i, data, n);
		//printf("%s: %d~%d\n", data, i, j);
		set_prob_n1gram(i, j);

		i = j;	// index of the next (n-1) gram
		if (i < N_data) strcpy(data, DF[i].str);	// next data of n-gram
	}
	return;
}

double calculatePercentage(char *data){
	int i;
	double percentage = 1.0;
	strcat(data, "\n");
	int index = 0;
	while(data[index] != '\0'){
		char input[5];
		if((data[index] & 0x80) == 0 ){
			int a = index;
			for(int j = 0; j < 3; j++){
				input[j] = data[a++];
			}
			input[3] = '\0';
			index++;
		} else if ((data[index+2] & 0x80) == 0) {
			int a = index;
			for(int j = 0; j < 3; j++){
				input[j] = data[a++];
			}
			input[3]= '\0';
			index += 2;
		} else {
			int a = index;
			for(int j = 0; j < 4; j++){
				input[j] = data[a++];
			}
			input[4] = '\0';
			index += 2;
		}

		set_blank2underbar(input, strlen(input));
		normalize(input);
		if(strcmp(input, "$_") == 0){
			break;
		}
		i = get_freq(input);
		if (i >= 0){
			percentage *= DF[i].prob;

		} else {
			i = get_freq_min(input, strlen(input));
			if(i >= 0){
				percentage *= DF[i].prob;
			} else {
				percentage *= DBL_MIN;
			}
		}
	}
	return percentage;
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

void printArrDic(PerSentence *arr, int size){
	for(int i = 0; i < size; i ++){
		printf("%s\t(%e)\n",arr[i].str, arr[i].percentage);
	}
	printf("\n");
}
	

int main(int argc, char *argv[]) {
	char *fname;
	int minfreq=2;
	int i;

	if (argc < 2) {
		puts("C> a.exe -n trigram-freq.txt (created by wordcount.exe)");
		return 0;
	}

	if (argc == 2) {
		fname = argv[1];
	} else {
		if (argv[1][0] == '-') minfreq = atoi(argv[1]+1);
		else minfreq = atoi(argv[1]);
		if (minfreq < 0) minfreq = 2;	// default
		fname = argv[2];
	}

	if (load_ngram_data(fname, minfreq)) {
		puts("Loading freq. text failed!");
		return -1;
	}
	fprintf(stderr, "Total <%d> data of min. frequency %d.\n", N_data, minfreq);

	set_prob_ngram();
	//put_freq(minfreq);	// print freq. and prob.

	// data search test
	printf("==================== Homework 2-1 ====================\n");
    while(1){
        char data[100];
		char pData[100];
		double per;
        
        printf(">> ");
        gets(data);
        if((strcmp(data, "q") == 0)){
			printf("\n");
            break;
        }
		strcpy(pData,data);
		per = calculatePercentage(data);
		printf("sen: %s\t(%e)\n\n",pData, per);
	}

	PerSentence dic1Sen[2000];
	PerSentence dic2Sen[2000];
	char *sen;
	printf("==================== Homework 2-2-1 ====================\n");
	
	int index = 0;
	while((sen=get_sent_dic1()) != NULL) {
		PerSentence temp;
		char tSen[100];
		strcpy(temp.str, sen);
		temp.percentage = calculatePercentage(sen);
		dic1Sen[index++] = temp;
	}

	qsort(dic1Sen, index-1, sizeof(PerSentence), compare);
	printArrDic(dic1Sen, index-1);

	printf("==================== Homework 2-2-2 ====================\n");
	index = 0;
	while((sen=get_sent_dic2()) != NULL) {
		PerSentence temp;
		char tSen[100];
		strcpy(tSen, sen);
		strcpy(temp.str, tSen);
		temp.percentage = calculatePercentage(sen);
		dic2Sen[index++] = temp;
	}
	qsort(dic2Sen, index-1, sizeof(PerSentence), compare);
	printArrDic(dic2Sen, index-1);

	free(DF); free(MEMpool);
	printf("==================== Calculating Percentage of Creating Sentence is Complete! ====================\n");	
	return 0;
}
