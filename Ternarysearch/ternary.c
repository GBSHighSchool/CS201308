
double f(double a);


// [left, right] 구간내에서 함수 f(x)가 최대인 x를 구한다.
double ternarySearch(int left, int right, function& f)
{
	// 적당히 큰 수만큼 반복 -> 오차범위는 (right-left)*(2/3)^(반복횟수)
	for (int i = 0; i < 1000; i++) {
		double a = (left*2 + right) / 3;
		double b = (left + right*2) / 3;

		// 최소인 점을 찾으려면 if 문의 부호를 반대로 하면 된다.
		if (f(a) < f(b))
			left = a;
		else 
			right = b;
	}
	
	return (left+right)/2;
}
