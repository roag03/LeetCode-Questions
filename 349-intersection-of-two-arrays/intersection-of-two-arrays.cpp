class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        set<int>st1(nums1.begin(),nums1.end());
        set<int>st2(nums2.begin(),nums2.end());
        for(auto it1:st1){
            for(auto it2:st2){
                if (it1==it2){
                    ans.push_back(it1);
                }
            }
        }
        return ans;
    }
};