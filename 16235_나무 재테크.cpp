# include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K; // N:땅의크기, M : 나무의 개수, K : K년이 지나고 얼마나 나무가 남았는지

	int A[11][11];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j]; // 각 칸에 추가되는 양분
		}
	}
	int tree[11][11]; // 나무의 나이 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			tree[i][j] = 0;
		}
	}
	int x, y, z;
	for (int i = 1; i <= M; i++) {
		cin >> x >> y >> z; //x,y : 나무의 위치(x,y), z : 나무의 나이
		tree[x][y] = z;
	} 

	int map[11][11];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = 5; // 양분의 초기값
		}
	}


	/*
	봄 : 나무가 자신의 나이만큼 양분을 먹음, 나이가 1증가.	하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다. 만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는
	양분을 먹지 못하고 즉시 죽는다.

	여름에는 봄에 죽은 나무가 양분으로 변하게 된다. 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다.
	소수점 아래는 버린다.

	가을에는 나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 8개의 칸에 나이가 1인 나무가 생긴다.
	어떤 칸 (r, c)와 인접한 칸은 (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1) 이다.
	상도의 땅을 벗어나는 칸에는 나무가 생기지 않는다.

	겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다.
*/
	while (K > 0) {
		//봄

		//여름
		//가을
		//겨울
	}
}