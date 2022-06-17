class Solution {
public:
    int minCameraCover(const TreeNode* const root) {
        int count = 0;
        const function<Type(const TreeNode*)> solve = [&](const TreeNode* const node) {
            if (node == nullptr) {
                return Type::NONE;
            }

            const auto l = solve(node->left);
            const auto r = solve(node->right);

            if (l == Type::NONE && r == Type::NONE) {
                return Type::LEAF;
            }

            if (l == Type::LEAF || r == Type::LEAF) {
                ++count;
                return Type::INODE;
            }

            // Pretend this node doesn't exist because it's monitored by
            // a camera installed on a child node
            return Type::NONE;
        };

        const auto type = solve(root);
        return count + (type == Type::LEAF);
    }

private:
    enum class Type { NONE, LEAF, INODE };
};
