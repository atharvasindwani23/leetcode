class FoodRatings {
public:
    unordered_map<string, pair<int, string>> foodItems;        // food → {rating, cuisine}
    unordered_map<string, map<int, set<string>>> cuisineMap;   // cuisine → {rating → foods}

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            string food = foods[i], cuis = cuisines[i];
            int rate = ratings[i];
            foodItems[food] = {rate, cuis};
            cuisineMap[cuis][rate].insert(food);
        }
    }

    void changeRating(string food, int newRating) {
        auto &[rating, cuis] = foodItems[food];
        int oldRating = rating;
        rating = newRating;

        auto &rMap = cuisineMap[cuis];
        rMap[oldRating].erase(food);
        if (rMap[oldRating].empty()) rMap.erase(oldRating);
        rMap[newRating].insert(food);
    }

    string highestRated(string cuisine) {
        auto &rMap = cuisineMap[cuisine];
        auto it = prev(rMap.end());             // highest rating
        return *it->second.begin();             // lexicographically smallest food
    }
};

