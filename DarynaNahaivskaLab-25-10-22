/*Ім'я фамілія Variant 21*/
// Підключення бібліотек;
#include <stdio.h>
#include <math.h>
#define N 255 
int main() {
	// Оголошеннх та ініціалізація деяких змінних
	double x, a;
	double y, z, t;
	
	const int A=2;
	const int B=3;
	double c;
	
	// Вивести на екран вигляд заданих функцій f1, f2, f3
	printf("Function F1: (x - 3*a) / (2 + sqrt(x - 3) - tan (fabs(x - 2))) \n" );
	printf("Function F2: (7/2)* pow(x, 3) - (3/10)*x + exp(1 / tan(x)) \n");
	printf("Function F3: (2/5)* pow(x, 3.8) \n");
	
	// Введення параметра "a" та зміної "x"
	printf("Vvedit` parametr 'a' ta zminnu 'x': \n");
	scanf("%lf %lf", &a, &x);
	
	// Розрахунок значення функцій F1, F2, F3 для змінних y, z, t
	y =  ((x - B*a)/(A + sqrt(x - B))) - tan(fabs(x - A));
	z = 3.5 * pow(x, 3) - 0.3 * x + exp(1 / tan(x));
	t = 2*pow(x,3.8) /5;
	
	// Виведення на екран результатів заданих функцій;
	printf(" y = %0.5lf\n z = %0.5lf\n t = %0.5lf\n", y, z, t);
	
	// Заміна значень як вказано в умові;
	c = y;
	y = z;
	z = t;
	t = c;
	
	// Виведення нових значень;
	printf("\n y = %0.5lf\n z = %0.5lf\n t = %0.5lf \n", y, z, t);
	return 0;
}
