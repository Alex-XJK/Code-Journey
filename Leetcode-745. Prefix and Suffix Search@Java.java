/**
 * This method was original inspired by Grand YANG in C++.
 * @see https://github.com/grandyang/leetcode/issues/745
 */
class WordFilter {
    private HashMap<String, Integer> map;

    public WordFilter(String[] words) {
        map = new HashMap<>();
        
        for(int weight = 0; weight < words.length; weight++) {
            for(int i = 0; i <= 10 && i <= words[weight].length(); i++) {
                for(int j = 0; j <= 10 && j <= words[weight].length(); j++) {
                    String key = words[weight].substring(0, i) +
                        "&" + 
                        words[weight].substring(words[weight].length() - j);
                    map.put(key, weight);
                }
            }
        }
    }
    
    public int f(String prefix, String suffix) {
        String target = prefix + "&" + suffix;
        
        if (map.containsKey(target)) {
            return map.get(target);
        }
        else {
            return -1;
        } 
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */