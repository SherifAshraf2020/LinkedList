#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H


template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};


template <class Type>
class circularLinkedList
{
    public:
        circularLinkedList();
        circularLinkedList();
        circularLinkedList& operator=(const circularLinkedList<Type>& otherList);

        void initializeList();
        bool isEmpty() const;
        void destroy();
        void print() const;
        int length() const;
        bool search(const Type& searchItem) const;
        void insert(const Type& insertItem);
        void deleteNode(const Type& deleteItem);

        virtual ~circularLinkedList();

    protected:
        Type count;
        nodeType<Type> *first;
    private:
        void copyList(const circularLinkedList<Type>& otherList);
};

template <class Type>
bool circularLinkedList<Type>::isEmpty() const
{
    return (first == NULL);
}

template <class Type>
void circularLinkedList<Type>::initializeList()
{
    destroy();
}

template <class Type>
int circularLinkedList<Type>::length() const
{
    return count;
}

template <class Type>
void circularLinkedList<Type>::destroy()
{
    nodeType<Type> *temp;
    temp = first->link;

    while(temp != first)
    {
        first->link = temp->link;
        delete temp;
        temp = first->link;
    }

    delete temp;
    first = NULL;
    count = 0;
}

template <class Type>
void circularLinkedList<Type>::print() const
{
    nodeType<Type> *current;
    current = first->link;

    do
    {
        cout<<current->info<<" ";
        current = current->link;

    }while(current != first->link);

}

template <class Type>
bool circularLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current;

    current = first->link;

    do
    {
        if(current->info == searchItem)
        {
            found = true;
        }
        else
        {
            current = current->link;
        }

    }while(current != first->link && !found);

    if(found)
    {
        found = (current->info == searchItem);
    }
    return found;
}

template <class Type>
void circularLinkedList<Type>::insert(const Type& insertItem)
{

}


template <class Type>
void circularLinkedList<Type>::deleteNode(const Type& deleteItem)
{

}
#endif // CIRCULARLINKEDLIST_H
