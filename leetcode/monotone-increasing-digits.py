class Solution:
    def monotoneIncreasingDigits(self, n: int) -> int:
        a = list(str(n))
        for i in range(1, len(a)):
            if a[i] < a[i - 1]:
                j = i - 1
                while j > 0 and a[j - 1] == a[i - 1]:
                    j -= 1
                a[j] = str(int(a[j]) - 1)
                for k in range(j + 1, len(a)):
                    a[k] = '9'
                break
        return int(''.join(a))