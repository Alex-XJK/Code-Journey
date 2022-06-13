class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rowLength = triangle.size();
        
        // Special cases
        if(rowLength == 1) {
            return triangle[0][0];
        }
        
        // Core DP
        for(int row = rowLength - 2; row >= 0; row--) {
            for(int col = 0; col < triangle[row].size(); col++) {
                triangle[row][col] = min(triangle[row + 1][col], triangle[row + 1][col + 1]) + triangle[row][col];
            }
        }
        
        // Return
        return triangle[0][0];
    }
};