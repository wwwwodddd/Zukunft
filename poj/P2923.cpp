#include<stdio.h>
#include<string.h>
int n,c1,c2;
int w[12],v[12];
int f[2048];
int s[2048],tot;
int T,t;
int i,j,k,l;
int t1,t2;
void C()
{
	int lim=1<<n;
	tot=0;
	for(i=1;i<lim;i++)
	{
		k=0;
		for(l=0;l<n;l++)
			if(i&(1<<l))
				v[k++]=w[l];
		int klim=1<<k;
		for(j=0;j<klim;j++)
		{
			t1=c1,t2=c2;
			for(l=0;l<k;l++)
			{
				if(j&(1<<l))
					t1-=v[l];
				else
					t2-=v[l];
				if(t1<0||t2<0)
					break;
			}
			if(t1>=0&&t2>=0)
			{
				s[++tot]=i;
				break;
			}
		}
	}
}
void DP()
{
	memset(f,-1,sizeof(f));
	f[0]=0;
	for(i=1;i<=tot;i++)
		for(j=(1<<n)-1-s[i];j>=0;j--)
		{
			if(f[j]<0)
				continue;
			k=j+s[i];
			if((j|s[i])!=k)
				continue;
			if(f[k]==-1||f[k]>f[j]+1)
				f[k]=f[j]+1;
		}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&c1,&c2);
		for(int i=0;i<n;i++)
			scanf("%d",&w[i]);
		C();
		DP();
		printf("Scenario #%d:\n%d\n\n",++t,f[(1<<n)-1]);
	}
	return 0;
}