#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
struct A
{
	int hpl,hp;
	int x,y;
	int ld;
	int ag;
	int ck;
	int lv;
};
vector<A>ant;
int ac;
int tx[30],ty[30];
int dx[5]={0,1,0,-1,0};
int dy[5]={1,0,-1,0,0};
int n,m,s,d,r,t;
int ck;
int g[10][10];
int w[10][10];
double hp;
int iv(int x,int y)
{
	if(x>=0&&y>=0&&x<=n&&y<=m&&g[x][y]==0)
		return w[x][y];
	return -1;
}
int main()
{
	scanf("%d %d",&n,&m);
	scanf("%d %d %d",&s,&d,&r);
	fr(i,s)
	{
		scanf("%d %d",tx+i,ty+i);
		g[tx[i]][ty[i]]=1;
	}
	scanf("%d",&t);
	hp=4.4;
	int tim;
	for(tim=1;tim<=t;tim++)
	{
		if(ant.size()<6)
		{
			if(!g[0][0])
			{
		//		printf("new %lf\n",hp);
				ant.push_back((A){(int)hp,(int)hp,0,0,-1,0,0,ac/6+1});
				g[0][0]=1;
				ac++;
				if(ac%6==0)
					hp*=1.1;
			}
		}
		fe(i,ant)
		{
			if(i->ck)
				w[i->x][i->y]+=5;
			else
				w[i->x][i->y]+=2;
		}
		fe(i,ant)
		{
			int mx=-1,md=-1;
			g[i->x][i->y]=0;
			fr(k,4)
				if(k!=i->ld)
				{
					if(iv(i->x+dx[k],i->y+dy[k])>mx)
						mx=iv(i->x+dx[k],i->y+dy[k]),md=k;
				}
			if((i->ag+1)%5==0&&md!=-1)
			{
				do
					md=(md+3)%4;
				while(iv(i->x+dx[md],i->y+dy[md])<0||md==i->ld);
			}
			if(md!=-1)
			{
				i->x+=dx[md];
				i->y+=dy[md];
				i->ld=(md^2);
			}
			else
				i->ld=-1;
			g[i->x][i->y]=1;
		}
		if(!ck)
			fe(i,ant)
			{
				if(i->x==n&&i->y==m)
				{
				//	printf("%d %d caked!\n",tim,i-ant.begin());
					i->ck=1;
					ck=1;
					i->hp=min(i->hpl,i->hp+i->hpl/2);
				}
			}
		if(ck)
		{
			int px,py;
			fe(i,ant)
			{
				if(i->ck)
				{
					px=i->x;
					py=i->y;
				}
			}
			fr(i,s)
			{
				if((tx[i]-px)*(tx[i]-px)+(ty[i]-py)*(ty[i]-py)>r*r)
				{
					int mn=0x7fffffff,mr=0;
					fe(j,ant)
					{
						if((j->x-tx[i])*(j->x-tx[i])+(j->y-ty[i])*(j->y-ty[i])<mn)
						{
							mn=(j->x-tx[i])*(j->x-tx[i])+(j->y-ty[i])*(j->y-ty[i]);
							mr=(j-ant.begin());
						}
					}
					if(mn<=r*r)
					{
						ant[mr].hp-=d;
					//	printf("A %d:damage to %d  %d\n",tim,mr,ant[mr].hp);
					}
				}
				else
				{
					fe(j,ant)
					{
						int lt=(j->x-tx[i])*(j->x-tx[i])+(j->y-ty[i])*(j->y-ty[i]);
						int lp=(j->x-px)*(j->x-px)+(j->y-py)*(j->y-py);
						int pt=(px-tx[i])*(px-tx[i])+(py-ty[i])*(py-ty[i]);
						int s=(px-tx[i])*(j->y-py)-(py-ty[i])*(j->x-px);
						if(lt+pt<=lp||lp+pt<=lt)
						{
							if(min(lt,lp)*4<=1)
							{
					//			puts("---------------spread");
								j->hp-=d;
						//		printf("B %d:damage to %d  %d\n",tim,j-ant.begin(),j->hp);
							}
						}
						else
						{
							if(4*s*s<=pt)
							{
					//			puts("---------------spread");
								j->hp-=d;
							//	printf("C %d:damage to %d  %d\n",tim,j-ant.begin(),j->hp);
							}
						}
					}
				}
			}
		}
		else
		{
			fr(i,s)
			{
				int mn=0x7fffffff,mr=0;
				fe(j,ant)
				{
					if((j->x-tx[i])*(j->x-tx[i])+(j->y-ty[i])*(j->y-ty[i])<mn)
					{
						mn=(j->x-tx[i])*(j->x-tx[i])+(j->y-ty[i])*(j->y-ty[i]);
						mr=(j-ant.begin());
					}
				}
				if(mn<=r*r)
				{
					ant[mr].hp-=d;
			//		printf("D %d:damage to %d  %d\n",tim,mr,ant[mr].hp);
				}
			}
		}
		vector<int>del;
		fe(i,ant)
		{
			if(i->hp<0)
			{
				if(i->ck)
					ck=0;
				g[i->x][i->y]=0;
				del.push_back(i-ant.begin());
			}
		}
		sort(del.begin(),del.end(),greater<int>());
		fe(i,del)
		{
		//	printf("del %d\n",*i);
			ant.erase(ant.begin()+*i);
		}
		fe(i,ant)
		{
			if(i->x==0&&i->y==0&&i->ck)
			{
				goto end;
			}
		}
		fr(i,n+1)
			fr(j,m+1)
				w[i][j]=max(w[i][j]-1,0);
		fe(i,ant)
			i->ag++;
		if(tim<120)
			continue;
	/*	printf("time %d::.\n",tim);
		printf("%d\n",ant.size());
		fe(i,ant)
		{
			printf("%d %d %d %d %d %d %d\n",i->ag,i->lv,i->hp,i->x,i->y,i->ld,i->ck);
		}
/*		fr(i,n+1)
		{
			fr(j,m+1)
				printf("%d ",w[i][j]);
			puts("");
		}
		printf("ck::%d\n",ck);*/
	//	printf("ended.\n");
	}
	end:
	if(tim>t)
	{
		puts("The game is going on");
	}
	else
	{
		printf("Game over after %d seconds\n",tim);	
	}
	printf("%d\n",ant.size());
	fe(i,ant)
	{
		printf("%d %d %d %d %d\n",i->ag,i->lv,i->hp,i->x,i->y);
	}
	return 0;
}
