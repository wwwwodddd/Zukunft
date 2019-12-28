#include<iostream>
using namespace std;
int n,x,z,i,f,g;
char v[20],a,b,c;
int ret(char a)
{
	if(a=='A')
		return 11;
	if(a>'A')
		return 10;
	return a-48;
}
int gt(char a)
{
	if(a=='A')
		return 14;
	if(a=='T')
		return 10;
	if(a=='K')
		return 13;
	if(a=='Q')
		return 12;
	if(a=='J')
		return 11;
	return a-48;
}
int main()
{

	while(cin>>n&&n)
	{
		memset(v,0,sizeof(v));
		cin>>c>>a>>b;
		if(a=='A'&&b=='A')
			f=12;
		else
			f=ret(a)+ret(b);
		g=ret(c);
		for(i=2;i<=10;i++)
			if(g+i<f)
				v[i]=1;
		for(i=11;i<=13;i++)
			if(g+10<f)
				v[i]=1;
		if(g<11&&g+11<f||g==11&&g+1<f)
			v[14]=1;
		x=0;
		z=52*n-3;
		for(i=2;i<15;i++)
			if(v[i])
				x+=4;
		x*=n;
		x-=v[gt(a)]+v[gt(b)]+v[gt(c)];
		printf("%0.3lf%%\n\n",x*100.0/z);
	}
	return 0;
}