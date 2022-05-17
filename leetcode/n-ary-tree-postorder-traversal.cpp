/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node*> st;
        st.push(root);
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        while (st.size() > 0) {
            Node *u = st.top();
            ans.push_back(u->val);
            st.pop();
            for (int i = 0; i < u->children.size(); i++) {
                st.push(u->children[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};