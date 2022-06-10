class Solution {
    public int lengthOfLongestSubstring(String s) {
        final int LEN = s.length();
        int result = 0;
        
        int left = 0;
        int right = 0;
        
        HashSet<Character> pool = new HashSet<>();
        char temp;
        
        while (right < LEN) {
            if (pool.contains(s.charAt(right))) {
                pool.remove(s.charAt(left));
                left += 1;
            }
            else {
                pool.add(s.charAt(right));
                right += 1;
                result = Math.max(result, pool.size());
            }
        }
        
        return result;
    }
}