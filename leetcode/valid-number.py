import re
class Solution(object):
    def isNumber(self, s):
        if re.match('^\\+\\d+$', s):
            return True
        s = s.strip()
        if s.find('L') != -1:
            return False
        if len(s.split()) > 1:
            return False
        if len(s[1:].replace('e+', '').split('+')) > 1:
            return False
        if len(s[1:].replace('e-', '').split('-')) > 1:
            return False
        try:
            eval(s)
        except:
            while len(s) > 1 and s[0] == '0':
                s = s[1:]
            try:
                eval(s)
            except:
                return False
        return True