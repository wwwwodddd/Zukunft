#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll>LL;
typedef pair<int,int>ii;
map<ll, ll>pp;
ll p;
ll mul(ll x,ll y) {
	return x*y-(long long)((long double)x*y/p)*p;
}
LL operator*(const LL&a,const LL&b)
{
	return ii((mul(a.X,b.X)+mul(a.Y,b.Y))%p,(mul(a.X,b.Y)+mul(a.Y,(b.X-b.Y+p)))%p);
}
pair<LL,int>l[1000020];
int lc;
LL F(ll n)
{
	if(n==0)
		return LL(0,1);
	else if(n&1)
	{
		LL u=F(n-1);
		return LL(u.Y,(u.X+u.Y)%p);
	}
	else
	{
		LL u=F(n/2);
		return LL(mul((2*u.Y+p-u.X),u.X),(mul(u.X,u.X)+mul(u.Y,u.Y))%p);
	}
}
ll P(ll p) {
	if (p % 10 == 1 || p % 10 == 9) {
		return p - 1;
	}
	if (pp.find(p) != pp.end()) {
		return pp[p];
	}
	::p=p;
	lc=0;
	LL u(1,1),w(1,0);
	int x=int(sqrt(2*p))+1;
	for(int i=0;i<x;i++) {
		l[lc++] = make_pair(w, -i);
		w=w*u;
	}
	sort(l,l+lc);
	u=w;
	for(ll i = x;; i += x) {
		int t=lower_bound(l,l+lc,make_pair(w,-1000000))-l;
		if (t < lc && l[t].X == w) {
			return pp[p] = i + l[t].Y;
		}
		w=w*u;
	}
	return -1;
}
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y) * y;
}
ll cal(ll n) {
	if (pp.find(n) != pp.end()) {
		return pp[n];
	}
	int N = n;
	ll z = 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ll w = P(i);
			for (n /= i; n % i == 0; n /= i) {
				w *= i;
			}
			z=lcm(z, w);
		}
	}
	if (n > 1) {
		z = lcm(z, P(n));		
	}
	return pp[N] = z;
}
int t,k,m;
long long n,b[220];
int main() {
	scanf("%d",&t);
	for(int tt=0;tt<t;tt++)  {
		scanf("%d%lld%d",&k,&n,&m);
		b[0]=m;
		for(int i=1;i<=k;i++) {
			b[i]=cal(b[i-1]);
		}
		n%=b[k];
		for(int i=k;i--;) {
			p=b[i];
			n=F(n).X;
		}
		printf("%lld\n",n);
	}
	return 0;
}