#include<iostream>
#include<math.h>
using namespace std;
const double eps=1e-6;
struct P{double x,y;}p[20];
int i,j,k,n,x,y,z;
double mx,s;
double C(P a,P b,P c)
{
	return(c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y);
}
double A(P a,P b,P c)
{
	return fabs(C(a,b,c))/2;
}
int check(int i,int j,int k,int n)
{
	for(int l=0;l<n;l++)
		if(l!=i&&l!=j&&l!=k)
			if(C(p[i],p[j],p[l])>-eps&&C(p[j],p[k],p[l])>-eps&&C(p[k],p[i],p[l])>-eps||C(p[i],p[j],p[l])<eps&&C(p[j],p[k],p[l])<eps&&C(p[k],p[i],p[l])<eps)
				return 0;
	return 1;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		mx=0;
		for(i=0;i<n;i++)
			scanf("%*s %lf %lf",&p[i].x,&p[i].y);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				for(k=j+1;k<n;k++)
				{
					s=A(p[i],p[j],p[k]);
					if(check(i,j,k,n))
						if(mx<s)
						{
							mx=s;
							x=i;
							y=j;
							z=k;
						}
				}
		printf("%c%c%c\n",x+'A',y+'A',z+'A');
	}
	return 0;
}
