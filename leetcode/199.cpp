class Solution {
public:
    vector<vector<int>> lvl;

    void dfs(TreeNode* node, int d) {
        if (!node) return;

        if (d == lvl.size())
            lvl.push_back({});

        lvl[d].push_back(node->val);

        dfs(node->left, d + 1);
        dfs(node->right, d + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0

        vector<int> ans;

        for (auto &v : lvl)
            ans.push_back(v.back());
        return ans;
    }
};