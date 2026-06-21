#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int &x : a)
         cin >> x;

        bool changed = true;
        while(changed) {
            changed = false;
            for(int i = 1; i < n-1; i++)
                if(a[i-1] < a[i] && a[i] > a[i+1]) {
                    swap(a[i], a[i+1]);
                    changed = true;
                }
        }

        if(is_sorted(a.begin(), a.end())) 
        
        cout << "YES\n";

        else cout << "NO\n";
    }
}