class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(int i=0;i<magazine.size();i++){
            m[magazine[i]]+=1;
        }
        for(char c: ransomNote){
            if(m[c]==0)return false;
            m[c]-=1;
        }
        return true;
        
    }
};