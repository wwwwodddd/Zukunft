class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def yue(s):
            s = s.split(' ', 1)
            return [(0, s[1], s[0]),(1,)][s[1][0].isdigit()]
        return sorted(logs, key=yue)