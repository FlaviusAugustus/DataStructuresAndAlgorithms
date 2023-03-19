#include <iostream>
#include <list>
#include "windows.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include ".\DoublyLinkedList\DoublyLinkedList.h"



int main() {

    _CrtMemState sOld;
    _CrtMemState sNew;
    _CrtMemState sDiff;
    _CrtMemCheckpoint(&sOld);


    DoublyLinkedList<int>* list1 = new DoublyLinkedList<int>;

    list1->pushBack(1);
    list1->addFirst(2);
    list1->pushBack(4);
    list1->addFirst(5);

    std::cout << *list1 << std::endl;

    std::cout << list1->removeFirst() << std::endl;

    std::cout << *list1 << std::endl;

    std::cout << list1->removeLast() << std::endl;

    std::cout << *list1 << std::endl;

    DoublyLinkedList<int>* list2 = new DoublyLinkedList<int>;

    std::cout << *list2 << std::endl;

    std::cout << list2->removeFirst() << std::endl;

    std::cout << list2->removeFirst() << std::endl;

    {
        std::list<int> stlList;
        stlList.push_back(12);
        stlList.push_back(10);

        stlList.clear();
    }

    DoublyLinkedList<int>* list4 = new DoublyLinkedList<int>;

    *list4 = *list1;

    std::cout << *list4 << std::endl;


    delete list1;
    delete list2;
    delete list4;

    //print out memory leaks if they exist in the program
    _CrtMemCheckpoint(&sNew);
    if (_CrtMemDifference(&sDiff, &sOld, &sNew))
    {
        OutputDebugStringA(reinterpret_cast<LPCSTR>(L"-----------_CrtMemDumpStatistics ---------"));
        _CrtMemDumpStatistics(&sDiff);
        OutputDebugString(reinterpret_cast<LPCSTR>(L"-----------_CrtMemDumpAllObjectsSince ---------"));
        _CrtMemDumpAllObjectsSince(&sOld);
        OutputDebugString(reinterpret_cast<LPCSTR>(L"-----------_CrtDumpMemoryLeaks ---------"));
        _CrtDumpMemoryLeaks();
    }


    return 0;
}
