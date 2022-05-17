class Solution:
    def findSubsequences(self, a: List[int]) -> List[List[int]]:
        f = [[]for i in range(len(a))]
        z = set()
        for i in range(len(a)):
            f[i].append([a[i]])
            for j in range(i)[::-1]:
                if a[j] <= a[i]:
                    for b in f[j]:
                        f[i].append(b + [a[i]])
                if a[j] == a[i]:
                    break
            for b in f[i]:
                if len(b) > 1:
                    z.add(tuple(b))
        return z