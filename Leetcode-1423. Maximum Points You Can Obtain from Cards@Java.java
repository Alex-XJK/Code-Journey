class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int len = cardPoints.length;
        if(len <= k) {
            return computeSum(cardPoints, len);
        }
        else {
            int left = 0;
            int right = len - k;
            int temp = computeSum(cardPoints, right);
            int min = temp;
            while(right < len) {
                temp += cardPoints[right] - cardPoints[left];
                left += 1;
                right += 1;
                min = Math.min(min, temp);
            }
            int total = computeSum(cardPoints, len);
            return total - min;
        }
    }
    
    private int computeSum(int[] array, int len) {
        int sum = 0;
        for(int i = len - 1; i >= 0; i--) {
            sum += array[i];
        }
        return sum;
    }
}