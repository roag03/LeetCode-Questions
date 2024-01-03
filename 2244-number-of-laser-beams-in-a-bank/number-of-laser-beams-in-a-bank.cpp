class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
           int prevSecDevCnt = 0, rows = bank.size(), cols = bank[0].size(), laserCnt = 0;
        for(int r = 0; r < rows; r++){
            int curSecDevCnt = 0;
            for(int c = 0; c < cols; c++){
                curSecDevCnt += bank[r][c] - '0';   
            }
            laserCnt  += curSecDevCnt * prevSecDevCnt;
            if(curSecDevCnt > 0)
                prevSecDevCnt = curSecDevCnt;
        }
        return laserCnt;
    }
};