//题目主要来源于leetcode

/*课程表
你这个学期必须选修numCourses门课程，记为0到numCourses-1 。
在选修某些课程之前需要一些先修课程。先修课程按数组prerequisites给出，其中prerequisites[i]=[ai,bi]，表示如果要学习课程ai则必须先学习课程bi 。
例如，先修课程对[0,1]表示：想要学习课程0，你需要先完成课程1 。
请你判断是否可能完成所有课程的学习？如果可以，返回true；否则，返回false。 */

//DFS
class Solution {
public:
    vector<int>visit;
    bool dfs(int v,vector<vector<int>>& g)
    {
        if (g[v].size() == 0)
            return true;
        if (visit[v] == -1)
            return true;
        if (visit[v] == 1)
            return false;
        visit[v] = 1;
        bool res = true;
        for (int i = 0; i < g[v].size(); i++)
        {
            res = dfs(g[v][i], g);
            if (res == false)
                break;
        }
        visit[v] =-1;
        return res;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        visit = vector<int>(numCourses + 1, 0);
        for (int i = 0; i < prerequisites.size(); i++)
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
        bool res = true;
          for(int i =0;i<numCourses;i++)
            for (int j = 0; j < g[i].size(); j++)
            {
                 res = dfs(g[i][j], g);
                 if (res == false)
                     return res;
            }
        return res;
    }
};



/*地图分析
你现在手里有一份大小为N x N的网格grid，上面的每个单元格都用0和1标记好了。
其中0代表海洋，1代表陆地，请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的。
我们这里说的距离是「曼哈顿距离」（Manhattan Distance）：(x0,y0)和(x1,y1)这两个单元格之间的距离是|x0-x1|+|y0-y1|。
如果网格上只有陆地或者海洋，请返回-1。  */


class Solution {
private:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

public:
    int maxDistance(vector<vector<int>>& grid) {
        const int xlen = grid.size();
        const int ylen = grid[0].size();

       deque<pair<int,int>> land;
        for(int i = 0;i < xlen;i++)
            for(int j = 0;j < ylen;j++)
                if(grid[i][j] == 1)
                    land.push_back({i,j});

        if(land.size() == 0 || land.size() == xlen * ylen)
            return -1;

        int res = -1;
        while(land.size() != 0)
        {
            res++;
            int len = land.size();
            while(len--)
            {
                auto cur = land.front();
                land.pop_front();
                for(const auto& c:directions)
                {
                    int x = cur.first + c[0];
                    int y = cur.second + c[1];
                    if(x < 0 || x >= xlen || y < 0 || y >= ylen || grid[x][y] != 0)
                        continue;
                    grid[x][y] = 2;
                    land.push_back({x,y});
                }
            }
        }
        return res;
    }
};
