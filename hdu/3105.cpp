#include<stdio.h>
int v[60],x,n;
int main()
{
	while(scanf("%d",&n),n)
	{
		for(x=1;x<50;x++)
			v[x]=1;
		for(n*=6;n--;)
			scanf("%d",&x),v[x]=0;
		for(x=1;x<50;x++)
			if(v[x])
				break;
		puts(x<50?"No":"Yes");
	}
	return 0;
}
