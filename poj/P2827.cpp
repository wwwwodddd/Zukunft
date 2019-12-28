#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
using namespace std;
map<int,int>m;
int n,cnt;
int f[20020];
int s[20020],ss;
int w[20020];
int F(int x)
{
	int u=0;
	ss=0;
	while(f[x]!=x)
	{
		s[ss++]=x;
		x=f[x];
	}
	s[ss]=x;
	for(int i=ss-1;i>=0;i--)
	{
		w[s[i]]+=w[s[i+1]];
		f[s[i]]=f[s[i+1]];
	}
	return x;
}
inline int R(int x)
{
	int &u=m[x];
	if(!u)
	{
		u=++cnt;
		f[u]=u;
	}
	return u;	
}
int main()
{
	int x,y,z;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d %d",&x,&y,&z);
		if(x>y)
			swap(x,y);
		x--;
		int lx=R(x),ly=R(y);
		int fx=F(lx),fy=F(ly);
		if(fx==fy)
		{
			if(w[ly]-w[lx]!=z)
				printf("Bug Detected %d\n",w[ly]-w[lx]);
			else
				puts("Accept");

		}
		else
		{
			f[fy]=fx;
			w[fy]=z-w[ly]+w[lx];
			puts("Accept");
		}
	}
	return 0;
}
