void doiTienGreedy(vector<int> a, int S) {
    sort(a.begin(), a.end(), greater<int>());

    int cnt = 0;
    cout << "Cac dong tien dung: ";

    for (int coin : a) {
        int k = S / coin;
        if (k > 0) {
            cnt += k;
            S -= k * coin;
            for (int i = 0; i < k; i++)
                cout << coin << " ";
        }
    }

    if (S != 0)
        cout << "\nKhong doi duoc dung so tien!";
    else
        cout << "\nSo dong tien it nhat (Greedy): " << cnt;
}
void doiTienDP(vector<int> a, int S) {
    const int INF = 1e9;
    vector<int> dp(S + 1, INF);
    vector<int> trace(S + 1, -1);

    dp[0] = 0;

    for (int i = 1; i <= S; i++) {
        for (int coin : a) {
            if (i >= coin && dp[i - coin] + 1 < dp[i]) {
                dp[i] = dp[i - coin] + 1;
                trace[i] = coin;
            }
        }
    }

    if (dp[S] == INF) {
        cout << "Khong doi duoc so tien\n";
        return;
    }

    cout << "So dong tien it nhat (DP): " << dp[S] << endl;
    cout << "Cac dong tien dung: ";

    int x = S;
    while (x > 0) {
        cout << trace[x] << " ";
        x -= trace[x];
    }
}

