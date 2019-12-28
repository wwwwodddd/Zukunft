#include<stdio.h>
#include<math.h>
int v[100020];
int m,a,b,x;
int i,j,k;
int main()
{
	for(i=2;i<100000;i++)
		v[i]=1;
	for(i=2;i*i<100000;i++)
		if(v[i])
			for(j=i*i;j<100000;j+=i)
				v[j]=0;
	while(scanf("%d%d%d",&m,&a,&b)&&m)
	{
		for(;m;m--)
		{
			x=a*m/b;
			i=(int)sqrt((double)x);
			j=(int)sqrt((double)m);
			if(i*i!=m)
				i+=1;
			for(k=i;k<=j;k++)
				if(m%k==0&&v[k]&&v[m/k])
				{
					printf("%d %d\n",k,m/k);
					goto end;
				}
			}
		end:;
	}
	return 0;
}