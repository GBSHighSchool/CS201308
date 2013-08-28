
#include <stdio.h>

double t;
double runSpeed[30], cycleSpeed[30];
int competitors;
FILE *fin;
FILE *fout;

// �޸��� ������ ���̰� run�� ��, i�� ������ �ɸ��� �ð�
double time(int i, double run) {
	double cycle = t - run;
	return run / runSpeed[i] + cycle / cycleSpeed[i];
}

double min(double a, double b) {
	return a > b ? b : a;
}

// �޸��� ���� ���̰� r�� ��, others(r) - cheater(r) �� ��ȯ�Ѵ�.
double diff(double r) {
	int n = competitors;
	double cheater = time(n-1, r);
	double others = time(0, r);
	int i;
	for(i = 1; i < n-1; ++i) 
		others = min(others, time(i, r));
	return others - cheater;
}

// diff() �Լ��� �ִ밪�� ��ġ�� ��� �˻����� ����Ѵ�.
double maxDifference() {
	double lo = 0, hi = t;
	int it;
	for(it = 0; it < 100; ++it) {
		double aab = (2*lo + hi) / 3;
		double abb = (lo + 2*hi) / 3;
		if(diff(aab) > diff(abb))
			hi = abb;
		else
			lo = aab;
	}
	return (lo + hi) / 2;
}

int main() {
    
    fin = fopen("INPUT.txt", "r");
    fout = fopen("OUTPUT.txt", "w");
    
    while (fscanf(fin, "%lf", &t) != EOF) {
    	
    	fscanf(fin, "%d", &competitors);
    	int i;
    	for (i = 0; i < competitors; i++) {
    		fscanf(fin, "%lf %lf", &runSpeed[i], &cycleSpeed[i]);
		}
    	double ret = maxDifference();
    	double timeDiff = diff(ret);
    	printf("ret = %f, timeDiff = %f\n", ret, timeDiff);
    	if(timeDiff < 0)
    		fprintf(fout, "The cheater cannot win.\n");
		else
			fprintf(fout, "The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n",
					timeDiff * 3600,
					ret,
					t - ret);
    		
		
	}
	int i;
	for (i = 0; i < competitors; i++) {
		printf("%f %f\n", runSpeed[i], cycleSpeed[i]);
	}
	fclose(fin);
	fclose(fout);
	
}


