/// @author Maltseva K.V.
/// Реализация  класса "Время"

#include "time.h"
#include <stdexcept>

/// Конструктор (инициализирует поля)
CTime::CTime() {
	days = 0;  hours = 0;  minutes = 0;  seconds = 0;
}

CTime::CTime(int d, int h, int m, int s) {
	days = d;
	hours = h;
	minutes = m;
	seconds = s;
}
/// Преобразовать cекунды в стандартный формат
void CTime::convert_s_to_std (int t) {
	if (t < 0) throw std::invalid_argument ("Invalid value of time");
	days = t/86400;
	hours = (t/3600)%24;
	minutes = (t/60)%60;
	seconds = t%60;
}


/// Задать время в стандартном формате
void CTime::set_time(int d, int h, int m, int s){
	set_days(d);
	set_seconds(s);
	set_minutes(m);
	set_hours(h);
	/*days = d; hours = h; minutes = m; seconds = s;
	set_all_time(d,h,m,s);*/
}

/// Задать секунды
void CTime::set_seconds(int s){
	if ((s < 0) || (s > 59)) throw std::invalid_argument("Invalid argument: seconds");
	seconds = s;
}

/// Задать минуты
void CTime::set_minutes(int m){
	if ((m < 0) || (m > 59)) throw std::invalid_argument("Invalid argument: minutes");
	minutes = m;
}

/// Задать часы
void CTime::set_hours(int h){
	if ((h < 0) || (h > 23)) throw std::invalid_argument("Invalid argument: hours");
	hours = h;
}

/// Задать дни
void CTime::set_days(int d){
	if (d < 0) throw std::invalid_argument ("Invalid argument: days");
	days = d;
}

/// Получить время в секундах
int CTime::get_all_time() const { return seconds + minutes * 60 + hours * 3600 + days * 86400; }

/// Получить секунды
int CTime::get_seconds() const { return seconds; }

/// Получить минуты
int CTime::get_minutes() const { return minutes; }

/// Получить часы
int CTime::get_hours() const { return hours; }

/// Получить дни
int CTime::get_days() const { return days; }

/// Добавить секунды
void CTime::add_seconds(int s){
	if (s < 0) throw std::invalid_argument("Invalid argument: seconds");
	int s1 = s;
	int s2 = get_all_time();
	int s3 = s + s2;
	convert_s_to_std(s3);
}
/// Добавить минуты
void CTime::add_minutes(int m){
	if (m < 0) throw std::invalid_argument("Invalid argument: minutes");
	int m1 = m;
	int m2 = get_all_time();
	int m3 = m*60 + m2;
	convert_s_to_std(m3);	
}

/// Добавить часы
void CTime::add_hours(int h){
	if (h < 0) throw std::invalid_argument("Invalid argument: hours");
	int h1 = h;
	int h2 = get_all_time();
	int h3 = h * 3600 + h2;
	convert_s_to_std(h3);	
}

/// Добавить дни
void CTime::add_days(int d){
if (d < 0) throw std::invalid_argument ("Invalid argument: days");
int d1 = d;
int d2 = get_all_time();
int d3 = d * 86400 + d2;
convert_s_to_std(d3);	
}


/// Добавить время
void CTime::add_time (int d, int h, int m, int s){
	if (d < 0) throw std::invalid_argument("Invalid argument: days");
    else if (h < 0 ) throw std::invalid_argument("Invalid argument: hours");
	else if (m < 0 ) throw std::invalid_argument("Invalid argument: minutes");
	else if (s < 0 ) throw std::invalid_argument("Invalid argument: seconds");
	int a_t1 = d * 86400 + h * 3600 + m * 60 + s;
	int a_t2 = get_all_time();
	int a_t3 = a_t1 + a_t2;
	convert_s_to_std(a_t3);
}

/// Добавить время с помощью время в стандартном формате
void CTime::add_time(CTime t2) {
	//if (d < 0) throw std::invalid_argument("Invalid argument: days");
	//else if (h < 0) throw std::invalid_argument("Invalid argument: hours");
	//else if (m < 0) throw std::invalid_argument("Invalid argument: minutes");
	//else if (s < 0) throw std::invalid_argument("Invalid argument: seconds");
	int a_tc1 = t2.days * 86400 + t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
	int a_tc2 = get_all_time();
	int a_tc3 = a_tc1 + a_tc2;
	convert_s_to_std(a_tc3);
}


/// Вычесть секунды
void CTime::subtract_seconds(int s){
	if (s < 0 || s > get_all_time()) throw std::invalid_argument("Invalid argument: seconds");
	int sub_s1 = s;
	int sub_s2 = get_all_time();
	int sub_s3 = sub_s2 - sub_s1;
	convert_s_to_std(sub_s3);
}

