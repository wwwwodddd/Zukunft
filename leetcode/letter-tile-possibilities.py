class Solution:
    def numTilePossibilities(self, a: str) -> int:
        s = set()
        for i in range(1,len(a)+1):
            for p in permutations(a,i):
                s.add(''.join(p))
        return len(s)