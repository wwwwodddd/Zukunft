#include<stdio.h>
int s[520][520],n,m,v,a,b,sm;
int ok(int l,int r,int v)
{
	int _=0,w=0;
	for(int i=1;i<=m;i++)
	{
		w+=s[r][i]-s[l][i];
		if(w>=v)
		{
			w=0;
			_++;
		}
	}
	return _>=b; 
}
int ok(int v)
{
	int _=0,l=0,r=1;
	while(_<a)
	{
		while(!ok(l,r,v))
		{
			r++;
			if(r>n)
				return 0;
		}
		_++;
		l=r;
	}
	return 1;
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&a,&b);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",s[i]+j),sm+=s[i][j],s[i][j]+=s[i-1][j];
	int l=0,r=sm/a/b+1;
	while(l<r-1)
	{
		v=l+r>>1;
		if(ok(v))
			l=v;
		else
			r=v;
	}
	printf("%d\n",l);
	return 0;
}
