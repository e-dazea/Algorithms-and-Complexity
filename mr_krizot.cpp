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
	bool b=false;

	while (1)  {
		if (bpos >= bsize) {
			bpos = 0;
			if (feof(stdin)) return x;
			bsize = fread(buffer, 1, BSIZE, stdin);
		}
		c = buffer[bpos++];
		if( c == '-') b=true;
		if (c >= '0' && c <= '9') { x = x*10 + (c-'0'); d = 1; }
	
	else if (d == 1) {if(b) {return (-1*x);} else {return x;} }
	}
	return -1;
}


int main(int argc, char **argv) {
	int a,b,c,i,j,n;
	long long *piata,temp;
	long long *apot;
	n = readLong();
	a = readLong();
	b = readLong();
	c = readLong();
	piata = new(nothrow) long long [n+1];
	apot = new(nothrow) long long [n+1];
	apot[0]=0;
	piata[0] = 0;
	for(i=1; i<=n; i++) {
		piata[i] = piata[i-1] + readLong(); 
	}
	for(i=1; i<=n; i++) {
		temp = piata[i];
		apot[i] = a*temp*temp + b*temp + c;	
		for(j=1; j<=i-1; j++) {
			temp = piata[i]- piata[j];
			temp = apot[j]+a*temp*temp + b*temp + c;
			if(temp > apot[i]) apot[i] = temp;

		 }}
	cout << apot[n] << endl;
	delete[] apot;
	delete[] piata;
	return 0; 
}
	
	
	
		
	
