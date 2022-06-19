class Solution {
    private List<List<String>> result = new ArrayList<>();
    private String[] library = null;
    private int lowB = 0;
    private int highB = 0;
    
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        buildLibrary(products);
        
        for (int i = 0; i < searchWord.length(); i++) {
            String current = searchWord.substring(0, i + 1);
            
            binarySearch(current);
            
            if (library[lowB].compareTo(current) < 0) {
                // Add empty list
                result.add(new ArrayList<>());
            } else {
                // Add up to 3 results
                List<String> list = getAnswer(current);
                result.add(list);
            }
        }
        
        return result;
    }
    
    /**
     * Check and get answers when input is target.
     * @param target The current sub-word input.
     * @return A list of strings that contains up-to 3 possibile words.
     */
    private List<String> getAnswer(String target) {
        List<String> list = new ArrayList<>();
        for (int j = lowB; j < lowB + 3 && j < library.length; j++) {
            if (library[j].startsWith(target)) {
                list.add(library[j]);
            } 
            else {
                break;
            }
        }
        return list;
    }
    
    /**
     * Binary search the location of target inside the library.
     * @param target The target word to search. 
     */
    private void binarySearch(String target) {
        // Receive experience
        int left = lowB;
        int right = highB;
        // Binary search
        while (left < right) {
            int mid = (left + right) / 2;
            if (library[mid].compareTo(target) >= 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        // Assign back
        lowB = left;
    }
    
    /**
     * Build and initialize words library.
     * @param source The source words to build our main library. 
     */
    private void buildLibrary(String[] source) {
        library = source;
        
        lowB = 0;
        highB = source.length - 1;
        
        Arrays.sort(library);
    }
}