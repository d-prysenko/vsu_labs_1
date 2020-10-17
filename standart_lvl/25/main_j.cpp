// Exercise 25 j

#include <iostream>
#include <cmath>

double seqMember(size_t n, double x)
{
	return n * pow(x, n-1) * ((n % 2 == 0)? -1 : 1 );
}

double f(double x)
{
	return 1 / ((1 + x) * (1 + x));
}

int main()
{
	setlocale(LC_ALL, "ru");

	const int R = 1;

	size_t N;
	double E, E2, x;

	std::cout << "Введите x из интервала (" << -R << "; " << R << "): ";
	//printf("Введите x из интервала (%d; %d): ", -R, R);
	std::cin >> x;	

	while (x <= -R || x >= R)
	{
		std::cout << "Значение должно лежать на интервале (" << -R << "; " << R << ")" << std::endl;
		//printf("Значение должно лежать на интервале (%d; %d): ", -R, R);
		std::cout << "Введите x: ";
		std::cin >> x;
	}

	std::cout << "Введите N: ";
	std::cin >> N;
	std::cout << "Введите E: ";
	std::cin >> E;

	double  sumN = 0,
			sumE = 0, sumE2 = 0;

	for (size_t i = 1; i <= N; i++)
		sumN += seqMember(i, x);

	double val;
	for (size_t i = 1; fabs(val = seqMember(i, x)) > E; i++)
		sumE += val;

	E2 = E * 10;
	size_t i = 1;
	for (; fabs(val = seqMember(i, x)) > E2; i++)
		sumE2 += val;


	std::cout << "Сумма " << N << " слагаемых: " << sumN << std::endl;
	std::cout << "Сумма слагаемых, которые по модулю больше " << E << ": " << sumE << std::endl;
	std::cout << "Сумма " << i << " слагаемых, которые по модулю больше " << E2 << ": " << sumE2 << std::endl;
	std::cout << "f(x) = f(" << x << ") = " << f(x) << std::endl;

	return 0;
}