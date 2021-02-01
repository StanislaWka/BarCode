#pragma once


#include <iostream>



using namespace std;

template <class Type> class cList;
template <class Type> struct ListNode;

template <class Type>
class OwnIterator 
{
protected:
    ListNode<Type>* Iter;
public:
    OwnIterator();
    OwnIterator(Type* p);
    OwnIterator(ListNode<Type>* node);
    OwnIterator(const OwnIterator& cO);
    OwnIterator& operator++();
    OwnIterator& operator--();
    bool operator==(const OwnIterator& other) const;
    bool operator!=(const OwnIterator& other) const;
    OwnIterator& operator=(ListNode<Type>& cOI);
    Type& operator*();
    Type& operator[](const int index);
    friend ostream& operator<<(ostream& os, OwnIterator& cOI) {
        os << cOI.Iter->value;
        return os;
    }
    friend istream& operator>>(istream& in, OwnIterator& cOI) {
        in >> cOI.Iter->value;
        return in;
    }
};

template <class Type>
OwnIterator<Type>::OwnIterator() {
    Iter = NULL;
}

template <class Type>
OwnIterator<Type>::OwnIterator(Type* p) {
    this->Iter = p;
}

template <class Type>
OwnIterator<Type>::OwnIterator(ListNode<Type>* root) {
    this->Iter = root;
}

template <class Type>
OwnIterator<Type>::OwnIterator(const OwnIterator& cO) {
    this->Iter = cO.Iter;
}

template <class Type>
bool OwnIterator<Type>::operator!=(const OwnIterator<Type>& other) const {
    return this->Iter != other.Iter;
}

template <class Type>
bool OwnIterator<Type>::operator==(const OwnIterator<Type>& other) const {
    return Iter == other.Iter;
}

template <class Type>
OwnIterator<Type>& OwnIterator<Type>::operator++() {

    Iter = Iter->next;
    return *this;
}

template <class Type>
OwnIterator<Type>& OwnIterator<Type>::operator--() {
    if (Iter->last != NULL)
        Iter = Iter->last;
    return *this;
}

template <class Type>
Type& OwnIterator<Type>::operator[](const int index) {
    int meter = 1;
    while (meter != index) {
        Iter = Iter->next;
        meter++;
    }
    return Iter;
}

template <class Type>
OwnIterator<Type>& OwnIterator<Type>::operator=(ListNode<Type>& cOI) {
    delete Iter;
    OwnIterator<Type> newOI(cOI);
    this = newOI;
    return *this;
}

template <class Type>
Type& OwnIterator<Type>::operator*() {
    return Iter->value;
}


template <class Type>
struct ListNode {
    Type value;
    ListNode* next;
    ListNode* last;
};

template <class Type>
class cList {
protected:
    ListNode<Type>* head;
    int counter = 0;
public:
    cList();
    ~cList();
    typedef OwnIterator<Type> iterator;
    typedef OwnIterator<const Type> const_iterator;
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    void Edit(ListNode<Type>* node,string tmp);
    void addNode(Type val);
    void remove();
    bool isEmpty();
    int getCount(); 
    void setValue(ListNode<Type>* pointer, Type val); 
    ListNode<Type>* getValue(ListNode<Type>* pointer);
    ListNode<Type>* getFirst();
    ListNode<Type>* getLast();
    bool FindItem(ListNode<Type>* node ,string key);
    void Print();
    void Print(int& number);
};

template <class Type>
cList<Type>::cList() {
    this->head = NULL;
}

template <class Type>
cList<Type>::~cList() {
    this->head = NULL;
}

template <class Type>
int cList<Type>::getCount() {
    return this->counter;
}

template <class Type>
bool cList<Type>::isEmpty() {
    return this->head == NULL;
}

template <class Type>
void cList<Type>::setValue(ListNode<Type>* pointer, Type val) {
    pointer->value = val;
}

template <class Type>
ListNode<Type>* cList<Type>::getValue(ListNode<Type>* pointer) {
    return pointer->value;
}

