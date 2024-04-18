#include <iostream>

using namespace std;

typedef int Info;

struct Elem
{
    Elem* next,
        * prev;
    int info;
};

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

Info dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next;
    Info value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    else
        first->prev = NULL;
    return value;
}

bool sameValue(Elem* L)
{
    while (L != NULL && L->next != NULL)
    {
        if (L->info == L->next->info)
        {
            return true;
        }
        L = L->next;
    }
    return false;
}

void printList(Elem* L)
{
    while (L != NULL)
    {
        cout << L->info << " ";
        L = L->next;
    }
    cout << endl;
}

int main()
{
    Elem* first = NULL;
    Elem* last = NULL;

    for (int i = 1; i <= 10; i++)
        enqueue(first, last, i);

    cout << "List: ";
    printList(first);

    cout << "Has neigbour elements with same value?" << endl;
    bool sameValuee = sameValue(first);
    if (sameValuee)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
