bool check_equals(Expression const *left, Expression const *right)
{
    int* pleft = (int*)left;
    int* pright = (int*)right;
    if (*pleft == *pright)
        return true;
    else
        return false;
}
