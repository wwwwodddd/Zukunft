#include<iostream>
#include<math.h>
#include<string>
#include<map>
using namespace std;
map<string,int>l,w;
map<string,int>::iterator it;
string ten="----------";
int i,n,v;
double ans;
string a,b;
int main()
{

	while(cin>>a,a!=ten)
	{
		b="";
		for(i=0;i<a.size();i++)
			if(isdigit(a[i])||islower(a[i]))
				b+=a[i];
			else if(isupper(a[i]))
				b+=tolower(a[i]);
		if(b!="")
			l[b]++;
	}
	v=0;
	while(cin>>a)
	{
		if(v==0&&a==ten)
		{
			v=1;
			ans=0.0;
			for(it=l.begin();it!=l.end();it++)
				ans+=sqrt((double)it->second*w[it->first]);
			printf("%.2lf\n",ans);
			w.clear();
		}
		else if(v==1&&a==ten)
			break;
		else
		{
			v=0;
			b="";
			for(i=0;i<a.size();i++)
				if(isdigit(a[i])||islower(a[i]))
					b+=a[i];
				else if(isupper(a[i]))
					b+=tolower(a[i]);
			if(l[b]>0)
			w[b]++;
		}
	}
	return 0;
}