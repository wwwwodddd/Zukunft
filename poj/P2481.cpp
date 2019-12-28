#include<stdio.h>
#include<algorithm>
using namespace std;
int f[100020][3];
int c[100020];
int r[100020];
int n,l;
int cmp(const void *a,const void *b)
{
	if(((int*)a)[1]==((int*)b)[1])
		return ((int*)a)[0]-((int*)b)[0];
	return ((int*)b)[1]-((int*)a)[1];
}
void R(int x,int v)
{
	for(;x<=l;x+=(x&(-x)))
		c[x]+=v;
}
int G(int x)
{
	int q=0;
	for(;x>0;x-=(x&(-x)))
		q+=c[x];
	return q;
}
int main()
{
	int i;
	while(scanf("%d", &n)&&n)
	{
		l=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&f[i][0],&f[i][1]);
			f[i][0]++;
			f[i][1]++;
			f[i][2]=i;
			if(l<f[i][1])
				l=f[i][1];
		}
		memset(c,0,sizeof(c));
		qsort(f,n,12,cmp);
		for(i=0;i<n;i++)
		{
			if(i!=0&&f[i][0]==f[i-1][0]&&f[i][1]==f[i-1][1])
				r[f[i][2]]=r[f[i-1][2]];
			else
				r[f[i][2]]=G(f[i][0]);
			R(f[i][0],1);
		}
		for (i=0;i<n;i++)
			printf("%d ",r[i]);
		printf("\n");
	}
	return 0;
}
