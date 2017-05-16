#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;

#define fr(i, n) for (int i = 0; i < (int)n; ++i) 
FILE *input = fopen("A-large-practice.in","r");
FILE *output = fopen("A-large-practice.out","w");
bool check(vector<int> &data,int money, pair<int,int> &result)
{
	fr(i,data.size()-1)
	{
		if((data[i]+data[data.size()-1])==money)
		{
			result.first=i+1;
			result.second=data.size();
			return 1;
		}
	}
	return 0;
}
bool calcredit(pair<int,int> &result)
{
	int money;
	fscanf(input,"%d",&money);
	int goods;
	fscanf(input,"%d",&goods);
	vector<int> data;
	fr(i,goods) 
	{
		int addnow;
		fscanf(input,"%d",&addnow);
		data.push_back(addnow);
		if(i>0)
		{if(check(data,money,result)) {fr(j,goods-i-1)fscanf(input,"%d",&addnow);return 1;}}
	}
	return 0;
}

int main(void)
{
	int cases;
	if(input!=NULL)
	{
		fscanf(input,"%d",&cases);
		pair<int,int> result;
		fr(i,cases)
			{
				if(calcredit(result))
				{
					fprintf(output,"Case #%d: %d %d\n",i+1,result.first,result.second);			
				}
			}
	}
	fclose(input);
	fclose(output);
	return 0;
}

