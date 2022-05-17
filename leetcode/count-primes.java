public class Solution {
    public int countPrimes(int n) {
        int []v = new int[n];
        int answer = 0;
        for (int i = 2; i < n; i++) {
            if (v[i] == 0) {
                answer += 1;
            }
            for (int j = i; j < n; j += i) {
                v[j] = i;
            }
        }
        return answer;
    }
}