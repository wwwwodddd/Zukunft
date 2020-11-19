#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int ed=01237654;
char d[16777220];
int q[50000],bb,ff;
inline int A(int z)
{
	return ((z&(00007777))<<12)|(z>>12);
}
inline int B(int z)
{
	return ((z&(077707770))>>3)|((z&(00070007))<<9);
}
inline int C(int z)
{
	int re=z&(070077007);
	re|=(z&(07000000))>>3;
	re|=(z&(00000070))<<3;
	re|=(z&(00700000))>>12;
	re|=(z&(00000700))<<12;
	return re;
}
int main()
{
	int i,st=0,x,z,a,b,c;
	/*for(i=0;i<4;i++)
	{
		scanf("%d",&z);
		st=(st<<3)+z-1;
	}
	st<<=12;
	for(i=0;i<4;i++)
	{
		scanf("%d",&z);
		st|=((z-1)<<(3*i));
	}*/
	if(st==ed)
	{
		puts("0");
		return 0;
	}
	d[ed]=0;
	q[ff++]=ed;
	while(bb<ff)
	{
		x=q[bb++];
		a=A(x);
		b=B(x);
		c=C(x);
		if(d[a]==0)
			d[a]=d[x]+1,q[ff++]=a;
		if(d[b]==0)
			d[b]=d[x]+1,q[ff++]=b;
		if(d[c]==0)
			d[c]=d[x]+1,q[ff++]=c;
		if(a==st||b==st||c==st)
			break;
	}
	printf("%d",d[st]);
	return 0;
}