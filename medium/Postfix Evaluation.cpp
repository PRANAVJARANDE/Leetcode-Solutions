class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        
        stack<int>s1;
        for(auto x:arr)
        {
            if(x=="*" || x=="+" || x=="-" || x=="/" || x=="^")
            {
                int i1=s1.top();
                s1.pop();
                int i2=s1.top();
                s1.pop();
                if(x=="*")s1.push(i1*i2);
                else if(x=="-")s1.push(i2-i1);
                else if(x=="+")s1.push(i1+i2);
                else if(x=="/") s1.push(floor((double)i2/i1));
                else s1.push(pow(i2,i1));
            }
            else
            {
                s1.push(stoi(x));
            }
        }
        return s1.top();
    }
};
