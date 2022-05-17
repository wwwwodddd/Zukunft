class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        return ''.join(str(i+1)for i in list(itertools.permutations(range(n)))[k-1])