/// Вычесть минуты
void CTime::subtract_minutes(int m) {
	if (m < 0 || m > get_all_time()) throw std::invalid_argument("Invalid argument: minutes");
	int sub_m1 = m;
	int sub_m2 = get_all_time();
	int sub_m3 = sub_m2 - sub_m1 * 60;
	convert_s_to_std(sub_m3);
}

/// Вычесть часы
void CTime::subtract_hours(int h){
	if (h < 0 || h>get_all_time()) throw std::invalid_argument("Invalid argument: seconds");
	int sub_h1 = h;
	int sub_h2 = get_all_time();
	int sub_h3 = sub_h2 - sub_h1 * 3600;
	convert_s_to_std(sub_h3);
}

/// Вычесть сутки
void CTime::subtract_days(int d){
	if (d < 0 || d> get_all_time()) throw std::invalid_argument("Invalid argument: days");
	int sub_d1 = d;
	int sub_d2 = get_all_time();
	int sub_d3 = sub_d2 - sub_d1 * 86400;
	convert_s_to_std(sub_d3);
}

/// Вычесть время 1 и время 2
void CTime::subtract_time (CTime t2){
	int sub_t1 = t2.days * 86400 + t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
	int sub_t2 = get_all_time();
	int sub_t3 = sub_t2 - sub_t1;
	convert_s_to_std(sub_t3);
	//if (d < 0 || d>all_time) throw std::invalid_argument("Invalid argument: days");
	//else if (h < 0 || h>all_time) throw std::invalid_argument("Invalid argument: hours");
	//else if (m < 0 || m>all_time) throw std::invalid_argument("Invalid argument: minutes");
	//else if (s < 0 || s>all_time) throw std::invalid_argument("Invalid argument: seconds");
	//all_time = all_time - d * 86400 - h * 3600 - m * 60 - s;
	
}

/// Перевести все время в секунды
//int convert_to_seconds(int d, int h, int m, int s){
//	if (d < 0) throw std::invalid_argument ("Invalid argument: days");
//	else if (h < 0) throw std::invalid_argument("Invalid argument: hours");
//	else if (m < 0) throw std::invalid_argument("Invalid argument: minutes");
//	else if (s < 0) throw std::invalid_argument("Invalid argument: seconds");
//	return d*86400 + h*3600 + m*60 + s;
//}

/// Перевести все время в секунды
int CTime::convert_to_seconds(CTime t2) {
	return  t2.days * 86400 + t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
}

 //Перевести все время в минуты
//float CTime::convert_to_minutes(int d, int h, int m, int s){
//	if (d < 0) throw std::invalid_argument ("invalid argument: days");
//	else if (h < 0) throw std::invalid_argument("invalid argument: hours");
//	else if (m < 0) throw std::invalid_argument("invalid argument: minutes");
//	else if (s < 0) throw std::invalid_argument("invalid argument: seconds");
//	return d*1440 + h*60 + m + s/60.0;
//}


 ///Перевести все время в минуты
float CTime::convert_to_minutes(CTime t2) {
	
	return printf("%.2f",t2.days * 1440 + t2.hours * 60 + t2.minutes + t2.seconds / 60.0);
}


/// Перевести все время в часы
//float CTime::convert_to_hours(int d, int h, int m, int s){
	//if (d < 0) throw std::invalid_argument ("Invalid argument: days");
	//else if (h < 0) throw std::invalid_argument("Invalid argument: hours");
	//else if (m < 0) throw std::invalid_argument("Invalid argument: minutes");
	//else if (s < 0) throw std::invalid_argument("Invalid argument: seconds");
	//return d*24 + h + m/60.0 + s/60.0;
//}

/// Перевести все время в часы
 float CTime::convert_to_hours(CTime t2) {
	
	return printf("%.2f", t2.days * 24 + t2.hours + t2.minutes / 60.0 + t2.seconds / 60.0);
}

/// Перевести все время в сутки
//float CTime::convert_to_days(int d, int h, int m, int s){
//	if (d < 0) throw std::invalid_argument ("Invalid argument: days");
//	else if (h < 0) throw std::invalid_argument("Invalid argument: hours");
//	else if (m < 0) throw std::invalid_argument("Invalid argument: minutes");
//	else if (s < 0) throw std::invalid_argument("Invalid argument: seconds");
//	return d + h/24.0 + m/1440.0 + s/3600.0;
//}

/// Перевести все время в сутки
float CTime::convert_to_days(CTime t2) {
	return days + hours / 24.0 + minutes / 1440.0 + seconds / 3600.0;
}

/// Преобразовать в строку всё время
std::string CTime::print_time() const {
	return std::to_string(days) + " days  " + std::to_string(hours) + " hours  " + std::to_string(minutes) + " minutes  " + std::to_string(seconds) + " seconds  " ;
}

/// Преобразовать в строку время суток
std::string CTime::print_time_of_day() const {
	return "Time of day: " + std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
}

std::string CTime::print_time_second() const {
	return "Seconds " + std::to_string(get_all_time());
}
///Перекодировка юникод