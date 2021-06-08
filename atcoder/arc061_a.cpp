#include <bits/stdc++.h>
using namespace std;
string s;
char x[1024][20];
int w[1000000],k=1,i,j,a;
long long h,o,f;
int main()
{
	cin>>s;
	for(i=0;i<s.size();i++)
	{
		w[i]=int(s[i]-48);
		k*=2;
	}
	k/=2;
	for(i=1;i<=k;i++)
	{
		h=0;
		j=i;
		for(a=1;a<=s.size();a++)
		{
			x[i][s.size()-a]=char(48+j%2);
			j/=2;
		}
		for(a=0;a<=s.size();a++)
		{
			if(x[i][a]=='1')
			{
				h=h*10+w[a];
			}
			else
			{	
				if(h!=0)
				{
					o+=h;
					
				}
				h=w[a];
			}
			
		}
//		cout<<o<<" ";
//		cout<<endl;
		f+=o;
		o=0;
	}
	cout<<f<<endl;

	return 0;
}
