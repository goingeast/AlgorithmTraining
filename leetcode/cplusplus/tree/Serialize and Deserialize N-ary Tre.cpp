class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        ostringstream res;
        serializeHelper(root, res);
        return res.str();
    }
    
    void serializeHelper(Node* node, ostringstream& res) {
        if (!node) return;
        else {
            res << to_string(node->val);
            for (auto child : node->children) {
                res << " " << serializeHelper(child, res);
            }
            res << " #";
        }
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.empty()) return NULL;
        istringstream iss(data);
        return deserializeHelper(iss);
    }

    Node* deserializeHelper(istringstream& iss) {
        if(iss.empty()) return NULL;
        string val = "";
        iss >> val;
        if (val == "#") return NULL;
        Node *node = new Node(stoi(val), {});
        while(true){
            Node* ret = deserializeHelper(iss);
            if(ret == NULL) break;
            node->children.push_back(ret);
        }
        return node;
    }
};