class Solution
{
public:
    int maxTotalReward(vector<int> &rewardValues)
    {

        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.resize(distance(rewardValues.begin(), unique(rewardValues.begin(), rewardValues.end())));

        bitset<100001> memo;
        bitset<100001> cur;
        memo[0] = 1;
        int pos = 0;

        for (int &v : rewardValues)
        {
            while (pos < v)
                cur.set(pos++);
            cur = memo & cur;
            memo |= (cur << v);
        }

        int ans = 100001;
        while (!memo[ans])
            ans--;
        return ans;
    }
};