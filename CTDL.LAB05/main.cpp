#include <iostream>

using namespace std;
//Bước1
 struct NODE
 {
  int data;//lưu dữ liệu
  NODE *pNext; // lưu địa chỉ Node sau

 };
 //Bước2
 struct LIST
 {
     NODE *head;
     NODE *tail;
 };
 //Bước3
 NODE *CreateNode (int x)
 {
     NODE *p;
     p=new NODE;
     if (p==NULL)
        return NULL;
     p-> data = x; //gán giá trị cho Node
     p-> pNext = NULL;
     return p;
 }
 //Bước4
 void CreateList(LIST &l)
 {
     l.head=NULL;
     l.tail=NULL;
 }
 //câu3
 void addHead (LIST &l,NODE *p)
 {
     if (l.head==NULL)
     {
         l.head=l.tail=p;
     }
     else
     {
         p->pNext=l.head;//Mốc địa chỉ
         l.head = p;//Di dời head theo địa chỉ của p
     }
 }
 //Câu4
 void addTail (LIST &l,NODE *p)
 {
     if (l.head==NULL)
     {
         l.head = l.tail = p;
     }
     else
     {
        l.tail->pNext = p;//Mốc địa chỉ
        l.tail = p; //Di dời tail theo đia chỉ của p
     }
 }
//Câu11.In danh sách
 void printList(LIST l)
 {
     for (NODE *i=l.head;i!=NULL;i=i->pNext)
     {
         cout << i->data << "\t";
     }
     cout << endl;
 }
 //Câu6.Nhập tự động
 void input_auto(LIST &l)
 {
  int n= 39 + rand()%(59-39+1);
  for (int i=1;i<=n;i++)
  {
      NODE *p=CreateNode(-99 + rand()%199);
      addTail(l,p);
  }
 }
 //Câu 7.Nhập danh sách từ mảng 1 chiều //
 void CreateList_Array(int a[],int n,LIST &l)
 {
     for (int i = 0;i < n;i++)
        addTail (l,CreateNode(a[i]));
 }

 //Câu 14.kiểm tra danh sách rỗng hay không //
 bool IsEmpty (LIST l)
 {
     if (l.head == NULL)
        return true;
     return false;
 }
 //Đếm số phần tử trong danh sách(cau19)
 int Size_of_List(LIST l)
 {
     int count = 0;
	NODE* p = l.head;
	while (p != NULL)
	{
		count++;
		p = p->pNext;
	}
	return count;
 }
 //Câu 8.Chèn giữa danh sách //
 void Insert_Mid(LIST &l,int pos,NODE *p)
 {

     if (pos <0 || pos >= Size_of_List(l))
      {
        cout << "Khong the chen Node!";
        return ;
      }
     if(pos==0)
      {
        addHead (l,p);
      }
     else if (pos == Size_of_List(l)-1)
      {
        addTail(l,p);
      }
     //*Thay đổi mối liên kết Node
     else
     {
          int x;
        NODE *p=CreateNode(x);
        NODE *pIns = l.head; //*pIns:Node đứng sau Node cần chèn
        NODE *pPre = NULL; //*pPre:Node đứng trước Node cần chèn
         int i=0;
       while (pIns != NULL) //*vòng lặp tìm pPre và pIns*//
       {
           if(i==pos)
            break;
           pPre = pIns;
           pIns = pIns ->pNext;
           i++;
       }
       //*Tìm được thì thay đổi con trỏ pNext//
       pPre ->pNext =p;
       p->pNext = pIns;
     }
 }
 //Câu 9.Chèn thêm giá trị x vào sau giá trị y//
 void Add_after_Y(LIST l,int x,int y)
 {
     NODE *P = CreateNode(x);
     NODE *Q =CreateNode (y);
     for (NODE *i=l.head;i!=NULL;i->pNext)
     {
         if (i ->data == Q ->data)
         {
             NODE *F = i ->pNext;
             i ->pNext = P;
             P ->pNext =F;
             return;
         }
     }
 }
 //Câu 16. Tìm kiếm 1 node X//
 NODE *Search_NodeX(LIST l,int x)
 {
     cin >> x;
     for (NODE *i=l.head;i!=NULL;i=i->pNext)
     if (i->data == x)
       return i;
       return NULL;
 }
//void Search_All_NodeX (LIST l,int x)
//{
   // for (NODE *i=l.head;i!=NULL;i=i->pNext)

//}

 //*Caua18.Tính tổng các Node//
 void Sum_Of_Node (LIST l)
 {
     int Sum = 0;
     for (NODE *i=l.head;i!=NULL;i=i->pNext)
       {
          Sum += i ->data;
       }
 }
