#include<vector>
#include<algorithm>
#include<cstdio>
#include<iostream>

using namespace std;

#define fr(i,j,n) for(int i=(int)j;i<(int)n;i++)
#define LARGE

bool canUse[2100][2100];
int numCase, numFlavor, numCustomer;
int numCanUse[2100];   //the number of unmalted types that jth customer chooses from current milk.
int malted[2100];      //the only malted type that jth customer likes.  
bool choice[2100];	   //save the result of milk types. start from all 0. 
bool visited[2100];

void MakeMilk(){
	bool possible = true;	
	while(1){
		bool found = true;
		fr(i,0,numCustomer){
			if(numCanUse[i] ==0 && !visited[i]){
				visited[i] = true;
				found = false;
				if(malted[i]==-1){
					possible = false;
					break;
					}
				else{
					choice[malted[i]] = true;	
					fr(j,0,numCustomer){
						if (canUse[j][malted[i]] == true){
							canUse[j][malted[i]] = false;
						    numCanUse[j]-- ;
						}
						
					}
				}
			}		
		}
		if(!possible) break;
		if(found) break;
	}
	if(!possible) printf(" IMPOSSIBLE");
	else{
		fr(i,0,numFlavor) printf(" %d",choice[i]);
	}			
	cout<<endl;
}

int main(){
#ifdef LARGE
	freopen("B-large-practice.in","r",stdin);	
	freopen("B-large-practice.out","w",stdout);
#else
	freopen("B-small-practice.in","r",stdin);	
	freopen("B-small-practice.out","w",stdout);
#endif

	cin>>numCase;
	string str;
	getline(cin,str);
	fr(i,0,numCase){
		cin>>numFlavor; getline(cin,str);
		cin>>numCustomer; getline(cin,str);
		fr(t,0,numCustomer)
			fr(t2,0,numFlavor) 
				canUse[t][t2] = false ;
		fr (j,0,numCustomer){
			malted[j] = -1;
			numCanUse[j] = 0;
			visited[j] = false;
			}
	    fr(t,0,numCustomer){
			int nl;
			cin>>nl;
			fr(t2,0,nl){
				int fla1,fla2;
				cin>>fla1>>fla2;
				fla1--;
				if(fla2==1)
					malted[t]=fla1;
				else{
					canUse[t][fla1] = true;
					numCanUse[t]++;
				}
			}	
		}
		fr(j,0,numFlavor) choice[j] = false;
		cout<<"Case #"<<i+1<<":";
		MakeMilk();
	}
	
	return 0;
}
