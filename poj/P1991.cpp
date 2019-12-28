#include<iostream>
using namespace std;
int i,j,k,n,f,b,t,ans;
int l[1020][1020],r[1020][1020],v[1020];
int main()
{
	memset(l,0x3f,sizeof(l));
	memset(r,0x3f,sizeof(r));
	scanf("%d%d%d",&n,&f,&b);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&j,&t);
		v[j]=max(v[j],t);
	}
	while(b<f&&v[f]==0)
		f--;
	l[0][f]=0;
	for(i=0;i<=b;i++)
		for(j=f;j>=b;j--)
		{
			if(i>0)
				l[i][j]=max(l[i-1][j],v[i-1])+1;
			if(j<f)
				r[i][j]=max(r[i][j+1],v[j+1])+1;
			l[i][j]=min(l[i][j],r[i][j]+j-i);
			r[i][j]=min(r[i][j],l[i][j]+j-i);
		}
	ans=max(min(l[b][b],r[b][b]),v[b]);
	printf("%d\n",ans);
	return 0;
}

