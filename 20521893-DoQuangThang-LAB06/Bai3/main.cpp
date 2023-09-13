#include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *pNext;
};

struct Stack
{
    Node *Top;
};

Node *CreateNode (int x)
{
    Node *p = new Node;
    if (p == NULL)
        return NULL;
    p->Data = x;
    p->pNext = NULL;
    return p;
}

void CreateStack (Stack &s)
{
    s.Top = NULL;
}

bool IsEmpty (Stack &s)
{
    if(s.Top == NULL)
        return true;
    return false;
}

void Push (Stack &s, Node *p)
{
    if (s.Top == NULL)
        s.Top = p;
    else
    {
        p->pNext = s.Top;
        s.Top = p;
    }
}

bool Pop (Stack &s, int &x)
{
    Node *p;
    if (s.Top != NULL)
    {
        p = s.Top;
        x = p->Data;
        s.Top = p->pNext;
        delete p;
        return true;
    }
    return false;
}

int Top (Stack &s)
{
    return s.Top->Data;
}

void Output (Stack &s)
{
    cout << "STACK = Top< ";
    for (Node *p = s.Top; p != NULL; p = p->pNext)
    {
        cout << "\t\t" << p->Data;
    }
    cout << " \t\t>\n";
}

void AtoB (Stack &a, Stack &b, int x)
{
    Pop(a,x);
    Node *p = CreateNode (x);
    Push(b,p);
}
void BtoA (Stack &b, Stack &a, int x)
{
    Pop(b,x);
    Node *p = CreateNode (x);
    Push(a,p);
}

void BtoC (Stack &b, Stack &c, int x)
{
    Pop(b,x);
    Node *p = CreateNode (x);
    Push(c,p);
}

void CtoB (Stack &c, Stack &b, int x)
{
    Pop(c,x);
    Node *p = CreateNode (x);
    Push(b,p);
}

void CtoA (Stack &c, Stack &a, int x)
{
    Pop(c,x);
    Node *p = CreateNode (x);
    Push(a,p);
}

void AtoC (Stack &a, Stack &c, int x)
{
    Pop(a,x);
    Node *p = CreateNode (x);
    Push(c,p);
}

void menu ()
{
    Stack a,b,c;
    CreateStack(a);
    CreateStack(b);
    CreateStack(c);
    int x;
    while (true)
    {
        int chon;
       cout << "\n\n=========== Demo Stack ===========\n";
       cout << "\t0. Creating Tower\n";
       cout << "\t1. A -> B\n";
       cout << "\t2. B -> A\n";
       cout << "\t3. B -> C\n";
       cout << "\t4. C -> B\n";
       cout << "\t5. C -> A\n";
       cout << "\t6. A -> C\n";
       cout << "A Tower\n";
       Output(a);
       cout << "B Tower\n";
       Output(b);
       cout << "C Tower\n";
       Output(c);
       cout << "===================================\n";
       cout << "    Please input: ";
       cin >> chon;
       switch(chon)
       {
       case 0:{
            cin >> x;
            Node *p = CreateNode (x);
            Push(a,p);
            }
            break;
       case 1:
           if (IsEmpty(a) != true)
            AtoB(a,b,x);
            break;
       case 2:
           if (IsEmpty(b) != true)
            BtoA(b,a,x);
            break;
       case 3:
           if (IsEmpty(b) != true)
            BtoC(b,c,x);
            break;
       case 4:
           if (IsEmpty(c) != true)
            CtoB(c,b,x);
            break;
       case 5:
           if (IsEmpty(c) != true)
            CtoA(c,a,x);
            break;
       case 6:
           if (IsEmpty(a) != true)
            AtoC(a,c,x);
            break;
       default:
        return ;
       }
    }
}

int main()
{
    menu();
    return 0;
}
