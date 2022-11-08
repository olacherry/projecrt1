#include <stdio.h>


int main ()
{
	int inp;
	printf("Ttype array size: \n");
	scanf("%i", &inp);
	
	int* array = new int[inp];
	
	printf("You size of array %i \n", inp);
	for (int i = 0; i<inp; i++)
	{
		scanf("%i", &array[i]);
	}
	printf("You array: ");
	for (int i = 0; i<inp; i++)
	{
		printf("%i ", array[i]);
	}
	printf("\n");
	// добавление элемента
	int num_index;
	printf("Type array index for push new element: \n");
	scanf("%i", &num_index );
	int num;
	printf("Type new array element: \n");
	scanf("%i", &num );
	
	int* array_new_push = new int[inp+1];
	for (int i = 0; i < num_index; i++)
	{
		array_new_push[i] = array[i];
	}
	array_new_push[num_index] = num;
	for (int i = num_index+1; i < inp+1; i++)
	{
		array_new_push[i] = array[i-1];
	}
	
	for (int i = 0; i<inp+1; i++)
	{
		printf("%i ", array_new_push[i]);
	}
	
	printf("\n");
	//Удаление элемента
	int num_index_del;
	printf("Type array index for delete element: \n");
	scanf("%i", &num_index_del );
	int* array_new_del = new int[inp];
	for (int i = 0; i<num_index_del; i++)
	{
		array_new_del[i] = array_new_push[i];
	}
	for (int i = num_index_del ; i<inp; i++)
	{
		array_new_del[i] = array_new_push[i+1];
	}
	for (int i = 0; i<inp; i++)
	{
		printf("%i ", array_new_del[i]);
	}
	//Удаляем массив
	delete[] array;
	delete [] array_new_del;
	delete [] array_new_push;
	int temp;
	scanf("%i", &temp);

	return 0;
}