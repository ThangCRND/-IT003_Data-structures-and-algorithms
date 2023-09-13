#include <iostream>

using namespace std;
//step #1
struct NODE
{
    int data;
    NODE *pre_node;
};
//step #2
struct QUEUE
{
    NODE *Rear;
    NODE *Front;
};
//Step #3
NODE *initNode(int x)
{
    NODE *p= new NODE;
    if (p==NULL)
        return NULL;
    p->data = x;
    p->pre_node=NULL;
    return p;
}
//Step #4
void initQueue(QUEUE &q)
{
    q.Front=NULL;
    q.Rear=NULL;
}
bool IsEmpty(QUEUE q)
{
	if (q.Front == NULL)
	 {
		return true;
	 }
	return false;
}
void EnQueue(QUEUE &q, NODE *p) //Thêm vào cuối//
{
    if (q.Front==NULL)
    {
        q.Front=q.Rear=p;
    }
    else
    {
        q.Rear ->pre_node = p;
        q.Rear = p;
    }
}
//Lấy phần tử đầu hàng đợi//
int DeQueue(QUEUE &q, int &x)
{
    NODE *p;
    if (IsEmpty(q) != true)
    {
        p = q.Front;
        x = p->data;
        q.Front=q.Front ->pre_node;
         if (q.Front==NULL)
            q.Rear==NULL;
         delete p;
        return 1;
    }
    return 0;
}
void Print_queue(QUEUE q)
{
    cout << "<==== FRONT    REAR  ====> " << endl;
    for (NODE *i=q.Front;i!=NULL;i=i->pre_node)
   {

     cout << "\t"<< i->data << " ";

   }
}
void menu()
{
    QUEUE q;
    initQueue(q);

  while (true)
  {
        cout << endl;
        cout <<"\n===================MENU================"<<endl;
        cout <<"\n>>\t1.EnQueue "<<endl;
        cout <<"\n>>\t2.DeQueue "<<endl;
        cout <<"\n>>\t3.Rear - Front " << endl;
        cout <<"\n>>\t4.Check Empty " << endl;
        cout <<"\n==================END=================="<<endl;
        cout << "\t"; Print_queue(q);
        cout <<"\n======================================="<<endl;
        cout <<"\n\t Vui long nhap lua chon: " << endl;

        int chon;
        cin >> chon;

    switch (chon)
    {
    case 1:
        {
        cout << "\tNhap gia tri vao queue: ";
        int value;
        cin >> value;
        EnQueue (q, initNode(value));
        }
      break;
    case 2:
        {
            cout << "\nKet qua: " << endl;
            int value;
            DeQueue(q,value);
            cout << "\tGia tri " << value << " da ra khoi QUEUE."<<endl;
        }
        break;
    case 3:
        {
            cout <<"\tKet qua: " << endl;
            if (q.Front==NULL)
               {
                cout << "\t+ Rear: " << "NULL" <<endl;
                cout << "\t+ Front: " << "NULL" << endl;
               }
            else
               {
                cout << "\t+ Rear: " << q.Rear ->data  <<endl;
                cout << "\t+ Front: " << q.Front->data << endl;
               }
        }
        break;
    case 4:
        {
            if(q.Front==NULL)
                {
                cout <<"QUEUE is Empty."<<endl;
                }
            else
                {
                cout << "QUEUE is not empty."<<endl;
                }
        }
        break;

    }

  }
}
int main()
{
    menu();
    return 0;
}
