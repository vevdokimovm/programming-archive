#define MAX(x, y, r) { \
    int _x = (x);\
    int _y = (y);\
    ((_x) > (_y) ? (r) = (_x) : (r) = (_y)); \
}
