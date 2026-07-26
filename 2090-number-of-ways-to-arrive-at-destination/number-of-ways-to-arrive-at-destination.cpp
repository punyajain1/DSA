class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int , int>>> adj(n);
        int a=roads.size();
        for(int i=0;i<a;i++){
            //adj[from]={to,time}
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n, 0);
        //start point and minimum distance or way to reach 0 is 0
        dist[0]=0;
        ways[0]=1;
        //pq contains-> distance,node
        pq.push({0,0});
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            long long d = temp.first;
            int node = temp.second;
            if (d > dist[node]) continue;

            for(auto it:adj[node]){
                int nt=it.second;
                int ne=it.first;

                if(d+nt < dist[ne]){
                    dist[ne] = d+nt;
                    ways[ne]=ways[node];
                    pq.push({dist[ne],ne});

                }else if(d+nt == dist[ne]){
                    ways[ne]=(ways[ne]+ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};