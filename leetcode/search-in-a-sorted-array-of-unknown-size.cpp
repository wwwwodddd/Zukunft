/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int t) {
        int l = -1;
        int r = 10000;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            int v = reader.get(m);
            if (v == t)
            {
                return m;
            }
            if (v < t)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        return -1;
    }
};