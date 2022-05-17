class Solution:
    def confusingNumber(self, n: int) -> bool:
        t = ''
        for i in str(n):
            if i in '018':
                t += i
            elif i in '69':
                t += str(15 - int(i))
            else:
                return False
        return int(t[::-1]) != n