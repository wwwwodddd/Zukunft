#include<stdio.h>
int s[400020],ss;
int f[400020];
int a[400020][2],tot;
int h[400020];
int v[400020];
int q[400020];
int w[400020];
int n,m,d,cnt;
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
int F(int x)
{
	int i;
	ss=0;
	while(f[x]!=x)
	{
		s[ss++]=x;
		x=f[x];
	}
	for(i=0;i<ss;i++)
		f[s[i]]=x;
	return x;
}
void U(int x,int y)
{
	if(F(x)==F(y))
		return;
	cnt--;
	f[F(x)]=F(y);
}
int main()
{
	int i,j,x,y;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		f[i]=i;
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		x++;
		y++;
		add(x,y);
		add(y,x);
	}
	scanf("%d",&d);
	cnt=n;
	for(i=1;i<=d;i++)
	{
		scanf("%d",&q[i]);
		q[i]++;
		v[q[i]]=1;
		cnt--;
	}
	for(i=1;i<=n;i++)
		if(!v[i])
			for(j=h[i];j;j=a[j][0])
				if(!v[a[j][1]])
					U(i,a[j][1]);
	w[d+1]=cnt;
	for(i=d;i>0;i--)
	{
		cnt++;
		v[q[i]]=0;
		for(j=h[q[i]];j;j=a[j][0])
			if(!v[a[j][1]])
				U(q[i],a[j][1]);
		w[i]=cnt;
	}
	for(i=1;i<=d+1;i++)
		printf("%d\n",w[i]);
	return 0;
}