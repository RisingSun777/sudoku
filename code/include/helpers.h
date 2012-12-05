void board_addconstraint(boardptr b, int row, int col, int value);
void board_removeconstraint(boardptr b, int row, int col, int value);

int board_validconstraint(boardptr b, int row, int col);

void board_setcell(boardptr b, int row, int col, int value);

int cell_val(int cell);
int subsquare(int row, int col,
              int* minrow, int* maxrow,
              int* mincol, int* maxcol);
