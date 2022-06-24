class Solution {
    public boolean isPossible(int[] target) {
        PriorityQueue<Long> heap = new PriorityQueue<Long>(
            Collections.reverseOrder()
        );
        
        long sum = 0;
        for (int tar : target) {
            long longtar = (long) tar;
            heap.add(longtar);
            sum += tar;
        }

        while(!heap.isEmpty() && heap.peek() != 1) {
            long curMax = heap.poll();
            long restSum = sum - curMax;

            if(restSum <= 0 || restSum >= curMax) {
                return false; 
            }

            // long replaced = curMax - restSum;
            long replaced = curMax % restSum;
            long prevSum = restSum + replaced;

            heap.add(replaced > 0 ? replaced : prevSum);
            sum = prevSum;
        }
        return true;
    }
}

/**
 * Attached below is a sample algorithm provided by the platform, which has almost the fastest running speed.
 * Fastest Running Speed:   2 ms
 * Minimum Memory Usage:    48400 KB
 */
class FastMinSolution {
    public boolean isPossible(int[] target) {
        long sum = 0;
        int max = 0, index = 0;
        for(int i = 0; i < target.length; i++) {
            sum += target[i];
            if (target[i] > max) {
                max = target[i];
                index = i;
            }
        }
        sum -= max;
        if(sum == 1 || max == 1) {
            return true;
        }
        if(max < sum || sum == 0 || max % sum == 0) {
            return false;
        }
        max %= sum;
        target[index] = max;
        return isPossible(target);
    }
}