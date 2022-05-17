class Solution:
    def numSpecialEquivGroups(self, w: List[str]) -> int:
        return len(set(''.join(sorted(s[::2])+sorted(s[1::2]))for s in w))