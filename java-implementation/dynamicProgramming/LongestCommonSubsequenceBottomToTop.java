package dynamicProgramming;

public class LongestCommonSubsequenceBottomToTop {
    public static void main(String[] args) {
        System.out.println(findLCSLength("huind", "houdini"));
    }
    public static int findLCSLength(String s1, String s2) {

        int[][] dp = new int[s1.length() + 1][s2.length() + 1];
        for (int i = s1.length(); i >= 1; i--) {
            for (int j = s2.length(); j >= 1; j--) {
                if (s1.charAt(i-1) == s2.charAt(j-1)) {
                    dp[i-1][j-1] =  Math.max((1 + dp[i][j]), Math.max(dp[i][j-1], dp[i-1][j]));
                }else {
                    dp[i-1][j-1] = Math.max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[0][0];
    }
}