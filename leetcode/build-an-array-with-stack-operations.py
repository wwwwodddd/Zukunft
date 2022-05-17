class Solution:
    def buildArray(self, a: List[int], n: int) -> List[str]:
        j = 0
        z = []
        for i in range(1, n + 1):
            if j == len(a):
                break
            z.append('Push')
            if a[j] == i:
                j += 1
            else:
                z.append('Pop')
        return z