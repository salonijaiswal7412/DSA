class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans=0;
        unordered_set<char> s;
        for(char i:allowed){
            s.insert(i);
        }
        for(int i=0;i<words.size();i++){
            bool f=true;
            for(char j:words[i]){
                if(s.find(j)==s.end()) f=false;
            }
            if(f==true)ans++;
        }
        return ans;
    }
};