#include<stdio.h>
struct N{int w,x,y,z;}a[5000];
int n,i,j,ans;
int main()
{
	while(scanf("%d",&n)+1)
	{
		ans=0;
		for(i=0;i<n;i++)
			scanf("%d %d %d %d",&a[i].w,&a[i].x,&a[i].y,&a[i].z);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(i!=j&&a[i].w>=a[j].w&&a[i].x<=a[j].x&&a[i].y>=a[j].y&&a[i].z<=a[j].z)
				{
					ans++;
					break;
				}
		printf("%d\n",ans);
	}
	return 0;
}