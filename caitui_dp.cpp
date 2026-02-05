//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//    int n, M;
//    int w[105], v[105];
//
//    cin >> n >> M;
//    for (int i = 1; i <= n; i++) {
//        cin >> w[i] >> v[i];
//    }
//
//    int dp[105][1005];
//    memset(dp, 0, sizeof(dp));
//
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= M; j++) {
//            dp[i][j] = dp[i-1][j];   
//            if (j >= w[i]) {
//                dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i]); 
//            }
//        }
//    }
//    for(int i=1; i<=n;i++){
//    	for(int j=1; j<=M;j++){
//    		cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//
//    cout << "Gia tri lon nhat la: " << dp[n][M] << endl;
//
//	 int j = M;
//    cout << "Cac goi duoc chon: ";
//    for (int i = n; i >= 1; i--) {
//        if (dp[i][j] != dp[i-1][j]) {
//            cout << i << " ";
//            j -= w[i];
//        }
//    }
//
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, M;
    cin >> n >> M;

    // vector thay cho m?ng w, v
    vector<int> w(n + 1), v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    // dp[i][j]: xét i gói, balo ch?a j
    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = dp[i - 1][j]; // không l?y gói i
            if (j >= w[i]) {
                dp[i][j] = max(dp[i][j],
                               dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    // In b?ng dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= M; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Gia tri lon nhat la: " << dp[n][M] << endl;

    // Truy v?t các gói du?c ch?n
    int j = M;
    cout << "Cac goi duoc chon: ";
    for (int i = n; i >= 1; i--) {
        if (dp[i][j] != dp[i - 1][j]) {
            cout << i << " ";
            j -= w[i];
        }
    }

    return 0;
}

