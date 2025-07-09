class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,vector<int>> neighbours;
        int maxi = 0;
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            neighbours[a].push_back(b);
            neighbours[b].push_back(a);
    }
    cout << "meow?"<< endl;
    for (auto x = neighbours.begin(); x != neighbours.end(); x++) {
        cout << x->first << endl;
        cout << x->second.size() << endl;
        if ((x->second).size() == edges.size()) {
            return x->first;
        }
    }
        return -1;
    }

};
