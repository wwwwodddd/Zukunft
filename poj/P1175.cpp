#include<stdio.h>
#include<math.h>
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={-1,-1,0,1,1,1,0,-1};
char c[105][105];
int m,n,f,b,l;
int s[161][2];
double t[27];
void F(char v)
{
	for(int i=0;i<b;i++)
		c[s[i][0]][s[i][1]]=v;
	return;
}
void bfs(int x,int y)
{
	int x1,y1;
	int i,j;
	double sum=0;
	f=b=0;
	s[b][0]=x;
	s[b][1]=y;
	b++;
	c[x][y]='0';
	while(f!=b)
	{
		x1=s[f][0];
		y1=s[f][1];
		f++;
		for(i=0;i<8;i++)
			if(c[x1+dx[i]][y1+dy[i]]=='1')
			{
				s[b][0]=x1+dx[i];
				s[b][1]=y1+dy[i];
				b++;
				c[x1+dx[i]][y1+dy[i]]='0';
			}
	}
	for(i=0;i<b;i++)
		for(j=i+1;j<b;j++)
		{
			x1=s[i][0]-s[j][0];
			y1=s[i][1]-s[j][1];
			sum+=sqrt(1.0*(x1*x1+y1*y1));
		}
	for(i=0;i<l;i++)
		if(fabs(sum-t[i])<0.00000001)
		{
			F('a'+i);
				break;
		}
	if(i==l)
	{
		F('a'+l);
		t[l++]=sum;
	}
	return;
}
int main()
{
	int i, j;
	scanf("%d %d",&m,&n);
	for(i=1;i<=n;i++)
		scanf("%s",c[i]+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(c[i][j]=='1')
				bfs(i,j);
	for(i=1;i<=n;i++)
		printf("%s\n",c[i]+1);
	return 0;
}
