class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        int remBricks = bricks;
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        
        int location = 0;
        for(location = 0; location < heights.length - 1; location++){
            int diff = heights[location + 1] - heights[location];
            if(diff > 0){
                // Try if using ladders first
                heap.offer(diff);
                
                // No ladders left, try using bricks to replace the min jump
                if (heap.size() > ladders) {
                    int minBricks = heap.poll();
                    remBricks -= minBricks;
                }
                
                // No enough bricks, stop here
                if (remBricks < 0) { 
                    break;
                }
            }
        }
        return location;
    }
}