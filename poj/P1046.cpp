#include<stdio.h>
int a[20][3];
int i,j,k;
int x,y,z,d,f;
int dis()
{
return (a[i][0]-x)*(a[i][0]-x)+(a[i][1]-y)*(a[i][1]-y)+(a[i][2]-z)*(a[i][2]-z);
}
int main()
{
for(i=0;i<16;i++)
	scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
while(scanf("%d %d %d",&x,&y,&z)&&x!=-1&&y!=-1&&z!=-1)
	{
	d=2147483647;
	for(i=0;i<16;i++)
		if(dis()<d)
			d=dis(),f=i;
	printf("(%d,%d,%d) maps to (%d,%d,%d)\n",x,y,z,a[f][0],a[f][1],a[f][2]);
	}
return 0;
}