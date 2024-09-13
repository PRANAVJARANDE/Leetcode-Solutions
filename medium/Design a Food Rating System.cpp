struct comp{
    bool operator()(const pair<string,int> &a,const pair<string,int> &b)const{
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
};


class FoodRatings {
public:

    unordered_map<string,pair<string,int>> m;
    unordered_map<string,set<pair<string,int>,comp>> rat;

    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        for(int i=0;i<f.size();i++)
        {
            m[f[i]]={c[i],r[i]};
            rat[c[i]].insert({f[i],r[i]});
        }
    }
    
    void changeRating(string food, int newR) {
        int org=m[food].second;
        string cc=m[food].first;
        m[food].second=newR;
        rat[cc].erase({food,org});
        rat[cc].insert({food,newR});
    }
    
    string highestRated(string ca) {
        return rat[ca].begin()->first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
