#include <iostream>
#include <cstring>
#include <string>
using namespace std;

typedef struct Node {
    int info;
    Node* Next;
} node;

struct List {
    Node* Head;
    Node* Tail;
};

void Init(List& lst) {
    lst.Head = nullptr;
    lst.Tail = nullptr;
}

Node* CreateNode(int x) {
    Node* temp = new Node;
    
    temp->info = x;
    temp->Next = nullptr;

    return temp;
}

void AddHead(List& lst, int x) {
    if (lst.Head == NULL) {
        Node* temp = CreateNode(x);
        lst.Head = temp;
        lst.Tail = lst.Head;
        return;
    }
    Node* temp = CreateNode(x);
    temp->Next = lst.Head;
    lst.Head = temp;
}

void AddTail(List& lst, int x) {
    if (lst.Head == nullptr) {
        Node* temp = CreateNode(x);
        lst.Head = temp;
        lst.Tail = lst.Head;
        return;
    }
    Node* temp = CreateNode(x);
    lst.Tail->Next = temp;
    lst.Tail = temp;
}

void AddElement(List& lst, int a, int b) {
    Node* temp = CreateNode(b);
    if (lst.Head == nullptr) {
        lst.Head = temp;
        lst.Tail = lst.Head;
        return;
    }

    Node* temp1 = lst.Head;
    while (temp1 != nullptr) {
        if (temp1->info == a) {
            break;
        }
        temp1 = temp1->Next;
    }

    if (temp1 == nullptr) {
        AddHead(lst, b);
        return;
    }

    if (temp1 == lst.Tail) {
        AddTail(lst, b);
        return;
    }


    temp->Next = temp1->Next;
    temp1->Next = temp;

}

void inputList(List& lst, int n) {
    if (n == 0) {
        return;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        AddTail(lst, x);
    }
}

void outputList(List& lst) {
    if (lst.Head == nullptr) {
        cout << "List is empty";
        return;
    }

    Node* temp = lst.Head;
    while (temp != nullptr) {
        cout << temp->info << " ";
        temp = temp->Next;
    }
}

Node* findMax(List& lst) {
    if (lst.Head == nullptr) {
        cout << "List is empty";
        return nullptr;
    }

    Node* temp = lst.Head;
    Node* tempMax = lst.Head;
    while (temp != nullptr) {
        if (tempMax->info < temp->info) {
            tempMax = temp;
        }
        temp = temp->Next;
    }
    return tempMax;
}

Node* findElementFromEnd(List& lst, int i) {
    if (lst.Head == nullptr && i != 0) {
        cout << "List is empty";
        return nullptr;
    }
    int count = 0;
    Node* temp = lst.Head;

    while (temp != nullptr) {
        count++;
        temp = temp->Next;
    }

    temp = lst.Head;
    if (count - i < 0 || i <= 0) {
        cout << "The index is invalid";
        return nullptr;
    }

    for (int j = 0; j <= count - i - 1; j++) {
        temp = temp->Next;
    }

    return temp;
}

Node* findMiddle(List& lst) {
    if (lst.Head == nullptr) {
        return nullptr;
    }

    int count = 0;
    Node* temp = lst.Head;

    while (temp != nullptr) {
        count++;
        temp = temp->Next;
    }

    int i = (count / 2) + 1;

    temp = lst.Head;
    for (int j = 1; j < i; j++) {
        temp = temp->Next;
    }

    return temp;
}

void copy(List& lst1, List& lst2) {
    if (lst1.Head == NULL) {
        return;
    }

    Node* temp = lst1.Head;

    while (temp != NULL) {
        AddTail(lst2, temp->info);
        temp = temp->Next;
    }
}

void concate(List& lst1, List& lst2) {
    if (lst2.Head == nullptr) {
        return;
    }
    if (lst1.Head == nullptr) {
        lst1 = lst2;
        return;
    }

    lst1.Tail->Next = lst2.Head;
}

