#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

//task 2
int main() {
	double N, R, S, rad;
	
	setlocale(LC_ALL,"rus");

	
	printf("Введите радиус описанной окружности: ");
	scanf("%lf", &R);
	
	printf("Введите количество сторон правильного многоугольника: ");
	scanf("%lf", &N);
	
	rad = 360 * (M_PI / 180);
	S = (N * pow(R, 2)) / 2 * sin(rad / N);
	
	printf("Площадь многоугольника равна: %lf\n", S);
	
	return 0;
}
