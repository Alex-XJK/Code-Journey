/**
 * [LeetCode-TLE] Time Limit Exceeded.
 * Status: 11 / 76 test cases passed.
 * Tried to use a standard DP to solve.
 * @example https://leetcode.com/submissions/detail/727268194/testcase/
 * @see     https://leetcode.com/submissions/detail/727268194/
 * @since   June 21, 2022
 * @author  Alex XU
 */
class Solution {
    private int[] heights = null;
    
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        this.heights = heights;
        return dp(0, bricks, ladders);
    }
    
    private int dp(int location, int remB, int remL) {
        if(location >= heights.length - 1) {
            return location;
        }
        
        if(heights[location] >= heights[location + 1]) {
            return dp(location + 1, remB, remL);
        }
        else {
            int useB = location;
            int useL = location;
            if(remB >= (heights[location + 1] - heights[location])) {
                useB = dp(location + 1, remB - (heights[location + 1] - heights[location]), remL);
            }
            if(remL > 0) {
                useL = dp(location + 1, remB, remL - 1);
            }
            return Math.max(useB, useL);
        }
    }
}