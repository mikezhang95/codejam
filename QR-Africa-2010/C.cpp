#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

#define fr(i,j,n) for(int i=(int)j;i<(int)n;i++)
//#define LARGE

string t9[27]={"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99","999","9999","0"};

void spelling(string str){
	 char last = '%';
	fr(i,0,str.length()){
       char now = str[i];		
	   int index=0;
	   if((int)now==32)
			index=26;
 	    else
			index = (int)now-97;
		if(t9[index].c_str()[0]==last)	
			cout<<" ";
		cout<<t9[index];
		last=t9[index].c_str()[0];
  	} 
  }
int main()
{	 
	int N;
	#ifndef LARGE
		freopen("C-small-practice.in","r",stdin);
		freopen("C-small-practice.out","w",stdout);
	#else
		freopen("C-large-practice.in","r",stdin);
		freopen("C-large-practice.out","w",stdout);
	#endif
	cin>>N;
	string str;
	getline(cin,str);
	fr(i,0,N)
	 {
		getline(cin,str);
	    cout<<"Case #"<<i+1<<": ";
		spelling(str);	
		cout<<endl;
	}
	
	return 0;
}
