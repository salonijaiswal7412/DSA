class Solution {
public:
    int passThePillow(int n, int time) {
        bool dir=true;
        while(time>=n){
            dir=(dir==true)?false:true;
            time=time-n+1;
        }
        if(dir==true){
            return time+1;
        }
        else return n-time;
        
    }
};
