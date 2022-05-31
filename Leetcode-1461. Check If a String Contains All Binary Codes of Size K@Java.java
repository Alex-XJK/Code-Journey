class Solution {
    public boolean hasAllCodes(String s, int k) {
        // Check total length requirements
        int len = s.length();
        if (len < ((1 << k) + k - 1)) {
            return false;
        }
        // Check details
        HashSet<String> set = new HashSet<>();
        for (int i = 0; i + k <= len; i++) {
            set.add(s.substring(i, i + k));
        }
        // Compare size 
        return set.size() == (1 << k);
    }
}