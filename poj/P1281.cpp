#include<iostream>
#include<set>
using namespace std;
int r[100020],a[100020];
int z,l,i,x,p,c;
int main()
{
	while(cin>>z>>l)
	{
		for(i=0;i<l;i++)
			cin>>a[i];
		char o;
		p=c=1;
		set<int>s;
		while(cin>>o,o!='e')
		{
			if(o=='a')
			{
				cin>>x;
				s.insert(x);
			}
			else if(o=='p')
				cin>>p;
			else if(o=='r')
			{
				if(p==1)
				{
					r[c++]=*s.begin();
					s.erase(s.begin());
				}
				else
				{
					r[c++]=*(--s.end());
					s.erase(--s.end());
				}
			}
		}
		for(i=0;i<l;i++)
			cout<<r[a[i]]<<endl;
		cout<<endl;
	}
	return 0;
}
