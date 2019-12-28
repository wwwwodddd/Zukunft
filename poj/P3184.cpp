#include<algorithm>
using namespace std;
int f[2][100010], p[10010];
int n,l,d,i,j,t;
struct P
{
	int f,s;
}pp,pq;
P R(int x)
{
	P z;
	z.f=max(x*d,l-(n-1-x)*(d+1));
	z.s=min(x*(d+1),l-(n-1-x)*d);
	return z;
}
int main()
{
	scanf("%d %d",&n,&l);
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	d=l/(n-1);
	f[0][0]=p[0];
	for(i=1;i<n;i++)
	{
		pp=R(i-1);
		pq=R(i);
		for(j=pq.f;j<=pq.s;j++)
		{
			f[1-t][j]=0x3fffffff;
			if(j-(d+1)>=pp.f)
				f[1-t][j]=min(f[1-t][j],f[t][j-d-1]);
			if(j-d<=pp.s)
				f[1-t][j]=min(f[1-t][j],f[t][j-d]);
			f[1-t][j]+=abs(p[i]-j); 
		}
		t=1-t;
	}
	printf("%d\n",f[t][l]);
	return 0;
}
