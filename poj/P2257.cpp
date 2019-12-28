#include<iostream>
#include<algorithm>
using namespace std;
int i,j,k,n,m,x,csc;
char c[20],d[20];
struct N
{
	char b[20];
	int s;
}a[25];
bool cmp(N x,N y)
{
	return x.s>y.s;
}
int main()
{
	while(scanf("%d%d",&n,&m),n+m)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%s",a[i].b);
			a[i].s=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%s%s%d",c,d,&x);
			for(j=1;j<=n;j++)
				if(strcmp(a[j].b,c)==0)
					a[j].s-=x;
				else if(strcmp(a[j].b,d)==0)
					a[j].s+=x;
		}
		sort(a+1,a+n+1,cmp);
		printf("Case #%d\n",++csc);
		for(i=1;i<=n;i++)
			if(a[i].s>0)
				for(j=i+1;j<=n;j++)
					if(a[j].s<0)
					{
						a[j].s+=a[i].s;
						printf("%s %s %d\n",a[i].b,a[j].b,a[i].s);
						a[i].s=0;
						break;
					}
		printf("\n");
	}
	return 0;
}