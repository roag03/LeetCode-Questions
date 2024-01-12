class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
          int n=nums.size();
        int res=0;
        unordered_map<int, int > mp;
        
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(nums[i]==0 || i==n-1){
                res= max(res,mp[1]);
                mp.clear(); 
            }
            
        }
        return res;
    }
};