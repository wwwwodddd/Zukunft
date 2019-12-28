#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<string>q;
stack<string>l;
string s,a;
int main()
{
q.push("Ignored");
q.push("http://www.acm.org/");
while(cin >> s)
{
if(s=="VISIT")
	{
	while(!l.empty())
		l.pop();
	cin >> a;
	q.push(a);
	}
else if(s=="BACK")
	{
		if(q.size()>2)
			{
			l.push(q.top());
			q.pop();
			}
		else
			{
			cout << "Ignored" <<endl;
			continue;
			}
	}
else if(s=="FORWARD")
	{
		if(!l.empty())
		{
		q.push(l.top());
		l.pop();
		}
		else
		{
		cout << "Ignored" <<endl;
		continue;
		}
	}
else if(s=="QUIT")
	break;
cout << q.top() <<endl;
}
return 0;
}