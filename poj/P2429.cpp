//DNF
#include<stdio.h>
#include<math.h>
#define LL long long
LL a, b, x, y;
LL gcd(LL p, LL q) {
    LL r = 1;
    while (r) {
        r = p % q;
        if (r) {
            p = q;
            q = r;
        }
    }
    return q;
}
LL solve() {
    LL i, te;
    b /= a;
    te = (LL) (sqrt(b * 1.0));
    for (i = te; i >= 1; i--) {
        if (b % i == 0) {
            if (gcd(i, b / i) == 1) {
                return i;
            }
        }
    }
    return 0;
}
int main() {
    /*freopen("t.txt", "r", stdin);*/
    LL te;
    while (scanf("%lld %lld", &a, &b) != EOF) {
        te = solve();
        x = te * a, y = b / te * a;
        if (x > y) {
            te = x, x = y, y = te;
        }
        printf("%lld %lld\n", x, y);
    }
    return 0;
}