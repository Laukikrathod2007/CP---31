#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int odd = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2 != 0)
                odd++;
        }

        if (odd % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}