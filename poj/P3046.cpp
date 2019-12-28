#include<stdio.h>
const int P=1000000;
int T,A,S,B,c[1024],f[2][131072],*n,*l;
int i,j,cnt,end,sum;
inline int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	scanf("%d%d%d%d",&T,&A,&S,&B);
	for(i=0;i<A;i++)
	{
		scanf("%d",&j);
		c[j]++;
	}
	f[0][0]=1;
	for(i=1;i<=T;i++)
	{
		n=f[i&1];
		l=f[1^i&1];
		n[0]=l[0];
		end+=c[i];
		for(j=1;j<=end;j++)
		{
			n[j]=n[j-1]+l[j];
			if(j>c[i])
				n[j]-=l[j-c[i]-1];
			n[j]+=P;
			n[j]%=P;
		}
	}
	for (i=S;i<=B;i++)
	{
		sum+=n[i];
		sum%=P;
	}
	printf("%d\n",sum);
	return 0;
}
