/// @author Maltseva K.V.
/// Реализация  класса "Время"
#include <string>
#pragma once /* Защита от двойного подключения заголовочного файла */

/// Класс время
class CTime{
	//свойства класса
	private:
		int days; // сутки
		int hours;	// часы	
		int minutes; // минуты
		int seconds; // секунды

	
  ///методы класса
	public:
		/// конструктор (инициализирует поля)
		CTime();

		CTime(int d,int h, int m, int s);

		/// Преобразовать cекунды в стандартный формат
		void convert_s_to_std (int t);
		
		/// Задать время в стандартном формате
		void set_time(int d, int h, int m, int s);

		/// Задать секунды
		void set_seconds(int s);

		/// Задать минуты
		void set_minutes(int m);

		/// Задать часы
		void set_hours(int h);

		/// Задать дни
		void set_days(int d);

		/// Получить время в секундах
		int get_all_time() const;

		/// Получить секунды
		int get_seconds() const;

		/// Получить минуты
		int get_minutes() const;

		/// Получить часы
		int get_hours() const;

		/// Получить дни
		int get_days() const;

		/// Добавить секунды
		void add_seconds(int s);

		/// Добавить минуты
		void add_minutes(int m);

		/// Добавить часы
		void add_hours(int h);

		/// Добавить дни
		void add_days(int d);

		/// Добавить время
		void add_time (int d, int h, int m, int s);
		
		/// Добавить время
		void add_time(CTime t2);

		/// Вычесть секунды
		void subtract_seconds(int s);

		/// Вычесть минуты
		void subtract_minutes(int m);

		/// Вычесть часы
		void subtract_hours(int h);

		/// Вычесть сутки
		void subtract_days(int d);

		/// Вычесть время
		void subtract_time (int d, int h, int m, int s);
		
		/// Вычесть время 
	 void subtract_time(CTime t2);

		/// Перевести все время в секунды
		//static int convert_to_seconds(int d, int h, int m, int s);
		static int convert_to_seconds(CTime t2);

		/// Перевести все время в минуты
		static float convert_to_minutes(CTime t2);
		//float convert_to_minutes(int d, int h, int m, int s);


		/// Перевести все время в часы
		static float convert_to_hours(CTime t2);
		//float convert_to_hours(int d, int h, int m, int s);

		/// Перевести все время в сутки
		float convert_to_days(CTime t2);
		float convert_to_days(int d, int h, int m, int s);

		/// Преобразовать в строку всё время
		std::string print_time() const;

		/// Преобразовать в строку время суток
		std::string print_time_of_day() const;

		/// Преобразовать в строку кол-во секунд
		std::string print_time_second() const;
};
///Перекодировка юникод