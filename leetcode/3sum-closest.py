class Solution:
    def threeSumClosest(self, a: List[int], t: int) -> int:
        a.sort()
        z = a[0] + a[1] + a[2]
        n = len(a)
        for i in range(n):
            j = i + 1
            k = n - 1
            while j < k:
                if abs(t - z) > abs(t - a[i] - a[j] - a[k]):
                    z = a[i] + a[j] + a[k]
                if a[i] + a[j] + a[k] > t:
                    k -= 1
                else:
                    j += 1
        return z