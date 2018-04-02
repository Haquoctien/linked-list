#include <iostream>
using namespace std;

struct intNode{
    int integer;
    intNode *next;
};

struct intNodeList {
    intNode *head;
    intNode *tail;
};

void intNodeListInit(intNodeList &);
void listInput(intNodeList &);
void listOutput(intNodeList);
void listDestroy(intNodeList &);
void addHead(intNodeList &, intNode *);
void addTail(intNodeList &, intNode *);
intNode *newNode(int);
intNode *popHead(intNodeList &);
intNode *popTail(intNodeList &);


int main(int argc, char const *argv[])
{
    intNodeList list;
    listInput(list);
    listOutput(list);
    intNode *head = popHead(list);
    cout << head->integer << " popped" << endl;
    intNode *tail = popTail(list);
    cout << tail->integer << " popped" << endl;
    listOutput(list);
    
    return 0;
}

void intNodeListInit(intNodeList &list) {
    list.head = list.tail = NULL;
}

void listInput(intNodeList &list) {
    intNodeListInit(list);
    cout << "Nhap n so nguyen muon nhap vao danh sach lien ket: ";
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++)
    {
        cout << "Nhap so thu " << i+1 << ": ";
        cin>>x;
        intNode *p = newNode(x);
        addHead(list, p);
    }
}

void listOutput(intNodeList list) {
    for(intNode *node = list.head; node; node = node->next)
    {
        cout << node->integer << " ";
    }
    cout << endl;
}
void listDestroy(intNodeList &list) {
    if (list.head == NULL)
        return;
    intNode *current = list.head, *holder;
    while(current) {
        holder = current;
        current = current->next;
        delete holder;
    }
    list.head = list.tail = NULL;
}

intNode *newNode(int n) {
    intNode * node = new intNode;
    if (node == NULL)
        return NULL;
    node->integer = n;
    node->next = NULL;
    return node;
}

void addHead(intNodeList &list, intNode *node) {
    if (list.head == NULL) {
        list.head = list.tail = node;
    }
    else {
        node->next = list.head;
        list.head = node;
    }
}

void addTail(intNodeList &list, intNode *node) {
    if (list.head == NULL)
        list.head= list.tail= node;
    else {
        list.tail-> next = node;
        list.tail = node;
    }
}

intNode *popHead(intNodeList &list) {
    if (list.head == NULL)
        return NULL;
    if (list.head == list.tail) {
        cout << "hi mark"  << endl;
        intNode * p = list.head;
        list.head = list.tail = NULL;
        return p;
    }
    intNode *p = list.head;
    list.head = list.head->next;
    p->next = NULL;
    return p;
}
intNode *popTail(intNodeList &list) {
    if (list.head == NULL)
        return NULL;
    if (list.head == list.tail) {
        intNode * p = list.head;
        list.head = list.tail = NULL;
        return p;
    }
    intNode *p = list.tail;
    intNode *nextToTail = list.head;
    while(nextToTail->next != list.tail)
    {
        nextToTail = nextToTail->next;
    }
    list.tail = nextToTail;
    list.tail->next = NULL;
    return p;
}