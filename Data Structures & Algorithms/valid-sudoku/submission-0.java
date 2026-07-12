class Solution {
    public boolean isValidSudoku(char[][] board) {
        //Store numbers seen in each row, col and 3X3 box
        HashSet<Character>[] rows = new HashSet[9];
        HashSet<Character>[] cols = new HashSet[9];
        HashSet<Character>[] boxes = new HashSet[9];

        //Initialize all Hashsets
        for(int i = 0; i<9; i++){
            rows[i] = new HashSet<>();
            cols[i] = new HashSet<>();
            boxes[i] = new HashSet<>();
        }

        //Traverse every cell
        for(int row = 0; row<9; row++){
            for(int col = 0; col<9; col++){
                //Ignore Empty cells
                if(board[row][col] == '.')continue;

                char num = board[row][col];

                // Identify which box this cell belongs to with formula
                int box = (row/3) * 3 + (col/3);
                
                //Check for Duplicates in Row, Col or Box
                if(rows[row].contains(num)||
                    cols[col].contains(num) ||
                    boxes[box].contains(num)){
                        return false;
                }
                //Mark the number as seen
                rows[row].add(num);
                cols[col].add(num);
                boxes[box].add(num);
            }
        }
        return true;
    }
}
