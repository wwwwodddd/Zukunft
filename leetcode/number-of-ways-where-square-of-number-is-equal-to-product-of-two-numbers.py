class Solution:
    def numTriplets(self, a: List[int], b: List[int]) -> int:
        z = 0
        c = Counter()
        for i in a:
            for j in b:
                if j * j % i == 0:
                    z += c[j * j // i]
            c[i] += 1
        c = Counter()
        for i in b:
            for j in a:
                if j * j % i == 0:
                    z += c[j * j // i]
            c[i] += 1
        return z
