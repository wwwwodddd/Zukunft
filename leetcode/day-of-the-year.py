class Solution:
    def dayOfYear(self, s: str) -> int:
        return (datetime.datetime.strptime(s, '%Y-%m-%d')-datetime.datetime.strptime(s[:4], '%Y')).days+1