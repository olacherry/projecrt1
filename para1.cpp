#include <iostream>
#include <stdint.h>

int main(int argc, const char**  argv)
{
	//���������� ���� ����������� ��������
	int variable_name =-1;

	//const - ���������, ��� �������� ���������� �� ����� ���� ��������
	const int const_variable = -2;
	//��������� ���������� ������ ������ {}
	/* {
		int variable_name = 0;

	}*/
	int32_t variable_32_bit = 32;
	//�����������
	uint16_t unsigned_variable = 16;

	char a = 'a';
	//��������� ��������
	float float_number = 0.f;
	//������� ��������
	double double_number = 0.;

	long double long_double_number = 0.l;

	std::cout << "hello0" << std::endl;
	std::cout << variable_name << std::endl;
	
	int a = 1;
	//a/2 ������ ��� ���������� int - ���������� � ������� �������
	float b = 1.2;
	float bad_sum = a + b;

	float floating_a = (float)a;
	float static_floating_a = static_cast<float>(a);

	float good_sum = floating_a + b;


	//������� ������ ����������� �������� � ����� �����������
	std::cout << "����� ���������� " << argc << std::endl;
	std::cout << "������ �������� " << argv[0] << std::endl;
	return 0;



}