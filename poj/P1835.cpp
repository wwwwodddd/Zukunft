#include<stdio.h>
#define swap(x,y) x^=y^=x^=y
int t,n,x,y,z,f,l,h,k,d[]={1,0,0,-1,0,0};
char s[9];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		x=y=z=f=0,l=1,h=2;
		for(scanf("%d",&n);n--;)
		{
			scanf("%s %d",s,&k);
			if(*s=='l')
				l=(l+3)%6,swap(f,l);
			else if(*s=='r')
				f=(f+3)%6,swap(f,l);
			else if(*s=='u')
				f=(f+3)%6,swap(f,h);
			else if(*s=='d')
				h=(h+3)%6,swap(f,h);
			else if(*s=='b')
				l=(l+3)%6,f=(f+3)%6;
			x+=d[f]*k,y+=d[(f+5)%6]*k,z+=d[(f+4)%6]*k;
		}
		printf("%d %d %d %d\n",x,y,z,f);
	}
}
