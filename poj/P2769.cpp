#include <stdio.h>
int v[1000020],vv;
int a[305],t,i,n;
int ok(int x)
{
	vv++;
	for(int i=0;i<n;i++)
		if(v[a[i]%x]==vv)
			return 0;
		else
			v[a[i]%x]=vv;
	return 1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=n;i<1000020;i++)
			if(ok(i))
				break;
		printf("%d\n",i);
	}
	return 0;
}