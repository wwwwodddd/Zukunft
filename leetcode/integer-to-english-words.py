class Solution:
    def numberToWords(self, n: int) -> str:
        F = self.numberToWords
        if n >= 1000000000:
            if n % 1000000000 == 0:
                return F(n//1000000000) + ' Billion'
            else:
                return F(n//1000000000) + ' Billion ' + F(n % 1000000000)
        elif n >= 1000000:
            if n % 1000000 == 0:
                return F(n//1000000) + ' Million'
            else:
                return F(n//1000000) + ' Million ' + F(n % 1000000)
        elif n >= 1000:
            if n % 1000 == 0:
                return F(n//1000) + ' Thousand'
            else:
                return F(n//1000) + ' Thousand ' + F(n % 1000)
        elif n >= 100:
            if n % 100 == 0:
                return F(n//100) + ' Hundred'
            else:
                return F(n//100) + ' Hundred ' + F(n % 100)
        elif n >= 20:
            if n % 10 == 0:
                return ['Zero','Ten','Twenty','Thirty','Forty',
                    'Fifty','Sixty','Seventy','Eighty','Ninety'][n//10]
            else:
                return F(n//10*10) + ' ' + F(n % 10)
        else:
            return ['Zero','One','Two','Three','Four','Five',
                    'Six','Seven','Eight','Nine','Ten',
                    'Eleven','Twelve','Thirteen','Fourteen','Fifteen',
                   'Sixteen','Seventeen','Eighteen','Nineteen'][n]