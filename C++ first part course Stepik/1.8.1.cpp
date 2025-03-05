int power(int a, unsigned b, int c = 1) {
    if (b == 0) return c;
    else if (b % 2 == 0) return power(a * a, b / 2, c);
    else return power(a, b - 1, a * c);
}