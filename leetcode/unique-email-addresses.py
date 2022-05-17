class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        s = set()
        for e in emails:
            e, f = e.split('@')
            e = e.split('+')[0]
            e = e.replace('.', '')
            s.add(e + '@' + f)
            print(e)
        return len(s)