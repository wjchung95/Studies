#define MAX_ROW 40
#define MAX_COL 30

struct Result{
    int row;
    int col;
};

int rows, cols;
int initial_game_board[MAX_ROW][MAX_COL], updating_game_board[MAX_ROW][MAX_COL];

void init(int mRows, int mCols, int mCells[MAX_ROW][MAX_COL])
{
    rows = mRows;
    cols = mCols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            initial_game_board[i][j] = updating_game_board[i][j] = mCells[i][j];
        }
    }
}

Result putPuzzle(int mPuzzle[3][3])
{
    Result ret = {-1, -1};

    
    return ret;
}

void clearPuzzles()
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            updating_game_board[i][j] = initial_game_board[i][j];
        }
    }
    return;
}
