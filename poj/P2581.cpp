#include<stdio.h>
#include<math.h>
int a,b,c,d,e,u;
int i,j,k,l;
double f;
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	while(scanf("%lf%d%d%d%d",&f,&b,&c,&d,&e)+1)
	{
		a=int(f*100+0.5);
		u=a;
		i=min(a/25,b);
		a-=25*i;
		j=min(a/10,c);
		a-=10*j;
		k=min(a/5,d);
		a-=5*k;
		l=min(a,e);
		a-=l;
		if(a==0)
		{
			printf("%d %d %d %d\n",i,j,k,l);
			continue;
		}
		i=min(u/25,b)-1;
		u-=25*i;
		j=min(u/10,c);
		u-=10*j;
		k=min(u/5,d);
		u-=5*k;
		l=min(u,e);
		u-=l;
		if(u==0)
			printf("%d %d %d %d\n",i,j,k,l);
		else
			printf("NO EXACT CHANGE\n");
	}
	return 0;
}