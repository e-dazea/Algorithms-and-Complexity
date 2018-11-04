#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
	long int  v1,A_t[50000],A_v[50000],B_t[50000],B_v[50000];
	long n,l,k;
	double t,pivot,time_div,A_x[50000],B_x[50000],abig1, bbig1;
	int i,posa1,posb1,firsta,firstb,j; 
	bool egine;
	
	n = readLong();
	l = readLong();
	k = readLong();
	for(i=0; i<n; i++){
		A_t[i] = readLong();
		A_x[i] = 0;
		A_v[i] = readLong(); }
	for(i=0; i<n; i++){
		B_t[i] = readLong();
		B_x[i] = 0;
		B_v[i] = readLong();}
	firsta = firstb = 0;
	for(i=1; i<=k; i++) 
		{ 
		egine =  false;
		v1=1L;
		t = l/v1;	
		time_div = (double)(t)/2 ; //division of time for binary search
		pivot = time_div;
		
		while(1) {
			
			abig1 =  0; //abig1 1o megisto 
		    	posa1 = posb1= 0;
			bbig1 = 0; //bbig1 1o elaxisto 
			for(j=firsta; j<n; j++) {
				if(A_t[j]>pivot) break;
				A_x[j]=A_v[j]*(pivot-A_t[j]);
				if(A_x[j]>abig1) {abig1=A_x[j];
					posa1=j; } }
		 	for(j=firstb; j<n; j++) {
				if(B_t[j]>pivot) break;
				B_x[j]=B_v[j]*(pivot-B_t[j]);
				if(B_x[j]>bbig1) {bbig1=B_x[j];
					posb1=j; } }
			if((abig1+bbig1==l)||((abig1+bbig1<l)&&(time_div<0.00001 && egine))||((abig1+bbig1>l)&&(time_div<0.00001 && (~egine)))) 			{
				cout << (posa1+1) << ' ' << (posb1+1) << '\n'; 
				A_v[posa1]=0;
				B_v[posb1]=0; 
				break; }
			else {
				if(abig1+bbig1<l) {
					egine = false;
					time_div /=2.0;
					pivot += time_div;
				 }
				else {
					egine = true;
					time_div /=2.0;
					pivot -= time_div;
					 }
				 }
			}}				 
return 0;
}
	
		
	
	






	

