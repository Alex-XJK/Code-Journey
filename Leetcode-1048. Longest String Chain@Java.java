class Solution {
    public int longestStrChain(String[] words) {
        int n = words.length;
        int result = 1;
        
        Arrays.sort(words, Comparator.comparingInt(String::length));
        
        int[] dp = new int[n];
        dp[0] = 1;
        
        for(int i = 1; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(isPredecessor(words[j], words[i])) {
                    dp[i] = Math.max(dp[j] + 1, dp[i]);
                }
            }
            result = Math.max(result, dp[i]);
        }
        return result;
    }
    
    private boolean isPredecessor(String word1, String word2){
        if(word1.length() + 1 == word2.length()) {
            for(int i = word2.length() - 1; i >= 0; i--) {
                String s = word2.substring(0, i) + word2.substring(i + 1);
                if(s.equals(word1)) {
                    return true;
                }
            }
        }
        return false;
    }
}