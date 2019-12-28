#include<string>
#include<iostream>
using namespace std;
class Int
{
private:
	int a[300];
public:
	Int(){memset(a,0,sizeof(a));}
	Int(int x)
	{
		memset(a,0,sizeof(a));
		*this=x;
	}
	~Int(){}
	void print()
	{
		printf("%d",a[a[0]]);
		for(int i=a[0]-1;i>0;i--)
			printf("%d",a[i]);
		printf("\n");
	}
	Int operator+(Int b)
	{
		Int re;
		int l=max(a[0],b.a[0]);
		for(int i=1;i<=l;i++)
			re.a[i]=a[i]+b.a[i];
		for(int i=1;i<=l;i++)
		{
			re.a[i+1]+=re.a[i]/10;
			re.a[i]%=10;
		}
		if(re.a[l+1])
			l++;
		re.a[0]=l;
		return re;
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
				re.a[i]+=10;
			}
		while(!re.a[l]&&l)
			l--;
		re.a[0]=l;
		return re;
	}
	Int operator*(Int b)
	{
		Int re;
		int l=a[0]+b.a[0];
		for(int i=1;i<=a[0];i++)
			for(int j=1;j<=b.a[0];j++)
				re.a[i+j-1]+=a[i]*b.a[j];
		for(int i=1;i<=l;i++)
		{
			re.a[i+1]+=re.a[i]/10;
			re.a[i]%=10;
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
			re.a[i+1]+=re.a[i]/10;
			re.a[i]%=10;
		}
		while(!re.a[l]&&l)
			l--;
		re.a[0]=l;
		return re;
	}
	Int operator/(int x)
	{
		Int re;
		int l=a[0],y=0;
		for(int i=a[0];i>0;i--)
		{
			y=y*10+a[i];
			re.a[i]=y/x;
			y%=x;
		}
		while(!re.a[l]&&l)
			l--;
		re.a[0]=l;
		return re;
	}
	void operator=(int x)
	{
		memset(a,0,sizeof(a));
		while(x!=0)
		{
			a[++a[0]]=x%10;
			x/=10;
		}
	}
	bool operator==(Int b)
	{
		for(int i=0;i<=a[0];i++)
			if(a[i]!=b.a[i])
				return false;
		return true;
	}
	bool operator>=(Int b)
	{
		if(a[0]>b.a[0])
			return true;
		if(a[0]<b.a[0])
			return false;
		for(int i=a[0];i>0;i--)
			if(a[i]>b.a[i])
				return true;
			else if(a[i]<b.a[i])
				return false;
		return true;
	}
};
Int f[600],x,y;
int m,l,t,ans;
char s[300];
int main()
{
	f[0]=1;
	f[1]=1;
	for(int i=2;i<600;i++)
		f[i]=f[i-1]+f[i-2];
	while(1)
	{
		x=0;
		y=0;
		ans=0;
		scanf("%s",s);
		l=strlen(s);
		for(int i=0;i<l;i++)
		{
			x=x*10;
			x=x+s[i]-'0';
		}
		scanf("%s",s);
		l=strlen(s);
		for(int i=0;i<l;i++)
		{
			y=y*10;
			y=y+s[i]-'0';
		}
		if(x==0&&y==0)
			break;
		for(int i=1;i<600;i++)
			if(f[i]>=x&&y>=f[i])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}