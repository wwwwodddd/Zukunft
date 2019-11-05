#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;
typedef long long ll;
int p = 1000000007;
int mp = p - 1;
int N = 100000000;
int phi[100000000 + 20];
int mu[100000000 + 20];
int v[100000000 + 20];
long long n;
ll mul(ll x, ll y) {
	x %= p;
	y %= p;
	return x * y % p;
}
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll pw(ll x, ll y) {
	if (x >= p) {
		x %= p;
	}
	if (y < 0)
		cout << "ERROR" << endl;
	ll z = 1;
	for (; y; y >>= 1, x = x * x % p) {
		if (y & 1) {
			z = z * x % p;
		}
	}
	return z;
}
ll inv(ll x) {
	return pw(x, p - 2);
}
ll SPhi(ll n) {
	if (n <= N) {
		return phi[n];
	}
	ll re = n % p;
	re = re * (re + 1) % p;
	if (re % 2 == 0) {
		re /= 2;
	} else {
		re = (re + p) / 2;
	}
	for (ll i = 2; i <= n; i++) {
		ll j = n / (n / i);
		re -= (j - i + 1) % p * SPhi(n / i) % p;
		if (re >= p)
			re -= p;
		if (re < 0)
			re += p;
		i = j;
	}
	return re;
}
ll SMu(ll n) {
	if (n <= N) {
		return mu[n];
	}
	ll re = 1;
	for (ll i = 2; i <= n; i++) {
		ll j = n / (n / i);
		re -= (j - i + 1) % mp * SMu(n / i) % mp;
		if (re >= mp) {
			re -= mp;
		}
		if (re < 0)
			re += mp;
		i = j;
	}
	return re;
}
int qqqq;
ll G1(ll n) {
	ll re = 0;
	for (ll i = 1; i <= n; i++) {
		qqqq++;
		if (qqqq % 1000 == 0)
			cout << "G1 " << i << ' ' << n << endl;
		ll j = n / (n / i);
		ll t = (n / i) % p;
		re += t * t % p * (SPhi(j) - SPhi(i - 1)) % p;
		if (re >= p) {
			re -= p;
		}
		if (re < 0)
			re += p;
		i = j;
	}
	return re;
}
int xxxx;
ll G2(ll n) {
	ll re = 0;
	for (ll i = 1; i <= n; i++) {
		xxxx++;
		if (xxxx % 1000 == 0)
			cout << "G2 " << i << ' ' << N << endl;
		ll j = n / (n / i);
		ll t = (n / i) % mp;
		re += t * t % mp * (SMu(j) - SMu(i - 1)) % mp;
		re %= mp;
//		cout << "G2 " << i << ' ' << N << endl;
		i = j;
	}
	if (re < 0)
		re += mp;
	return re;
}
ll G(ll n) {
	ll re = 1;
	for (ll k = 1; k <= n; k++) {
		cout << "G " << k << endl;
		ll l = (n / (n / k));
		ll tmp = G2(n / k);
		re = re * inv(pw(k, tmp)) % p * pw(l + 1, tmp) % p;
		k = l;
	}
	return re;
}
ll BF(ll n) {
	ll re = (n + 1) % p * G(n) % p;
	ll tot = pw(re, 4);
	re = pw(re, 2);
	tot -= (n + 1) % p * (n % p) % p * 4 % p * re % p;
	tot--;
	tot = (tot + 4 * G1(n)) % p;
	tot %= p;
	if (tot < 0) {
		tot += p;
	}
	return tot;
}
int main() {
	cin >> n;
	N = min((long long) N, n);
	for (int i = 2; i <= N; i++) {
		if (v[i] == 0) {
			for (int j = i; j <= N; j += i) {
				v[j] = i;
			}
		}
	}
	phi[1] = mu[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (v[i / v[i]] == v[i]) {
			phi[i] = phi[i / v[i]] * v[i];
			mu[i] = 0;
		} else {
			phi[i] = phi[i / v[i]] * (v[i] - 1);
			mu[i] = -mu[i / v[i]];

		}
	}
	for (int i = 1; i <= N; i++) {
		phi[i] += phi[i - 1];
		if (phi[i] >= p) {
			phi[i] -= p;
		}
		mu[i] += mu[i - 1];
		if (mu[i] < 0) {
			mu[i] += mp;
		}
		if (mu[i] >= mp) {
			mu[i] -= mp;
		}
	}

	cout << BF(n) << endl;
	printf("%f\n", (double) clock() / CLOCKS_PER_SEC);
	return 0;

}
