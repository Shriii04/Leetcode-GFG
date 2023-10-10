//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        map<Node*, Node*>mp;
        queue<Node*>q;
        q.push(root);
        root = NULL;
        while(q.size()>0)
        {
            Node* x = q.front();
            q.pop();
            if(root == NULL and x->data == target)
                root = x;
            if(x->left != NULL)
            {
                q.push(x->left);
                mp[x->left]=x;
            }
            if(x->right != NULL)
            {
                q.push(x->right);
                mp[x->right]=x;
            }
        }
        
        map<Node*,int>dis;
        q.push(root);
        dis[root]=0;
        vector<int>ans;
        while(q.size()>0)
        {
            Node* x = q.front();
            q.pop();
            if(dis[x]==k)
            {
                ans.push_back(x->data);
                continue;
            }
            if(x->left and dis.count(x->left)==0)
            {
                q.push(x->left);
                dis[x->left]=dis[x]+1;
            }  
            if(x->right and dis.count(x->right)==0)
            {
                q.push(x->right);
                dis[x->right]=dis[x]+1;
            }  
            if(mp[x] and dis.count(mp[x])==0)
            {
                q.push(mp[x]);
                dis[mp[x]]=dis[x]+1;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends