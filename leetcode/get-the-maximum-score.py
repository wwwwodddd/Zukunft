class Solution:
    def maxSum(self, a: List[int], b: List[int]) -> int:
        i = 0
        j = 0
        A = 0
        B = 0
        while i < len(a) or j < len(b):
            if j == len(b):
                A += a[i]
                i += 1
            elif i == len(a):
                B += b[j]
                j += 1
            elif a[i] == b[j]:
                A = B = max(A, B)
                A += a[i]
                B += b[j]
                i += 1
                j += 1
            elif a[i] < b[j]:
                A += a[i]
                i += 1
            else:
                B += b[j]
                j += 1
        return max(A, B) % 1000000007
        