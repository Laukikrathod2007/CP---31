class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int n = s.size();
        int ans = 0;

        // Try removing every 1-block
        for (int i = 0; i < n; i++) {

            if (s[i] == '0')
                continue;

            int j = i;
            while (j < n && s[j] == '1')
                j++;

            // It must be surrounded by zeros
            if (i == 0 || j == n || s[i - 1] == '1' || s[j] == '1') {
                i = j - 1;
                continue;
            }

            string t = s;

            // Remove this 1-block
            for (int k = i; k < j; k++)
                t[k] = '0';

            // Find merged zero block
            int l = i;
            while (l > 0 && t[l - 1] == '0')
                l--;

            int r = j - 1;
            while (r + 1 < n && t[r + 1] == '0')
                r++;

            // Flip merged block
            for (int k = l; k <= r; k++)
                t[k] = '1';

            int cnt = 0;
            for (char c : t)
                if (c == '1')
                    cnt++;

            ans = max(ans, cnt);

            i = j - 1;
        }

        return ans;
    }
};