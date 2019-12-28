#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int mod=100000;
int g[100][100];
int a[100][100];
int q[100];
int m,n,f,b;
struct T
{
	int n[4];//0A 1C 2T 3G
	int cnt,f,u;
	char c;
}t[100];
int tt=1;
char s[20];
int i,j,k;
int C(char c)
{
	if(c=='A')
		return 0;
	if(c=='C')
		return 1;
	if(c=='T')
		return 2;
	if(c=='G')
		return 3;
}
void I(char *c)
{
	int i,l=strlen(c);
	int x;
	x=0;
	for(i=0;i<l;i++)
	{
		if(t[x].n[C(c[i])]==-1)
		{
			t[tt].u=x;
			t[tt].c=c[i];
			memset(t[tt].n,-1,16);
			t[x].n[C(c[i])]=tt++;
		}
		x=t[x].n[C(c[i])];
	}
	t[x].cnt++;
}//沿着他父亲的失败指针走，直到走到一个节点，他的儿子中也有字母为C的节点。然后把当前节点的失败指针指向那个字母也为C的儿子。
void F()
{
	b=0;
	f=1;
	while(b<f)
	{
		int p=q[b++];
		for(int i=0;i<4;i++)
			if (t[p].n[i]!=-1)
			{
				if(p==0)
					t[t[p].n[i]].f=0;
				else
				{
					int r=t[p].f;
					while(r!=0&&t[r].n[i]==-1)
						r=t[r].f;
					t[t[p].n[i]].f=t[r].n[i]==-1?0:t[r].n[i];
				}
				q[f++]=t[p].n[i];
			}
	}
}
void mul(int a[][100],int b[][100])
{
	int r[100][100],i,j,k;
	memset(r,0,sizeof(r));
	for(i=0;i<tt;i++)
		for(j=0;j<tt;j++)
			for(k=0;k<tt;k++)
				r[i][j]=(r[i][j]+a[i][k]*b[k][j])%mod;
	memcpy(a,r,sizeof(r));
}
void ss(int n)
{
	for(i=0;i<tt;i++)
		a[i][i]=1;
	while(n)
	{
		if(n&1)
			mul(a,g);
		mul(g,g);
		n>>=1;
	}
}
int main()
{
	memset(t[0].n,-1,16);
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		scanf("%s",&s);
		I(s);
	}
	for(int i = 0; i <tt; i++)
		printf("%d ",t[i].f);
	printf("\n-------\n");
	F();
	for(int i = 0; i <tt; i++)
		printf("%d ",t[i].f);
	printf("\n-------\n");
	for(i=0;i<0;i++)
		for(j=0;j<4;j++)
			if(t[i].n[j]==-1)
				t[i].n[j]=0;
	for(i=0;i<tt;i++)
		for(j=0;j<4;j++)
		{
			if(t[i].n[j]!=-1)
				g[i][t[i].n[j]]++;
			else if(t[i].n[j]==-1)
			{
				if(t[t[i].f].n[j]==-1)
					g[i][0]++;
				else
					g[i][t[t[i].f].n[j]]++;
			}
		}
	for(i=0;i<tt;i++)
		if(t[i].cnt)
			for(j=0;j<tt;j++)
				g[i][j]=g[j][i]=0;
	for(int i = 0; i <tt; i++)
		printf("%d ",t[i].f);
	printf("\n-------\n");
	for(int i = 0; i <tt; i++)
	{
		for (int j = 0; j <tt; j++)
			printf("%d ",g[i][j]);
		printf("\n");
	}
	ss(n);
	long long ans=0;
	for(i=0;i<tt;i++)
		ans+=a[0][i];
	ans%=mod;
	printf("%lld\n", ans);
	return 0;
}
