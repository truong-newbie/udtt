#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[11][11];
int dp[11][11];

// ==================== NHAP DU LIEU ====================
void Nhap()
{
    cout << "Nhap m, n: ";
    cin >> m >> n;

    cout << "Nhap bang so tao:\n";
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
}

 void taoB (){
     cout << " bang so tao:\n";
    for (int i = 1; i <= m; i++){
         for (int j = 1; j <= n; j++){
             cout<< a[i][j]<<"  ";

        }cout<<endl;
    }



 }


// ==================== QUY HOACH DONG ====================
void QuyHoachDong()
{
    dp[1][1] = a[1][1];

    for (int i = 2; i <= m; i++)
        dp[i][1] = dp[i - 1][1] + a[i][1];

    for (int j = 2; j <= n; j++)
        dp[1][j] = dp[1][j - 1] + a[1][j];

    for (int i = 2; i <= m; i++)
        for (int j = 2; j <= n; j++)
            dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
}

// ==================== TRUY VET DUONG DI ====================
void TruyVet()
{
    cout << "\n--- QUY HOACH DONG ---";
    cout << "\nSo tao nhieu nhat: " << dp[m][n];
    cout << "\nDuong di: ";

    int i = m, j = n;
    while (i != 1 || j != 1)
    {
        cout << "(" << i << "," << j << ") ";
        if (i > 1 && dp[i][j] == dp[i - 1][j] + a[i][j])
            i--;
        else
            j--;
    }
    cout << "(1,1)";
}
// ==================== THAM LAM ====================
void ThamLam()
{
    int i = 1, j = 1;
    int tong = a[1][1];

    cout << "\n\n--- THAM LAM ---";
    cout << "\nDuong di: (1,1) ";

    while (i < m || j < n)
    {
        if (i == m)
            j++;
        else if (j == n)
            i++;
        else if (a[i + 1][j] > a[i][j + 1])
            i++;
        else
            j++;

        cout << "(" << i << "," << j << ") ";
        tong += a[i][j];
    }

    cout << "\nSo tao lay duoc (tham lam): " << tong;
}
int main()
{
    Nhap();
    taoB();

    QuyHoachDong();
    TruyVet();

    ThamLam();

    return 0;
}
