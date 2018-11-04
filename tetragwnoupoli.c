#include <stdio.h>
#include <stdlib.h>
#define BSIZE 1<<15


char buffer[BSIZE];
long bpos = 0L, bsize = 0L;

struct spiti{
unsigned long mikos,pou;
unsigned long long sunolo1;};

long readLong() 
{
	long d = 0L, x = 0L;
	char c;

	while (1)  {
		if (bpos >= bsize) {
			bpos = 0;
			if (feof(stdin)) return x;
			bsize = fread(buffer, 1, BSIZE, stdin);
		}
		c = buffer[bpos++];
		if (c >= '0' && c <= '9') { x = x*10 + (c-'0'); d = 1; }
		else if (d == 1) return x;
	}
	return -1;
}

int cmprfunc(const void * a, const void * b) {
	struct spiti *orderA = (struct spiti*)a;
    struct spiti *orderB = (struct spiti*)b;
   return ( orderA->mikos - orderB->mikos ); 
}


int main(int argc, char **argv) {
	int i,plithos;
	unsigned long long int A[500000], min;
	struct spiti X1[500000], X2[500000],Y1[500000],Y2[500000];
	plithos = readLong();
	for(i=0; i<plithos; i++) {
		X1[i].mikos = readLong();
		Y1[i].mikos = readLong();
		X1[i].pou = Y1[i].pou =i;
		}

	qsort(X1, plithos, sizeof(struct spiti), cmprfunc);
	qsort(Y1, plithos, sizeof(struct spiti), cmprfunc);
	
	
	X2[plithos-1].sunolo1 = Y2[plithos-1].sunolo1 = 0;
	for(i=plithos-2; i>=0; i--) {
		X2[i].mikos = X1[i].mikos;
		X2[i].pou = X1[i].pou;
		X2[i].sunolo1 = X2[i+1].sunolo1 + (plithos-1 - i)*(X1[i+1].mikos - X1[i].mikos);
		
		Y2[i].mikos = Y1[i].mikos;
		Y2[i].pou = Y1[i].pou;
		Y2[i].sunolo1 = Y2[i+1].sunolo1 + (plithos-1 - i)*(Y1[i+1].mikos - Y1[i].mikos);
		 
		}
	X1[0].sunolo1 = Y1[0].sunolo1 = 0;
	for(i=1; i<plithos; i++) {
		X1[i].sunolo1 = X1[i-1].sunolo1 + i*(X1[i].mikos - X1[i-1].mikos);
		Y1[i].sunolo1 = Y1[i-1].sunolo1 + i*(Y1[i].mikos - Y1[i-1].mikos); 
		}
	for(i=0; i<plithos; i++) {
		A[X1[i].pou] = A[X1[i].pou] + X1[i].sunolo1 + X2[i].sunolo1;
		A[Y1[i].pou] = A[Y1[i].pou] + Y1[i].sunolo1 + Y2[i].sunolo1;
		}
	min = A[0];
	for(i=1; i<plithos; i++) {
		if(A[i] < min) {min=A[i];
		 }
		}
	printf("%llu\n",min);
	return 0;
}
