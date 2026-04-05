class Solution {
public:
    bool judgeCircle(string moves) {
        int net_x = 0;
        int net_y = 0;

        for (char ch: moves) {
            if (ch == 'U') {
                net_y += 1;     
            } else if (ch == 'D') {
                net_y -= 1;
            } else if (ch == 'L') { 
                net_x -= 1;
            } else {
                net_x += 1;
            }
        }
        
        return (net_x == 0 && net_y == 0);
    }
};
