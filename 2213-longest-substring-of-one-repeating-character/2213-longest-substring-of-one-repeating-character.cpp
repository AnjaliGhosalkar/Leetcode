class Solution {
public:

    struct Node {
        char leftChar, rightChar;
        int prefix, suffix, best, len;
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {

        Node res;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;
        res.len = a.len + b.len;

        // Prefix
        res.prefix = a.prefix;

        if (a.leftChar == b.leftChar && a.prefix == a.len) {
            res.prefix = a.len + b.prefix;
        }

        // Suffix
        res.suffix = b.suffix;

        if (a.rightChar == b.rightChar && b.suffix == b.len) {
            res.suffix = b.len + a.suffix;
        }

        // Best answer
        res.best = max(a.best, b.best);

        // Join left suffix + right prefix
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suffix + b.prefix);
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {

        if (l == r) {
            tree[node] = {
                s[l],   // leftChar
                s[l],   // rightChar
                1,      // prefix
                1,      // suffix
                1,      // best
                1       // len
            };
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    void update(int node, int l, int r,
                int index, char ch) {

        if (l == r) {
            tree[node] = {
                ch, ch,
                1, 1, 1, 1
            };
            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, ch);
        } else {
            update(node * 2 + 1, mid + 1, r, index, ch);
        }

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n);

        // Build segment tree
        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            // Update character
            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            // Root stores the longest repeating substring
            ans.push_back(tree[1].best);
        }

        return ans;
    }
};