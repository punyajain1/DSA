class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //max heap (pq is already sorted in decreasing order)
        priority_queue<pair<int, pair<int, int>>> pq;
        for(auto x:points){
            //as other point is 0,0 so we only consider the x^2 + y^2
            int dist=x[0]*x[0] + x[1]*x[1];
            pq.push({dist , {x[0],x[1]}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};
