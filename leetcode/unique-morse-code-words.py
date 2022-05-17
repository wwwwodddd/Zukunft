class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        b=[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
           "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        s=set()
        for w in words:
            t=''
            for i in w:
                t+=b[ord(i)-97]
            s.add(t)
        return len(s)