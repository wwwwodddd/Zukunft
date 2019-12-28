#include<stdio.h>
#include<string.h>
#include<math.h>
int n,x,y,t,lc,ls,d;
int r[300];
char s[300],p[300],c[300],m[300];
int main()
{
	while(scanf("%d",&n),n)
	{
		scanf("%s %s %s",s,p,c);
		ls=strlen(s);
		for(int i=0;i<ls;i++)
			r[s[i]]=i;
		lc=strlen(c);
		d=(int)(pow(lc,1.5)+n)%lc;
		m[d]=p[r[c[d]]];
		for(int i=lc+d-1;i>d;i--)
		{
			t=i%lc;
			x=r[c[t]];
			y=r[m[(i+1)%lc]];
			m[t]=p[x^y];
		}
		m[lc]=0;
		puts(m);
	}
}
