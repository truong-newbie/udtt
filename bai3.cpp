void bai3_greedy(vector<Fan> d, int p) {
    sort(d.begin(), d.end(), [](Fan a, Fan b) {
        return a.price > b.price;
    });

    int sum = 0;
    vector<Fan> sell;

    for (auto &f : d) {
        sum += f.price;
        sell.push_back(f);
        if (sum > p) break;
    }

    cout << "So quat ban it nhat (Greedy): " << sell.size() << endl;
    for (auto &f : sell)
        cout << f.brand << " - " << f.price << endl;
}
void bai3_dp(vector<Fan> d, int p) {
    int sumAll = 0;
    for (auto &f : d) sumAll += f.price;

    const int INF = 1e9;
    vector<int> dp(sumAll + 1, INF);
    dp[0] = 0;

    for (auto &f : d) {
        for (int j = sumAll; j >= f.price; j--) {
            dp[j] = min(dp[j], dp[j - f.price] + 1);
        }
    }

    int ans = INF;
    for (int j = p + 1; j <= sumAll; j++)
        ans = min(ans, dp[j]);

    cout << "So quat ban it nhat (DP): " << ans << endl;
}

