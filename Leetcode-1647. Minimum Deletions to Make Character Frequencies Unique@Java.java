class Solution {
    public int minDeletions(String s) {
        int[] freq = getFrequency(s.toCharArray());
        int deletions = countDeletion(freq);
        return deletions;
    }
    
    private int countDeletion(int[] freq) {
        int result = 0;
        
        HashSet<Integer> set = new HashSet<>();
        for(int fr : freq) {
            while(fr != 0 && set.contains(fr)) {
                fr -= 1;
                result += 1;
            }
            set.add(fr);          
        }
       
        return result;
    }
    
    private int[] getFrequency(char[] arr) {
        int[] freq = new int[26];
        
        for(char c : arr){
            freq[c - 'a'] += 1;
        }
        
        return freq;
    }
}