class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        f=[1,2]
        for i in range(50):
            f.append(f[-1]+f[-2])
        z=0
        for i in f[::-1]:
            if k>=i:
                k-=i
                z+=1
        return z