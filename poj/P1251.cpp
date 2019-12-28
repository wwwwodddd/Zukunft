#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m[30][30];
int d[30];
int b[30];
char c,s,l;
int n,i,j,k;
int ans,t;
void prim(int st)
{
	int next,i,j;
	int min;
	for(i=0;i<n;i++)
		d[i]=120;
	next=0;
	d[st]=0;
	for(i=0;i<n;i++)
	{
		min=110;
		for(j=0;j<n;j++)
			if((!b[j])&&(d[j]<min))
			{
				next=j;
				min=d[j];
			}
		ans+=min;
		b[next]=1;
		for(j=0;j<n;j++)
			if((!b[j])&&(d[j]>m[next][j]))
				d[j]=m[next][j];
	}
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
	ans=0;
	memset(b,0,sizeof(b));
	memset(m,0x7f,sizeof(m));
	m[0][0]=0;
	for(i=1;i<n;i++)
	{
		m[i][i]=0;
		scanf("%s %d",&c,&t);
		k=c;
		for(j=0;j<t;j++)
		{
			scanf("%s %d",&s,&l);
			m[k-'A'][s-'A']=l;
			m[s-'A'][k-'A']=l;
		}
	}
	prim(0);
	printf("%d\n",ans);
	}
	return 0;
}
