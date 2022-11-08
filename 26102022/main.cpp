#include <iostream>
struct dynamic_array_t
{
	int* ptr;
	int element_count;
	int cur_element_count;
};	

void create_dynamic_array(dynamic_array_t* dynamic_array, const int element_count = 10)
{
	dynamic_array->cur_element_count = 0;
	dynamic_array->element_count = element_count;
	dynamic_array->ptr = new int[10];
	
	
}

void dynamic_array_add(dynamic_array_t* dynamic_array, int value)
{
	if (dynamic_array->cur_element_count < dynamic_array->element_count)
	{
		dynamic_array->ptr[dynamic_array->cur_element_count] = value;
		dynamic_array->cur_element_count++;
	}
	else
	{
		int* dynamic_array_new = new int[dynamic_array->element_count*2];
		for (int i = 0; i < dynamic_array->element_count; i++)
		{
			dynamic_array_new[i] = dynamic_array->ptr[i];
		}

		dynamic_array_new[dynamic_array->element_count] = value;
		delete[] dynamic_array->ptr;
		dynamic_array->ptr = dynamic_array_new;
		dynamic_array->cur_element_count++;
		dynamic_array->element_count *=2;
		
		
	}
}
void dynamic_array_push(dynamic_array_t* dynamic_array)
{	printf("\n");
	int* array_new_push = new int[dynamic_array->element_count+1];
	int num_index;
	printf("Type array index for push new element: \n");
	scanf("%i", &num_index );
	int num;
	printf("Type new array element: \n");
	scanf("%i", &num );
	
	for (int i = 0; i < num_index; i++)
	{
		array_new_push[i] = dynamic_array->ptr[i];
	}
	array_new_push[num_index] = num;
	for (int i = num_index+1; i < dynamic_array->element_count+1; i++)
	{
		array_new_push[i] = dynamic_array->ptr[i-1];
	}
	dynamic_array->ptr = array_new_push;
	dynamic_array->element_count +=1;
	printf("\n");
}


void dynamic_array_delete(dynamic_array_t* dynamic_array)
{
	delete[] dynamic_array->ptr;
	
}
void dynamic_array_show(const dynamic_array_t* dynamic_array)
{
	for(int i = 0; i<dynamic_array->cur_element_count;i++){
		printf("%i ", dynamic_array->ptr[i] );
	}
}

int main()
{
	
	
	
	dynamic_array_t dynamic_array = {};
	create_dynamic_array(&dynamic_array);
	for (int i = 0; i<30; i++)
	{
		dynamic_array_add(&dynamic_array, i*i);
	}
	dynamic_array_show(&dynamic_array);
	dynamic_array_push(&dynamic_array);
	dynamic_array_show(&dynamic_array);
	int a;
	std::cin >> a;
	
	dynamic_array_delete(&dynamic_array);
	return 0;
}