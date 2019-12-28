#include<stdio.h>
char p[64][64][64];
int i,j,x,y,z,n,ans=5;
char s[16];
struct node{int x,y,z;}a[25032];
int main()
{
	scanf("%d",&n);
	a[1].x=a[1].y=32;
	a[1].z=0;
	p[32][32][0]=1;
	for(i=2;i<=n;i++)
	{
		scanf("%d %s",&j,s);
		x=a[j].x;
		y=a[j].y;
		z=a[j].z;
		if(s[0]=='L')
			x--;
		if(s[0]=='R')
			x++;
		if(s[0]=='F')
			y--;
		if(s[0]=='B')
			y++;
		if(s[0]=='U')
			z--;
		if(s[0]=='O')
			z++;
		if(z<0||p[x][y][z])
			break;
		a[i].x=x;
		a[i].y=y;
		a[i].z=z;
		p[x][y][z]=1;
		ans+=6;
		if(p[x-1][y][z])
			ans-=2;
		if(p[x+1][y][z])
			ans-=2;
		if(p[x][y-1][z])
			ans-=2;
		if(p[x][y+1][z])
			ans-=2;
		if(!z)
			ans--;
		else if(p[x][y][z-1])
			ans-=2;
		if(p[x][y][z+1])
			ans-=2;
	}
	printf("%d\n",i<=n?-1:ans);
	return 0;
}
