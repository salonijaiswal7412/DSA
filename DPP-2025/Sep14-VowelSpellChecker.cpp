class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> s(wordlist.begin(),wordlist.end());
        unordered_map<string,string> case_m;
        unordered_map<string,string> vowel_m;

        auto norm=[](const string& word){
            string ans=word;
            for(char& i:ans){
                if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u'){
                    i='*';
                }
            }
            return ans;
        };

        for(string& i: wordlist){
            string lower=i;
            transform(lower.begin(),lower.end(),lower.begin(),::tolower);
            if(!case_m.count(lower)){
                case_m[lower]=i;
            }

            string vowel=norm(lower);
            if(!vowel_m.count(vowel)){
                vowel_m[vowel]=i;
            }
        }

        vector<string> ans;
        for(string& i:queries){
            if(s.count(i)){
                ans.push_back(i);
                continue;
            }

            string l=i;
            transform(l.begin(),l.end(),l.begin(),::tolower);
            if(case_m.count(l)){
                ans.push_back(case_m[l]);
                continue;
            }

            string v=norm(l);
            if(vowel_m.count(v)){
                ans.push_back(vowel_m[v]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
        
    }
};