//Cau20.Đếm chẵn//
int Count_Chan(LIST l)
{
    int count_chan = 0;

    for (NODE *i=l.head;i!=NULL;i=i->pNext)
      {

        if (i->data %2 == 0)
          count_chan++;
       }
    return count_chan;
}
//Câu20.Dếm lẻ//
int Count_Le (LIST l)
{
      int count_le = 0;
     for (NODE *i=l.head;i!=NULL;i=i->pNext)
         {
        if (i->data%2!=0)
        count_le++;
         }
    return count_le;
}
//Caau21.Đếm Node dương//
int Count_Node_Duong(LIST l)
{
    int count_duong =0;
    for (NODE *i=l.head;i!=NULL;i=i->pNext)
        if (i->data >0)
        count_duong ++;
    return count_duong;
}
//Câu 21.Đếm Node âm//
int Count_Node_Am(LIST l)
{
    int count_am = 0;
    for (NODE *i=l.head;i!=NULL;i=i->pNext)
        if (i ->data < 0)
     count_am++;
    return count_am;
}
//Cau22.Tìm node max
int Find_Node_Max(LIST l)
{
    NODE *p;
    int max;
    max =l.head ->data;
    while (p!=NULL)
    {
        if (max < p->data)
        {
            max = p->data;
        }
        p=p->pNext;
    }
    return max;
}
//Cau22.Tìm Node min//
int Find_Node_Min(LIST l)
{
    int min;
    min = l.head ->data;
    for (NODE *i=l.head;i!=NULL;i=i->pNext)
    {

        if (min > i->data)
        {
            min = i->data;
        }
    }
    return min;
}
//Cau32.Xóa node đầu//
void RemoveHead(LIST &l)
{
    if (l.head == NULL)
        return;
    else{
        NODE *p=l.head ;
        l.head =l.head -> pNext;
        delete p;
    }
}
//Câu 33.Xóa node cuối//
void RemoveTail(LIST &l)
{
    if (l.head==NULL)
     {
        return;
     }
    if (l.head -> pNext == NULL)
     {
       RemoveHead(l);
        return;
     }
    else
    {
        for (NODE *i=l.head;i!=NULL;i=i->pNext)
      {
        if (i->pNext == l.tail)
        delete l.tail;
        i->pNext = NULL;
        l.tail = i;
        return ;
      }
    }
}
//*Câu34.Xóa node X//
void RemoveX(LIST &l,int x)
{
    if(l.head==NULL)
    {
        return;
    }
    if(l.head->data==x)
    {
        RemoveHead(l);
    }
    NODE *X=new NODE;
    for(NODE *i=l.head;i!=NULL;i=i->pNext)
    {
        if(i->data==x)
        {
            X->pNext=i->pNext;
            delete i;
            return;
        }
        X=i;
    }
}
//Cau37.Xóa toàn bo node //
void RemoveList(LIST &l)
{
    NODE *p;
   while (l.head !=NULL)
   {
       p=l.head;
       l.head = p->pNext;
       delete p;
   }
}
int Sum_All_Chan(LIST l)
{
    int Sum1=0;
    for (NODE *i=l.head;i!=NULL;i=i->pNext)
        if (i->data % 2 == 0)
        Sum1 += i->data;
    return Sum1;
}
int Sum_All_Le(LIST l)
{
    int Sum2=0;
    for (NODE *i=l.head;i!=NULL;i=i->pNext)
        if (i->data % 2 != 0)
        Sum2 += i->data;
    return Sum2;
}
//Cau27.So sanh tong chan -tong le//
int SoSanh(LIST l)
{
    for (NODE *i=l.head;i!=NULL;i=i->pNext)
    {
        if (Sum_All_Chan < Sum_All_Le)
         return 1;
      else if (Sum_All_Chan == Sum_All_Le)
          return 0;
       else
         return -1;
    }
}
//Câu 29.Đảo ngược danh sách//
void Reverse (LIST &l,NODE *p)
{
    NODE *parent =l.head;
    NODE *current = l.head -> pNext;
      l.head = current ->pNext;
      current ->pNext =NULL;
      current ->pNext =parent;
    while (l.head ->pNext)
    {
        parent = current;
        current = l.head;
        l.head =l.head ->pNext;
        current ->pNext=parent;
    }
    l.head->pNext=current;


}
//Cau35.Noi danh sach//
void Noi_Danh_Sach(LIST &l,LIST &L1,NODE *p,LIST &L2)
{
    if (L1.head ==NULL && L2.head==NULL)
     {
        addTail(l,p);
        return;
     }
     NODE *a=L1.head;
     NODE *b=L2.head;
    while (a!=NULL)
     {
        addTail(l,a);
        a=a->pNext;
     }
        addTail(l,p);

    while (b!=NULL)
     {
        addTail (l,b);
        b=b->pNext;
     }
}
//Câu 38.Sắp xếp DS tăng/giảm //
void Interchange_Sort (LIST l) //Đổi chỗ trực tiếp //
{
    for (NODE *i=l.head;i->pNext!=NULL;i=i->pNext)
     for (NODE *j=i->pNext;j!=NULL;j=j->pNext)
      if (i->data > j->data)
       {
        int temp = i->data;
            i->data = j->data;
            j->data =temp;
       }
}









int main()
{
    NODE *p1=CreateNode(20);
      cout << p1 << endl;
      cout << p1->data << endl;
      cout << p1->pNext <<endl;
    NODE *p2=CreateNode(20);
      cout << p2 << endl;
      cout << p2->data << endl;
      cout << p2->pNext << endl;
    LIST l;
    CreateList(l);
     cout << l.head << "\n" << l.tail << endl;
     NODE *p=CreateNode(20);
     addHead (l,p);
    //addHead(l,CreateNode(20));
     addTail (l,CreateNode(25));
     addHead (l,CreateNode(10));
     addTail (l,CreateNode(30));
     printList (l);
     input_auto(l);



    return 0;
}
