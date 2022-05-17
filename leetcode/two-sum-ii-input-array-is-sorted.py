class Solution:
    def twoSum(self, a: List[int], s: int) -> List[int]:
        i = 0
        j = len(a) - 1
        while i < j:
            if a[i] + a[j] == s:
                return [i+1, j+1]
            if a[i] + a[j] > s:
                j -= 1
            else:
                i += 1