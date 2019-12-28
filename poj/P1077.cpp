#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
int f[10];
int p[400000];
char d[400000];
void F()
{
	f[0]=1;
	for(int i=1;i<=9;i++)
		f[i]=f[i-1]*i;
}
long H(int s[])
{
	int i,j,t;
	long num=0;
	for(i=0;i<9-1;i++)
	{
		t=0;
		for(j=i+1;j<9;j++)
			if(s[j]<s[i]) ++t;
		num+=f[9-i-1]*t;
	}
	return num;
}
void AH(int s[],int ct)
{
	int i,j,t,r;
	bool p[10]={0};
	for(i=0;i<9;i++)
	{
		t=ct/f[9-i-1]+1;
		ct%=f[9-i-1];
		r=0,j=1;
		while(1)
		{
			if(!p[j])
				r++;
			if(r==t)
				break;
			j++;
		}
		s[i]=j;
		p[j]=1;
	}
}
int main()
{
	F();
	int tc[9];
	char c[2];
	int ot,t,i;
	bool ok=0;
	for(i=0;i<9;i++)
	{
		scanf("%s",c);
		if(c[0]=='x')
			tc[i]=9;
		else
			tc[i]=c[0]-'0';
	}
	memset(p,0,sizeof(p));
	queue<int> q;
	t=H(tc);
	p[t]=-1;
	q.push(t);
	while(!q.empty())
	{
		ot=q.front();
		q.pop();
		if(ot==0)
		{
			ok=1;
			break;
		}
		AH(tc,ot);
		for(i=0;i<9;i++)
			if(tc[i]==9)
				break;
		if(i!=0&&i!=1&&i!=2)
		{
			swap(tc[i],tc[i-3]);
			t=H(tc);
			if(!p[t])
			{
				p[t]=ot;
				d[t]='u';
				q.push(t);
			}
			swap(tc[i],tc[i-3]);
		}
		if(i!=6&&i!=7&&i!=8)
		{
			swap(tc[i],tc[i+3]);
			t=H(tc);
			if(!p[t])
			{
				p[t]=ot;
				d[t]='d';
				q.push(t);
			}
			swap(tc[i],tc[i+3]);
		}
		if(i!=0&&i!=3&&i!=6)
		{
			swap(tc[i],tc[i-1]);
			t=H(tc);
			if(!p[t])
			{
				p[t]=ot;
				d[t]='l';
				q.push(t);
			}
			swap(tc[i],tc[i-1]);
		}
		if(i!=2&&i!=5&&i!=8)
		{
			swap(tc[i],tc[i+1]);
			t=H(tc);
			if(!p[t])
			{
				p[t]=ot;
				d[t]='r';
				q.push(t);
			}
			swap(tc[i],tc[i+1]);
		}
	}
	if(ok)
	{
		stack<char>s;
		while(p[ot]!=-1)
		{
			s.push(d[ot]);
			ot=p[ot];
		}
		while(!s.empty())
		{
			printf("%c",s.top());
			s.pop();
		}
	}
	else
		printf("unsolvable");
	return 0;
}