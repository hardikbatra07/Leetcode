class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>>st;
    int next(int price) 
    {
        int count=0;
        while(!st.empty() && st.top().first<=price)
        {
            count+=st.top().second+1;
            st.pop();
        }
        st.push({price,count});
        return count+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */