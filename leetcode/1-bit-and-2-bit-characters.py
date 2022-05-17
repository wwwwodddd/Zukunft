class Solution:
    def isOneBitCharacter(self, a: List[int]) -> bool:
        i=0
        while i+1<len(a):
            if a[i]==0:
                i+=1
            else:
                i+=2
        return i<len(a)