class Solution:
    def countEven(self, n: int) -> int:
        z = 0
        for i in range(1,n+1):
            if sum(map(int,str(i)))%2==0:
                z += 1
        return z