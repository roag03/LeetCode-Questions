class Solution {
public:
    string longestPalindrome(string s) {
         int n = s.size();
        int Start = 0;
        int maxLen = 1;

        for(int k=0; k<n; k++) {
            int i = k-1;
            int j = k;

            while(i>=0 && j<n && s[i]==s[j]) {
                if(j-i+1 >  maxLen) {
                    maxLen = j-i+1;
                    Start = i;
                }
                i--; j++;
            }

            i = k-1;
            j = k+1;

            while(i>=0 && j<n && s[i]==s[j]) {
                if(j-i+1 >  maxLen) {
                    maxLen = j-i+1;
                    Start = i;
                }
                i--; j++;
            }
        } 
        return s.substr(Start, maxLen);
    }
};