template <class Type>
void cList<Type>::addNode(Type val) {
    ListNode<Type>* current = head, * newNode;
    newNode = new ListNode<Type>;
    if (newNode != NULL) {
        newNode->next = NULL;
        newNode->value = val;

        if (head == NULL) {
            head = newNode;
            head->last = NULL;
            counter++;
            return;
        }

        current = getLast();
        current->next = newNode;
        newNode->last = current;
        counter++;
    }
    else {
        cout << "No memory was kept." << endl;
        exit(1);
    }
}

template <class Type>
void cList<Type>::remove() {
    ListNode<Type>* current = getLast(), * previous;
    while (current) {
        previous = current->last;
        delete current;
        current = NULL;
        current = previous;
    }
    this->head = NULL;
}

template <class Type>
ListNode<Type>* cList<Type>::getFirst() {
    return head;
}

template <class Type>
 ListNode<Type>* cList<Type>::getLast() {
    if (head != NULL) {
        ListNode<Type>* pointer = head;
        while (pointer->next != NULL) {
            pointer = pointer->next;
        }
        return pointer;
    }
    return head;
}

template <class Type>
void cList<Type>::Print() {
    if (isEmpty()) {
        cout << "\nThe list is empty.\n" << endl;
        return;
    }

    int number = 1;
    ListNode<Type>* current = head;
    while (current) {
        cout << "\n" << number << ".";
        current->value.Print();
        current = current->next;
        number++;
    }
}

template <class Type>
void cList<Type>::Print(int& number) {
    if (isEmpty()) {
        cout << "\nThe list is empty.\n" << endl;
        return;
    }

    ListNode<Type>* current = head;
    while (current) {
        cout << "\n" << number << ".";
        current->value.Print();
        current = current->next;
        number++;
    }
    return;
}


template <class Type>
bool cList<Type>::FindItem(ListNode<Type> *node, string key) {
   
    while ( node != NULL) {
    	if(node->value.GetNameNumberBarcode() == key)
    	{
            cout << node->value;
            return true;
    	}
        node = node->next;
    }
    return false;
}



template <class Type>
void cList<Type>::Edit(ListNode<Type>* node, string tmp)
{
    int flg = 0;
    for(int i=0; i < this->getCount() ; i++)  {
        if (node->value.GetNameNumberBarcode() == tmp)
        {
            flg++;
            break;
        }
        node = node->next;
    }
	if(flg==0)
	{
        cout << "No such Barcode" << endl;
        return;
	}
   
    int choice = 1;
    while (choice) {
        cout << "[1] - Change country \n[2] - Change Manufacture \n[3] - Change Product \n[0] - Exit" << endl;
        cin >> choice;
        string tmp;
        switch (choice)
        {
        case(1):
            cout << "Enter the new country" << endl;
            cin >> tmp;
            node->value.SetNameCountry(tmp);
            break;
        case(2):
            cout << "Enter the new Manufactura" << endl;
            cin >> tmp;
           node->value.SetNameManufactura(tmp);
            break;
        case(3):
            cout << "Enter the new product" << endl;
            cin >> tmp;
           node->value.SetNameProduct(tmp);
            break;
        case(0):
            break;
        default: cout << "Enter the number from 0 to 3" << endl;
            cin >> choice;
            break;
        }
    }
    return;
}



template <class Type>
typename cList<Type>::iterator cList<Type>::begin() {
    return iterator(getFirst());
}

template <class Type>
typename cList<Type>::iterator cList<Type>::end() {
    if (getLast() != NULL)
        return iterator(getLast()->next);
    return iterator(getLast());
}

template <class Type>
typename cList<Type>::const_iterator cList<Type>::begin() const {
    return const_iterator(getFirst());
}

template <class Type>
typename cList<Type>::const_iterator cList<Type>::end() const {
    if (getLast() != NULL)
        return const_iterator(getLast()->next);
    return const_iterator(getLast());
}