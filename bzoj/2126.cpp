#include<stdio.h>
#include<string.h>
int t[150],c,mo=19921107,z,p,q;
long long a[150][150],b[150][150];
void mul(long long v[150][150],long long a[150][150],long long b[150][150])
{
	long long _[150][150];
	memset(_,0,sizeof _);
	for(int i=0;i<c;i++)
		for(int k=0;k<c;k++)
			if(a[i][k])
				for(int j=0;j<c;j++)
					_[i][j]=(_[i][j]+a[i][k]*b[k][j])%mo;
	memcpy(v,_,sizeof _);
}
int main()
{
	scanf("%d %d",&p,&q);
	for(int i=0;i<1<<p;i++)
		if((i&i>>1)==0&&(i&i>>p-1)==0)
			t[c++]=i;
	if(p==1)
		t[c++]=1;
	for(int i=0;i<c;i++)
		for(int j=0;j<c;j++)
			if(t[i]&t[j])
				;
			else
				b[i][j]=1;
	for(int i=0;i<c;i++)
		a[i][i]=1;
	if(q==1)
		return printf("%d",c),0;
	for(;q;q>>=1)
	{
		if(q&1)
			mul(a,a,b);
		mul(b,b,b);
	}
	for(int i=0;i<c;i++)
		z=(z+a[i][i])%mo;
	printf("%d",(z+mo)%mo);
}
