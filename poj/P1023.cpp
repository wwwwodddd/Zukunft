#include<iostream>
#include<string>
using namespace std;
string s;
long long n;
int t,i,k;
int r[100];
int z;
int main()
{
	cin>>t;
	while(t--)
	{
		z=0;
		cin>>k>>s>>n;
		for(i=k-1;i>=0;i--)
			if(n&1)
			{
				if(s[i]=='p')
					n=(n-1)/2;
				else if (s[i]=='n')
					n=(n+1)/2;
				r[z++]=1;
			}
			else
			{
				n/=2;
				r[z++]=0;
			}
		if(n!=0)
			cout<<"Impossible";
		else
			for(i=k-1;i>=0;i--)
				cout<<r[i];
		cout<<endl;
		
	}
	return 0;
}