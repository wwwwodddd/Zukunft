class Solution:
    def countVowelStrings(self, n: int) -> int:
        z=1
        for i in range(n):
            z=z*(5+i)//(i+1)
        return z