#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Point
{
	int x,y;
}p[55];
int cross(Point a, Point b, Point o)
{
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
int cmp(const void* a,const void* b)
{
	return -cross(*(Point*)a,*(Point*)b,p[0]);
}
int main()
{
	int n=0;
	while(scanf("%d%d",&p[n].x,&p[n].y)+1)
		n++;
	qsort(p+1,n-1,sizeof(*p),cmp);
	for(int i=0;i<n;i++)
		printf("(%d,%d)\n",p[i].x,p[i].y);
	return 0;
}
