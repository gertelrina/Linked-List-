#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>


using namespace std;

int N;              //N - число элементов в списке

template <class Type>
struct element {
    Type tmp;
    element* Next;//адрес на след поле
    element* Prev;//адрес на пред поле
    element(Type a = 0, element *next = nullptr, element *prev = nullptr):tmp(a), Next(next), Prev(prev){}
} ;

template <class Type>
class List                        //класс список
{
    element<Type>* fst, * lst;    //первый и последний элемент
    int N;                        //кол-во элементов списке
    
public:
    List()
    {
        lst = NULL;
        fst = NULL;
        N = 0;
    }
    
    List(const List<Type>& b){
        fst = lst = nullptr;
        N = 0;
        element<Type> *p = b.fst;
        while(p!=nullptr){
            AddtoEnd(p->tmp);
            p = p->Next;
        }
    }                              //коструктор копирования
    
     List& operator=(const List<Type>& l) {
         if (fst) this->~List();
         fst = lst = nullptr;
         List <Type>* temp = l.fst;
         while (temp != nullptr){
             AddtoEnd(temp->tmp);
             temp = temp->next;
             
         }
         return *this;
     }
    
    ~List(){
        while(N>0){
            element<Type>* tmp = fst;
            fst = fst->Next;
            delete tmp;
            N--;
        }
    };                              //деструктор
    void AddtoBegin(const Type& a); //добавить элемент в начало
    void DeletefromBegin();         //удалить элемент из начала
    void AddtoEnd(const Type& a);   //добавить элемент в конец
    void DeletefromEnd();           //удалить элемент из конца
    Type ShowFst();                 //показать 1
    Type ShowLst();                 //показать последний
    void ShowN();//+                //вывести размер
    void Delete(const Type& a);
    
//******************************************//
//              TASK #3                     //
//******************************************//
    void SWAP(List<Type>& a, List<Type>& b);
};

//******************************************//
//              TASK #3                     //
//******************************************//
template <class Type>
void List<Type>::SWAP(List<Type>& a, List<Type>& b){
    List <Type> d;
    d = a;
    a = b;
    b = d;
}

template <class Type>
List<Type> list;

template <class Type>
void List<Type>::ShowN(){
    cout << "Размер " << N;
}

template <class Type>
void List<Type>::AddtoBegin(const Type& a)
{
    element<Type>* temp = new element<Type>(a, fst, nullptr); //выделяем память под новый элемент
    if(fst!=nullptr) fst->Prev = temp;
    if(N==0) fst = lst = temp;
    else fst = temp;
    N++;
}

template <class Type>
void List<Type>::DeletefromBegin()
{
    if (N == 0) throw -1;
    element<Type> *temp = fst;
    fst = fst->Next;
    delete temp;
    N--;
}

template <class Type>
void List<Type>::AddtoEnd(const Type& a)
{
    element<Type>* temp = new element<Type>(a, nullptr, lst); //выделяем память под новый элемент
       if(lst!=nullptr) lst->Next = temp;
       if(N==0) fst = lst = temp;
       else lst = temp;
    N++;
}

template <class Type>
void List<Type>::DeletefromEnd()
{
    if (N == 0) throw -1;
    element<Type> *temp = lst;
    lst = lst->Prev;
    delete temp;
    N--;
}

template <class Type>
Type List<Type>::ShowFst(){
    if(N==0) throw -1;
    Type temp = lst->tmp;
    return temp;
}

template <class Type>
Type List<Type>::ShowLst(){
    if(N==0) throw -1;
    Type temp = lst->tmp;
    return temp;
}

template <class Type>
void List<Type>::Delete(const Type& a){
    if(N == 0) throw -1;
    while(fst->tmp == a && fst != nullptr){ DeletefromEnd(); }
    element<Type> *temp = fst;
    while(temp != nullptr){
        if(temp->tmp == a){
            if(temp == lst) {DeletefromEnd(); break; }
            else {
                 element<Type> *w = temp->Prev;
                 element<Type> *h = temp->Next;
                w->Next = h;
                h->Prev = w;
                delete temp;
                temp = w;
                N--;
            }
        }
        else
            temp = temp->Next;
    }
}
      
