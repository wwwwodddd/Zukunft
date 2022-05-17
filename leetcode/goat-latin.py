class Solution:
    def toGoatLatin(self, a: str) -> str:
        b=[]
        s=''
        for i in a.split():
            s+='a'
            if i[0].lower()in'aeiou':
                b.append(i+'ma'+s)
            else:
                b.append(i[1:]+i[:1]+'ma'+s)
        return ' '.join(b)