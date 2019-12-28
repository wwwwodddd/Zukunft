#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int b[30],t[30],f[30];
int n,x,y;
string s,c;
void rs(int x)
{
	if(x==-1)
		return;
	b[x]=-1;
	f[x]=x;
	if(t[x]!=-1)
		rs(t[x]);
	t[x]=-1;
	return;
}
void mn(int x,int y)
{
	rs(t[x]);
	t[x]=-1;	
	rs(t[y]);
	t[y]=x;
	b[x]=y;
	f[x]=f[y];
}
void mv(int x,int y)
{
	int p;
	for(p=y;t[p]!=-1;p=t[p]);
	t[x]=-1;
	rs(t[x]);
	t[p]=x;
	b[x]=p;
	f[x]=f[p];
}
void pn(int x,int y)
{
	rs(t[y]);
	t[y]=x;
	t[b[x]]=-1;
	b[x]=y;
	for(int i=x;i!=-1;i=t[i])
		f[i]=f[y];
}
void pv(int x,int y)
{
	int p;
	for(p=y;t[p]!=-1;p=t[p]);
	pn(x,p);
}
int main()
{
	while(cin>>n)
	{
		memset(b,-1,sizeof(b));
		memset(t,-1,sizeof(t));
		for(int i=0;i<30;i++)
			f[i]=i;
		while(cin>>s&&s!="quit")
		{
			cin>>x>>c>>y;
			if(x==y||f[x]==f[y])
				continue;
			if(s=="move"&&c=="onto")
				mn(x,y);
			if(s=="move"&&c=="over")
				mv(x,y);
			if(s=="pile"&&c=="onto")
				pn(x,y);
			if(s=="pile"&&c=="over")
				pv(x,y);
		}
		for(int i=0;i<n;i++)
		{
			printf("%d:",i);
			if(b[i]==-1)
				for(int j=i;j!=-1;j=t[j])
					printf(" %d",j);
			printf("\n");
		}
	}
	return 0;
}