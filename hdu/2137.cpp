#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>a;
int b[1020];
int main()
{
    int t,n,k;
    for(cin>>t;t--;)
    {
        a.clear();
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>b[i];
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                a.push_back(abs(b[i]-b[j]));
        sort(a.begin(),a.end());
        unique(a.begin(),a.end());
        cout<<a[k-1]<<endl;
    }    
}
