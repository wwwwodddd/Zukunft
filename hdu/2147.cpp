#include<stdio.h>
#include<bitset>
std::bitset<2048>f[2001];
int n,m;
int main()
{
	for(int i=1;i<=2000;i++)
		for(int j=1;j<=2000;j++)
			if(!(f[i-1][j]||f[i][j-1]||f[i-1][j-1]))
				f[i][j]=1;
	while(scanf("%d %d",&n,&m),n+m)
		puts(f[n][m]?"What a pity!":"Wonderful!");
	return 0;
}
