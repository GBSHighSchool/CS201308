#include <stdio.h>
#include <math.h>


void swap(double *a, double *b) {
	double temp = *a;
	*a = *b;
	*b = temp;
}


double f(double x) {
	return cos(x);
}

int main() {
	const double PI = 2.0 * acos(0);
	printf("%.10lf\n", bisection(PI*0.2, PI*1.2));
	
}

double bisection(double lo, double hi) {
	double flo = f(lo), fhi = f(hi);
	if(flo == 0) return lo;
	if(fhi == 0) return hi;
	if(flo > 0) {
		swap(&lo, &hi);
		swap(&flo, &fhi);
	}

	int i;
	
	for(i = 0; i < 100; i++) {
	     double mid = (lo + hi) / 2;
	     double fmid = f(mid);
	     if(fmid == 0) return mid;
         	     if(fmid < 0)
	         lo = mid;
	     else
	         hi = mid;
	}
	return (lo + hi) / 2;
}

