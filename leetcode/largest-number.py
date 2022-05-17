class Solution:
    def largestNumber(self, a: List[int]) -> str:
        a = list(map(str, a))
        for i in range(len(a)):
            for j in range(1, len(a)):
                if a[j-1] + a[j] < a[j] + a[j-1]:
                    a[j-1],a[j]=a[j],a[j-1]
        return str(int(''.join(a)))