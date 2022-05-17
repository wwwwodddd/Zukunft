class Solution:
    def numTeams(self, a: List[int]) -> int:
        n = len(a)
        z = 0
        for i in range(n):
            lu = ld = ru = rd = 0
            for j in range(i):
                if a[j] < a[i]:
                    ld += 1
                if a[j] > a[i]:
                    lu += 1
            for j in range(i+1,n):
                if a[j] < a[i]:
                    rd += 1
                if a[j] > a[i]:
                    ru += 1
            z += ld * ru + lu * rd
        return z
                