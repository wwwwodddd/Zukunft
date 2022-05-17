class Solution:
    def getDistances(self, a: List[int]) -> List[int]:
        z = [0 for i in a]
        c = Counter()
        s = Counter()
        for i in range(len(a)):
            z[i] += c[a[i]] * i - s[a[i]]
            c[a[i]] += 1
            s[a[i]] += i
        c = Counter()
        s = Counter()
        for i in range(len(a))[::-1]:
            z[i] += s[a[i]] - c[a[i]] * i
            c[a[i]] += 1
            s[a[i]] += i
        return z
