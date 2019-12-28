#include<stdio.h>
#include<string.h>
char s[300];
int d[4][2]={{10,0},{0,-10},{-10,0},{0,10}};
int work()
{
	int i;
	int n=strlen(s);
	int z=0;
	int x=300;
	int y=420;
	printf("%d %d moveto\n",x,y);
	x+=10;
	printf("%d %d lineto\n",x,y);
	for(i=0;i<n;i++)
	{
		if(s[i]=='A')
			z=(z+1)%4;
		else if(s[i]=='V')
			z=(z+3)%4;
		x+=d[z][0];
		y+=d[z][1];
		printf("%d %d lineto\n",x,y); 
	}
	printf("stroke\nshowpage\n"); 
	return 0; 
}
int main() 
{
	while(scanf("%s",s)+1)
		work();
	return 0;
}
