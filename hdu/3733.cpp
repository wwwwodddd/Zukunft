#include<stdio.h>
int main(){
puts("Please submit me, then you will get AC :-)");
puts("The key is RobaHouGong3000DuoWanOrz");
return 0;
}
/*

This is the program to play with this.
The key to the problem is "#include".
When you try this,you will find this length is some times of 8.
Tricky: plz delete the enter of the source.


#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int a[30000];
int b[30000];
int n,l;
//char s[30000]={"#include <stdio.h>\nint main() {\n    int n = 10;\n"};
char s[30000]={"#include <stdio.h>\nint m"};
FILE *in=fopen("c.in","r");
int main()
{
	while(~fscanf(in,"%2x",a+n))
		n++;
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	puts("");
	l=strlen(s);	
	for(int i=0;i<l;i++)
		printf("%d\n",b[i]=(a[i]^s[i]));
	while(1)
	{
//		cin>>l;
//		for(int i=0;i<l;i++)
//			cin>>b[i];
		for(int i=0;i<n;i++)
			printf("%c",a[i]^b[i%l]);
//		for(int i=0;i<30;i++)
//			printf("%d %c\n",i,a[i]^b[i%l]);
		while(1);
	}
}


*/
