#include<stdio.h>
#include<map>
#define X first
#define Y second
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
map<int,int>g,h;
int gi()
{
	int r=0;
	char c;
	while(!((c=getchar())>='0'&&c<='9'))
		;
	r=c-'0';
	while((c=getchar())>='0'&&c<='9')
		r=r*10+c-'0';
	return r;
}
int a[20][20],b[20][20]; 
void ud(int x,int y)
{
	if(!h.count(x)||y<h[x])
		h[x]=y;
}
int n,m,t;
int main()
{
	for(t=gi();t--;)
	{
		n=gi(),m=gi();;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m-1;j++)
				a[i][j]=gi();
			if(i<n-1)
				for(int j=0;j<m;j++)
					b[i][j]=gi();
		}
		g.clear();
		g[0]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				fe(k,g)
				{
					int l=k->X>>j*2&3;
					int u=k->X>>j*2+2&3;
					int o=k->X&~(15<<j*2);
					if(l==0&&u==0)
					{
						if(i<n-1&&j<m-1)
							ud(o|9<<j*2,k->Y+a[i][j]+b[i][j]);
					}
					else if(l==0||u==0)
					{
						if(j<m-1)
							ud(o|(u|l)<<j*2+2,k->Y+a[i][j]);
						if(i<n-1)
							ud(o|(u|l)<<j*2,k->Y+b[i][j]);
					}
					else if(l==2&&u==1)
						ud(o,k->Y);
					else if(l==1&&u==1)
					{
						for(int p=j+2,t=0;p<=m;p++)
							if((k->X>>p*2&3)==1)
								t++;
							else if((k->X>>p*2&3)==2)
							{
								if(t==0)
								{
									ud(o^3<<p*2,k->Y);
									break;
								}
								t--;
							}
					}
					else if(l==2&&u==2)
					{
						for(int p=j-1,t=0;p>=0;p--)
							if((k->X>>p*2&3)==2)
								t++;
							else if((k->X>>p*2&3)==1)
							{
								if(t==0)
								{
									ud(o^3<<p*2,k->Y);
									break;
								}
								t--;
							}
					}
					else if(l==1&&u==2)
					{
						if(i==n-1&&j==m-1)
							ud(o,k->Y);
					}
				}
				g.swap(h);
				h.clear();
			}
			fe(k,g)
				h[k->X<<2]=k->Y;
			g.swap(h);
			h.clear();
		}
		printf("%d\n",g[0]);
	}
	return 0;
}
