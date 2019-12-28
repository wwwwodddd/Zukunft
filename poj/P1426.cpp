#include<iostream>
using namespace std;
unsigned long long que[1048580];
unsigned long long num;
int b=0, f=0;
int main()
{
	int N;
	while(cin>>N&&N!=0)
	{
		f=b=0;
		que[f++]=1;
		while(b!=f)
		{
			num=que[b++];
			b%=800000;
			if((num%N)==0) 
				break;
			num*=10;
			que[f++]=num;
			++num;
			que[f++]=num;
		}
		cout << num << endl;
	}
	return 0;
}
