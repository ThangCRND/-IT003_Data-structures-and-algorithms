#include <iostream>

using namespace std;

struct NODE
{
    int data;
    NODE *pNext;
};
struct STACK
{
   NODE *Top;
};
NODE *CreateNODE (int x)
{
    NODE *p;
    p = new NODE ;
    if (p==NULL)
        return NULL;
    p->data = x;
    p->pNext = NULL;
    return p;
}
// Khoi tạo Stack//
void CreateStack(STACK &s)
{
    s.Top = NULL;
}
bool IsEmpty (STACK s)
{
    if (s.Top == NULL)
        return true;
    return false;
}
void Push (STACK &s, NODE *p)
{
    if (s.Top==NULL)
        s.Top = p;
    else
        p ->pNext =s.Top;
         s.Top = p;
}
bool Pop(STACK &s, int &x)
{
    if (s.Top==NULL)
        return false;
    NODE *p =s.Top;
    x = p ->data;
    s.Top = s.Top ->pNext;
    delete p;
    return true;
}
//Xuat Stack //
void Output_Stack(STACK s)
{
    cout << "STACK = TOP < ";
    for (NODE *i=s.Top;i!=NULL;i=i->pNext)
    {
        cout << i->data << "  ";
    }
    cout << " >" << endl;

}

void menu()
{
    STACK s;
    CreateStack (s);

    while (true)
    {
        cout << endl;
        cout << "==========Demo Stack========="<<endl;
        cout << "\t1.Push " <<endl;
        cout << "\t2.Pop " <<endl;
        cout << "\t3.Top " <<endl;
        cout << "\t4.Checking Empty " <<endl;
        cout << "\t5.(No) Checking Full " <<endl;
        cout << "=============================="<<endl;
        Output_Stack (s);
        cout << "=============================="<<endl;

        cout << "Nhap cau lua chon :" << endl;

    int chon;
    cin >> chon ;
    cout << endl << endl;


    switch (chon)
     {

       case 1:
       {
          cout<<"Them gia tri vao Stack .Gia tri la :" ;
          int x;
          cin >> x;
           NODE *p=CreateNODE(x);
           Push(s,p);
          break;
       }

        case 2:
        {
           int x;
           bool bao_hieu = Pop (s,x);
            if (bao_hieu == false)
              {
                cout << "Khong Pop duoc do Stack rong." <<endl;
              }
            else
              {
                cout << "Pop was sucessfull" << endl;
                cout << "Value is : " << x << endl;
              }
          break;
        }
        case 3:
        {
          if (IsEmpty(s))
            cout << "Stack is Empty => No Top."<<endl;
           else
            cout << "Top of Stack is: " << s.Top ->data << endl;
          break;
        }
        case 4:
        {
            cout <<"Stack is Empty: " << IsEmpty (s) <<endl;
            break;
        }

      }
    }

}

int main()
{
    menu();
    return 0;
}
