#include<bits/stdc++.h>

using namespace std;

struct DNode {
	int info;
	DNode *pNext, *pPrev;
};

struct DList {
	DNode *pHead, *pTail;
};

DNode* CreateDnode(int x) {
    DNode* temp = new DNode;

    temp->info = x;
    temp->pNext = NULL;
    temp->pPrev = NULL;

    return temp;
}

void init(DList& lst) {
    lst.pHead = NULL;
    lst.pTail = NULL;
}

void addHead(DList& lst, int x) {
    DNode* temp = CreateDnode(x);
    if (lst.pHead == NULL) {
        lst.pHead = temp;
        lst.pTail = lst.pHead;
        return;
    }

    temp->pNext = lst.pHead;
    lst.pHead->pPrev = temp;
    lst.pHead = temp;
}

void addTail(DList& lst, int x) {
    DNode* temp = CreateDnode(x);
    if (lst.pHead == NULL) {
        lst.pHead = temp;
        lst.pTail = lst.pHead;
        return;
    }

    temp->pPrev = lst.pTail;
    lst.pTail->pNext = temp;
    lst.pTail = temp;
}

void createList(DList& lst) {
    int x;
    while (1) {
        cin >> x;
        if (x == -1) {
            break;
        }

        addTail(lst, x);
    }
}

void printList(DList& lst) {
    if (lst.pHead == NULL) {
        cout << "List is empty";
        return;
    }

    DNode* temp = lst.pHead;
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->pNext;
    }
}

void addAfter(DList& lst, int x, int y) {
    DNode* temp = CreateDnode(y);
    if (lst.pHead == NULL) {
        cout << "\nCan't find the value "<<x;
        return;
    }

    DNode* temp1 = lst.pHead;
    while (temp1 != NULL) {
        if (temp1->info == x) {
            break;
        }
        temp1 = temp1->pNext;
    }

    if (temp1 == NULL) {
        cout << "\nCan't find the value "<<x;
        return;
    }

    if (temp1 == lst.pTail) {
        addTail(lst, y);
        return;
    }


    temp->pNext = temp1->pNext;
    temp->pPrev = temp1;

    temp1->pNext->pPrev = temp;
    temp1->pNext = temp;
}

void addBefore(DList& lst, int x, int y) {
    DNode* temp = CreateDnode(y);
    if (lst.pHead == NULL) {
        cout << "\nCan't find the value "<<x;
        return;
    }

    DNode* temp1 = lst.pHead;
    while (temp1 != NULL) {
        if (temp1->info == x) {
            break;
        }
        temp1 = temp1->pNext;
    }

    if (temp1 == NULL) {
        cout << "\nCan't find the value "<<x;
        return;
    }

    if (temp1 == lst.pHead) {
        addHead(lst, y);
        return;
    }


    temp->pNext = temp1;
    temp->pPrev = temp1->pPrev;

    temp1->pPrev->pNext = temp;
    temp1->pPrev = temp;
}

void addAfterMulti(DList& lst, int x, int y) {
    bool check = 0;
    if (lst.pHead == NULL) {
        cout << "\nCan't find the value "<<x;
        return;
    }

    DNode* temp1 = lst.pHead;
    while (temp1 != NULL) {
        if (temp1->info == x) {
            check = 1;
            if (temp1 == lst.pTail) {
                addTail(lst, y);
            } else {
                DNode* temp = CreateDnode(y);

                temp->pNext = temp1->pNext;
                temp->pPrev = temp1;

                temp1->pNext->pPrev = temp;
                temp1->pNext = temp;
            }
        }
        temp1 = temp1->pNext;
    }

    if (!check) {
        cout << "\nCan't find the value "<<x;
    }
}

void addBeforeMulti(DList& lst, int x, int y) {
    bool check = 0;
    if (lst.pHead == NULL) {
        cout << "\nCan't find the value "<<x;
        return;
    }

    DNode* temp1 = lst.pHead;
    while (temp1 != NULL) {
        if (temp1->info == x) {
            check = 1;
            if (temp1 == lst.pHead) {
                addHead(lst, y);
            } else {
                DNode* temp = CreateDnode(y);
                
                temp->pNext = temp1;
                temp->pPrev = temp1->pPrev;

                temp1->pPrev->pNext = temp;
                temp1->pPrev = temp;
            }
        }
        temp1 = temp1->pNext;
    }

    if (!check) {
        cout << "\nCan't find the value "<<x;
    }
}

