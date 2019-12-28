#include<iostream>
#include<math.h>
#include<string>
#include<map>
using namespace std;
map<string,int>t;
double v[31][31];
double r;
int i,j,k,n,m,z;
string x,y;
int main()
{
	while(scanf("%d",&n)&&n)
	{
		t.clear();
		memset(v,0,sizeof(v));
		for(i=1;i<=n;i++)
		{
			cin >> x;
			t[x]=i;
		}
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			cin >> x >> r >> y;
			v[t[x]][t[y]]=r;
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(v[i][j]<v[i][k]*v[k][j])
						v[i][j]=v[i][k]*v[k][j];
		int w=0;
		for(i=1;i<=n;i++)
			if(v[i][i]>1)
			{
				w=1;
				break;
			}
		printf("Case %d: %s\n",++z,w==1?"Yes":"NO");
	}
	return 0;
}