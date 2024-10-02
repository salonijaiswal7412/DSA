//using sorting and unique elements
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> m;
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        for(int i=0;i<temp.size();i++){
            m[temp[i]]=i+1;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=m[arr[i]];
        }
        return arr;
        
    }
};

//using set
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        set<int> s(a.begin(),a.end());
        unordered_map<int,int> m;
        int rank=1;

        for(auto i: s){
            m[i]=rank++;
        }
        for(auto& i:a){
            i=m[i];
        }
        return a;
        
    }
};