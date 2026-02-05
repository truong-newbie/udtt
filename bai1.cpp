#include <bits/stdc++.h>
using namespace std;

struct Fan {
    string brand;
    string color;
    int price;
};
void bai1_greedy(vector<Fan> d, int p) {
    sort(d.begin(), d.end(), [](Fan a, Fan b) {
        return a.price < b.price;
    });

    int total = 0;
    vector<Fan> buy;

    for (auto &f : d) {
        if (total + f.price <= p) {
            total += f.price;
            buy.push_back(f);
        }
    }

    cout << "So quat mua duoc nhieu nhat: " << buy.size() << endl;
    for (auto &f : buy)
        cout << f.brand << " - " << f.price << endl;
}
void bai1_dp(vector<Fan> d, int p) {
    int n = d.size();
    vector<vector<int>> dp(n+1, vector<int>(p+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= p; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= d[i-1].price)
                dp[i][j] = max(dp[i][j],
                               dp[i-1][j - d[i-1].price] + 1);
        }
    }

    cout << "So quat mua duoc nhieu nhat (DP): " << dp[n][p] << endl;
}

