#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int i,j;
int p[3][2];
char c[3][4];
int di[8][2]={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};
int arrive(int u,int v)
{
	int i,j,mx,mn;
	mx=v>p[1][1]?v:p[1][1];
	mn=v<p[1][1]?v:p[1][1];
	for(i=0;i<3;i++)
		if(p[i][0]==u&&p[i][1]==v)
			return 0;
	if(u==p[1][0])
	{
		if(p[0][0]==u&&p[0][1]>mn&&p[0][1]<mx)
		return 0;
		if(p[2][0]==u&&p[2][1]>mn&&p[2][1]<mx)
		return 0;
		return 1;
	}
	mx=u>p[1][0]?u:p[1][0];
	mn=u<p[1][0]?u:p[1][0];
	if(v==p[1][1])
	{
		if(p[0][1]==v&&p[0][0]>mn&&p[0][0]<mx)
			return 0;
		if(p[2][1]==v&&p[2][0]>mn&&p[2][0]<mx)
			return 0;
		return 1;
	}
	if(abs(u-p[1][0])==abs(v-p[1][1])) 
	{
		mx=v>p[1][1]?v:p[1][1];
		mn=v<p[1][1]?v:p[1][1];
		if(abs(u-p[0][0])==abs(v-p[0][1]))
			if(abs(p[0][0]-u)+abs(p[1][0]-p[0][0])==abs(p[1][0]-u))
				return 0;
		if(abs(u-p[2][0])==abs(v-p[2][1]))
			if(abs(p[2][0]-u)+abs(p[2][0]-p[1][0])==abs(p[1][0]-u))
				return 0;
		return 1;
	}
	return 0;
}
int decide(int u,int v)
{
	int i,x,y;
	if(!((u==p[2][0]||v==p[2][1]||abs(u-p[2][0])==abs(v-p[2][1]))||(abs(p[0][0]-p[2][0])<2&&abs(p[0][1]-p[2][1])<2)))
		return 0;
	for(i=0;i<8;i++)
	{
		x=p[2][0]+di[i][0];
		y=p[2][1]+di[i][1];
		if(x<=8&&x>0&&y<=8&&y>0)
		{
			if(x==u&&v==y)
				if(!(abs(p[0][0]-x)<2&&abs(p[0][1]-y)<2))
					return 0;
			if(!((abs(p[0][0]-x)<2&&abs(p[0][1]-y)<2)||x==u||y==v||abs(x-u)==abs(y-v)))
				return 0;
		}
	}
	return 1;
}
int main()
{
	while(scanf("%s%s%s",c[0],c[1],c[2])==3)
	{
		for(i=0;i<3;i++)
		{
			p[i][0]=c[i][0]-'a'+1;
			p[i][1]=c[i][1]-'0';
		}
		for(i=1;i<=8;i++)
			for(j=1;j<=8;j++)
				if(arrive(i,j)&&decide(i,j))
					goto end;
		printf("no\n");
		continue;
		end:;
		printf("%c%d\n",i+'a'-1,j);
	}
	return 0;
}