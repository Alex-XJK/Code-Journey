class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) {
            return false;
        }
        else {
            char[] char_s = s.toCharArray();
            char[] char_t = t.toCharArray();
            Arrays.sort(char_s);
            Arrays.sort(char_t);
            return Arrays.equals(char_s, char_t);
        }
    }
}