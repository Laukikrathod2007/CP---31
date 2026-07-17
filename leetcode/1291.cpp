class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";

        for (int len = 2; len <= 9; len++) {
            for (int start = 0; start + len <= 9; start++) {

                int num = stoi(s.substr(start, len));

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};

//Brute force approach

class Solution {
public:
    bool isSequential(int num) {
        string s = to_string(num);

        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1] + 1)
                return false;
        }
        return true;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for (int i = low; i <= high; i++) {
            if (isSequential(i))
                ans.push_back(i);
        }

        return ans;
    }
};


clear