Node* FindNode(List& lst, int a) {
    if (lst.Head == nullptr) {
        return nullptr;
    }

    Node* temp = lst.Head;
    while (temp != nullptr) {
        if (temp->info == a) {
            return temp;
        } 
        temp = temp->Next;
    }

    return nullptr;
}

Node* swapData(List& lst, int a, int b) {
    Node* temp1 = FindNode(lst, a);
    Node* temp2 = FindNode(lst, b);

    if (temp1 == nullptr || temp2 == nullptr) {
        return nullptr;
    }

    int temp = temp1->info;
    temp1->info = temp2->info;
    temp2->info = temp;

    return temp1;
}

void DeleteTail(List& lst) {
    if (lst.Head == NULL) {
        return;
    }

    Node* temp = lst.Head;
    if (temp == lst.Tail) {
        delete temp;
        lst.Head = NULL;
        lst.Tail = NULL;
        return;
    }

    while (1) {
        if (temp->Next == lst.Tail) {
            break;
        }
        temp = temp->Next;
    }

    lst.Tail = temp;
    delete lst.Tail->Next;
    lst.Tail->Next = NULL;

}

void moveLastToFront(List& lst) {
    if (lst.Head == NULL) {
        return;
    }
    if (lst.Head == lst.Tail) {
        return;
    }

    int x = lst.Tail->info;
    AddHead(lst, x);
    DeleteTail(lst);
}

void reverse_list(List &l) {
    if (l.Tail->Next != NULL) {
        return;
    }
    if (l.Head == NULL) {
        return;
    }

    Node* tempNode = l.Head;
    Node* prevNode = NULL;
    Node* nextNode;

    while (tempNode != NULL) {
        nextNode = tempNode->Next;
        tempNode->Next = prevNode;

        prevNode = tempNode;
        tempNode = nextNode;
    }

    Node* temp = l.Head;
    l.Head = l.Tail;
    l.Tail = l.Head;
}

int DeleteElement(List& lst, int x) {
    if (lst.Head == nullptr) {
        return 0;
    }

    Node* temp1 = lst.Head;
    Node* temp2 = nullptr;
    while (temp1 != nullptr) {
        if (temp1->info == x) {
            break;
        }
        temp2 = temp1;
        temp1 = temp1->Next;
    }

    if (temp1 == nullptr) {
        return 0;
    }

    if (temp1 == lst.Head) {
        lst.Head = lst.Head->Next;
        delete temp1;

        if (lst.Head == nullptr) {
            lst.Head = nullptr;
            lst.Tail = nullptr;
        }

        return 1;
    }

    if (temp1 == lst.Tail) {
        lst.Tail = temp2;
        delete temp1;
        lst.Tail->Next = nullptr;
        return 1;
    }

    temp2->Next = temp1->Next;
    delete temp1;
    return 1;

}

void DeleteMultipleElements(List& lst, int x) {
    if (lst.Head == nullptr) {
        return;
    }

    while (1) {
        int check = DeleteElement(lst, x);
        if (!check) {
            break;
        }
    }
}

void DeleteHead(List& lst) {
    if (lst.Head == nullptr) {
        return;
    }

    Node* temp1 = lst.Head;
    if (lst.Tail == lst.Head) {
        delete temp1;
        lst.Head = nullptr;
        lst.Tail = nullptr;
        return;
    }

    lst.Head = lst.Head->Next;
    delete temp1;
}

int main()
{
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);


    cout<<"\nThe maximum value: ";
    node *p = findMax(L);
    if(p) cout<<p->info;

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<" (from the end of L): ";
    p = findElementFromEnd(L,i);
    if(p) cout<<p->info;

    p=findMiddle(L); //Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if(p)cout<<"\nThe middle element is "<<p->info << "\n";

    List l2; Init(l2);
    copy(L, l2);

    p = L.Head;
    Node *q = l2.Head;
    while(p != NULL){
    	if (p == q || p->info != q->info) cout << "WRONG";
    	cout << p->info << endl;
    	p = p->Next;
    	q = q->Next;
    }



    return 0;
}
