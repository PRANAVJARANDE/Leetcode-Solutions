class Solution {
public:
   
    vector<int> helper(string& input) {
        vector<int> numbers;
        regex re("id(\\d+)"); 
        sregex_iterator it(input.begin(), input.end(), re);
        sregex_iterator end;

        while (it != end) {
            numbers.push_back(stoi((*it)[1])); 
            ++it;
        }

        return numbers;
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        
        vector<int> mentions(numberOfUsers, 0);  
        vector<int> status(numberOfUsers, 0);  

        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int timeA = stoi(a[1]);
            int timeB = stoi(b[1]);
            if (timeA != timeB) {
                return timeA < timeB;
            }
            return a[0] > b[0];
        });
        
        // for(auto x:events)
        // {
        //     cout<<x[1]<<" "<<x[0]<<endl;
        // }
        // cout<<endl;
        
        
    
        for (const auto& event : events) 
        {
            string type = event[0];
            int timestamp = stoi(event[1]);

            if (type == "MESSAGE") {
                string mentionsString = event[2];

                if (mentionsString == "ALL") {
                    // Mention all users
                    for (int i = 0; i < numberOfUsers; i++) {
                        mentions[i]++;
                    }
                } else if (mentionsString == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (status[i] <= timestamp) {
                            mentions[i]++;
                        }
                    }
                } else {
                    // Mention specific users
                    vector<int> specificMentions = helper(mentionsString);
                    for (int id : specificMentions) {
                        mentions[id]++;
                    }
                }
            } else if (type == "OFFLINE") {
                int userId = stoi(event[2]);
                status[userId] = timestamp + 60;    
            }
        }

        return mentions;
    }
};
