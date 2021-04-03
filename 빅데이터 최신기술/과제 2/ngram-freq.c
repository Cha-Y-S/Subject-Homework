/*
 * Make a syllable trigram header file for trigram.c
 * C> a.exe -minFreq trigram.txt
 *    tigram.txt -- "freq trigram-string" pair in a line
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Freq {
	int freq;
	char *str;
};

struct Freq *DF;
char *MEMpool;	// memory pool for 'str'
long N_data;	// number of data(ngram or word)

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
			printf("freq(%s) = %d\n", DF[i].str, DF[i].freq);
	}
}

// Ngram search -- freq. for 'data[]'
int get_freq(char data[]) {
	int i;

	for (i=0; i < N_data; i++) {
		if (strcmp(data, DF[i].str) == 0) {
			return DF[i].freq;
		}
	}

	return -1;	// 'data[]' is not found in DF[].str
}

// Ngram search -- index of the highest freq. for '(n-1)gram'
//	n -- (n-gram * 2)
int maxfreq_index(char data[], int n) {
	int i, maxfreq=0, maxindex=-1;

	for (i=0; i < N_data; i++) {
		if (DF[i].str[n-2] &&	// Check ngram size error -- ',' and '.' may be dropped!
			strncmp(DF[i].str, data, n-2) == 0) {	// (n-1) syllables are matched
			if (DF[i].freq > maxfreq) {	// higher freq. is found
				maxfreq = DF[i].freq;
				maxindex = i;
				//printf("freq(%s) = %d\n", DF[maxindex].str, DF[maxindex].freq);
			}
		}
	}

	return maxindex;	// index of the highest freq. for 'data'
}

// Load ngram data from freq. text file
int load_ngram_data(char *fname, int minfreq) {
	FILE *fp;
	long filesize;
	int n_max;	// max. number of ngrams
	char line[BUFSIZ], *p;
	char token[BUFSIZ];

	int freq;

	fp = fopen(fname, "r");
	if (!fp) { printf("File not found <%s>.", fname); return -1; }

	fseek(fp, 0, SEEK_END);
	filesize = ftell(fp);;
	n_max = filesize / 15;	// rough number of max. ngrams

	// memory pool for char. string(ngram data)
	NextPtr = MEMpool = (char *) malloc(filesize);
	if (MEMpool == NULL) {
		printf("Memory pool alloc. failed -- %ld bytes\n", filesize);
		return 1;
	}

	// array for <data, freq>
	DF = (struct Freq *) calloc(n_max, sizeof(struct Freq));
	if (DF == NULL) {
		printf("Data freq mem. alloc. failed -- %ld bytes\n",
			sizeof(struct Freq) * n_max);
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

int main(int argc, char *argv[]) {
	char *fname;
	int minfreq=2;
	int i, freq;
	char data[100];

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

	//put_freq(minfreq);	// print data that are loaded

	// data search test
	printf("Input data = "); scanf("%s", data);
	freq = get_freq(data);
	printf("freq(%s) = %d\n", data, freq);

	// max. freq. for (n-1)-gram
	i = maxfreq_index(data, 3*2);	// byte-size = ngram * 2
	if (i >= 0) printf("freq(%s) = %d\n", DF[i].str, DF[i].freq);

	free(DF); free(MEMpool);
	return 0;
}
