// Exercise 25 j

#include <iostream>
#include <cmath>

int main()
{
	
	setlocale(LC_ALL, "ru");

	const int R = 1;

	size_t N;
	double E, E2, x;
	std::cout << "Введите x из интервала (" << -R << "; " << R << "): ";
	std::cin >> x;

	

	while (x <= -R || x >= R)
	{
		std::cout << "Значение должно лежать на интервале (" << -R << "; " << R << ")" << std::endl;
		std::cout << "Введите x: ";
		std::cin >> x;
	}

	std::cout << "Введите N: ";
	std::cin >> N;
	std::cout << "Введите E: ";
	std::cin >> E;

	double  sumN = x,
			sumE = x, sumE2 = x;

	double m1 = 1; double x1 = x;
	for (size_t i = 1; i <= N; i++)
	{
		m1 = m1 * (2 * i - 1) / (2 * i);
		x1 *= x * x;
		sumN += m1 * x1 / (2 * i + 1);
	}

	
	E2 = E * 10;
	size_t i = 1;
	x1 = x*x*x;
	m1 = 0.5;
	double val = m1 * x1 / (2 * i + 1);
	i++;

	while (val > E2)
	{
		sumE2 += val;
		m1 = m1 * (2 * i - 1) / (2 * i);
		x1 *= x * x;
		i++;
		val = m1 * x1 / (2 * i + 1);
	}

	sumE = sumE2;
	while (val > E)
	{
		sumE += val;
		m1 = m1 * (2 * i - 1) / (2 * i);
		x1 *= x * x;
		i++;
		val = m1 * x1 / (2 * i + 1);
	}

	std::cout << "Сумма " << N << " слагаемых: " << sumN << std::endl;
	std::cout << "Сумма слагаемых, которые по модулю больше " << E << ": " << sumE << std::endl;
	std::cout << "Сумма " << i << " слагаемых, которые по модулю больше " << E2 << ": " << sumE2 << std::endl;
	std::cout << "arcsin(x) = arcsin(" << x << ") = " << asin(x) << std::endl;
	
	return 0;
}