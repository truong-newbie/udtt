#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), L(n, 1), trace(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Quy ho?ch d?ng + truy v?t
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && L[j] + 1 > L[i]) {
                L[i] = L[j] + 1;
                trace[i] = j;
            }
            
//            if(a[i] > a[j]){
//            	L[i]=max(L[i], L[j]+1);
//			}
        }
    }
    
//    cout<<*max_element(L.begin(), L.end()) <<endl;

    // Tìm v? trí k?t thúc LIS
    int len = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        if (L[i] > len) {
            len = L[i];
            pos = i;
        }
    }

    cout << "Do dai LIS: " << len << endl;

    // Truy v?t ngu?c
    vector<int> lis;
    while (pos != -1) {
        lis.push_back(a[pos]);
        pos = trace[pos];
    }

    reverse(lis.begin(), lis.end());

    cout << "Day LIS: ";
    for (int x : lis) cout << x << " ";

    return 0;
}

