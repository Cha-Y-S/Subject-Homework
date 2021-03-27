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

typedef struct _UnigramIndex{
    int i, j;
	int cnt;
} UnigramIndex;

int compare(const void *a, const void *b){

}

void swap(UnigramIndex *a, UnigramIndex *b){
	UnigramIndex temp = *a;
	*a = *b;
	*b = temp;
}

void swapIndex(UnigramIndex *uniArr, int hIndex, int lIndex, int cnt){

}

void unigramMaxFreq(char *fname, UnigramIndex *uniArr){
	int i, len;
	char line[BUFSIZ];
	int uniCnt[25][94];
	int hIndex, lIndex;
	int hByte=0xB0-0xA1, lByte=0;
	int minCnt = 0;	// in UnigramIndex Array
	FILE *fp;

	fp = fopen(fname, "r");

	while(!feof(fp)) {
		fgets(line, BUFSIZ-1, fp);
		len = strlen(line);
		for(i=0; len-i > 1;){
			if((line[i] & 0x80 == 0)){
				i++;
				continue;	// ASCII char
			} else {
				hIndex = (line[i+0] & 0x00FF) - 0x00A1;
				lIndex = (line[i+1] & 0x00FF) - 0x00A1;
				if( hIndex < 0 || lIndex < 0){
					;
				} else {
					uniCnt[hIndex][lIndex]++;
				}
				i += 2;
			}
		}
	}

	for(int i = 0; i < _msize(uniArr)/sizeof(int); i++){
		uniArr[i].i = 15;
		uniArr[i].j = i;
		uniArr[i].cnt = uniCnt[15][i];
	}

	for(hIndex = 15; hIndex < 40; hIndex++){
		for(lIndex = 0; lIndex < 94; lIndex++){
			if(uniCnt[hIndex][lIndex] > minCnt){
				swapIndex(uniArr, hIndex, lIndex, uniCnt[hIndex][lIndex]);
				minCnt = uniCnt[hIndex][lIndex];
			}
		}
	}
}

int main(int argc, char* argv[]){
    int n, freq;
	UnigramIndex *unigram;

    if (argc < 3) { puts("Invalid command"); puts("Command: $create-sentence-bigram-base -n corpus.txt"); return 0; }
    
    freq = atoi(argv[1] + 1);
    if (freq < 3 || freq > 5) { puts("n must be range from 3 to 5"); return 0;}

	unigram = malloc(sizeof(int) * freq);

}