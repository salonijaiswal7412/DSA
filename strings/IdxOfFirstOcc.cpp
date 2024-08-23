class Solution {
public:
    int strStr(string h, string n) {
        int s=n.size();
        if(h.size()<s) return -1;
        if(h.size()==s) 
        {
            if(h==n) return 0;
            else return -1;
        }
        string str="";
        str=h.substr(0,s);
        int l=0;
        while((l+s)<=h.size()){
            str=h.substr(l,s);
            if(str==n){
                return l;
            }
            l++;
        }
        return -1;


        
    }
};
