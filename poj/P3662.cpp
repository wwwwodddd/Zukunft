#include<stdio.h>
#include<string.h>
int a[20020][3];
int h[1005];
int d[1005];
int v[1005];
int q[1000020];
int tot;
int x,y,z;
int b,f,now;
int i,j,k;
int l,r;
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
	return ;
}
int n,p,c,m;
int check(int x)
{
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
			if(d[a[i][1]]>d[now]+(a[i][2]>x?1:0))
			{
				d[a[i][1]]=d[now]+(a[i][2]>x?1:0);
				if(v[a[i][1]]==0)
				{
					q[f++]=a[i][1];
					v[a[i][1]]=1;
				}
			}
	}
	return k>=d[n];
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
		if(z>r)
			r=z;
	}
	while(l!=r)
		if(check((l+r)/2))
			r=(l+r)/2;
		else
			l=(l+r)/2+1;
	if(check(r))
		printf("%d",r);
	else
		printf("-1");
	return 0;
}

