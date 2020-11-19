#include<stdio.h>
#include<string.h>
int n,k,b,f,i,x,y;
int q[100020];
int w[100020];
int c[3]={1,1,2},d[3]={-1,1,0};
int main()
{
	while(scanf("%d %d",&n,&k)+1)
	{
		b=f=0;
		memset(w,0,sizeof(w));
		q[f++]=n;
		w[n]=1;
		if(n>=k)
			printf("%d\n",n-k);
		else
		{
			while(b<f)
			{
				x=q[b++];
				for(i=0;i<3;i++)
				{
					y=x*c[i]+d[i];
					if(y>=0&&y<=100000&&!w[y])
					{
						w[y]=w[x]+1;
						q[f++]=y;
						if(y==k)
							goto end;
					}
				}
			}
			end:
			printf("%d\n",w[k]-1);
		}
	}
	return 0;
}