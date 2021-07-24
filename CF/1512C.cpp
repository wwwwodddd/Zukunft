#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,n;
        cin>>a>>b;
        n=a+b;
        string s;
        cin>>s;
        for(int i=0; i<n; i++){
            if(s[i]=='?')s[i]=s[n-i-1];
        }
        a-=count(s.begin(),s.end(),'0');
        b-=count(s.begin(),s.end(),'1');
        for(int i=0;i<=n/2;i++){
            if(i!=n-i-1&&s[i]=='?'){
             if(a>1)s[i]=s[n-i-1]='0', a-=2;
                else if(b>1)s[i]=s[n-i-1]='1', b-=2;
            }
            else if(s[i]=='?'){
                if(a)s[i]='0',a--;
                else s[i]='1',b--;
            }
        }
        string v=s;
        reverse(v.begin(),v.end());
        if(v==s&&a==0&&b==0)cout<<s<<'\n';
        else cout<<"-1\n";
    }
    return 0;
}
