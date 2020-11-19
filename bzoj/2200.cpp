#include<stdio.h>
#include<stdlib.h>
int a[200020][3];
int p[25020];
int q[10000000];
int c[25020];
int v[25020];
int d[25020];
int n,m,m1,m2,u;
int i,j,k,b,f,s,t;
inline void push(int x)
{
	if(b==f||d[x]>d[q[b]])
	{
		q[f++]=x;
		return;
	}
	q[--b]=x;
	return;
}
int cmp(const void *a,const void *b)
{
	if(((int *)a)[0]-((int *)b)[0])
		return ((int *)a)[0]-((int *)b)[0];
	return ((int *)a)[2]-((int *)b)[2];
}
inline void scan(int &x)
{
	register char c,sg=0;
	x=0;
	while(!((c=getchar())<='9'&&c>='0'||c=='-'));
	if(c!='-')
		x=c-'0';
	else
		sg=1;
	while((c=getchar())<='9'&&c>='0')
		x=10*x+c-'0';
	if(sg)
		x=-x;
}
int main()
{
	scanf("%d %d %d %d",&n,&m1,&m2,&s);
	m=2*m1+m2;
	for(i=1;i<=n;i++)
		d[i]=0x3f3f3f3f;
	for(i=0;i<2*m1;i++)
	{
		scan(a[i][0]);
		scan(a[i][1]);
		scan(a[i][2]);
		a[i+1][0]=a[i][1];
		a[i+1][1]=a[i][0];
		a[i+1][2]=a[i][2];
		i++;
	}
	for(i=2*m1;i<2*m1+m2;i++)
	{
		scan(a[i][0]);
		scan(a[i][1]);
		scan(a[i][2]);
	}
	qsort(a,m,12,cmp);
	for(i=0;i<m;i++)
		p[a[i][0]]++;
	for(i=1;i<=n;i++)
		p[i]=p[i-1]+p[i];
	d[s]=0;
	b=f=30000;
	q[f++]=s;
	while(b<f)
	{
		u=q[b++];
		for(i=p[u-1];i<p[u];i++)
		{
			if(d[a[i][1]]>d[u]+a[i][2])
			{
				d[a[i][1]]=d[u]+a[i][2];
				if(v[a[i][1]]==0)
				{
					push(a[i][1]);
					v[a[i][1]]=1;
				}
			}
		}
		v[u]=0;
	}
	for(i=1;i<=n;i++)
	{
		if(d[i]==0x3f3f3f3f)
			puts("NO PATH");
		else
			printf("%d\n",d[i]);
	}
	return 0;
}
