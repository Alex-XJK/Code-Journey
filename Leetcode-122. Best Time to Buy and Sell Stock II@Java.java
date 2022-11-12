class Solution {
    public int maxProfit(int[] prices) {
        int total = 0;
        int previous = prices[0];
        for(int i = 1; i < prices.length; i++) {
            int current = prices[i];
            if(current > previous) {
                total += (current - previous);
            }
            previous = current;
        }
        return total;
    }
}