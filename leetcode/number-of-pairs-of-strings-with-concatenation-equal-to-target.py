class Solution:
    def numOfPairs(self, a: List[str], s: str) -> int:
        z = 0
        for i in range(len(a)):
            for j in range(len(a)):
                if i != j and a[i] + a[j] == s:
                    z += 1
        return z