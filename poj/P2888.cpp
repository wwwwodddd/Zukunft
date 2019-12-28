#include<cstdio>
#include<cstring>
int a[50],b[50],q[20][20],p[50][20][20];
int n,mod=9973,m,ans,csc,N,d,k,w;
int phi(int n)
{
	int m=1;
	for(int i=2;i*i<=n;i++)
		if(!(n%i))
		{
			n/=i;
			m*=(i-1);
			while(!(n%i))
			{
				m*=i;
				n/=i;
			}
		}
	if(n!=1)
		m*=(n-1);
	return m%mod;
}
void init()
{
	int i,j,k,l;
	memset(p,0,sizeof(p));
	memcpy(p[1],q,sizeof(q));
	for(i=2;(1<<(i-1))<=N;i++)
		for(j=0;j<m;j++)
			for(k=0;k<m;k++)
				for(l=0;l<m;l++)
					p[i][j][k]=(p[i][j][k]+p[i-1][j][l]*p[i-1][l][k])%mod;
}
int aa(int y)
{
	int a[20][20],b[20][20];
	int i,j,k,x=1,re=0;;
	memset(a,0,sizeof(a));
	for(i=0;i<m;i++)
		a[i][i]=1;
	while(y)
	{
		if(y&1)
		{
			memset(b,0,sizeof(b));
			for(i=0;i<m;i++)
				for(j=0;j<m;j++)
					for(k=0;k<m;k++)
						b[i][j]=(b[i][j]+a[i][k]*p[x][k][j])%mod;
			memcpy(a,b,sizeof(b));
		}
		x++;
		y>>=1;
	}
	for(i=0;i<m;i++)
		re+=a[i][i];
	return re%mod;
}
void solve(int x,int y)
{
	if(x==k)
	{
		ans=(ans+aa(y)*phi(N/y))%mod;
		return;
	}
	if(!((1<<x)&d))
	{
		solve(x+1,y);
		return;
	}
	for(int i=1;i<=b[x];i++)
	{
		y*=a[x];
		solve(x+1,y);
	}
}
void gcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	gcd(b,a%b,y,x);
	y-=(a/b)*x;
}
int main()
{
	int i,j,x,y;
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d%d%d",&n,&m,&k);
		if(m==1)
		{
			if(!k)
				printf("%d\n",1%mod);
			else
			{
				for(i=0;i<k;i++)
					scanf("%d%d",&x,&y);
				printf("0\n");
			}
			continue;
		}
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				q[i][j]=1;
		for(i=0;i<k;i++)
		{
			scanf("%d%d",&x,&y);
			q[x-1][y-1]=q[y-1][x-1]=0;
		}
		ans=0;
		N=n;k=0;
		init();
		for(i=2;n>1;i=i*i<=n?i+1:n)
			if(n%i==0)
			{
				a[k]=i;
				b[k]=0;
				while(n%i==0)
				{
					n/=i;
					++b[k];
				}
				k++;
			}
		for(d=0;d<(1<<k);d++)
			solve(0,1);
		gcd(N%mod,mod,x,y);
		printf("%d\n",(ans*((x%mod+mod)%mod))%mod);
	}
	return 0;
}