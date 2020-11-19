#include<stdio.h>
typedef unsigned long long ll;
int F(ll x,ll y,ll z,int w)
{
	if(w==32)
		return 1;
	if(x%2==0&&y%2==0&&z%2==0)
		return F(x/2,y/2,z/2,w+1);
	int t=0;
	if((x+y+z)%2==0)
		t|=F(4*x,4*x+2*y,x+y+z,w+1);
	if(z%2==0)
		t|=F(2*x,y,z/2,w+1);
	return t;
}
int t;
ll x,y,z;
int main()
{
	for(scanf("%d",&t);t--;puts(F(x,y,z,0)?"YES":"NO"))
		scanf("%I64u%I64u%I64u",&x,&y,&z);
	return 0;
}
