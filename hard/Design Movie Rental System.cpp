class MovieRentingSystem {
public:

    //Search 
    // map<int,set<int>>movie_to_shop_ur {Movie, unrented movies in these shops}
    //just return the set as answer

    //Rent 
    //remove that entry of shop from set movie_to_shop_ur
    // map<int,set<int>>movie_to_shop_r add this movie to shop

    //Drop
    //if movie present in movie_to_shop_r then remove it and put it in unrented

    //report
    //List of cheapest rented movies 
    // set {price , shop , movie} rented


    //later on optimize map to vector ****************

    map<int,set<pair<int,int>>>movie_to_shop_ur; //{price,shop}
    set<vector<int>>list_of_rented;              // {price,shop,movie}
    map<pair<int,int>,int>price_mappings;        // {shop,movie}->price

    MovieRentingSystem(int n, vector<vector<int>>& entries) 
    {
        for(auto x:entries)
        {
            movie_to_shop_ur[x[1]].insert({x[2],x[0]});
            price_mappings[{x[0],x[1]}]=x[2];
        }
    }
    
    vector<int> search(int movie)
    {
        int cnt=5;
        auto itr=movie_to_shop_ur[movie].begin();
        vector<int>ans;
        while(itr!=movie_to_shop_ur[movie].end() && cnt--)
        {
            ans.push_back((*itr).second);
            itr++;
        }
        return ans;
    }
    
    void rent(int shop, int movie) 
    {
        movie_to_shop_ur[movie].erase({price_mappings[{shop,movie}],shop});
        list_of_rented.insert({price_mappings[{shop,movie}],shop,movie});
    }
    
    void drop(int shop, int movie) 
    {
        movie_to_shop_ur[movie].insert({price_mappings[{shop,movie}],shop});
        list_of_rented.erase({price_mappings[{shop,movie}],shop,movie});
    }
    
    vector<vector<int>> report() 
    {
        int cnt=5;
        auto itr=list_of_rented.begin();
        vector<vector<int>> ans;
        while(itr!=list_of_rented.end() && cnt--)
        {
            ans.push_back({(*itr)[1],(*itr)[2]});
            itr++;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
