#include<stdio.h>
#include<string.h>
long long v[70],a[70],x,z;
int t,n,q,c,k;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		memset(v,0,sizeof v);
		printf("Case #%d:\n",++k);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%I64d",&x);
			for(int i=62;~i;i--)
				if(x>>i&1)
					if(v[i])
						x^=v[i];
					else
					{
						v[i]=x;
						break;
					}
		}
		for(int i=0;i<63;i++)
			for(int j=0;j<i;j++)
				if(v[i]>>j&1)
					v[i]^=v[j];
		for(int i=c=0;i<63;i++)
			if(v[i])
				a[c++]=v[i];
		for(scanf("%d",&q);q--;)
		{
			scanf("%I64d",&x);
			if(c<n)
				x--;
			if(x>>c>0)
				z=-1;
			else
			{
				for(int i=z=0;i<c;i++)
					if(x>>i&1)
						z^=a[i];
			}
			printf("%I64d\n",z);
		}
	}
	return 0;
}
