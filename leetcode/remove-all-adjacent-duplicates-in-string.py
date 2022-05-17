class Solution:
    def removeDuplicates(self, s: str) -> str:
        a = []
        for i in s:
            if len(a)==0 or i!=a[-1]:
                a.append(i)
            else:
                a.pop()
        return ''.join(a)