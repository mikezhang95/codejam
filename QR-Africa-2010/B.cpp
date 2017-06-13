#include<cstdio>
#include<cstring>
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

#define fr(i,j,n) for(int i=j;i<n;i++)
#define LARGE
void reverse(string line){
    stringstream S(line); 
    vector<string> output;
    string tmp;
    while(S>>tmp)
     output.push_back(tmp);
    reverse(output.begin(),output.end());
    fr(i,0,output.size())
	cout<<" "<<output[i];
    cout<<endl;
}

int main(){
    int N;
#ifndef LARGE 
    freopen("B-small-practice.in","r",stdin);
    freopen("B-small-practice.out","w",stdout);
#else
    freopen("B-large-practice.in","r",stdin);
    freopen("B-large-practice.out","w",stdout);
#endif
    cin>>N;   
    string line;
    getline(cin,line); 
    fr(i,1,N+1){
    printf("Case #%d:",i);
    getline(cin,line);
    reverse(line);
	}
return 0;
}
