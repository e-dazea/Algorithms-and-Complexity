#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define BSIZE 1<<15

using namespace std;

char buffer[BSIZE];
long bpos = 0L, bsize = 0L;

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




int main(int argc, char **argv) {
	int n,l,i, j, cost[100001],curr_max, *algo;
	n = readLong();
	l = readLong();
	algo = new(nothrow) int [(l+1)*n];
	for(i=0; i<n; i++) {
		cost[i] = readLong(); 
		algo[i] = 0;  
	}
	for(j=0; j<=l; j++) {
		algo[j*n]=0; }
	for(i=1; i<=l; i++) {
		curr_max = INT_MIN;
		for(j=1; j<n; j++) {
			algo[n*i+j] = max(algo[n*i+j-1], (cost[j] + (curr_max = max(curr_max, (algo[n*(i-1)+j-1] - cost[j-1]))))); 
	} } 
	cout << algo[l*n+n-1] << '\n';
	delete[] algo;
	return 0;
}
		
	
