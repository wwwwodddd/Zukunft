#include<stdio.h>
#include<math.h>
double a[102][2];
double map[102][102];
double d[102];
int b[102];
int n,i,j;
double ans=0;
void prim(int st)
    {
    int next,i,j;
    double min;
    for(i=1;i<=n;i++)
        d[i]=2147483647.0;
    next=0;
    d[st]=0;
    for(i=1;i<=n;i++)
        {
        min=2147483646.0;
        for(j=1;j<=n;j++)
            if((!b[j])&&(d[j]<min))
                {
                next=j;
                min=d[j];
                }
        ans+=min;
        b[next]=1;
        for(j=1;j<=n;j++)
            if((!b[j])&&(d[j]>map[next][j]))
                d[j]=map[next][j];
        }
    }
int main()
    {
    double x,y,z;
	scanf("%d",&n);
    for(i=1;i<=n;i++)
		scanf("%lf %lf",&a[i][0],&a[i][1]);
	for(i=1;i<=n;i++)
        for(j=1;j<i;j++)
            if(i!=j)
            {
				x=a[i][0]-a[j][0];
				y=a[i][1]-a[j][1];
				map[i][j]=sqrt(x*x+y*y);
				map[j][i]=map[i][j];
            }
    prim(1);
    printf("%.2lf",ans);
    return 0;
    }