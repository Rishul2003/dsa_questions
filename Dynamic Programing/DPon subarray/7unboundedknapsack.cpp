#include <bits/stdc++.h>
using namespace std;
int f(int ind, int wt, vector<int> &weight, vector<int> &val)
{
    if (ind == 0)
    {
        if (weight[ind] <= wt)
        {
            return (wt / weight[ind]) * val[ind];
        }
        return 0;
    }
    int nottake = f(ind - 1, wt, weight, val);
    int take = 0;
    if (wt <= weight[ind])
    {
        take = val[ind] + f(ind, wt - weight[ind], weight, val);
    }
    return max(take, nottake);
}
int main()
{
    //
    int n, amount, wt;
    vector<int> weight;
    vector<int> val;

    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    vector<int>prev(amount+1,0);
    for (int i = 0; i <= amount; i++)
    {
        prev[i]=(wt / weight[0]) * val[0];
        dp[0][i] = (wt / weight[0]) * val[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = amount; j >= 0; j--)
        {
            int ntake=prev[j];
            int nottake = dp[i - 1][j];
            int take = 0;
            int tke=0;
            if (j >= weight[i])
            {
                take = val[i] + dp[i][j - weight[i]];
                tke=val[i]+prev[j-weight[i]];
            }
            prev[j]=max(take,nottake);
            dp[i][j] = max(take, nottake);
        }
    }
    return 0;
}