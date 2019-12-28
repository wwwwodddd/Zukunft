#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct In{
    int L;
    int W;
}S[20010];
int t,i,j,n,sum,res[20010];
bool cmp(In a,In b)
{
    if(a.L != b.L) return a.L < b.L;
    else return b.W < a.W;
}
int Sov()
{
    int T[20010],len=0,r,l,mid,j;
    memset(T,0,sizeof(T));
    for(int i=0;i<n;i++)
    {
        l=0;
        r=len;
        while(l<r)
        {
            mid=(l+r)/2;
            if(T[mid]>=S[i].W)
				l=mid+1;
            else r=mid;
        }
        if(len==l) len++;
			T[l]=S[i].W;
	/*	for(j=0;j<=len;j++)
			printf("%d ",T[j]);
		printf("\n");*/
    }
    return len;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&S[i].L,&S[i].W);
            res[i]=0;
        }
        sort(S,S+n,cmp);
        printf("%d\n",Sov()); 
    }            
    return 0;
}

/*
3

4
50 40
50 30
30 10
30 20

10
50 50
49 5
40 40
39 4
30 30
29 3
20 20
19 2
10 10
9 1

10
50 50
5 49
40 40
4 39
30 30
3 29
20 20
2 19
10 10
1 9

*/