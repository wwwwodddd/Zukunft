class Solution:
    def flipAndInvertImage(self, a: List[List[int]]) -> List[List[int]]:
        for i in range(len(a)):
            a[i] = [1-j for j in a[i][::-1]]
        return a