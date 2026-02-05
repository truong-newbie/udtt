#include <bits/stdc++.h>
using namespace std;

struct Item {
    int id;
    int w, v;
    double ratio;
};

int main() {
    int n, M;
    cin >> n >> M;

    vector<Item> x(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> x[i].w >> x[i].v;
        x[i].id = i;
        x[i].ratio = (double)x[i].v / x[i].w;
    }

    // S?p x?p gi?m d?n theo ratio
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (x[i].ratio < x[j].ratio) {
                swap(x[i], x[j]);
            }
        }
    }

    int curWeight = 0;
    int curValue = 0;

    cout << "Cac goi duoc chon: ";
    for (int i = 1; i <= n; i++) {
        if (curWeight + x[i].w <= M) {
            curWeight += x[i].w;
            curValue += x[i].v;
            cout << x[i].id << " ";
        }
    }

    cout << "\nGia tri thu duoc: " << curValue << endl;

    return 0;
}
