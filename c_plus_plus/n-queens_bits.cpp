//Q: N-Queens
//Method: bit masking

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

void solveBoard(vector<vector<char>> &board, int row, int rowmask, int ldmask, int rdmask, int &ways){

    int n = board.size(); //board is size nxn
    int all_rows_filled = (1 << n) - 1; // bit mask having all N bits set
    /*
    1 << n, shifts 1 by n digits, or multiply by 2^n
    (1 << n) - 1, makes right most bits to 1.
    For example, (1 << 2) - 1 = 1 * 2*2 - 1, = 3 or equivalently, 0001 << 2 - 1 = 0100 - 1 = 0011 -> 3
    */

}