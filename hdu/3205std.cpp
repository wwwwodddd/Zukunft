#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1001;
int n;

struct poly_t {
 int c, v[MAX_N + 1];
 poly_t() { c = 0, memset(v, 0, sizeof(v)); }
 bool operator < (const poly_t &t) const {
     if (c != t.c) return c < t.c;
     for (int i = c; i >= 0; i --) {
         if (v[i] == t.v[i]) continue;
         if (abs(v[i]) != abs(t.v[i])) return abs(v[i]) < abs(t.v[i]);
         return v[i] < t.v[i];
     }
     return 0;
 }
 void clear() { c = 0, memset(v, 0, sizeof(v)); }
 void print() {
     printf("(");
     if (c > 1) printf("x^%d", c);
     else printf("x");
     for (int i = c - 1; i >= 0; i --) {
         if (!v[i]) continue;
         if (v[i] > 0) printf("+");
         else printf("-");
         if (i > 1) {
             if (abs(v[i]) != 1) printf("%d", abs(v[i]));
             printf("x^%d", i);
         }
         else if (i == 1) {
             if (abs(v[i]) != 1) printf("%d", abs(v[i]));
             printf("x");
         }
         else printf("%d", abs(v[i]));
     }
     printf(")");
 }
} p[MAX_N + 1];

poly_t operator - (const poly_t &a, const poly_t &b) {
 poly_t ret;
 ret.c = a.c;
 for (int i = 0; i <= ret.c; i ++) ret.v[i] = a.v[i] - b.v[i];
 while (ret.c && !ret.v[ret.c]) ret.c --;
 return ret;
}

poly_t operator / (const poly_t &a, const poly_t &b) {
 poly_t ret, tmp = a;
 ret.c = a.c - b.c;
 for (int i = ret.c; i >= 0; i --) {
     if (!tmp.v[i + b.c]) continue;
     ret.v[i] = tmp.v[i + b.c] / b.v[b.c];
     poly_t t;
     for (int j = b.c; j >= 0; j --) t.v[j + i] = b.v[j] * ret.v[i];
     t.c = b.c + i;
     tmp = tmp - t;
 }
 return ret;
}

bool cmp(const int &a, const int &b) {
 return p[a] < p[b];
}

int main() {
	freopen("c.in","r",stdin);
	freopen("s.out","w",stdout);
 while (scanf("%d", &n) != EOF && n) {
     for (int i = 1; i <= n; i ++) p[i].clear();
     vector <int> fact;
     for (int i = 1; i <= n; i ++)
         if (n % i == 0) fact.push_back(i);
     for (int i = 0, sz = fact.size(); i < sz; i ++) {
         int j = fact[i];
         p[j].c = j, p[j].v[j] = 1, p[j].v[0] = -1;
         for (int k = 1; k < j; k ++)
             if (j % k == 0) p[j] = p[j] / p[k];
     }
     sort(fact.begin(), fact.end(), cmp);
     for (int i = 0, sz = fact.size(); i < sz; i ++) p[fact[i]].print();
     printf("\n");
 }
 return 0;
}
