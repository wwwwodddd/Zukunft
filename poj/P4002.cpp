#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int t[2520],w[2520];
int p[100020];
int q[100020],bb,ff,n,m,ss,s,v;
char str[][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
int M[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
int Y[2]={365,366};
long long z;
int G(char *s)
{
	for(int i=0;i<12;i++)
		if(strcmp(str[i],s)==0)
			return i;
}
int R(int x)
{
	return x%400==0||x%100&&x%4==0;
}
int main()
{
	while(scanf("%d %d",&n,&m),n)
	{
		ss=bb=ff=z=0;
		for(int i=0;i<n;i++)
		{
			t[i]=0;
			char o[5];
			int m,d,y,h,_;
			scanf("%s %d %d %d %d",o,&d,&y,&h,w+i);
			m=G(o);
			for(int j=2000;j<y;j++)
				t[i]+=Y[R(j)];
			_=R(y);
			for(int j=0;j<m;j++)
				t[i]+=M[_][j];
			t[i]+=d-1;
			t[i]*=24;
			t[i]+=h;
		}
		scanf("%d %d",&v,&s);
		for(int i=0;i<m;i++)
			scanf("%d",p+i);
		for(int i=0;i<m;i++)
		{
			while(bb<ff&&q[bb]<i-v)
				bb++;
			while(bb<ff&&p[q[ff-1]]+(i-q[ff-1])*s>p[i])
				ff--;
			q[ff++]=i;
			for(;ss<n&&t[ss]==i;ss++)
				z+=w[ss]*(p[q[bb]]+(i-q[bb])*s);
		}
		printf("%I64d\n",z);
	}
	return 0;
}
