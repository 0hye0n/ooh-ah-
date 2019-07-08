#include <bits/stdc++.h>

using namespace std;

int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1};
int visit[1001][1001];
int a[1001][1001];
queue<pair<pair<int, int>, int> > q;
int m, n;
int ans = -1;

int main(void) {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1) {
				q.push({ { i, j }, 0 });
				visit[i][j] = 1;
			}
			else if (a[i][j] == -1) {
				visit[i][j] = 1;
			}
		}
	}
	
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		if (z > ans) ans = z;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = x + dx[i];
			int nc = y + dy[i];
			if (0 <= nc && 0 <= nr && nc < m && nr < n && visit[nr][nc] == 0 && a[nr][nc] == 0) {
				visit[nr][nc] = 1;
				q.push({ {nr,nc}, z + 1 });
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == 0) ans = -1;
		}
	}
	printf("%d\n", ans);
	return 0;
}