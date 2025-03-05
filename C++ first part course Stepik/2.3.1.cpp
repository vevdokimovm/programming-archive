void rotate(int a[], unsigned size, int shift)
{
    unsigned last_index = size - 1;
    for (int j = 0; j < shift; ++j){
        int first_element = a[0];
        for (unsigned i = 0; i <= last_index; ++i){
            a[i] = a[(i + 1) % (size)];
        }
        a[last_index] = first_element;
    }
}