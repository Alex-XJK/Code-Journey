class Solution {
    public int[][] transpose(int[][] matrix) {
        // Create transposed matrix
        int oriX = matrix[0].length;
        int oriY = matrix.length;
        
        int[][] result = new int[oriX][oriY];
        
        // Fill up the contents
        for (int i = 0; i < oriY; i++) {
            for (int j = 0; j < oriX; j++) {
                result[j][i] = matrix[i][j];
            }
        }
        
        // Return result
        return result;
    }
}