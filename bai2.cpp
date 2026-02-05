void bai2_greedy(vector<Fan> d, int p) {
    sort(d.begin(), d.end(), [](Fan a, Fan b) {
        return a.price > b.price;
    });

    int sum = 0;
    vector<Fan> sell;

    for (auto &f : d) {
        if (sum + f.price <= p) {
            sum += f.price;
            sell.push_back(f);
        }
        if (sum == p) break;
    }

    if (sum != p) {
        cout << "Khong tim duoc tap quat co tong bang p (Greedy)\n";
        return;
    }

    cout << "So quat ban it nhat (Greedy): " << sell.size() << endl;
    for (auto &f : sell)
        cout << f.brand << " - " << f.price << endl;
}
void bai2_dp(vector<Fan> d, int p) {
    const int INF = 1e9;
    vector<int> dp(p+1, INF);
    dp[0] = 0;

    for (auto &f : d) {
        for (int j = p; j >= f.price; j--) {
            dp[j] = min(dp[j], dp[j - f.price] + 1);
        }
    }

    if (dp[p] == INF)
        cout << "Khong co tap quat tong bang p\n";
    else
        cout << "So quat ban it nhat (DP): " << dp[p] << endl;
}

