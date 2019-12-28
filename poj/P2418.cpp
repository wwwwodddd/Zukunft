#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
string a[10020];
int cmp(const void *a,const void *b)
{
return *(string*)a>*(string*)b?1:-1;
}
int main()
{
	int i=0,j=0,k=1;
	while(cin >> a[i])
		i++;
	qsort(a,i,sizeof(string),cmp);
	for(j=0;j<i;j++)
		{
		if(a[j]==a[j+1])
			{
			k++;
//			cout << a[j] << ' ' << a[j+1] << ' ' << j << ' ' << j+1 << ' ' << k << ' ' << i <<endl;
//			printf("%s %s %d %d %d %d\n",a[j],a[j+1],j,j+1,k,i);	
			}
		else
			{
			cout << a[j];
			printf(" %.4lf\n",1.0*k/(i-1));
			k=1;
			}
//			printf("%s %.4lf\n",a[j],1.0*k/(i-1)),k=1;
		}
	return 0;
}
