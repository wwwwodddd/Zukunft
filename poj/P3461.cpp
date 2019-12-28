#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
string t,p;
int a[10020];
int l,m,n,i,j,k,q,ans;
void cpf()
{
memset(a,0,sizeof(a));
a[0]=-1;
k=-1;
for(q=1;q<m;q++)
	{
	while(k>=0&&p[k+1]!=p[q])
		k=a[k];
	if(p[k+1]==p[q])
		k++;
	a[q]=k;
	}
return;
}
int main()
{
cin >> l;
while(l--)
	{
	ans=0;
	cin >> p >> t;
	n=t.size();
	m=p.size();
	cpf();
	q=-1;
	for(i=0;i<n;i++)
		{
		while(q>=0&&p[q+1]!=t[i])
			q=a[q];
		if(p[q+1]==t[i])
			q++;
		if(q==m-1)
			{
			ans++;
			q=a[q];
			}
		}
	printf("%d\n",ans);
	}
return 0;
}