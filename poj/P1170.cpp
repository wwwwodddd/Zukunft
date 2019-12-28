#include<iostream>
#include<map>
#define S(x) scanf("%d",&x)
using namespace std;
int p[110][6],a[6];
int n,s;
int dp[6][6][6][6][6];
int P(int A,int B,int C,int D,int E)
{
int i,j,t=0x7fffffff,f,*o,*u=dp[A][B][C][D]+E;
if(*u>0)
	return *u;
if(!A&&!B&&!C&&!D&&!E)
	return 0;
for(i=n+s;i>0;i--)
	{
	o=p[i];
	if(o[1]>A||o[2]>B||o[3]>C||o[4]>D||o[5]>E)
			continue;
	f=P(A-o[1],B-o[2],C-o[3],D-o[4],E-o[5])+o[0];
	f<t?t=f:0;
	}
return *u=t;
}
int main()
{
	S(n);
	int i,j,t,x,y,z;
	map<int,int>m;
	for(i=1;i<=n;i++)
	{
		S(t),S(a[i]),S(p[i][0]);
		m[t]=i;
		p[i][i]=1; 
	}
	S(s);
	for(i=n+1;i<=s+n;i++)
	{
		S(x);
		for(j=1;j<=x;j++)
		{
			S(y),S(z);
			p[i][m[y]]=z;
		}
		S(p[i][0]);
	}
	printf("%d\n",P(a[1],a[2],a[3],a[4],a[5]));
return 0;
}

