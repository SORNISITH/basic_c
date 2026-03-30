int simple(int* xp, int y)
{
    int x = *xp + y;
    *xp = y;
    return x;
}
