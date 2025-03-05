void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min_ar = m[0][0], index = 0;
    for (unsigned i = 0; i != rows; ++i){
        for (unsigned j = 0; j != cols; ++j){
            if (m[i][j] < min_ar){
                min_ar = m[i][j];
                index = i;
            }
        }
    }
    int * swapper = m[0];
    m[0] = m[index];
    m[index] = swapper;
}
