class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0,j=s.size()-1;
        for(;;)
        {
            while(i<j&&!isalpha(s[i]))
            {
                i++;
            }
            while(i<j&&!isalpha(s[j]))
            {
                j--;
            }
            if (i<j)
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else
            {
                break;
            }
        }
        return s;
    }
};