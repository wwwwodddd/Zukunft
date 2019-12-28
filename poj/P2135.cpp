#include<stdio.h>
#include<string.h>
int a[40020][5];
int h[1020];
int p[1020];
int d[1020];
int q[10020];
int v[1020];
int b,f;
int n,m;
int i,j,k;
int x,y,z;
int tot=1;;
void add(int x,int y,int z,int v)
{
	tot++;
	a[tot][0]=x;
	a[tot][1]=y;
	a[tot][2]=z;
	a[tot][3]=v;
	a[tot][4]=h[x];
	h[x]=tot;
	tot++;
	a[tot][0]=y;
	a[tot][1]=x;
	a[tot][2]=0;
	a[tot][3]=-v;
	a[tot][4]=h[y];
	h[y]=tot;
}
int spfa()
{
	int i,j,k;
	memset(p,-1,sizeof(p));
	memset(d,0x3f,sizeof(d));
	b=f=0;
	q[f++]=0;
	v[0]=1;
	d[0]=0;
	while(b<f)
	{
		j=q[b++];
		v[j]=0;
		for(i=h[j];i;i=a[i][4])
		{
			k=a[i][1];
			if(a[i][2]&&d[k]>d[j]+a[i][3])
			{
				d[k]=d[j]+a[i][3];
				p[k]=i;
				if(!v[k])
				{
					v[k]=1;
					q[f++]=k;
				}
			}
		}
	}
	if(p[n]==-1)
		return false;
	return true;
}
int MF()
{
	int i,j;
	int u,v;
	int ans=0;
	n++;
	while(spfa())
	{
		ans+=d[n];
		j=p[n];
		while(j!=-1)
		{
			a[j][2]--;
			a[j^1][2]++;
			j=p[a[j][0]];
		}
	}
	return ans;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,1,z);
		add(y,x,1,z);
	}
	add(0,1,2,0);
	add(n,n+1,2,0);
	printf("%d",MF());
	return 0;
}