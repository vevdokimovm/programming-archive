int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** ans = new int * [cols];
    int * ptr = new int [cols * rows];
    for (unsigned i = 0; i != cols; ++i){
        ans[i] = ptr + i * rows;
        for (unsigned j = 0; j != rows; ++j){
            ans[i][j] = m[j][i];
        }
    }
    return ans;
}