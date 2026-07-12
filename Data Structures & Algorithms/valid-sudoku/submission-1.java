class Solution {
    public boolean isValidSudoku(char[][] board) {
        //Declared Hashsets to store the values 
        HashSet<Character>[] rows = new HashSet[9];
        HashSet<Character>[] cols = new HashSet[9];
        HashSet<Character>[] boxes = new HashSet[9];

        //Initialize the Hashsets
        for(int i = 0; i<9; i++){
            rows[i] = new HashSet<>();
            cols[i] = new HashSet<>();
            boxes[i] = new HashSet<>();
        }

        //traverse every cell wehre r is for rows, c for cols, b for box
        for(int r = 0; r<9; r++){
            for(int c = 0; c<9; c++){
                //Ignore the empty cells
                if(board[r][c] == '.') continue;

                char num = board[r][c];

                //identify which box the cell belongs to 
                int b = (r/3) * 3+ (c/3);

                //Check if dupes are there in hashsets
                if(rows[r].contains(num)||
                    cols[c].contains(num) ||
                    boxes[b].contains(num)
                ){
                    return false;
                }
                //copy it in all mark it as seen
                rows[r].add(num);
                cols[c].add(num);
                boxes[b].add(num);

            }
        }
        return true;

    }
}
