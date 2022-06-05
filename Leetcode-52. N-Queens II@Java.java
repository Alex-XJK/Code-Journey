class Solution {
    
    private static int IDLE = 0;
    
    private int N;
    private int result;

    public int totalNQueens(int n) {
        this.N = n;

        int[] queen = new int[this.N]; // index is Row, value is Column
        Arrays.fill(queen, IDLE);
        
        solve(queen, 0);
        
        return this.result;
    }
    
    private void solve(int[] queen, int current) {
        if (current >= this.N) {
            this.result += 1;
            return;
        }
        else {
            for (int i = 0; i < this.N; i++) {
                if (isAllow(queen, current, i)) {
                    queen[current] = i;
                    solve(queen, current + 1);
                    queen[current] = IDLE;
                }
            }
        }
    }
    
    private boolean isAllow(int[] queen, int index, int position) {
        int myRow = index;
        int myCol = position;
        for (int taRow = 0; taRow < myRow; taRow++) {
            int taCol = queen[taRow];
            if (taCol == myCol || 
                ((myRow - taRow) == Math.abs(taCol - myCol))
               ) {
                return false;
            }
        }
        return true;
    }
}