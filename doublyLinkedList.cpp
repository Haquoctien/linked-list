#include <iostream>
using namespace std;

struct intNode {
    int info;
    intNode *nextNode;
    intNode *prevNode;
};

struct intNodeList {
    intNode *first;
    intNode *last;
};

void intNodeListInit(intNodeList &list) {
    list.first = NULL;
    list.last = NULL;
}

intNode *newNode(int x) {
    intNode *node = new intNode;
    if (node == NULL)
        return NULL;
    node->info = x;
    // no link is made
    node->nextNode = NULL;
    node->prevNode = NULL;
    return node;
}
void addFirst(intNodeList &list, intNode *node) {
    if(list.first == NULL)
    {
        // node is first and last if list is empty
        list.first = list.last = node;
    }
    else {
        // node points forward to first
        node->nextNode = list.first;
        // first point backward to node
        list.first->prevNode = node;
        // now node is first
        list.first = node;
    }

}
void listInput(intNodeList &list) {
    int n;
    cout << "Nhap so phan tu can nhap: ";
    cin >> n;
    intNodeListInit(list);
    for(int i = 0; i < n; i++)
    {
        int x;
        cout << "Nhap phan thu thu " << i+ 1 << ": ";
        cin>>x;
        intNode *node = newNode(x);
        if (node != NULL)
        {
            addFirst(list, node);
        }
    }
}
void listOuput(intNodeList &list) {
    intNode *p = list.first;
    while(p != NULL) {
        cout << p->info;
        p = p->nextNode;
    }
    cout << endl;
}


int main(void)
{
    intNodeList list;
    listInput(list);
    listOuput(list);
    return 0;
}