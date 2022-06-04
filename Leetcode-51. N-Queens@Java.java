class Solution {
    private static int IDLE = 0;
    private static char QUEEN = 'Q';
    private static char EMPTY = '.';
    
    private List<List<String>> result;
    private int N;
    
    public List<List<String>> solveNQueens(int n) {
        this.result = new ArrayList<List<String>>();
        this.N = n;

        int[] queen = new int[this.N]; // index is Row, value is Column
        Arrays.fill(queen, IDLE);
        
        solve(queen, 0);
        
        return this.result;
    }
    
    private void solve(int[] queen, int current) {
        if (current >= this.N) {
            List<String> temp = new ArrayList<>();
            for(int i = 0; i < this.N; i++) {
                char[] array = new char[this.N];
                Arrays.fill(array, EMPTY);
                array[queen[i]] = QUEEN;
                temp.add(new String(array));
            }
            this.result.add(temp);
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