void removeHead(DList& lst) {
    if (lst.pHead == NULL) {
        cout << "\nList is empty. Can't delete";
        return;
    }

    char choice;
    cout<<"\nDo you want to delete the first element?(y/n): ";
    cin >> choice;

    if (choice != 'y' && choice != 'Y') {
        return;
    }

    DNode* temp = lst.pHead;
    if (lst.pHead == lst.pTail) {
        delete temp;
        lst.pHead = NULL;
        lst.pTail = NULL;
        cout<<"\nThe list becomes empty";
        return;
    }

    lst.pHead = temp->pNext;
    delete temp;
    lst.pHead->pPrev = NULL;
}

void removeTail(DList& lst) {
    if (lst.pHead == NULL) {
        cout << "\nList is empty. Can't delete";
        return;
    }

    char choice;
    cout<<"\nDo you want to delete the last element?(y/n): ";
    cin >> choice;

    if (choice != 'y' && choice != 'Y') {
        return;
    }

    DNode* temp = lst.pTail;
    if (lst.pHead == lst.pTail) {
        delete temp;
        lst.pHead = NULL;
        lst.pTail = NULL;
        cout<<"\nThe list becomes empty";
        return;
    }

    lst.pTail = temp->pPrev;
    delete temp;
    lst.pTail->pNext = NULL;
}

void removeNode(DList& lst, int x) {
    if (lst.pHead == NULL) {
        cout<<"\nList is empty. Can't delete";
        return;
    }

    DNode* temp1 = lst.pHead;
    while (temp1 != NULL) {
        if (temp1->info == x) {
            break;
        }
        temp1 = temp1->pNext;
    }

    if (temp1 == NULL) {
        cout << "\nCan't find the value "<<x;
        return;
    }

    char choice;
    cout<<"\nDo you want to delete "<<x<<" ?(y/n): ";
    cin >> choice;
    if (choice != 'y' && choice != 'Y') {
        return;
    }

    
    if (temp1 == lst.pHead) {
        if (lst.pHead == lst.pTail) {
            delete temp1;
            lst.pHead = NULL;
            lst.pTail = NULL;
            cout<<"\nThe list becomes empty";
            return;
        }

        lst.pHead = temp1->pNext;
        lst.pHead->pPrev = NULL;
        delete temp1;

        return;
    }

    if (temp1 == lst.pTail) {
        lst.pTail = temp1->pPrev;
        lst.pTail->pNext = NULL;
        delete temp1;
        return;
    }


    temp1->pNext->pPrev = temp1->pPrev;
    temp1->pPrev->pNext = temp1->pNext;

    delete temp1;
    return;
}

void DeleteAssignedDNode(DList& lst, DNode*& temp1) {
    if (temp1 == NULL) {
        return;
    }
    DNode* NodeToDelete = temp1;

    if (temp1 == lst.pHead) {
        if (lst.pHead == lst.pTail) {
            delete temp1;
            lst.pHead = NULL;
            lst.pTail = NULL;
            cout<<"\nThe list becomes empty";
            return;
        }

        lst.pHead = temp1->pNext;
        lst.pHead->pPrev = NULL;
        temp1 = lst.pHead;
        delete NodeToDelete;

        return;
    }

    if (temp1 == lst.pTail) {
        lst.pTail = temp1->pPrev;
        lst.pTail->pNext = NULL;
        delete temp1;
        temp1 = NULL;
        return;
    }

    temp1->pPrev->pNext = temp1->pNext;
    temp1->pNext->pPrev = temp1->pPrev;
    temp1 = temp1->pNext;

    delete NodeToDelete;
}

