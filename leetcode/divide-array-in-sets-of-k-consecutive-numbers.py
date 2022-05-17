class Solution:
    def isPossibleDivide(self, a: List[int], m: int) -> bool:
        c = Counter(a)
        for i in sorted(c):
            if c[i]==0:
                continue
            for j in range(m)[::-1]:
                if c[i+j]<c[i]:
                    return False
                c[i+j]-=c[i]
        return True