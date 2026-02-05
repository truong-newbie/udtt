//#include <bits/stdc++.h>
//using namespace std;
//
//using ll = long long;
//
//int main(){
//
//    int n, S; cin >> n >> S;
//    vector<int> a(n);
//    for(int i = 0; i < n; i++) cin >> a[i];
//
//    vector<bool> dp(S + 1, false);
//    dp[0] = true;
//
//    for(int i = 0; i < n; i++){
//        for(int j = S; j >= a[i]; j--){
//            if(dp[j - a[i]] == true){
//                dp[j] = true;
//            }
//        }
//    }
//
//    if(dp[S]) cout << 1 << endl;
//    else cout << 0 << endl;
//}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, S;
    cin >> n >> S;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<bool>> dp(n+1, vector<bool>(S+1, false));
    vector<vector<bool>> trace(n+1, vector<bool>(S+1, false));

    dp[0][0] = true;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= S; j++){
            // không l?y a[i]
            if(dp[i-1][j]){
                dp[i][j] = true;
            }
            // l?y a[i]
            if(j >= a[i] && dp[i-1][j - a[i]]){
                dp[i][j] = true;
                trace[i][j] = true;
            }
        }
    }

    if(!dp[n][S]){
        cout << 0 << endl;
        return 0;
    }

    cout << 1 << endl;

    // ?? Truy v?t
    vector<int> subset;
    int j = S;
    for(int i = n; i >= 1; i--){
        if(trace[i][j]){
            subset.push_back(a[i]);
            j -= a[i];
        }
    }

    reverse(subset.begin(), subset.end());

    cout << "Tap con: ";
    for(int x : subset) cout << x << " ";

    return 0;
}

