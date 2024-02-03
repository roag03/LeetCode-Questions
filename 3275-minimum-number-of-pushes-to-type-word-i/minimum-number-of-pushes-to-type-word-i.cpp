class Solution {
public:
    int minimumPushes(string word) {
     int k=1,ans=0,i=0,count=0;
        while(i<word.size()){
            count++;
            ans+=k;
            i++;
            if(count==8){
                ++k;
                count=0;
            }
            
        }
        return ans;}
};