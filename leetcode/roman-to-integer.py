class Solution:
    def romanToInt(self, s: str) -> int:
        s=s.replace('IV','IIII')
        s=s.replace('IX','VIIII')
        s=s.replace('XL','XXXX')
        s=s.replace('XC','LXXXX')
        s=s.replace('CD','CCCC')
        s=s.replace('CM','DCCCC')
        s=s.replace('V','IIIII')
        s=s.replace('L','XXXXX')
        s=s.replace('D','CCCCC')
        return s.count('I')+s.count('X')*10+s.count('C')*100+s.count('M')*1000