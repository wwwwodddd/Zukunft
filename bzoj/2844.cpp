#include<stdio.h>
#define BUFSIZE 10000000
char buf[BUFSIZE],*pt=buf;
#define scan(t)\
{\
	t=0;\
	while(*pt<'0'||*pt>'9')\
		 pt++;\
	while(*pt>='0'&&*pt<='9')\
		t=t*10+(*pt++)-'0';\
}
int n,x,mo=10086,v[40],q,w,z;
int main()
{
	fread(buf,1,BUFSIZE,stdin);
	scan(n);
	for(int i=0;i<n;i++)
	{
		scan(x);
		for(int i=30;~i;i--)
			if(x>>i&1)
				if(v[i])
					x^=v[i];
				else
				{
					v[i]=x;
					break;
				}
	}
	scan(w);
	for(int i=0;i<31;i++)
		for(int j=i-1;~j;j--)
			if(v[i]>>j&1)
				v[i]^=v[j];
	for(int i=0;i<31;i++)
		if(v[i])
			q++;
	for(int i=30,p=q;~i;i--)
	{
		if(v[i])
			p--;
		if(w>>i&1)
			w^=v[i],z+=1<<p;	
	}
	for(int i=0;i<n-q;i++)
		z=z*2%mo;
	printf("%d\n",(z+1)%mo);
	return 0;
}
