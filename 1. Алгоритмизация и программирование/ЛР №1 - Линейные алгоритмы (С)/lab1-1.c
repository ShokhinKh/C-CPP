/*  Лабораторная работа 1
    Вариант 23. Заданы длительности двух интервалов времени и соответствующие скорости движения тела. 
	Найти среднюю скорость движения тела.       */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	double speed1, time1, speed2, time2, result;
	
	setlocale(LC_ALL,"rus");

	//Ввод данных	
	printf("Введите скорость первого тела(в км/ч): ");
	scanf("%lf", &speed1);
	
	printf("Введите промежуток времени движения первого тела(в часах): ");
	scanf("%lf", &time1);
	
	printf("Введите скорость второго тела(в км/ч): ");
	scanf("%lf", &speed2);
	
	printf("Введите промежуток времени движения второго тела(в часах):  ");
	scanf("%lf", &time2);

	// Вычесления
	result = ((speed1 * time1) + (speed2 * time2)) / (time1 + time2);

	//Вывод результата
	printf("Средняя скорость равна: %lf\n", result);
	return 0;
	
	system("pause");
}
