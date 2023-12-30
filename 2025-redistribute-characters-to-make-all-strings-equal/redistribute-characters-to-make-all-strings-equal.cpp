class Solution {
public:
    bool makeEqual(vector<string>& words) {
      int n = words.size();
      
        vector<int> v(26, 0); 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                v[words[i][j] - 'a']++;
            }
        }

        for (auto it : v) {
            if (it % n != 0) {
                return false;
            }
        }

        return true;  
    }
};