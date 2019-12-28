#include<iostream>
#include<queue>
using namespace std;
const int MAX=1005;
const int inf=2147483647;
int m[310][310];
int t[310][310];
int d[310][310];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int i,j,w,ans,x,r;
int l,n,p;
int ex,ey,q,nx,ny,nd;
char c;
struct node
{
	int x,y,d;
	bool operator < (const node &a) const
	{
		return a.d<d;
	}
};
node a,b;
priority_queue<node>que;
void in(int fx,int fy,int fd)
{
if(fx>=0&&fy>=0&&fx<l&&fy<n)
		if(m[fx][fy]!=999&&d[fx][fy]>fd+1+m[fx][fy])
			{
				d[fx][fy]=fd+1+m[fx][fy];
				if(t[fx][fy]!=p)
					{
					a.x=fx;
					a.y=fy;
					a.d=fd+1+m[fx][fy];
					que.push(a);
					t[fx][fy]=p;
					}
				if(fx==ex&&fy==ey)
						{
						printf("%d\n",fd+1);
						r=1;
						}
			}
			
return;
}
int main()
{
while(scanf("%d %d",&l,&n)&&n!=0&&l!=0)
	{
	p++;
	ans=2147483647;
	memset(t,0,sizeof(t));
	while(!que.empty())
		que.pop();
	getchar();
	x=1;
	r=0;
	for(i=0;i<l;i++)
		for(j=0;j<n;j++)
			d[i][j]=999;	
	for(i=0;i<l;i++)
		{
		for(j=0;j<n;j++)
			{
			scanf("%c",&c);
			if(c=='S'||c=='R')
				m[i][j]=999;
			else if(c=='E')
				m[i][j]=0;
			else if(c=='B')
				m[i][j]=1;
			else if(c=='T')
				{
				m[i][j]=x++;
				ex=i;
				ey=j;
				}
			else if(c=='Y')
				{
				m[i][j]=0;
				a.x=i;
				a.y=j;
				a.d=0;
				que.push(a);
				t[i][j]=p;
				d[i][j]=0;
				}
			}
		getchar();
		}
	while(!que.empty())
		{
		a=que.top();
		que.pop();
		nx=a.x;
		ny=a.y;
		nd=a.d;
		t[nx][ny]=0;
		for(i=0;i<4;i++)
			{
			in(nx+dx[i],ny+dy[i],nd);
			if(r==1)
				goto end;
			}
		}
	printf("-1\n");
	end:;
	}
return 0;
}
