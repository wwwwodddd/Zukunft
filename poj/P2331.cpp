#include<stdio.h>
#include<string.h>
int f1[10020][5],f2[10020][5],q1,q2;
int x1,x2,y1,y2,k,i,j,m,n,u;
int l[5],c[5];
int now,ans=0x3fffffff;
int min(int x,int y)
{
	return x<y?x:y;
}
int abs(int x)
{
	return -x>x?-x:x;
}
int main()
{
	scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&k);
	for(i=0;i<k;i++)
		scanf("%d",&l[i]);
	for(i=0;i<k;i++)
		scanf("%d",&c[i]);
	for(i=-c[0];i<=c[0];i++)
		for(j=-c[1];j<=c[1];j++)
			for(m=-c[2];m<=c[2];m++)
				for(n=-c[3];n<=c[3];n++)
				{
					u=i*l[0]+j*l[1]+m*l[2]+n*l[3];
					if(u==abs(x1-x2))
					{
						f1[q1][0]=abs(i);
						f1[q1][1]=abs(j);
						f1[q1][2]=abs(m);
						f1[q1][3]=abs(n);
						f1[q1][4]=abs(i)+abs(j)+abs(m)+abs(n);
						q1++;
					}
					if(u==abs(y1-y2))
					{
						f2[q2][0]=abs(i);
						f2[q2][1]=abs(j);
						f2[q2][2]=abs(m);
						f2[q2][3]=abs(n);
						f2[q2][4]=abs(i)+abs(j)+abs(m)+abs(n);
						q2++;
					}
				}
	for(i=0;i<q1;i++)
		for(j=0;j<q2;j++)
		{
			if(f1[i][4]+f2[j][4]>=ans)
				continue;
			for(m=0;m<k;m++)
				if(f1[i][m]+f2[j][m]>c[m])
					goto end;
			ans=f1[i][4]+f2[j][4];
			end:;
		}
	printf("%d",ans>10000?-1:ans);
	return 0;
}