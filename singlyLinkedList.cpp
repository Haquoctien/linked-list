#include <iostream>
using namespace std;

struct intNode {
    int info;
    intNode *next;
};

intNode *getNode(int x) {
    intNode *node = new intNode;
    if (node == NULL)
        return NULL;
    node->info = x;
    node->next = NULL;
    return node;
}

struct intNodeList {
    intNode *start;
    intNode *end;
};
void listInit(intNodeList &list) {
    list.start = NULL;
    list.end = NULL;
}

void addStart(intNodeList &list, intNode *node) {
    if (list.start == NULL)
        list.start = list.end = node;
    else {
        node->next = list.start;
        list.start = node;
    }
}

void listInput(intNodeList &list) {
    cout << "Nhap n: ";
    int n;
    cin >> n;
    listInit(list);
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Nhap phan tu thu " << i+1 << ": ";
        cin >> x;
        intNode *node = getNode(x);
        if (node != NULL)
            addStart(list, node);
    }
}

void listOuput(intNodeList list) {
    intNode *ptr = list.start;
    while(ptr) {
        cout << ptr->info << " ";
        ptr = ptr->next; 
    }
    cout << endl;
}

void addEnd(intNodeList &list, intNode *node) {
    if (list.start == NULL) {
        list.start = list.end = node;
    }
    else {
    list.end->next = node;
    node = list.end;
    }
}
int main(int argc, char const *argv[])
{
    intNodeList list;
    listInput(list);
    addEnd(list, getNode(10));
    listOuput(list);
    return 0;
}
