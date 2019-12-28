#include<iostream>
#include<algorithm>
using namespace std;
double eps=1e-8;
struct P
{
	double x,y;
	P(double x=0,double y=0):x(x),y(y){}
};
struct R
{
	int n,m;
	char c,s[30];
	P p[30];
}a[30];
int sgn(double x)
{
	return (x>eps)-(x<-eps);
}
bool cmp(R a,R b)
{
	return a.c<b.c;
}
double xm(P a,P b,P c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
int is(P a,P b,P c,P d)
{
	return max(a.x,b.x)>=min(c.x,d.x)&&max(a.y,b.y)>=min(c.y,d.y)&&max(c.x,d.x)>=min(a.x,b.x)&&max(c.y,d.y)>=min(a.y,b.y)&&sgn(xm(a,b,c))*sgn(xm(a,b,d))<=0&&sgn(xm(c,d,a))*sgn(xm(c,d,b))<=0;
}
int it(R a,R b)
{
	int i,j;
	for(i=0;i<a.n;i++)
		for(j=0;j<b.n;j++)
			if(is(a.p[i],a.p[(i+1)%a.n],b.p[j],b.p[(j+1)%b.n]))
				return 1;
	return 0;
}
void set_sq(R&a)
{
	a.n=4;
	a.p[2]=a.p[1];
	a.p[1].x=(a.p[0].x+a.p[2].x+a.p[2].y-a.p[0].y)/2;
	a.p[1].y=(a.p[0].y+a.p[2].y+a.p[0].x-a.p[2].x)/2;
	a.p[3].x=(a.p[0].x+a.p[2].x-a.p[2].y+a.p[0].y)/2;
	a.p[3].y=(a.p[0].y+a.p[2].y-a.p[0].x+a.p[2].x)/2;
}
void set_rec(R&a)
{
	a.n=4;
	a.p[3].x=a.p[0].x+a.p[2].x-a.p[1].x;
	a.p[3].y=a.p[0].y+a.p[2].y-a.p[1].y;
}
char o[100];
int main()
{
	int n,i,j;
	while(1)
	{
		i=0;
		while(1)
		{
			scanf("%s",o);
			if(o[0]=='.'||o[0]=='-')
				break;
			a[i].c=o[0];
			scanf("%s",o);
			if(o[0]=='l'||o[0]=='s')
				a[i].n=2;
			else if(o[0]=='r'||o[0]=='t')
				a[i].n=3;
			else
				scanf("%d",&a[i].n);
			for(j=0;j<a[i].n;j++)
				scanf(" (%lf,%lf)",&a[i].p[j].x,&a[i].p[j].y);
			if(o[0]=='s')
				set_sq(a[i]);
			else if(o[0]=='r')
				set_rec(a[i]);
			a[i].m=0;
			i++;
		}
		if(i==0)
			break;
		n=i;
		sort(a,a+n,cmp);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(it(a[i],a[j]))
				{
					a[i].s[a[i].m++]=a[j].c;
					a[j].s[a[j].m++]=a[i].c;
				}
		for(i=0;i<n;i++)
		{
			printf("%c ",a[i].c);
			if(a[i].m)
			{
				printf("intersects with ");
				if(a[i].m==1)
					printf("%c\n",a[i].s[0]);
				else if(a[i].m==2)
					printf("%c and %c\n",a[i].s[0],a[i].s[1]);
				else
				{
					for(j=0;j<a[i].m-1;j++)
						printf("%c, ",a[i].s[j]);
					printf("and %c\n",a[i].s[j]);
				}
			}
			else
				printf("has no intersections\n");
		}
		printf("\n");
	}
	return 0;
}