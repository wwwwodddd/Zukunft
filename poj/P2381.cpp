#include<iostream>
#include<stdio.h>
using namespace std;
char v[16000020];
long long a,c,m,r,mx,i,p;
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&a,&c,&m,&r);
	while(1)
	{
		v[r%m]=1;
		r=(a*r+c)%m;
		if(v[r])
			break;
	}
	p=m;
	for(i=0;i<m;i++)
		if(v[i])
		{
			mx=max(mx,i-p);
			p=i;
		}
	printf("%I64d\n",mx);
	return 0;
}