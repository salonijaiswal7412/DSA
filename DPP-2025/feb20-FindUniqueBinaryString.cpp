class Solution {
public:
    string generate(string curr,int n,unordered_set<string>& s){
        if(curr.size()==n){
            if(s.find(curr)==s.end()){
                return curr;
            }
            return "";
        }
        string zero=generate(curr+'0',n,s);
        if(zero.size()>0) return zero;

        return generate(curr+'1',n,s);

    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s;
        for(auto i: nums){
            s.insert(i);
        }
        int n=nums.size();
        return generate("",n,s);
        
        
        
    }
};
