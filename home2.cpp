#include <iostream>
using namespace std;


const int n = 5;
struct LinkedListNode
{
    int size; // размер подмассива
    int CurElementCount;// заполненность подмассива
    int* mass; // указатель на подмассив
    LinkedListNode* next; // указательна на следующий список
    LinkedListNode* prev; // указатель на предыдущий список
};

struct LinkedList
{
    LinkedListNode* first; // указатель на самый первый список
    LinkedListNode* last; // указатель на последний список
};

// создание самого первого списка
void linker_list_add_node(LinkedList* ptr)
{
    LinkedListNode* new_node = new LinkedListNode();
    new_node->mass = new int[n];
    new_node->size = n;
    new_node->CurElementCount = 0;
    new_node->next = nullptr;
    new_node->prev = nullptr;
    ptr->first = new_node;
    ptr->last = new_node;
}
int linked_list_find (LinkedList* ptr,LinkedListNode* out, int value)
{
    for (LinkedListNode* cur_node = ptr->first;
        cur_node != nullptr; cur_node = cur_node->next)
    {
        for (int i = 0; i < cur_node->CurElementCount; i++)
        {if (cur_node->mass[i] == value)
            *out = *cur_node;
            return i;
            }
    }
    return -1;
}

int linked_list_get(LinkedList* ptr,LinkedListNode* out, int index)
{
    int counter = 0;
    for (LinkedListNode* cur_node = ptr->first;
         cur_node != nullptr; cur_node = cur_node->next)
    {
        for (int i = 0; i < cur_node->CurElementCount; i++){
            counter ++;
            if( counter == index)
            {
                
                *out = *cur_node;
                return cur_node->mass[i];
            }}
    }
    return  -1;
}
// добавление последующих списков, после того, как подмассив переполнится
void linker_list_add_node(LinkedList* ptr, int value)
{
    LinkedListNode* new_node = new LinkedListNode(); // выделение памяти под список
    new_node->mass = new int[n];
    new_node->mass[0] = value;
    new_node->size = n;
    new_node->CurElementCount = 1;

    new_node->prev = ptr->last;
    ptr->last->next = new_node;
    ptr->last = new_node;
    ptr->last->next = nullptr;

}

//добавление элемента в подмассив
void linker_list_add(LinkedList* ptr, int value)
{
    if (ptr->last->CurElementCount == ptr->last->size)
        linker_list_add_node(ptr, value);
    else
    {
        ptr->last->mass[ptr->last->CurElementCount] = value;
        ptr->last->CurElementCount++;
    }
}

//вставка элемента по индексу
void linker_list_insert(LinkedList* ptr, int index, int value)
{
    int prev_s = 0;
    int s = 0;
    for (LinkedListNode* cur_node = ptr->first;
        cur_node != nullptr; cur_node = cur_node->next)
    {
        prev_s = s;
        s += cur_node->CurElementCount;
        if (s >= index)
        {
            index -= prev_s;
            if (cur_node->CurElementCount == cur_node->size)
            {
                int size = cur_node->size + 1;
                int* array = new int[size];
                for (int i = 0; i < cur_node->size; i++)
                {
                    array[i] = cur_node->mass[i];
                }
                cur_node->size++;
                delete[] cur_node->mass;
                cur_node->mass = array;
            }
            for (unsigned int i = cur_node->CurElementCount; i > index; i--)
            {
                cur_node->mass[i] = cur_node->mass[i - 1];
            }
            cur_node->mass[index] = value;
            cur_node->CurElementCount++;

            return;
        }
    }
}

//удавление элемента по индексу
void linker_list_delete(LinkedList* ptr, int index)
{
    int prev_s = 0;
    int s = 0;
    for (LinkedListNode* cur_node = ptr->first;
        cur_node != nullptr; cur_node = cur_node->next)
    {
        prev_s = s;
        s += cur_node->CurElementCount;
        if (s >= index)
        {
            index -= prev_s;
            if (cur_node->CurElementCount == 1)
            {
                if (cur_node->next == nullptr)
                {
                    cur_node->prev->next = nullptr;
                    ptr->last = cur_node->prev;
                    delete[] cur_node->mass;
                    delete cur_node;
                }
                else if (cur_node->prev == nullptr)
                {
                    cur_node->next->prev = nullptr;
                    ptr->first = cur_node->next;
                    delete[] cur_node->mass;
                    delete cur_node;
                }
                else
                {
                    cur_node->prev->next = cur_node->next;
                    cur_node->next->prev = cur_node->prev;
                    delete[] cur_node->mass;
                    delete cur_node;
                }
            }
            else // если же в подмассиве больше одного элемента
            {
                for (int i = index; i < cur_node->CurElementCount; i++)
                {
                    cur_node->mass[i] = cur_node->mass[i + 1];
                }
                cur_node->CurElementCount--;
            }
            return;
        }
    }
}

// вывод элементов подмассивово на экран
void linker_list_show(LinkedList* ptr)
{
    for (LinkedListNode* cur_node = ptr->first;
        cur_node != nullptr; cur_node = cur_node->next)
    {
        for (int i = 0; i < cur_node->CurElementCount; i++)
            cout << cur_node->mass[i] << endl;
    }
}

// удаление указателя на двусвязный список
void linker_list_delete(LinkedList* ptr)
{
    for (LinkedListNode* cur_node = ptr->first;
        cur_node->next != nullptr; cur_node = cur_node->next)
        delete[] cur_node->mass;
}


int main()
{
    LinkedList ptr = LinkedList();
    ptr.first = nullptr;
    ptr.last = nullptr;
    linker_list_add_node(&ptr);
    for (int i = 0; i < 30; i++)
    {
        linker_list_add(&ptr, i * i);
    }
     
    linker_list_insert(&ptr, 2, 100); // вставка элемента по индексу

    linker_list_delete(&ptr, 28); // удавление элемента в массиве
    

    linker_list_show(&ptr); // выведение на консоль элемнтов массива
    cout << " " << endl;
    int a;
    linked_list_find(&ptr, a, 100);
    
    node* node;
    int mass = linked_list_get(list, node, 3)

    linker_list_delete(&ptr); // удаление двусвязного списка из памяти компьютера

    return 0;
}
