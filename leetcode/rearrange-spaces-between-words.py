class Solution:
    def reorderSpaces(self, s: str) -> str:
        c = s.count(' ')
        a = s.split()
        if len(a) == 1:
            return a[0] + ' ' * c
        else:
            return (' ' * (c // (len(a) - 1))).join(a) + ' ' * (c % (len(a) - 1))