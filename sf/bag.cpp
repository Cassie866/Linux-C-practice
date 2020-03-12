#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N,V;
	while(cin >> N >> V)
	{
		vector<int> value(N);//存储每个物品的价值
		vector<int> capacity(N);//存储每个物品的容量
		for(int i = 0; i < N; ++i)
		{
			cin >> value[i] >> capacity[i];
		}
		vector<vector<int>> dp(N+1,vector<int>(V+1,0));
		//有N+1行，但是从1开始遍历，所以每行表示每个物品
		//有V+1列，但是从1开始遍历，所以每列表示从1开始到最大容量 的 各种情况下 的 物品最大价值
		for(int i = 1; i < N+1; ++i)
		{
			for(int j = 1; j < V+1; ++j)
			{
				if(capacity[i-1] > j)//如果不下，那就等于上次的最优存储
				{
					//这里的capacity[i-1]是因为这里的i从1开始
					dp[i][j] = dp[i-1][j];
				}
				else
				{
					int tmp_best = value[i-1] + dp[i-1][j-capacity[i-1]];
					dp[i][j] = max(tmp_best,dp[i-1][j]);
				}
			}
		}
		cout << dp[N][V] << endl;
	}
	return 0;
}
