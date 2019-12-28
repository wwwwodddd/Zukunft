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
			printf("%03d",a[i]);
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
			re.a[i+1]+=re.a[i]/1000;
			re.a[i]%=1000;
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
				re.a[i]+=1000;
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
			re.a[i+1]+=re.a[i]/1000;
			re.a[i]%=1000;
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
			re.a[i+1]+=re.a[i]/1000;
			re.a[i]%=1000;
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
			y=y*1000+a[i];
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
			a[++a[0]]=x%1000;
			x/=1000;
		}
	}
	bool operator==(Int b)
	{
		for(int i=0;i<=a[0];i++)
			if(a[i]!=b.a[i])
				return false;
		return true;
	}
};
Int f[105][105],n,ans;
int m,l,t;
char s[120];
Int pw(Int a,int z)
{
	if(z==0)
		return Int(1);
	return a*pw(a,z-1);
}
Int C(Int x,int y)
{
	Int re=1;
	for(int i=0;i<y;i++)
	{
		re=re*(x-i);
		re=re/(i+1);
	}
	return re;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %d",s,&m);
		l=strlen(s);
		n=0;
		memset(f,0,sizeof(f));
		for(int i=0;i<l;i++)
		{
			n=n*10;
			n=n+s[i]-'0';
		}
		for(int i=0;i<=m;i++)
			f[0][i]=pw(i,m);
		for(int i=1;i<=m;i++)
			for(int j=i;j<=m;j++)
				f[i][j]=f[i-1][j]-f[i-1][j-1];
		ans=0;
		for(int i=0;i<=m;i++)
			ans=ans+f[i][i]*C(n+1,i+1);
		ans.print();
	}
	return 0;
}
