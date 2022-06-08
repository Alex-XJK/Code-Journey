class Solution {
    public int removePalindromeSub(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        if (s.equals(rev)) {
            // Palindromic itself 
            return 1;
        }
        else {
            // Delete all a's first and then all b's
            return 2;
        }
    }
}