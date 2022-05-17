class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        a = list(map(int, re.findall('\d+', s)))
        for i in range(1, len(a)):
            if a[i - 1] >= a[i]:
                return False
        return True
        