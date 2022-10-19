#include <iostream>

int division(float a, float b, float* c_ptr)
{
	if (b == 0.f)
	{
		return -1;
	}
	*c_ptr = a/b;
	return 0;
}

struct MyStruct
{
	float a;
	float b;
	float c;
	int ret;
	int arr[10];
	
	
};

MyStruct my_division(const MyStruct* my_struct)
{
	std::cout << my_struct << std::endl;
	MyStruct ret = {
		my_struct->a,
		my_struct->b,
		my_struct->a/my_struct->b + my_struct->c,
		0 + my_struct->ret,
		{1, 2, 3, 4, 5,6,7,8,9,10}
	};
	return ret;
}

int main()
{
	const int b =1000;
	const int* ptr_to_b = &b;
	
	int arr[] = {2, 3, 5};
	
	std::cout << ptr_to_b << std::endl;
	std::cout<<arr<<std::endl;
	//работа  с указателем
	std::cout<<*ptr_to_b<<std::endl;
	std::cout<< ptr_to_b[0] <<std::endl;
	
	//работа с массивом
	std::cout<<*arr<<std::endl;
	std::cout<<arr[0]<<std::endl;
	
	//работаем с функцией division
	float c = 0;
	if (division(3,2,&c))
	{
		std::cout<<"Error"<<std::endl;
	}
	else
	{
		std::cout<< c <<std::endl;
	}
	
	
	//пример со структурой 
	MyStruct input_struct = {
		3,
		2,
		0,
		0,
		{0, 0, 0, 0, 0,0,0,0,0,0}
	};
	std::cout << "Address input_struct:" << &input_struct <<std::endl;
	std::cout<<"Size of input_struct: "<< sizeof(input_struct)<< std::endl;
	std::cout<<"Size of &input_struct: " <<sizeof(&input_struct)<<std::endl;
	MyStruct ret = my_division(&input_struct);
	std::cout<<"My struct c: "<<ret.c<<std::endl;
	int a;
	std::cin >> a;
	
	
	return 0;
}	