void removeMultiNodeS(DList& lst, int x) {
    if (lst.pHead == NULL) {
        cout<<"\nList is empty. Can't delete";
        return;
    }

    bool check = false;
    char choice;
    DNode* temp1 = lst.pHead;
    while (temp1 != NULL) {
        if (temp1->info == x) {
            check = true;
            break;
        }
        temp1 = temp1->pNext;
    }

    if (!check) {
        cout << "\nCan't find the value "<<x;
        return;
    }

    cout<<"\nDo you want to delete "<<x<<"s ?(y/n): ";
    cin >> choice;
    if (choice != 'y' && choice != 'Y') {
        return;
    }

    temp1 = lst.pHead;
    while (temp1 != NULL) {
        if (temp1->info == x) {
            DeleteAssignedDNode(lst, temp1);
        } else {
            temp1 = temp1->pNext;
        }  
    }
}

void removeAfter(DList& lst, int x) {
    if (lst.pHead == NULL) {
        cout<<"\nList is empty. Can't delete";
        return;
    }

    DNode* temp1 = lst.pHead;
    while (temp1 != NULL) {
        if (temp1->info == x) {
            break;
        }
        temp1 = temp1->pNext;
    }

    if (temp1 == NULL) {
        cout << "\nCan't find the value "<<x;
        return;
    }

    if (lst.pHead == lst.pTail) {
        cout<<endl<<x<<" is the last element. Can't delete the element after it";
        return;
    }

    if (temp1 == lst.pTail) {
        cout<<endl<<x<<" is the last element. Can't delete the element after it";
        return;
    }

    char choice;
    cout<<"\nDo you want to delete the element after "<<x<<" ?(y/n): ";
    cin >> choice;
    if (choice != 'y' && choice != 'Y') {
        return;
    }

    DNode* temp2 = temp1->pNext;
    if (temp2 == lst.pTail) {
        lst.pTail = temp1;
        temp1->pNext = NULL;
        delete temp2;
        return;
    }

    temp1->pNext = temp1->pNext->pNext;
    temp1->pNext->pPrev = temp1;  

    delete temp2;
    return;
}

void removeBefore(DList& lst, int x) {
    if (lst.pHead == NULL) {
        cout<<"\nList is empty. Can't delete";
        return;
    }

    DNode* temp1 = lst.pHead;
    while (temp1 != NULL) {
        if (temp1->info == x) {
            break;
        }
        temp1 = temp1->pNext;
    }

    if (temp1 == NULL) {
        cout << "\nCan't find the value "<<x;
        return;
    }

    if (lst.pHead == lst.pTail) {
        cout<<endl<<x<<" is the first element. Can't delete the element before it";
        return;
    }

    if (temp1 == lst.pHead) {
        cout<<endl<<x<<" is the first element. Can't delete the element before it";
        return;
    }

    char choice;
    cout<<"\nDo you want to delete the element before "<<x<<" ?(y/n): ";
    cin >> choice;
    if (choice != 'y' && choice != 'Y') {
        return;
    }

    DNode* temp2 = temp1->pPrev;
    if (temp2 == lst.pHead) {
        lst.pHead = temp1;
        temp1->pPrev = NULL;
        delete temp2;
        return;
    }

    temp1->pPrev = temp1->pPrev->pPrev;
    temp1->pPrev->pNext = temp1;

    delete temp2;
    return;
}

void DeleteAssignedAfter(DList& lst, DNode*& temp1) {
    if (temp1->pNext == NULL) {
        return;
    }

    DNode* NodeToDelete = temp1->pNext;

    if (temp1->pNext == lst.pTail) {
        delete temp1->pNext;
        temp1->pNext = NULL;
        lst.pTail = temp1;
        return;
    }

    temp1->pNext = temp1->pNext->pNext;
    temp1->pNext->pPrev = temp1;

    delete NodeToDelete;
}

