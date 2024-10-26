/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
typedef struct node {
    int Info;
    node* Left;
    node* Right;
} Node;

typedef node* Tree;

node* Createnode(int x) {
    node* temp = new node;

    temp->Info = x;
    temp->Left = NULL;
    temp->Right = NULL;

    return temp;
}

int countnodes(node*& Root) {
    if (Root == NULL) {
        return 0;
    }
    return 1 + countnodes(Root->Left) + countnodes(Root->Right);
}

int depthOfTree(node*& Root) {
    if (Root == NULL) return -1;
    return 1 + max(depthOfTree(Root->Left), depthOfTree(Root->Right));
}

void Addnode(node*& Root, int x) {
    node* temp = Createnode(x);
    if (Root == NULL) {
        Root = temp;
        return;
    }

    if (Root->Info == x) {
        return;
    }

    if (Root->Info > x) {
        Addnode(Root->Left, x);
    }
    if (Root->Info < x) {
        Addnode(Root->Right, x);
    }
}

void inputTree(node*& Root) {
    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        Addnode(Root, x);
    }
}

void LNR(node*& Root) {
    if (Root == NULL) {
        return;
    }

    LNR(Root->Left);
    cout << Root->Info << " ";
    LNR(Root->Right);
}

void NLR(node*& Root) {
    if (Root == NULL) {
        return;
    }

    cout << Root->Info << " ";
    NLR(Root->Left);
    NLR(Root->Right);
}

int FindHeight(node* Root) {
    if (Root == NULL) {
        return -1;
    }

    return 1 + max(FindHeight(Root->Left), FindHeight(Root->Right));
}

int AVL(node*& Root) {
    if (Root == NULL) {
        return -1;
    }

    if (Root->Right == NULL) {
        return 0;
    }

    node* p = Root->Right;

    Root->Right = p->Left;
    p->Left = Root;
    Root = p;

    return 1;
}

bool isAVL(node*& Root) {
    if (Root == NULL) return true;
    int LHeight = FindHeight(Root->Left);
    int RHeight = FindHeight(Root->Right);

    return (abs(LHeight - RHeight) <= 1) && isAVL(Root->Left) && isAVL(Root->Right);
}

Node* FindNode(Node*& Root, int x) {
    if (Root->Info == x) {
        return Root;
    }

    if (Root->Info > x) {
        return FindNode(Root->Left, x);
    }

    if (Root->Info < x) {
        return FindNode(Root->Right, x);
    }

    return nullptr;
}

Node* minValue(Node*& Root) {
    if (Root == nullptr) {
        return nullptr;
    }

    if (Root->Left == nullptr) {
        return Root;
    }

    return minValue(Root->Left);
}

Node* maxValue(Node*& Root) {
    if (Root == nullptr) {
        return nullptr;
    }

    if (Root->Right == nullptr) {
        return Root;
    }
    
    return maxValue(Root->Right);
}

void listLeafs(Node*& Root) {
    if (Root == nullptr) {
        return;
    }

    if (Root->Left == nullptr && Root->Right == nullptr) {
        cout << Root->Info << " ";
    }
    listLeafs(Root->Left);
    listLeafs(Root->Right);
}

void listInternalNodes(Node*& Root, int x) {
    if (Root == nullptr) {
        return;
    }

    if ((Root->Left != nullptr || Root->Right != nullptr) && x != 0) {
        cout << Root->Info << " ";
    }
    listInternalNodes(Root->Left, x + 1);
    listInternalNodes(Root->Right, x + 1);
}

void listNodesWithOneChild(Node*& Root) {
    bool check = true;
    if (Root == nullptr) {
        return;
    }

    if (Root->Left != nullptr && Root->Right != nullptr) {
        check = false;
    }

    if ((Root->Left != nullptr || Root->Right != nullptr) && check == true) {
        cout << Root->Info << " ";
    }
    listNodesWithOneChild(Root->Left);
    listNodesWithOneChild(Root->Right);
}

void listNodesWithTwoChildren(Node*& Root) {
    if (Root == nullptr) {
        return;
    }

    if (Root->Left != nullptr && Root->Right != nullptr) {
        cout << Root->Info << " ";
    }

    listNodesWithTwoChildren(Root->Left);
    listNodesWithTwoChildren(Root->Right);
}


void Delete(Node*& Root, int x) { //understand it as deleting Root carrying the value of x
    if (Root == nullptr) {
        return;
    }

    if (Root->Info > x) {
        Delete(Root->Left, x);
    } else if (Root->Info < x) {
        Delete(Root->Right, x);
    } else {
        if ((Root->Left == nullptr) && (Root->Right == nullptr)) {
            delete Root;
            Root = nullptr;
            return;
        }
        if (Root->Right == nullptr) {      
            Node* p = Root;
            Root = Root->Left;

            delete p;
            return;
        } 
        if (Root->Left == nullptr) {
            Node* p = Root;
            Root = Root->Right;

            delete p;
            return;
        } 
        
        Node* tmp = maxValue(Root->Left);
        
        Root->Info = tmp->Info;
        Delete(Root->Left, tmp->Info);
        return;
    }   
}

int main()
{
	Tree T = NULL;
	inputTree(T);
    //NLR(T);
    cout<<isAVL(T);
	return 0;
}
