#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

        long long xK, yK;
        cin >> xK >> yK;

        long long xQ, yQ;
        cin >> xQ >> yQ;

        vector<pair<long long, long long>> moves = {
            {a, b}, {a, -b}, {-a, b}, {-a, -b},
            {b, a}, {b, -a}, {-b, a}, {-b, -a}
        };

        vector<pair<long long, long long>> kingPos;
        vector<pair<long long, long long>> queenPos;

        for (auto [dx, dy] : moves) {
            kingPos.push_back({xK + dx, yK + dy});
            queenPos.push_back({xQ + dx, yQ + dy});
        }

        int ans = 0;

        for (auto &k : kingPos) {
            for (auto &q : queenPos) {
                if (k == q) {
                    ans++;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}