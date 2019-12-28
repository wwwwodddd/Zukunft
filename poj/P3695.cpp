#include<stdio.h>
#include<iostream>
using namespace std;
struct rec{int v,x,y,X,Y;}p[10000],q[10000];
int i,j,k,x,s,n,m,l,z,csc,qy;
void it(rec p1,rec p2,rec &p3)
{
	p3.x=max(p1.x,p2.x);
	p3.y=max(p1.y,p2.y);
	p3.X=min(p1.X,p2.X);
	p3.Y=min(p1.Y,p2.Y);
	p3.v=-p1.v*p2.v;
}
int main()
{
	while(scanf("%d %d",&n,&m),n+m)
	{
		qy=0;
		for(i=1;i<=n;i++)
			scanf("%d %d %d %d",&p[i].x,&p[i].y,&p[i].X,&p[i].Y);
		printf("Case %d:\n",++csc);
		while(m--)
		{
			scanf("%d",&l);
			for(s=z=i=0;i<l;i++)
			{
				scanf("%d",&x);
				k=z++;
				q[k]=p[x];
				q[k].v=1;
				for(j=0;j<k;j++)
				{
					it(q[j],q[k],q[z]);
					if(q[z].X>=q[z].x&&q[z].Y>=q[z].y)
						if(q[z].x==q[k].x&&q[z].X==q[k].X&&q[z].y==q[k].y&&q[z].Y==q[k].Y)
						{
							z=k;
							break;
						}
						else
							z++;
				}
			}
			for(i=0;i<z;i++)
				s+=q[i].v*(q[i].X-q[i].x)*(q[i].Y-q[i].y);
			printf("Query %d: %d\n",++qy,s);
		}
		printf("\n");
	}
	return 0;
}