#include<stdio.h>
#include<iostream>
#include<algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;
ii a[200020];
int f[200020][2];
int z,n,l,L,R;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].X),a[i].Y=i;
	sort(a+1,a+1+n);
	L=R=0x3f3f3f3f;
	for(int i=1,j;i<=n;i=j+1)
	{
		for(j=i;a[i].X==a[j].X&&j<=n;j++)
			;
		j--;
		f[j][0]=min(f[i-1][1],f[i-1][0]+(a[i].Y<R));
		f[j][1]=min(f[i-1][0]+1,f[i-1][1]+(L<a[j].Y));
		L=a[i].Y,R=a[j].Y;
	}
	printf("%d",min(f[n][0],f[n][1])+1);
	return 0;
}
