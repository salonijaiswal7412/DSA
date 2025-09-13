class Solution {
public:
    int maxFreqSum(string str) {
        unordered_map<char,int> m;
        for(char i:str){
            m[i]++;
        }
        int s1=0,s2=0;
        for(auto [i,j]:m){
            if(i=='a'||i=='e'||i=='o'||i=='i'||i=='u'){
                s1=max(s1,j);
            }
            else{
                s2=max(s2,j);
            }
        }
        return s1+s2;
    }
};
