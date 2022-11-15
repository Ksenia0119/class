#include "pch.h"
#include"../class/class/time.cpp"
#include <iomanip>
#include<string>
//проверка конструктора с параметрами и геттеров
TEST(TestTime, TestGetAll) {
	CTime t(2, 5, 6, 7);
  EXPECT_EQ(t.get_days(), 2);
  EXPECT_EQ(t.get_hours(), 5);
  EXPECT_EQ(t.get_minutes(), 6);
  EXPECT_EQ(t.get_seconds(), 7);
}
// проверка конструктора без параметров и сеттера (в стандартном формате)
TEST(TestTime, TestSetTime) {

	CTime t;
	t.set_time(6, 2, 7, 34);

	EXPECT_EQ(t.get_days(), 6);
	EXPECT_EQ(t.get_hours(), 2);
	EXPECT_EQ(t.get_minutes(), 7);
	EXPECT_EQ(t.get_seconds(), 34);
}
// проверка сеттеров дней,часов,минут,секунд

TEST(TestTime, TestSetAll) {

	CTime t; // вызов конструктора без параметров
	t.set_days(2);
	t.set_hours(19);
	t.set_minutes(30);
	t.set_seconds(57);

	EXPECT_EQ(t.get_days(), 2);
	EXPECT_EQ(t.get_hours(), 19);
	EXPECT_EQ(t.get_minutes(), 30);
	EXPECT_EQ(t.get_seconds(), 57);
}
// проверка конвертации в секунды
TEST(TestTime, TestConvertToAll) {
	CTime t2(0, 22, 36, 24);
	CTime t3(0, 3, 20, 12);
	CTime t4(0, 6, 28, 30);
	EXPECT_EQ(CTime::convert_to_seconds(t2), 81384);
	EXPECT_EQ(CTime::convert_to_seconds(t3), 12012);
	//EXPECT_EQ(CTime::convert_to_hours(t4), 7.43);
	//EXPECT_EQ(CTime::convert_to_hours(t3), 3.53); //ghjdthbv
	//EXPECT_EQ(CTime::convert_to_minutes(t2), 1356.40);
}

TEST(TestTime, TestSubTime) {
	CTime t1(1, 22, 36, 24);
	CTime t2(0, 3, 20, 12);
	//EXPECT_EQ
}
// проверка добавления времени
TEST(TestTime, TestAddTime) {

	CTime t1(0, 2, 25, 48);
	t1.add_time(1, 3, 48, 67);

	EXPECT_EQ(t1.get_days(), 1);
	EXPECT_EQ(t1.get_hours(), 6);
	EXPECT_EQ(t1.get_minutes(), 14);
	EXPECT_EQ(t1.get_seconds(), 55);

	t1.add_time(2, 25, 12, 57);

	EXPECT_EQ(t1.get_days(), 4);
	EXPECT_EQ(t1.get_hours(), 7);
	EXPECT_EQ(t1.get_minutes(), 27);
	EXPECT_EQ(t1.get_seconds(), 52);

}
//проверка добавления секунд к времени
TEST(TestTime, TestAddTimeSeconds) {
	CTime t1(0, 5, 29, 23);
	t1.add_seconds(60);
	EXPECT_EQ(t1.get_all_time(), 19823);
	EXPECT_EQ(t1.get_days(), 0);
	EXPECT_EQ(t1.get_hours(), 5);
	EXPECT_EQ(t1.get_minutes(), 30);
	EXPECT_EQ(t1.get_seconds(), 23);
	;
}
//проверка добавления минут к времени
TEST(TestTime, TestAddTimeMinutes) {
	CTime t1(0, 6, 46, 20);
	t1.add_minutes(20);
	EXPECT_EQ(t1.get_days(), 0);
	EXPECT_EQ(t1.get_hours(), 7);
	EXPECT_EQ(t1.get_minutes(), 6);
	EXPECT_EQ(t1.get_seconds(), 20);
	
}
//проверка добавления часов к времени
TEST(TestTime, TestAddTimeHours) {
	CTime t1(0, 6, 46, 20);
	t1.add_hours(5);
	EXPECT_EQ(t1.get_days(), 0);
	EXPECT_EQ(t1.get_hours(), 11);
	EXPECT_EQ(t1.get_minutes(), 46);
	EXPECT_EQ(t1.get_seconds(), 20);

}
//проверка добавления суток к времени
TEST(TestTime, TestAddTimeDays) {
	CTime t1(0, 20, 4, 4);
	t1.add_days(5);
	EXPECT_EQ(t1.get_days(), 5);
	EXPECT_EQ(t1.get_hours(), 20);
	EXPECT_EQ(t1.get_minutes(), 4);
	EXPECT_EQ(t1.get_seconds(), 4);

}
// проверка преобразования в строку время
TEST(TestTime, TestToString) {

	CTime t(2, 23, 15, 34);

	EXPECT_EQ(t.print_time(), "2 days  23 hours  15 minutes  34 seconds  ");
	EXPECT_EQ(t.print_time_second(), "Seconds 256534");
	EXPECT_EQ(t.print_time_of_day(), "Time of day: 23:15:34");
}