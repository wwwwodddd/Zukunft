class Solution:
    def badSensor(self, a: List[int], b: List[int]) -> int:
        i = 0
        while i < len(a) and a[i] == b[i]:
            i += 1
        if i == len(a):
            return -1
        if a[i:-1] == b[i+1:] and a[i+1:] == b[i:-1]:
            return -1
        if a[i:-1] == b[i+1:]:
            return 1
        if a[i+1:] == b[i:-1]:
            return 2