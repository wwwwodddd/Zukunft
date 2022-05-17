class Solution:
    def findDifferentBinaryString(self, a: List[str]) -> str:
        n=len(a[0])
        a=set(a)
        for i in range(1<<n,1<<n+1):
            if bin(i)[3:]not in a:
                return bin(i)[3:]