#include<stdio.h>
#include<string.h>
struct P{int x,y,r;}p[100];
int v[100];
int s[100];
int csc,n,i,j;
int xm(P a,P b,P c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int dis(P a,P b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		memset(s,-1,sizeof(s));
		memset(v,0,sizeof(v));
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&p[i].r,&p[i].x,&p[i].y);
			if(s[0]==-1||p[s[0]].y>p[i].y||p[s[0]].y==p[i].y&&p[s[0]].x>p[i].x)
				s[0]=i;
		}
		v[s[0]]=1;
		for(i=1;i<n;i++)
		{
			for(j=0;j<n;j++)
				if(!v[j])
					if(s[i]==-1||xm(p[s[i-1]],p[s[i]],p[j])<0||xm(p[s[i-1]],p[s[i]],p[j])==0&&dis(p[s[i-1]],p[j])<dis(p[s[i-1]],p[s[i]]))
						s[i]=j;
			v[s[i]]=1;
		}
		printf("%d",n);
		for(i=0;i<n;i++)
			printf(" %d",p[s[i]].r);
		printf("\n");
	}
	return 0;
}