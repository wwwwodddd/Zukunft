#include<stdio.h>
#include<string.h>
int w,n,x;
int i,j,k,sum,max,am,cnt,csc;
int b[52][22];
int g[1020];
int h[1020];
int main()
{
	//freopen("C:\\c2.out","w",stdout);
	while(scanf("%d",&w)&&w)
	{
		am=cnt=0;
		memset(b,0,sizeof(b));
		for(j=0;j<w;j++)
		{
			sum=max=k=0;
			scanf("%d",&n);
			b[j][0]++;
			for(i=0;i<n;i++)
			{
				scanf("%d",&x);
				sum+=10-x;
				if(max<sum)
				{
					max=sum;
					b[j][0]=0;
					b[j][++b[j][0]]=i+1;
				}
				else if(max==sum)
					b[j][++b[j][0]]=i+1;
			}
			am+=max;
		}
		memset(h,0,sizeof(h));
		h[0]=1;
		for(i=0;i<w;i++)
		{
			memcpy(g,h,sizeof(h));
			memset(h,0,sizeof(h));
			for(j=1;j<=b[i][0];j++)
			{
				for(k=1010;k>=b[i][j];k--)
					if(g[k-b[i][j]])
						h[k]=1;
			}
		}
		printf("Workyards %d\n",++csc);
		printf("Maximum profit is %d.\n",am);
		printf("Number of pruls to buy:");
		for(i=0;i<1010&&cnt<10;i++)
			if(h[i])
			{
				cnt++;
				printf(" %d",i);
			}
		printf("\n\n");
	}
	return 0;
}