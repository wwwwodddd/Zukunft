#include<string>
#include<iostream>
using namespace std;
class Int
{
public:
	int a[300];
	Int(){memset(a,0,sizeof(a));}
	~Int(){}
	void print()
	{
		printf("%d",a[a[0]]);
		for(int i=a[0]-1;i>0;i--)
			printf("%08d",a[i]);
		printf("\n");
	}
	Int operator-(Int b)
	{
		Int re;
		int l=max(a[0],b.a[0]);
		for(int i=1;i<=l;i++)
			re.a[i]=a[i]-b.a[i];
		for(int i=1;i<=l;i++)
			if(re.a[i]<0)
			{
				re.a[i+1]--;
				re.a[i]+=100000000;
			}
		while(!re.a[l]&&l)
			l--;
		re.a[0]=l;
		return re;
	}
	Int operator*(int x)
	{
		Int re;
		int l=a[0]+5;
		for(int i=1;i<=a[0];i++)
			re.a[i]+=a[i]*x;
		for(int i=1;i<=l+5;i++)
		{
			re.a[i+1]+=re.a[i]/100000000;
			re.a[i]%=100000000;
		}
		while(!re.a[l]&&l)
			l--;
		re.a[0]=l;
		return re;
	}
};
Int f[105];
int i,n;
int main()
{
	f[1].a[0]=f[1].a[1]=1;
	for(i=2;i<=100;i++)
		f[i]=f[i-1]*3-f[i-2];
	while(scanf("%d",&n)+1)
		f[n].print();
	return 0;
}