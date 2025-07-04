/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)   return "";
        //do a simple level order traversal and create a string
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int qsize = q.size();
            for(int i=0; i<qsize; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node == nullptr)    s.append("#,"); //if child is nullptr add "#,"
                else s.append(to_string(node->val) + ","); //else convert the number to str and add
                if(node != nullptr){ //if our current node isn't nullptr
                    q.push(node->left); //add its left and right irrespective of
                    q.push(node->right); //the left and right are nullptr or actual numbers
                }
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)   return nullptr;
        //create a stringstream so that you can get separated strings using delimiter
        stringstream s(data);
        string str;
        getline(s, str, ','); //takes the stream, separates using "," and puts it into str 
        TreeNode* root = new TreeNode(stoi(str)); //create a root node by converting str into int
        //do level order traversal to create the tree 
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front(); //take the node from the queue
            q.pop();
            getline(s, str, ','); //pick the string from the stringstream
            //add the next number or nullptr to the left
            if(str == "#")  node->left = nullptr;
            else { //if its a number then create a node then add to the left
                TreeNode* leftc = new TreeNode(stoi(str));
                node->left = leftc;
                q.push(leftc); //push into queue this node to be traversed later
            }
            getline(s, str, ','); //pick the string from the stringstream
            //add the next number or nullptr to the right
            if(str == "#")  node->right = nullptr;
            else { //if its a number then create a node then add to the right
                TreeNode* rightc = new TreeNode(stoi(str));
                node->right = rightc;
                q.push(rightc); //push into queue this node to be traversed later
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));