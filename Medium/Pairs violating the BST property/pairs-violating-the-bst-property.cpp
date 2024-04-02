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
    
 private:
    int merge(int arr[], int s, int e, int mid) {
        int inv_count = 0;
        int n1 = mid - s + 1;
        int n2 = e - mid;

        vector<int> arr1(n1);
        vector<int> arr2(n2);

        for (int i = 0; i < n1; i++)
            arr1[i] = arr[s + i];
        for (int j = 0; j < n2; j++)
            arr2[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = s;

        while (i < n1 && j < n2) {
            if (arr1[i] <= arr2[j]) {
                arr[k++] = arr1[i++];
            } else {
                arr[k++] = arr2[j++];
                inv_count += (n1 - i); // Count inversions
            }
        }

        while (i < n1)
            arr[k++] = arr1[i++];

        while (j < n2)
            arr[k++] = arr2[j++];

        return inv_count;
    }

    int MergeSort(int arr[], int s, int e) {
        int inv_count = 0;
        if (s < e) {
            int mid = (s + e) / 2;
            inv_count += MergeSort(arr, s, mid);
            inv_count += MergeSort(arr, mid + 1, e);
            inv_count += merge(arr, s, e, mid);
        }
        return inv_count;
    }

    void inorderTraversal(Node* curr, vector<int>& arr) {
        if (curr == NULL)
            return;

        inorderTraversal(curr->left, arr);
        arr.push_back(curr->data);
        inorderTraversal(curr->right, arr);
    }

public:
    int pairsViolatingBST(int n, Node* root) {
        vector<int> arr;
        inorderTraversal(root, arr);
        int inv_count = MergeSort(arr.data(), 0, arr.size() - 1);
        return inv_count;
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