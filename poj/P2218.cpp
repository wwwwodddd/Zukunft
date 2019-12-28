#include<iostream>
#include<string>
using namespace std;
struct N
{
	string s;
	int w,t;
}a[1000];
int cmp(const void *a,const void *b)
{
	return ((N*)b)->w-((N*)a)->w;
}
string s;
int i,k;
int main()
{
	while(cin>>s)
	{
		k=0;
		while(cin>>s)
		{
			if(s=="END")
				break;
			a[k].s=s;
			cin>>a[k].t>>a[k].w;
			a[k].w=max(a[k].w-a[k].t,0);
			k++;
		}
		qsort(a,k,sizeof(N),cmp);
		for(i=0;i<k;i++)
			cout<<a[i].s<<endl;
		cout<<endl;
	}
	return 0;
}
