#include<stdio.h>
#include<queue>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
#define ef(i,n) for(__typeof(n.rbegin()) i=n.rbegin();i!=n.rend();i++)
typedef pair<int,int> ii;
deque<vector<ii> >z;
vector<ii>a;
int n,x,y;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&x,&y),a.push_back(ii(x,y));
	sort(a.begin(),a.end());
	ef(i,a)
	{
		if(z.empty()||z.front().back().Y>=i->Y)
			z.push_front(vector<ii>(1,*i));
		else
		{
			int l=0,r=z.size()-1,m;
			while(l<r)
			{
				m=l+r+1>>1;
				if(z[m].back().Y>=i->Y)
					r=m-1;
				else
					l=m;
			}
			z[l].push_back(*i);
		}
	}
	ef(i,z)
	{
		printf("%d:",i->size());
		ef(j,(*i))
			printf(" (%d,%d)",j->X,j->Y);
		puts("");
	}
	return 0;
}
