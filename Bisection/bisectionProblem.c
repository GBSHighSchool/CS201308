

#include <stdio.h>
FILE *fin;
FILE *fout;

// 도경이가 할 생각이 있는 최대 게임 수
long long L = 2000000000;

// b게임 중 a게임 승리했을 때의 승률
int ratio(long long b, long long a) {
	return (a * 100) / b;
}

// 최소 몇 연승해야 승률이 올라갈까?
int neededGames(long long games, long long won) {
	// 불가능한 경우를 미리 걸러낸다
	if(ratio(games, won) == ratio(games + L, won + L))
		return -1;
	long long lo = 0, hi = L;
	// 반복문 불변식: 
	// 1. lo 게임 이기면 승률은 변하지 않는다
	// 2. hi 게임 이기면 승률은 변한다
	while(lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		if(ratio(games, won) == ratio(games + mid, won + mid))
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

long long ceil(long long a, long long b) {
	return (a + b - 1) / b;
}


  	
int main() {
	
    int cases;
    fin = fopen("INPUT.txt","r");
    fout = fopen("OUTPUT.txt", "w");
    fscanf(fin, "%d", &cases);
    
    int cc;
    
    for(cc = 0; cc < cases; ++cc) {
    	int n, m;
    	fscanf(fin, "%d %d", &n, &m);
    	int a = neededGames(n, m);
    	fprintf(fout, "%d\n", a);
    }
    fclose(fin);
    fclose(fout);
}

