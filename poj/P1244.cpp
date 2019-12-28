#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#define N 20
using namespace std;
double eps=1E-8;
struct P{double x,y;P(){}P(double x0,double y0):x(x0),y(y0){}};
vector<P>v[100];
int n,i,j,l,u;
double x,y,a,b,c;
char s[10000];
int sgn(double x)
{
	return (x>eps)-(x<-eps);
}
double dis(P a,P b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
	while(scanf("%d",&n),n)
	{
		scanf("%s",s);
		u=l=0;
		for(i=0;i<26;i++)
			v[i].clear();
		for(i=1;i<=n;i++)
		{
			x=n-i;
			y=(n-i)*sqrt(3.0);
			for(j=0;j<i;j++,x+=2)
				v[s[l++]-'a'].push_back(P(x,y));
		}
		for(i=0;i<26;i++)
			if(v[i].size()==3)
			{
				a=dis(v[i][0],v[i][1]);
				b=dis(v[i][1],v[i][2]);
				c=dis(v[i][2],v[i][0]);
				if(!sgn(a-b)&&!sgn(b-c))
				{
					u=1;
					printf("%c",i+'a');
				}
			}
		if(!u)
			printf("LOOOOOOOOSER!");
		printf("\n");
	}
	return 0;
}