void removeMultiAfters(DList& lst, int x) {
    if (lst.pHead == NULL) {
        cout<<"\nList is empty. Can't delete";
        return;
    }

    int check = 0;
    char choice;
    DNode* temp1 = lst.pHead;
    while (temp1 != NULL) {
        if (temp1->info == x) {
            check++;
        }
        temp1 = temp1->pNext;
    }

    if (!check) {
        cout << "\nCan't find the value "<<x;
        return;
    }

    if (lst.pHead == lst.pTail || ((lst.pTail->info == x) && (check == 1))) {
        cout<<"\nList has only one "<<x<<" and "<<x<<" is the last element. Can't delete the element after it";
        return;
    }

    cout<<"\nDo you want to delete all elements after "<<x<<" ?(y/n): ";
    cin >> choice;
    if (choice != 'y' && choice != 'Y') {
        return;
    }

    temp1 = lst.pHead;
    while (temp1 != NULL) {
        if (temp1->info == x) {
            DeleteAssignedAfter(lst, temp1);
        } 
        temp1 = temp1->pNext;
    }
}

void DeleteAssignedBefore(DList& lst, DNode*& temp1) {
    if (temp1->pPrev == NULL) {
        return;
    }

    DNode* NodeToDelete = temp1->pPrev;

    if (temp1->pPrev == lst.pHead) {
        delete temp1->pPrev;
        temp1->pPrev = NULL;
        lst.pHead = temp1;
        return;
    }

    temp1->pPrev = temp1->pPrev->pPrev;
    temp1->pPrev->pNext = temp1;

    delete NodeToDelete;
}

void removeMultiBefores(DList& lst, int x) {
    if (lst.pHead == NULL) {
        cout<<"\nList is empty. Can't delete";
        return;
    }

    int check = 0;
    char choice;
    DNode* temp1 = lst.pHead;
    while (temp1 != NULL) {
        if (temp1->info == x) {
            check++;
        }
        temp1 = temp1->pNext;
    }

    if (check == 0) {
        cout << "\nCan't find the value "<<x;
        return;
    }

    if ((lst.pHead == lst.pTail) || ((lst.pHead->info == x) && (check == 1))) {
        cout<<"\nList has only one "<<x<<" and "<<x<<" is the first element. Can't delete the element before it";
        return;
    }

    cout<<"\nDo you want to delete all elements before "<<x<<" ?(y/n): ";
    cin >> choice;
    if (choice != 'y' && choice != 'Y') {
        return;
    }

    temp1 = lst.pHead;
    while (temp1 != NULL) {
        if (temp1->info == x) {
            DeleteAssignedBefore(lst, temp1);
        } 
        temp1 = temp1->pNext;
    }
}

void removeAll(DList& lst) {
    if (lst.pHead == NULL) {
        cout<<"\nList is empty. Can't delete";
        return;
    }

    char choice;
    cout<<"\nDo you want to delete all elements?(y/n): ";
    cin >> choice;
    if (choice != 'y' && choice != 'Y') {
        return;
    }

    DNode* temp = lst.pHead;
    while (temp != NULL) {
        DNode* next = temp->pNext;
        delete temp;
        temp = next;
    }
    lst.pHead = lst.pTail = NULL;

    cout << "\nThe list becomes empty";
}

int main()
{
	DList L;
	init(L);
	int x,y,choice; char c;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n9. Delete the first element";
    cout<<"\n10. Delete the last element";
    cout<<"\n11. Delete the first element containing a specific value";
    cout<<"\n12. Delete all elements storing a particular value";
    cout<<"\n13. Delete the element after a specific value (only for the first one found)";
    cout<<"\n14. Delete the element before a specific value (only for the first one found)";
    cout<<"\n15. Delete all elements after a specific value";
    cout<<"\n16. Delete all elements before a specific value";
    cout<<"\n17. Delete all elements";
    cout<<"\n20. Exit"<<endl;


	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 7:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfterMulti(L,x,y);
            break;
        case 8:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBeforeMulti(L,x,y);
            break;
        case 9:
            removeHead(L);
            break;
        case 10:
            removeTail(L);
            break;
        case 11:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeNode(L,x);
            break;
        case 12:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiNodeS(L,x);
            break;
        case 13:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeAfter(L,x);
            break;
        case 14:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeBefore(L,x);
            break;
        case 15:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiAfters(L,x);
            break;
        case 16:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            cout<<"\nEnter a number: ";
            cin>>x;
            removeMultiBefores(L,x);
            break;
        case 17:
            if (L.pHead==NULL){cout<<"\nList is empty. Can't delete";break;}
            removeAll(L);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}

