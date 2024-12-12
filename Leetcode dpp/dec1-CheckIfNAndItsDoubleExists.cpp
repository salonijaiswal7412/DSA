class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> s;
        for(auto i:arr){
            if(i%2==0){
                if(s.find(i/2)!=s.end()) return true;
            }
            if(s.find(i*2)!=s.end()) return true;

            s.insert(i);
        }
        return false;


        
    }
};
