class Solution {
    public boolean isValidSudoku(char[][] board) {
        if (validRow(board) && validCol(board) && validBox(board)) {
            return true;
        }
        else {
            return false;
        }
    }
    
    private boolean validRow(char[][] board) {
        for(int row = 0; row < 9; row++){
            HashSet<Character> temp = new HashSet<Character>();
            for(int col = 0; col < 9; col++){
                char cur = board[row][col];
                if(cur == '.'){
                    continue;
                }
                else {
                    if(temp.contains(cur)){
                        return false;
                    }
                    else{
                        temp.add(cur);
                    }
                }
            }
        }
        return true;
    }
    
    private boolean validCol(char[][] board) {
        for(int col = 0; col < 9; col++){
            HashSet<Character> temp = new HashSet<Character>();
            for(int row = 0; row < 9; row++){
                char cur = board[row][col];
                if(cur == '.'){
                    continue;
                }
                else {
                    if(temp.contains(cur)){
                        return false;
                    }
                    else{
                        temp.add(cur);
                    }
                }
            }
        }
        return true;
    }
    
    private boolean validBox(char[][] board) {
        for(int i = 0; i < 9; i++){
            int rowOffset = (i / 3) * 3;
            int colOffset = (i % 3) * 3;
            HashSet<Character> temp = new HashSet<Character>();
            for(int col = 0; col < 3; col++){
                for(int row = 0; row < 3; row++){
                    char cur = board[rowOffset + row][colOffset + col];
                    if(cur == '.'){
                        continue;
                    }
                    else {
                        if(temp.contains(cur)){
                            return false;
                        }
                        else{
                            temp.add(cur);
                        }
                    }
                }
            }
        }
        return true;
    }
}