#include<stdio.h>
#include<iostream>
#include<map>
#include<list>
#include<string>
using namespace std;
struct N
{
	string s;
	N *f;
	list<N*>a;
}t[6020];
map<string,N*>m;
void print(N *x,int y)
{
	cout << string(y,'+') << x->s << endl;
	for(list<N*>::iterator i=x->a.begin();i!=x->a.end();i++)
		print(*i,y+1);
}
int main()
{
	string s1,s2;
	cin>>s1;
	m[s1]=t;
	t[0].s=s1;
	while(cin>>s1)
	{
		if(s1=="print")
		{
			print(t,0);
			puts("------------------------------------------------------------");
		}
		else if(s1!="fire")
		{
			cin>>s2>>s2;
			N *x=m[s1];
			N *y=t+m.size();
			y->s=s2;
			y->f=x;
			x->a.push_back(y);
			m[s2]=y;
		}
		else
		{
			cin>>s2;
			N *x=m[s2];
			while(x->a.size())
			{
				x->s=x->a.front()->s;
				m[x->s]=x;
				x=x->a.front();
			}
			x->f->a.remove(x);
		}
	}
	return 0;
}
