#include<stdio.h>
#include<string.h>
int a[2020][3];
int ans[120];
int h[505];
int d[505];
int v[505];
int q[1000020];
int tot;
int x,y,z;
int b,f,now;
int i,j,k;
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
	return ;
}
int F,p,c,m;
int main()
{
	scanf("%d %d %d %d",&F,&p,&c,&m);
	for(i=0;i<p;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);	
	}
	memset(d,0x3f,sizeof(d));
	b=f=0;
	q[f++]=1;
	v[1]=1;
	d[1]=0;
	while(b<f)
	{
		now=q[b++];
		v[now]=0;
		for(i=h[now];i;i=a[i][0])
			if(d[a[i][1]]>d[now]+a[i][2])
			{
				d[a[i][1]]=d[now]+a[i][2];
				if(v[a[i][1]]==0)
				{
					q[f++]=a[i][1];
					v[a[i][1]]=0;
				}
			}
	}
	for(i=1;i<=c;i++)
	{
		scanf("%d",&x);
		if(d[x]<=m)
		ans[++ans[0]]=i;
	}
	for(i=0;i<=ans[0];i++)
		printf("%d\n",ans[i]);
	return 0;	
}
