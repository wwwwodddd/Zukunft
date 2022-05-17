/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *b, int n) {
        int r = 0;
        while (r < n)
        {
            int t = read4(b + r);
            r += t;
            if (t == 0)
            {
                break;
            }
        }
        return min(r, n);
    }
};