class Solution:
    def coutPairs(self, a: List[int], k: int) -> int:
        c = Counter(gcd(i, k) for i in a)
        z = 0
        for i in c:
            for j in c:
                if i * j % k == 0:
                    if i == j:
                        z += c[i] * (c[j] - 1)
                    else:
                        z += c[i] * c[j]
        return z // 2