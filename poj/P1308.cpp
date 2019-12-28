#include<iostream>
#include<stdio.h>
using namespace std;
int f[100];
int F(int x)
{
	if(f[x]==x)
		return x;
	if(f[x]==-x)
		return -x;
	return f[x]=F(f[x]);
}
int main()
{
	int a,b,A,B;
	int c=1,n=0,i;
	bool j=0,t=0;
	for(i=0;i<100;i++)
	f[i]=-i;
	while(cin>>a>>b,a>=0)
		if(a==0)
		{
			printf("Case %d is %sa tree.\n",c++,n==1||!t?"":"not ");
			t=n=j=0;
			for(i=0;i<100;i++)
				f[i]=-i;
		}
		else
		{
		t=1;
		A=F(a);
		if(A==-a)
			f[a]=a;
		B=F(b);
		if(B==-b)
			f[b]=b;
		if(A==B)
		{
			n=0;
			j=1;
		}
		if(j==0)
			if(B==b)
			{
				if(A!=-a)
					n--;
				f[b]=F(a);
			}
			else if(B==-b)
			{
				if(A==-a)
					n++;
				f[b]=F(a);
			}
			else
			{
				n=0;
				j=1;
			}
		}
	return 0;
}

