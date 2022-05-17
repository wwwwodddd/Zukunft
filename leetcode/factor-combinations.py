class Solution:
    def getFactors(self, n: int) -> List[List[int]]:
        i = 1
        d = []
        while i * i <= n:
            if n % i == 0:
                d.append(i)
                if i * i < n:
                    d.append(n // i)
            i += 1
        d.sort()
        z = [[] for i in d]
        z[0].append([])
        for i in range(len(d)):
            for j in range(i):
                if d[i] % d[j] == 0:
                    for k in z[j]:
                        if len(k) == 0 or k[-1] <= d[i] // d[j]:
                            z[i].append(k + [d[i] // d[j]])
        return z[-1][1:]