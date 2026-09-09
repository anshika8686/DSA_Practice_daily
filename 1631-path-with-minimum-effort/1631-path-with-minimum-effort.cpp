class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        // {effort, {row, col}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        while(!pq.empty()) {

            auto [currEffort, cell] = pq.top();
            pq.pop();

            int row = cell.first;
            int col = cell.second;

            // Ignore stale entry
            if(currEffort > dist[row][col])
                continue;

            if(row == n-1 && col == m-1)
                return currEffort;

            for(int i = 0; i < 4; i++) {

                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m) {

                    int edgeEffort =
                        abs(heights[nrow][ncol] - heights[row][col]);

                    int newEffort =
                        max(currEffort, edgeEffort);

                    if(newEffort < dist[nrow][ncol]) {

                        dist[nrow][ncol] = newEffort;

                        pq.push({
                            newEffort,
                            {nrow, ncol}
                        });
                    }
                }
            }
        }

        return -1;
    }
};