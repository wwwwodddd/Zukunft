class Solution:
    def threeConsecutiveOdds(self, a: List[int]) -> bool:
        c=0
        for i in a:
            if i%2:
                c+=1
                if c>=3:
                    return True
            else:
                c=0
        return False