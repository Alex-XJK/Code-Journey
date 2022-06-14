/**
 * Based on "Longest Common Subsequence" template.
 */
class Solution {
    private int n = 0;
    private int m = 0;
    private int[][] dp = null;
    private int result = 0;
    
    public int minDistance(String word1, String word2) {
        int lcsres = lcs(word1, word2);
        int del4w1 = n - lcsres;
        int del4w2 = m - lcsres;
        return (del4w1 + del4w2);
    }
    
    protected int lcs(String str1, String str2) {
        // Declaration
        n = str1.length();
        m = str2.length();
        dp = new int[n + 1][m + 1];

        // Initialize
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for(int j = 0; j <= m; j++){
            dp[0][j] = 0;
        }

        // Core DP
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // Store result
        result = dp[n][m];

        // Return
        return result;
    }
}