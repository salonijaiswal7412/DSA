class Trie {
public:
    class Node{
        public:
        vector<Node*> children;
        bool end;
        Node(){
            children.resize(26,0);
            end=0;
        }
    };
    Node* root;
    Trie() {
        root=new Node();

        
    }
     
    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(!temp->children[idx]){
                temp->children[idx]=new Node();
            }
            temp=temp->children[idx];
        }
        temp->end=true;
        
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(!temp->children[idx]){
                return false;
            }
            temp=temp->children[idx];
        }
        return temp->end;

        
    }
    
    bool startsWith(string word) {
         Node* temp=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(!temp->children[idx]){
                return false;
            }
            temp=temp->children[idx];
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
