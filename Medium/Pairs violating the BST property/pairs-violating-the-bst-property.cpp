//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:

    void inorder(Node* root, vector<int> &ans) {
    if (root == NULL)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

int merge(int arr[], int l, int m, int r) {
    int a = l, b = m + 1;
    vector<int> v;
    int inversions = 0; 
    while (a <= m && b <= r) {
        if (arr[a] > arr[b]) {
            v.push_back(arr[b]);
            b++;
            inversions += (m - a + 1);
        } else {
            v.push_back(arr[a]);
            a++;
        }
    }
    while (a <= m) {
        v.push_back(arr[a]);
        a++;
    }
    while (b <= r) {
        v.push_back(arr[b]);
        b++;
    }
    for (int i = l; i <= r; i++) {
        arr[i] = v[i - l];
    }
    return inversions; 
}

int mergesort(int arr[], int l, int r) {
    int inversions = 0;
    if (l >= r)
        return inversions;
    int m = l + (r - l) / 2;
    inversions += mergesort(arr, l, m);
    inversions += mergesort(arr, m + 1, r);
    inversions += merge(arr, l, m, r);
    return inversions;
}

/*You are required to complete below function */
int pairsViolatingBST(int n, Node *root) {
    vector<int> ans;
    inorder(root, ans);
    return mergesort(ans.data(), 0, n - 1); 
}
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends