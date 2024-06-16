class Solution
{
public:
    int numberOfChild(int n, int k)
    {
        int round = k / (n - 1);
        int pos = k % (n - 1);
        return round & 1 ? n - 1 - pos : pos;
    }
};