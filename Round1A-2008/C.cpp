#include<vector>
#include<cstdio>
#include<iostream>

using namespace std;
#define fr(i,j,n) for(int i=(int)j;i<(int)n;i++)
#define LARGE

int x0=2,x1=6;
vector<int> X(2);
void Update(int times){
	int n=X.size();	
	int t1=X[n-1],t2=X[n-2];
    fr(i,n-1,times)
		{
			int newone;
			newone = (6*t1-4*t2)%1000;
			if(newone<0) newone+=1000;
			X.push_back(newone);
			t2=t1;t1=newone;
			}
}

int main(){

#ifdef LARGE
	freopen("C-large-practice.in","r",stdin);
	freopen("C-large-practice.out","w",stdout);
#else
	freopen("C-small-practice.in","r",stdin);
	freopen("C-small-practice.out","w",stdout);
#endif
	int N;
	cin>>N;
    string str;
	getline(cin,str);
	X[0]=x0;X[1]=x1;
	fr(i,0,N){
		int times;
		cin>>times;getline(cin,str);
		printf("Case #%d: ",i+1);
		if(times>=X.size())
			Update(times);
		if(times==0)
			printf("%03d\n",1);
		else
			printf("%03d\n",X[times--]-1);
	}	
}
