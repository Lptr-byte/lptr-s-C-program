#include <bits/stdc++.h>
int n, m, Map[105][105], ans = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int color){
	Map[x][y] = color;
	for(int i = 0; i < 4; i++){
		int tx = x + dx[i], ty = y + dy[i];
		if(tx < 1 || tx > n || ty < 1 || ty > m || Map[tx][ty] <= 0)
			continue;
		dfs(tx, ty, color);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		char c[20];
		scanf("%s", c);
		for(int j = 0; j < m; j++){
			Map[i][j + 1] = c[j] - '0';
		}
	}
	int color = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(Map[i][j] > 0){
				ans++;
				color--;
				dfs(i, j, color);
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}
