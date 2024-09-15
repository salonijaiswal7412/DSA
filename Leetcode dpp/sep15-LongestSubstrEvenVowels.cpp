class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<char> a(26,0);
        a[0]=1;
        a['e'-'a']=2;
        a['i'-'a']=4;
        a['o'-'a']=8;
        a['u'-'a']=16;       
        unordered_map<int,int> m;
        int x=0;
        m[x]=-1;
        int ans=0;
        for(int i=0;i<s.size();i++){
            x^=a[s[i]-'a'];
            if(m.find(x)!=m.end()){
                ans=max(ans,i-m[x]);

            }
            else{
                m[x]=i;
            }

        }return ans; 
        
    }
};