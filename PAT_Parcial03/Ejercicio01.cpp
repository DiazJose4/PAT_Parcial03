#include <queue>
#include <unordered_map>
#include <map>
#include "Ejercicio01.h"


//Ordenamiento entre listas
Node<int>* mergeSortedLists(Node<int>* list1, Node<int>* list2) {
    Node<int> header{ 0 };
    Node<int>* current = &header;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->value > list2->value) {
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != nullptr) {
        current->next = list1;
    }
    else {
        current->next = list2;
    }

    return header.next;  
}


Node<int>* Ejercicio01::mergeLists(Node<Node<int>*>* lists)
{
    if (lists == nullptr) {
        return nullptr;
    }

    while (lists->next != nullptr) {
        lists->value = mergeSortedLists(lists->value, lists->next->value);
        lists->next = lists->next->next;
    }

    return lists->value;
}
