#include<stdio.h>
int p[1020],i,n,a[12],z=1,o,x,y;
int main()
{
	for(;~scanf("%d",p+n);)
		n++;
	for(;p[i]!=100;i++)
	{
		z++;
		o=p[i]/100;
		x=p[i]/10%10;
		y=p[i]%10;
		if(o==2)
			a[x]=y;
		else if(o==3)
			a[x]=(a[x]+y)%1000;
		else if(o==4)
			a[x]=a[x]*y%1000;
		else if(o==5)
			a[x]=a[y];
		else if(o==6)
			a[x]=(a[x]+a[y])%1000;
		else if(o==7)
			a[x]=a[x]*a[y]%1000;
		else if(o==8)
			a[x]=p[a[y]];
		else if(o==9)
			p[a[y]]=a[x];
		else if(o==0)
			if(a[y])
				i=a[x]-1;
	}
	printf("%d\n",z);
}
