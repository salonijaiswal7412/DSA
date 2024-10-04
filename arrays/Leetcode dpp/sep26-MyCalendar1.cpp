class MyCalendar {
public:
    unordered_map<int,int> m;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto i:m){
            int a=i.first,b=i.second;
            if(!(end<=a || start>=b)) return false;
        }
        m[start]=end;
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */