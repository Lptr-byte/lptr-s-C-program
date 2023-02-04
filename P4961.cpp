#include <bits/stdc++.h>
const int MAXN = 1005;
int n, m, res = 0, Map[MAXN][MAXN], vis[MAXN][MAXN];
int dx[] = {0, 0, 1, 1, -1, -1, 1, -1};
int dy[] = {1, -1, 0, -1, 1, -1, 1, 0};

void dfs(int x, int y){
	vis[x][y] = 1;
	for(int i = 0; i < 8; i++){
		int tx = x + dx[i], ty = y +dy[i];
		if(tx < 1 || tx > n || ty < 1 || ty > m || vis[tx][ty])	
			continue;
		dfs(tx, ty);
	}
}

void init(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(Map[i][j] == 0){
				bool flag = true;
				for(int k = 0; k < 8; k++){
					int tx = i + dx[k], ty = j + dy[k];
					if(tx < 1 || tx > n || ty < 1 || ty > m)	continue;
					if(Map[tx][ty] != 0){	
						flag = false;
						break;
					}
				}
				if(flag)	Map[i][j] = 2;
			}
		}
	}
}

int main(){
	freopen("P4961#1.in", "r", stdin);
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			std::cin >> Map[i][j];
			if(Map[i][j] == 1)
				vis[i][j] = 1;
		}
	}
	init();
	for(int i = 1; i <= n; i++)
		for(int j  = 1; j <= m; j++)
			printf("%d%c", Map[i][j], (j == m) ? '\n' : ' ');
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(Map[i][j] == 0){
				bool flag = true;
				for(int k = 0; k < 8; k++){
					int tx = i + dx[k], ty = dy[k];
					if(Map[tx][ty] == 2){
						flag = false;
						break;
					}
				}
				if(flag) res++;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(Map[i][j] == -1){
				dfs(i, j);
				res++;
			}
		}
	}
	std::cout << res << std::endl;
	
	return 0;
}
