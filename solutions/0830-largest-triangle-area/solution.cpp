class Solution {
public:
        double largestTriangleArea(vector<vector<int>>& p) {
        double res = 0;
        for (auto &i : p)
            for (auto &j : p)
                for (auto &k : p)
            res = max(res, 0.5 * abs(i[0] * j[1] + j[0] * k[1] + k[0] * i[1]- j[0] * i[1] - k[0] * j[1] - i[0] * k[1]));
        return res;
    }

        //the reason im finding this slightly tricky is because im a bit unaware of
        //lets say we sort them according to x coord, e
    //formula will be 0.5 * b * h the obv goal is to maximize x difference and y difference, q is how do we do this

};
