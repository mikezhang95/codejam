#include<cstdio>
#include<iostream>
using namespace std;

fr(i,j,n) for(int i=(int);j<(int)n;i++)
#define LARGE

double E[41];
int C,T;
double A[41][41];
double B[41];

void Calculate(){
	fr(i,0,C+1){
		int tmp = (i+T)<C ? i+T : C;
		fr(j,i,tmp+1){
			A[i][j] = 	Permulate(C-i,y-i)*Permulate(i,T-y+i)/Permulate(C,T);
		}			
	}		
	
	E = AE+B;  //解这个方程
	
}

int main(){
		
#ifndef LARGE
		freopen("C-small-practice.in","rt",stdin);
		freopen("C-small-practice.out","wt",stdout);
#else
		freopen("C-large-practice.in","rt",stdin);
		freopen("C-large-practice.out","wt",stdout);
#endif
	string str;
	int N;
    cin>>N;getline(cin,str);
	fr(i,0,N){
		cin>>C>>T;getline(cin,str);
	    fr(j,0,C) {E[j]=0;B[j]=1;}
	    Calculate();	
		printf("Case #%d: %lf",i+1,E[0]);
	}	
	return 0;
	
}
