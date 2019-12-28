#include<iostream>
#include<algorithm>
using namespace std;
long long f[1020][1020][2],d[1020];
int n,v,i,j;
int ab(int x)
{
	return x>0?x:-x;
}
int main()
{
	scanf("%d %d",&n,&v);
	for(i=1;i<=n;i++)
		scanf("%d",&d[i]);
	sort(d+1,d+n+1);
	memset(f,0x3f,sizeof(f));
	for(i=1;i<=n;i++)
		f[i][i][0]=f[i][i][1]=ab(v-d[i])*n;
	for(j=1;j<=n;j++)
		for(i=j-1;i>0;i--)
		{
			f[i][j][0]=min(f[i+1][j][0]+(n-j+i)*(d[i+1]-d[i]),f[i+1][j][1]+(n-j+i)*(d[j]-d[i]));
			f[i][j][1]=min(f[i][j-1][0]+(n-j+i)*(d[j]-d[i]),f[i][j-1][1]+(n-j+i)*(d[j]-d[j-1]));
		}
	printf("%I64d",min(f[1][n][0],f[1][n][1]));
	return 0;
}