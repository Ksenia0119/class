/// @author Maltseva K.V.
/// ����������  ������ "�����"

#include <iostream>
#include "time.h"

using namespace std;


int main() {

	try {
		CTime t1,t2,t3;
		/// �������� ����� 1 � ����� 2
		t1.set_time(3, 5, 7, 26);
		t2.set_time(3, 2, 7, 26);
		t1.subtract_time(t2);
		
		cout << endl;
		cout << t1.print_time();
		cout << endl;
		cout << t1.print_time_second();
		
		//���������� �������
		t1.set_time(5, 6, 50, 50);
		t1.add_seconds(50);
		cout << endl;
		cout << t1.print_time();
		cout << endl;
		////����� ������� ���
		cout << t1.print_time_of_day() ;
		cout << endl;


		////�������� ����
		t1.subtract_hours(7);
		cout << endl;
		cout << t1.print_time();
		cout << endl;

		///��������� �����
		t1.add_time(7, 0, 0, 0);
		cout << t1.print_time();
		cout << endl;
		cout << t1.print_time_of_day();
		cout << endl;

		///��������� ����� 2 � 3
		t3.set_time(2, 0, 5, 34);
		t3.add_time(t2);
		cout << t3.print_time();
		cout << endl;
		cout << t3.print_time_of_day();
		cout << endl;

	
		///��������� ����� � ��������� �������
		cout << t3.convert_to_days(t3);
		cout << endl;
		cout << t3.convert_to_hours(t3);
		cout << endl;
		cout << t3.convert_to_minutes(t3);
		cout << endl;
		cout << t3.convert_to_seconds(t3);

		return 0;
	}
	catch (invalid_argument e) { /// �������� �������������� ��������
		cout << e.what(); ///����� ��������� �� ������ � ���� ��������  �������������� ��������
	}
}


