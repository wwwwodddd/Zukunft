#include<stdio.h>
#include<string.h>
int i,m,n,mx,mn,j,b,e,h,t,p;
int f[1000020];
int q[2000020];
char v[1000020];
int main()
{
	scanf("%d %d",&n,&m);
	scanf("%d %d",&mn,&mx);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&b,&e);
		for(j=b+1;j<e;j++)
			v[j]=1;
	}
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(i=mn;i<=(m>>1);i++)
	{
		p=i<<1;
		while(h<=t&&f[q[t]]>=f[p-2*mn])
			t--;
		q[++t]=p-2*mn;
		while(h<=t&&q[h]<p-2*mx)
			h++;
		if(h>t||v[p])
			continue;
		f[p]=f[q[h]]+1;
	}
	if(f[m]>0xffffff)
		printf("-1");
	else
		printf("%d",f[m]);
}