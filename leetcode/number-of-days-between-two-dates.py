class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        return abs((datetime.datetime.strptime(date2, '%Y-%m-%d') - datetime.datetime.strptime(date1, '%Y-%m-%d')).days)