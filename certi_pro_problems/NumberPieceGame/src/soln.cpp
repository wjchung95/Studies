#define MAX_ROW 40
#define MAX_COL 30
 
struct Result {
    int row;
    int col;
};
 
struct pos_t // 위치
{
    int r, c;
};
 
const int block_len[5] = { 2, 3, 3, 4, 5 }; // 블럭 길이
const pos_t block_shape[5][5] = { // 블럭 모양
    { { 0, 0 }, { 0, 1 }, }, 
    { { 0, 0 }, { 0, 1 }, { 0, 2 }, },
    { { 0, 0 }, { 1, 0 }, { 2, 0 }, },
    { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 }, },
    { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 1, 2 }, { 2, 2 } }
};
const pos_t block_size[5] = { {1, 2}, {1, 3}, {3, 1}, {2, 3}, {3, 3} }; //  블럭 크키
 
int n_pos[5][9999]; // ?
pos_t position[5][9999][500]; //?
int put_count[MAX_ROW][MAX_COL], base;
 
void init(int mRows, int mCols, int mCells[MAX_ROW][MAX_COL])
{
    for (int i = 0; i < 9999; i++)
        n_pos[0][i] = n_pos[1][i] = n_pos[2][i] = n_pos[3][i] = n_pos[4][i] = 0; // 초기화
     
    for (int r = 0; r < mRows; r++)
        for (int c = 0; c < mCols; c++)
            for (int t = 0; t < 5; t++) // 타입별?
            {
                if (r + block_size[t].r > mRows || c + block_size[t].c > mCols) // 위치 게임보드 초과하면 무시
                    continue;
                int index = 0;
                for (int i = 1; i < block_len[t]; i++) // 블럭 길이만큼 반복
                    index = index * 10 + mCells[r + block_shape[t][i].r][c + block_shape[t][i].c] - mCells[r][c] + 4;
                position[t][index][n_pos[t][index]++] = { r, c };
            }
    base++;
}
 
Result putPuzzle(int mPuzzle[3][3])
{
    int type = 0;
    if (mPuzzle[0][2] > 0)       type = 1;
    else if (mPuzzle[2][0] > 0) type = 2;
    else if (mPuzzle[1][0] > 0) type = 4;
    else if (mPuzzle[1][1] > 0) type = 3;
 
    int index = 0;
    for (int i = 1; i < block_len[type]; i++)
        index = index * 10 + mPuzzle[block_shape[type][i].r][block_shape[type][i].c] - mPuzzle[0][0] + 4;
 
    const pos_t* shape = block_shape[type];
    for (int i = 0; i < n_pos[type][index]; i++)
    {
        pos_t* pos = &position[type][index][i];
 
        bool overlap = false;
        for (int j = 0; j < block_len[type]; j++)
            if (put_count[pos->r + shape[j].r][pos->c + shape[j].c] == base)
            {
                overlap = true;
                break;
            }
 
        if (overlap == false)
        {
            for (int j = 0; j < block_len[type]; j++)
                put_count[pos->r + shape[j].r][pos->c + shape[j].c] = base;
            return { pos->r, pos->c };
        }
    }
    return { -1, -1 };
}
 
void clearPuzzles()
{
    base++;
    return;
}