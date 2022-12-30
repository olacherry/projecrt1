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
/*добавление в конец*/
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
        for (int i = 0; i < dynamic_array->element_count-1; i++)
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
/*добавление по индексу*/
void dynamic_array_push(dynamic_array_t* dynamic_array, int num_index, int num)
{    printf("\n");
    
    dynamic_array_add(dynamic_array, 0);

    
    for (int i = dynamic_array->element_count - 1; i > num_index; i--)
    {
        dynamic_array->ptr[i] = dynamic_array->ptr[i-1];
    }
    dynamic_array->ptr[num_index] = num;
    
    printf("\n");
    
}

void dynamic_array_delete(dynamic_array_t* dynamic_array, int num_index_del)
{


    for (int i = num_index_del ; i<dynamic_array->element_count; i++)
    {
        dynamic_array->ptr[i] = dynamic_array->ptr[i+1];
    }
    
    dynamic_array->element_count -=1;

    printf("\n");

}

void dynamic_array_deleteall(dynamic_array_t* dynamic_array)
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
    printf("\n добавляем элеиент");
    dynamic_array_push(&dynamic_array, 3, 10);
    dynamic_array_show(&dynamic_array);
    printf("\n удаляем элеиент");
    dynamic_array_delete(&dynamic_array, 2);
    dynamic_array_show(&dynamic_array);
    int a;
    std::cin >> a;
    
    dynamic_array_deleteall(&dynamic_array);
    return 0;
}
