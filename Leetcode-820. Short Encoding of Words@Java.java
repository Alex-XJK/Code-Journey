class Solution {
    public int minimumLengthEncoding(String[] words) {
        // Build a set of words
        List<String> wds = Arrays.asList(words);
        Set<String> set = new HashSet(wds);
        // Remove suffix strings
        for(String word: words) {
            for(int i = word.length() - 1; i >= 1; i--) {
                String temp = word.substring(i);
                if(set.contains(temp)) {
                    set.remove(temp);
                }
            }
        }
        // Compute remainings' length
        int result = 0;
        for(String remain: set) {
            result += remain.length() + 1;
        }
        // Return
        return result;
    }
}