class Solution:
    def canAttendMeetings(self, a: List[List[int]]) -> bool:
        a.sort()
        for i in range(1, len(a)):
            if a[i - 1][1] > a[i][0]:
                return False
        return True