class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        c = Counter()
        z = 0
        for i in s1:
            if c[i] == 0:
                z += 1
            c[i] += 1
            
        for i in range(len(s2)):
            if c[s2[i]] == 0:
                z += 1
            c[s2[i]] -= 1
            if c[s2[i]] == 0:
                z -= 1
            if z == 0:
                return True
            if i >= len(s1) - 1:
                if c[s2[i - len(s1) + 1]] == 0:
                    z += 1
                c[s2[i - len(s1) + 1]] += 1
                if c[s2[i - len(s1) + 1]] == 0:
                    z -= 1
        return False
                