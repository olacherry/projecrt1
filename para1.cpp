#include <iostream>
#include <stdint.h>

int main(int argc, const char**  argv)
{
	//переменным учше присваивать значение
	int variable_name =-1;

	//const - ознаачает, что значение переменной не может быть изменено
	const int const_variable = -2;
	//видимость переменных только внутри {}
	/* {
		int variable_name = 0;

	}*/
	int32_t variable_32_bit = 32;
	//беззнаковый
	uint16_t unsigned_variable = 16;

	char a = 'a';
	//одинарной точности
	float float_number = 0.f;
	//двойной точности
	double double_number = 0.;

	long double long_double_number = 0.l;

	std::cout << "hello0" << std::endl;
	std::cout << variable_name << std::endl;
	
	int a = 1;
	//a/2 вернет тип переменной int - округление в меньшую сторону
	float b = 1.2;
	float bad_sum = a + b;

	float floating_a = (float)a;
	float static_floating_a = static_cast<float>(a);

	float good_sum = floating_a + b;


	//выведем первый переданнный параметр и число парраметров
	std::cout << "Число параметров " << argc << std::endl;
	std::cout << "Первый параметр " << argv[0] << std::endl;
	return 0;



}