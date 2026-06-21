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

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        unordered_map<int, int> maxA, maxB;

        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && a[j] == a[i]) j++;

            int length = j - i;
            maxA[a[i]] = max(maxA[a[i]], length);

            i = j;
        }

        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && b[j] == b[i]) j++;

            int length = j - i;
            maxB[b[i]] = max(maxB[b[i]], length);

            i = j;
        }

        int ans = 0;

        for (auto &[value, lenA] : maxA) {
            int lenB = maxB[value];
            ans = max(ans, lenA + lenB);
        }

        for (auto &[value, lenB] : maxB) {
            if (!maxA.count(value)) {
                ans = max(ans, lenB);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}