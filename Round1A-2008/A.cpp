#include<vector>
#include<numeric>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;

#define fr(i,j,n) for(int i=(int)j;i<(int)n;i++)

#define LARGE

long long minipro(vector<long long>x,vector<long long>y){
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	reverse(y.begin(),y.end());
	long long ans = 0;
	fr(j,0,x.size())
		ans += (x[j] * y[j]);
	return ans;
}
 

int main(){	
#ifndef LARGE
		freopen("A-small-practice.in","rt",stdin);
		freopen("A-small-practice.out","wt",stdout);
#else
		freopen("A-large-practice.in","rt",stdin);
		freopen("A-large-practice.out","wt",stdout);
#endif
	int N;
	cin>>N;
	string str;
	getline(cin,str);
	fr(i,0,N){ 
		printf("Case #%d: ",i+1);
		vector<long long>x;
		vector<long long>y;
		int n;
		cin>>n;getline(cin,str);
		fr(j,0,n){
			long long tmp;
			cin>>tmp;
			x.push_back(tmp);
		} 
		fr(j,0,n){
			long long tmp;
			cin>>tmp;
			y.push_back(tmp);
		} 
		long long product = minipro(x,y);
		printf("%lld\n",product);
	 }       

}
