class Solution:
    def reformatDate(self, date: str) -> str:
        d,m,y=date.split()
        m=["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"].index(m)+1
        return '%s-%02d-%02d' % (y,m,int(d[:-2]))