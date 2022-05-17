class Solution:
    def fourSum(self, a: List[int], s: int) -> List[List[int]]:
        re = []
        n = len(a)
        a.sort()
        for i in range(n):
            for j in range(i + 1, n):
                k = j + 1
                l = n - 1
                while k < l:
                    if a[i] + a[j] + a[k] + a[l] == s:
                        re.append((a[i], a[j], a[k], a[l]))
                    if a[i] + a[j] + a[k] + a[l] > s:
                        l -= 1
                    else:
                        k += 1
        return list(set(re))