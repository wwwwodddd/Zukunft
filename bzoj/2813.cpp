#include<stdio.h>
typedef long long ll;
const int N=10000020;
int p=1000000007,Q;
int v[N],g[N],f[N],q,A,B,C,a,b;
int main()
{
	f[1]=g[1]=1;
	scanf("%d%d%d%d%d",&Q,&q,&A,&B,&C);
	for(int i=2;i<=C;i++)
		if(!v[i])
			for(int j=1;i*j<=C;j++)
			{
				v[i*j]=i;
				if(v[j]==i)
					f[i*j]=2*f[j]-f[j/i],g[i*j]=(g[j]+(g[j]-g[j/i]+p)*(ll)i%p*i)%p;
				else
					f[i*j]=f[j]*2,g[i*j]=g[j]*((ll)i*i+1)%p;
			}
	while(Q--)
	{
		a=(a+f[q])%p;
		b=(b+g[q])%p;
		if(q&1)
			a=(a+1)%p,b=(b+4)%p;
		q=((ll)q*A+B)%C+1;
	}
	printf("%d\n%d\n",a,b);
	return 0;
}
