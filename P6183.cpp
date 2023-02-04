#include <bits/stdc++.h>
using namespace std;
int n, vis[32800], temp[20], ans[32800][20], goal[20];

bool check(){
	int a = 0;
	for(int i = 1; i <= n; i++)
		a += temp[i];
	if(a == 1)
		return true;
	return false;
}

int Hash(){
	int res = 0;
	for(int i = 1; i <= n; i++)
		if(temp[i])
			res += (1 << (i - 1));
	return res;
}

void print(){
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 1; j <= n; j++) {
			if (ans[i][j] == 0)
				cout << "O";
			else
              cout << "X";
            if (j == n)
              cout << endl;
          }
    }
	for(int i = 1; i <= n; i++)
		cout << "O";
	cout << endl;
}

void dfs(int step){
	if(step == (1 << n)){
		if(check()){
			print();
			exit(0);
		}
		return;
	}
	for(int i = 1; i <= n; i++){
		temp[i] = !temp[i];
		int h = Hash();
		//cout << "step" << step << ":" << "hash = " << h <<endl;
		//for(int i = 1; i <= 20; i++)
		//	cout << temp[i];
		//cout << endl;
		if(!vis[h]){
			vis[h] = 1;
			memcpy(ans[step], temp, sizeof(temp));
			dfs(step + 1);
			vis[h] = 0;
		}
	}
}

void solve(){
	cin >> n;
	vis[0] = 1;
	dfs(1);
}

int main(){
	solve();
	return 0;
}
