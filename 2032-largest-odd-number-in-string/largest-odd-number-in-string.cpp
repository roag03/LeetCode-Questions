class Solution {
public:
    string largestOddNumber(string num) {
       int index=-1;
        string ans;
        for(int i=num.size();i>=0;i--)
        {
            int temp=(int)num[i];
            if(temp%2==1)
            {
                index=i;
                break;
            }
        }
        if(index==-1)
        return ans;
        return num.substr(0,index+1);
    }
};