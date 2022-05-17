class Solution:
    def minimalKSum(self, a: List[int], k: int) -> int:
        a.append(0)
        a.append(10**10)
        a = sorted(list(set(a)))
        s = 0
        for i in range(1, len(a)):
            c = a[i] - a[i-1] - 1
            if k >= c:
                s += c * (a[i-1] + 1 + a[i] - 1) // 2
                k -= c
            else:
                s += k * (a[i-1] + 1 + a[i-1] + k) // 2
                k = 0
        return s