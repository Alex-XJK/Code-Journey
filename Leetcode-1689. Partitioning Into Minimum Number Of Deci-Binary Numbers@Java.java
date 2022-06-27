class Solution {
    public int minPartitions(String n) {
        int[] digits = chars2ints(n.toCharArray());
        int max = getMax(digits);
        return max;
    }
    
    /**
     * My First Time Using {@code stream}.
     */
    private int getMax(int[] array) {
        return Arrays.stream(array).max().getAsInt();
    }
    
    private int[] chars2ints(char[] ca) {
        int length = ca.length;
        int[] result = new int[length];
        for(int j = length - 1; j >= 0; j--) {
            result[j] = ca[j] - '0';
        }
        return result;
    }
}

/**
 * Attached below is a sample algorithm provided by the platform, 
 * which has the fastest running speed and the smallest memory usage.
 * Fastest Running Speed:   4 ms
 * Minimum Memory Usage:    42200 KB
 */
class FastMinSolution {
    public int minPartitions(String n) {
        int res = 0;
        for(int i = 9; i >= 1; i--) {
            String ch = String.valueOf(i);
            if(n.contains(ch) ) {
                res = i;
                break;
            } 
        }    
        return res;
    }
}