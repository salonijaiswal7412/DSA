class Solution {
public:
    int thirdMax(vector<int>& n) {
        sort(n.begin(),n.end());
        n.erase(unique(n.begin(),n.end()),n.end());
        
        if(n.size()<3){
            return n[n.size()-1];
        }
        else return n[n.size()-3];
        
    }
};
