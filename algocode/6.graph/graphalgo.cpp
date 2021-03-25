//��Ŀ��Ҫ��Դ��leetcode

/*�γ̱�
�����ѧ�ڱ���ѡ��numCourses�ſγ̣���Ϊ0��numCourses-1 ��
��ѡ��ĳЩ�γ�֮ǰ��ҪһЩ���޿γ̡����޿γ̰�����prerequisites����������prerequisites[i]=[ai,bi]����ʾ���Ҫѧϰ�γ�ai�������ѧϰ�γ�bi ��
���磬���޿γ̶�[0,1]��ʾ����Ҫѧϰ�γ�0������Ҫ����ɿγ�1 ��
�����ж��Ƿ����������пγ̵�ѧϰ��������ԣ�����true�����򣬷���false�� */

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



/*��ͼ����
������������һ�ݴ�СΪN x N������grid�������ÿ����Ԫ����0��1��Ǻ��ˡ�
����0������1����½�أ������ҳ�һ������Ԫ���������Ԫ�����������½�ص�Ԫ��ľ��������ġ�
��������˵�ľ����ǡ������پ��롹��Manhattan Distance����(x0,y0)��(x1,y1)��������Ԫ��֮��ľ�����|x0-x1|+|y0-y1|��
���������ֻ��½�ػ��ߺ����뷵��-1��  */


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
