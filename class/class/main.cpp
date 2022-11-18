/// @author Maltseva K.V.
/// Реализация  класса "Время"

#include <iostream>
#include "time.h"

using namespace std;


int main() {

	try {
		CTime t1,t2,t3;
		/// Вычетаем время 1 и время 2
		t1.set_time(3, 5, 7, 26);
		t2.set_time(3, 2, 7, 26);
		t1.subtract_time(t2);
		
		cout << endl;
		cout << t1.print_time();
		cout << endl;
		cout << t1.print_time_second();
		
		//Прибавляем секунды
		t1.set_time(5, 6, 50, 50);
		t1.add_seconds(50);
		cout << endl;
		cout << t1.print_time();
		cout << endl;
		////Вывод времени дня
		cout << t1.print_time_of_day() ;
		cout << endl;


		////Вычитаем часы
		t1.subtract_hours(7);
		cout << endl;
		cout << t1.print_time();
		cout << endl;

		///Добавляем время
		t1.add_time(7, 0, 0, 0);
		cout << t1.print_time();
		cout << endl;
		cout << t1.print_time_of_day();
		cout << endl;

		///Добавляем время 2 и 3
		t3.set_time(2, 0, 5, 34);
		t3.add_time(t2);
		cout << t3.print_time();
		cout << endl;
		cout << t3.print_time_of_day();
		cout << endl;

	
		///Перевести время в различные форматы
		cout << t3.convert_to_days(t3);
		cout << endl;
		cout << t3.convert_to_hours(t3);
		cout << endl;
		cout << t3.convert_to_minutes(t3);
		cout << endl;
		cout << t3.convert_to_seconds(t3);

		return 0;
	}
	catch (invalid_argument e) { /// Проверка исключительных ситуаций
		cout << e.what(); ///Вывод сообщения об ошибке в ходе проверки  исключительных ситуации
	}
}
///Перекодировка юникод

