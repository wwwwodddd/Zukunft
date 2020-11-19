#include<stdio.h>
int n,m,x,s;
int a[420];
int b[420];
int check()
{
	for(int i=0;i<n;i++)
		if(a[i]>1)
		{
			int j;
			for(j=0;j<n;j++)
				b[j]=a[j];
			b[i]-=2;
			for(j=0;j<n;j++)
			{
				b[j]%=3;
				if(b[j+1]<b[j]||b[j+2]<b[j])
					break;
				b[j+1]-=b[j];
				b[j+2]-=b[j];
			}
			if(j==n)
				return 1;
		}
	return 0;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m*3+1;i++)
	{
		scanf("%d",&x);
		a[--x]++;
	}
	for(int i=0;i<n;i++)
	{
		a[i]++;
		if(check())
			s++,printf("%d ",i+1);
		a[i]--;
	}
	if(!s)
		puts("NO");
	return 0;
}