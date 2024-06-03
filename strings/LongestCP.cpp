class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp=strs[0];
        if(strs.empty())return "";
        for(string i:strs){
            while(i.find(lcp)!=0){
                lcp=lcp.substr(0,lcp.length()-1);
                
            }
            if(lcp=="")return "";

        }
        return lcp;
        
    }
};
