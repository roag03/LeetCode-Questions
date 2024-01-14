class Solution {
public:
    bool closeStrings(string word1, string word2) {
       unordered_map<char, int> mp1, mp2, mp3, mp4;
        // existence checking
        for(auto i : word1) mp1[i]++, mp3[i] = 1;
        for(auto i : word2) mp2[i]++, mp4[i] = 1;
        if(mp4 != mp3) return false;
        // checking if we can swap
        multiset<int> s1, s2;
        for(auto [c, f] : mp1) s1.insert(f);
        for(auto [c, f] : mp2) s2.insert(f);
        return s1 == s2;  
    }
};