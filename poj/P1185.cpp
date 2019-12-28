#include<iostream>
using namespace std;
int f[103][61][61],g[103],s[61],a[61],n,m,i,j,k;
int F(int x,int y,int z)
{
	if(f[x][y][z]!=-1)
		return f[x][y][z];
	if(x==1)
		return f[x][y][z]=a[y];
	for(int i=0;i<k;i++)
		if(!(s[i]&(s[y]|s[z])||g[x-2]&s[i]))
			f[x][y][z]=max(f[x][y][z],F(x-1,z,i));
	f[x][y][z]+=a[y];
	return f[x][y][z];
}
char c[20];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",c);
		for(j=0;j<m;j++)
			if(c[j]=='H')
				g[i]+=1<<j;
	}
	memset(f,-1,sizeof(f));
	for(i=0;i<(1<<m);i++)
		if(!((i<<1)&i)&&!((i<<2)&i)&&!((i>>1)&i)&&!((i>>2)&i))
		{
			for(j=i;j;j-=j&-j)
				a[k]++;
			s[k++]=i;
		}
	printf("%d\n",F(n+2,0,0));
	return 0;
}