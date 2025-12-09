class Solution {
public:
    int hIndex(vector<int>& citations) {
        //[0, 1, 3, 5, 6]
        //for h = 5, citations[len - h] >= h

        sort(citations.begin(), citations.end());

        int h = citations.size();

        while (h > 0) {
            if (citations[citations.size() - h] >= h) {
                return h;
            }
            h--;
        }
        return 0;
    }

    //n papers should have n citations
    // work backward and conclude from there
    //5 papers should have 5 citations
    //4 papers should have 4 citations
    //..
    //..
};
