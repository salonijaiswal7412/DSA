class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        auto split = [](const string& s) {
            vector<string> ans;
            string i = "";
            for (char c : s) {
                if (c == ' ') {
                    if (!i.empty()) {
                        ans.push_back(i);
                        i = "";
                    }
                } else {
                    i += c;
                }
            }
            if(!i.empty()) ans.push_back(i);
            return ans;
        };

        vector<string> a=split(sentence1);
        vector<string> b=split(sentence2);

        if(a.size()<b.size()) swap(a,b);
        int l=0,r=0,n1=a.size(),n2=b.size();
        while(l<n2 && a[l]==b[l]) l++;
        while(r<n2 && a[n1-r-1]==b[n2-r-1]) r++;

        return l+r>=n2;
    }
};