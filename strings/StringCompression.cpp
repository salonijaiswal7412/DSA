class Solution {
public:
    int compress(vector<char>& s) {
        int n=s.size();
        int j=0,c=1;
        for(int i=1;i<=n;i++){
            if(i<n && s[i]==s[i-1]){
                c++;
            }
            else{
                s[j++]=s[i-1];
                if(c>1){
                    for(auto ch: to_string(c)){
                        s[j++]=ch;
                    }
                }
                c=1;
            }
        }
        return j;
        
    }
};
