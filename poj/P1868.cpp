#include<stdio.h>
int i,j,n,a[10005];
int main()
{
	while(scanf("%d",&n)&&n)
	{
		getchar();
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			a[j]=i;
		}
		for(i=0;i<n;i++)
			for(j=i+1;2*j-i<n;j++)
				if(a[2*j-i]>a[j]&&a[j]>a[i]||a[2*j-i]<a[j]&&a[j]<a[i])
					goto s;
		printf("yes\n");
		continue;
		s:
		printf("no\n");
	}
	return 0;
}