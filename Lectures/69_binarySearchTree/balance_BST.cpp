#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    void formArray(TreeNode *root, vector<int> &arr)
    {
        if (root == nullptr)
        {
            return;
        }

        formArray(root->left, arr);
        arr.push_back(root->val);
        formArray(root->right, arr);
    }

    TreeNode *formBST(vector<int> &arr, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }

        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(arr[mid]);

        root->left = formBST(arr, start, mid - 1);
        root->right = formBST(arr, mid + 1, end);

        return root;
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> arr;
        formArray(root, arr);

        return formBST(arr, 0, arr.size() - 1); // Corrected here
    }
};

TreeNode *createBST(TreeNode *root, int data)
{
    if (root == nullptr)
    {
        root = new TreeNode(data);
        return root;
    }

    if (data < root->val)
    {
        root->left = createBST(root->left, data);
    }
    else
    {
        root->right = createBST(root->right, data);
    }

    return root;
}

void takeData(TreeNode *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = createBST(root, data);
        cin >> data;
    }
}

void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    TreeNode *root = nullptr;
    cout << "Enter data to create BST (enter -1 to stop):" << endl;
    takeData(root);

    Solution sln;
    TreeNode *balancedRoot = sln.balanceBST(root);
    cout << "Balanced BST created successfully." << endl;

    cout << "Inorder traversal of balanced BST: ";
    inorderTraversal(balancedRoot);
    cout << endl;

    return 0;
}
