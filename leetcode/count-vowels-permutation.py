class Solution:
    def countVowelPermutation(self, n: int) -> int:
        a, e, i, o, u = 1, 1, 1, 1, 1
        p = 1000000007
        for j in range(1,n):
            a, e, i, o, u = e, (a+i)%p, (a+e+o+u)%p, (i+u)%p, a
        return (a+e+i+o+u)%p