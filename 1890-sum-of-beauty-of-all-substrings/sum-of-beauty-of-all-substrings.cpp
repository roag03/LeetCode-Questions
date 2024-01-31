class Solution {
public:
    int beautySum(string s) {
         int ans = 0;
        for(int i=0;i<s.length();i++)
        {
            map<char,int> mp;
            for(int j=i;j<s.length();j++)
            {
                int mx = 0,mn = 501;
                mp[s[j]]++;
                for(auto it : mp)
                {
                    mx = max(mx,it.second);
                    mn = min(mn,it.second);
                }
                ans += mx - mn;
            }
        }
        return ans;
    }
};