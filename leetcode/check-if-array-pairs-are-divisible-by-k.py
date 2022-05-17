class Solution:
    def canArrange(self, a: List[int], k: int) -> bool:
        c=Counter(i%k for i in a)
        for i in range(1,(k+1)//2):
            if c[i]!=c[k-i]:
                return False
        if c[0]%2!=0:
            return False
        if k%2==0 and c[k//2]%2!=0:
            return False
        return True