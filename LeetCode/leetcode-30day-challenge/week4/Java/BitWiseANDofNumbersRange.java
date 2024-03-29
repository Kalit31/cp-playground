
class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        while (m != n) {
            m = m >> 1;
            n = n >> 1;
            result++;
        }
        return m << result;
    }
}