#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int n,m;
int b[20],a[20];
int f[40];
int p[15000];
int sq(int x)
{
return (int)sqrt((double)x);	
}
int phi(int x)
{
int i,pro=0;
for(i=1;i<=x;i++)
	if(x%i==0)
		pro++;
return pro;
}
int fx(int x)
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int i,j=0,t=0;
	for(i=0;p[i]<=sq(x);i++)
	{
		while(x%p[i]==0)
	    {
			a[j]=p[i];
		    b[j]++;
			x/=p[i];
			t=1;
		}
		if(t==1)
			{
			j++;
			t=0;
			}
	}
	if(x!=1)
		{
		a[j]=x;
		b[j++]=1;
		}
	return j;
}
int main()
{
	int i,j,k=1,sq;
	int o,n,m;
	long long ans;
	p[0]=2;
	o=65535;
	for(i=3;i<=o;i+=2)
    {
		sq=(int)sqrt(i+0.);
		for(j=3;j<=sq;j+=2)
			if(i%j==0)
				goto next;
		p[k++]=i;
		next:;
    }
	f[0]=1;
	for(i=1;i<32;i++)
		f[i]=f[i-1]+i+1;
	for(i=1;i<32;i++)
		f[i]*=f[i];
	scanf("%d",&k);
	while(k--)
	{
		ans=1;
		scanf("%d",&n);
		m=fx(n);
		for(j=0;j<m;j++)
			ans*=f[b[j]];
		printf("%I64d\n",ans);
	}
	return 0;
}

