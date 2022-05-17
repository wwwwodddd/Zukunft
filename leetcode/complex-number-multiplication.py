class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        a,b=map(int,num1.replace('i','').split('+'))
        c,d=map(int,num2.replace('i','').split('+'))
        return '%d+%di'%(a*c-b*d,a*d+b*c)