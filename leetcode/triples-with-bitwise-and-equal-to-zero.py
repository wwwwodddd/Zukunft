class Solution:
    def countTriplets(self, a: List[int]) -> int:
        c = [0 for i in range(2**16)]
        for i in a:
            c[i] += 1
        for j in range(16):
            for i in range(2**16):
                if i>>j&1:
                    c[i^(1<<j)]+=c[i]
        for i in range(2**16):
            c[i]**=3
        for j in range(16):
            for i in range(2**16):
                if i>>j&1:
                    c[i^(1<<j)]-=c[i]
        return c[0]