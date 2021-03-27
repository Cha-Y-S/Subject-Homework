/*
* This program create sentence based on bigram syllable
*   $gcc -o create-sentence-bigram-base create-sentence-bigram-base.c
*   $create-sentence-bigram-base -n corpus.txt
*       Input
*           -n: the number of highest syllable unigram
*           corpus.txt: lines of Korean syllable bigram
*        Char. code
*            KS C 5601-1987 Hangul/Hanja/2byte-symbol
*        Output
*            Created Sentence from based on bigram syllable including blank
*
*   Process
*       1. Choose one random syllable from n syllables with high syllable unigram frequency
*       2. Create next syllable from current syllable
*       3. Repeat process #2 until syllable be created more than 10 and '다' syllable is created
*       4. Return & print created sentence and terminate program
*
* Written by Cha Yoonsung, 20163162, vaite714@gmail.com
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int Cnt[94][94][94][94];	// valid for <A1~FE, A1~FE>
int CntBlank[94][94];	// freq -- syl+blank
int CntBlankStart[94][94];	// freq -- blank+syl

typedef struct _UnigramIndex{
    int i, j;
	int cnt;
} UnigramIndex;

int compare(const void *a, const void *b);
void swap(UnigramIndex *a, UnigramIndex *b);
void changeMinFreq(UnigramIndex *uniArr, int hIndex, int lIndex, int cnt, int arrSize);
void unigramMaxFreq(char *fname, UnigramIndex *uniArr, int arrSize);
void printArr(UnigramIndex *arr, int size);
long freq_count_bigram(char *fname);

int main(int argc, char* argv[]){
    int n, freq;
	int uniHigh, uniLow;
	char sentence[BUFSIZ];
	UnigramIndex *unigram;

    if (argc < 3) { puts("Invalid command"); puts("Command: $create-sentence-bigram-base -n corpus.txt"); return 0; }
    
    freq = atoi(argv[1] + 1);
    if (freq < 3 || freq > 5) { puts("n must be range from 3 to 5"); return 0;}

	unigram = malloc(sizeof(UnigramIndex) * freq);

	printf("===== Extracting highest frequency unigrams is proceeding =====\n");
	unigramMaxFreq(argv[2], unigram, freq);
	printf("===== Extracting highest frequency unigrams is complete =====\n");

	printf("-\tHighest frequency unigrams' list\t-\n");
	printArr(unigram, freq);
	printf("-------------------------------------------------\n");

	srand(time(NULL));
	int random = rand() % freq;
	printf("choose one random unigram from list: %c%c\n\n", uniHigh=unigram[random].i+0xA1, uniLow=unigram[random].j+0xA1);

	// TODO
	// 	2. 선택된 음절 bigram의 빈도 가장 높은거 3개 중 하나 선택
	//	3. 선택된 
	// 

	return 0;
}

long freq_count_bigram(char *fname){
	int i, len;
	int i1, i2, j1, j2;
	char line[BUFSIZ];
	long n=0;
	FILE *fp;

	fp = fopen(fname, "r");

	while (!feof(fp)) {
		fgets(line, BUFSIZ-1, fp);
		len = strlen(line) - 1;

		for (i=0; len-i > 3; ) {
			if ((line[i+0] & 0x80) == 0) {
				if (line[i+0] == ' ') CntBlankStart[i1][i2]++;	// blank + '음절'
				i++;
				continue;	// ASCII char
			} else if ((line[i+2] & 0x80) == 0) {
				if (line[i+2] == ' ') CntBlank[i1][i2]++;	// '음절' + blank
				i += 3;
				continue;	// ASCII char
			} else {
				i1 = (line[i+0] & 0x00FF) - 0x00A1;
				i2 = (line[i+1] & 0x00FF) - 0x00A1;
				j1 = (line[i+2] & 0x00FF) - 0x00A1;
				j2 = (line[i+3] & 0x00FF) - 0x00A1;
				if (i1 < 0 || i2 < 0 || j1 < 0 || j2 < 0) {
					;	// non-KS C 5601 -- cp949 syllables
				} else {
					Cnt[i1][i2][j1][j2]++;
					n++;
				}
				i += 4;
			}
		}
	}
	fclose(fp);
	return n;
}

int compare(const void *a, const void *b){
	UnigramIndex *pa = (UnigramIndex *)a;
	UnigramIndex *pb = (UnigramIndex *)b;

	if(pa->cnt > pb->cnt)
		return 1;
	else if(pa->cnt < pb->cnt)
		return -1;
	else
		return 0;
}

void changeMinFreq(UnigramIndex *uniArr, int hIndex, int lIndex, int cnt, int arrSize){
	UnigramIndex temp;
	temp.i = hIndex;
	temp.j = lIndex;
	temp.cnt = cnt;
	qsort(uniArr, arrSize, sizeof(UnigramIndex), compare);
	uniArr[0] = temp;
	qsort(uniArr, arrSize, sizeof(UnigramIndex), compare);
}

void unigramMaxFreq(char *fname, UnigramIndex *uniArr, int arrSize){
	int i, len;
	int uniCnt[94][94];
	int hIndex, lIndex;
	int minCnt = 0;	// in UnigramIndex Array
	FILE *fp;
	
	fp = fopen(fname, "r");

	while(!feof(fp)) {
		char line[BUFSIZ] = { 0, };
		fgets(line, BUFSIZ-1, fp);
		len = strlen(line);
		for(i=0; len-i > 1;){
			if((line[i] & 0x80) == 0){
				i++;
				continue;	// ASCII char
			} else {
				hIndex = (line[i+0] & 0x00FF) - 0x00A1;
				lIndex = (line[i+1] & 0x00FF) - 0x00A1;
				if( hIndex < 0 || lIndex < 0){
					;
				} else {
					uniCnt[hIndex][lIndex]++;
					// printf("%d: Found unigram %c%c\n", i, hIndex+0xA1,lIndex+0xA1);	
				}
				i += 2;
			}
		}
	}

	for(int i = 0; i < arrSize; i++){
		uniArr[i].i = -1;
		uniArr[i].j = -1;
		uniArr[i].cnt = 0;
	}

	for(hIndex = 15; hIndex < 40; hIndex++){
		for(lIndex = 0; lIndex < 94; lIndex++){
			if(uniCnt[hIndex][lIndex] > minCnt){
				changeMinFreq(uniArr, hIndex, lIndex, uniCnt[hIndex][lIndex], arrSize);
				minCnt = uniArr[0].cnt;
			}
		}
	}
	fclose(fp);
}

void printArr(UnigramIndex *arr, int size){
	for(int i = 0; i < size; i++){
		printf("|\t\t%d: %c%c  freq = %d\t\t|\n",i, arr[size-1-i].i+0xA1, arr[size-1-i].j+0xA1, arr[size-1-i].cnt);
	}
}
