#include <iostream>
#include <time.h>
#include <iomanip>
#include <math.h>
using namespace std;

struct NODE
{
    float data;
    NODE *pNext;
};
struct LIST
{
    NODE *Head;
    NODE *Tail;
};
NODE *CreateNode (float x)
{
    NODE *p = new NODE;
     if (p==NULL)
        return NULL;
     p->data=x;
     p->pNext=NULL;
     return p;
}
void CreateList (LIST &l)
{
    l.Head=NULL;
    l.Tail=NULL;
}
void AddTail (LIST &l,NODE *p)
{
    if (l.Head==NULL)
    {
        l.Head=l.Tail=p;
    }
    else
    {
        l.Tail->pNext=p;
        l.Tail=p;
    }
}
void Print_BK (LIST &l)
{
    for (NODE *p=l.Head;p!=NULL;p=p->pNext)
        cout << p->data << "   ";
    cout << endl;
}
//=================================HASH TABLE==========================//
#define M 11
struct HASHTABLE
{
    LIST bucket [M];
};

void InitBuckets(HASHTABLE &h)
{
    for (int i=0;i<M;i++)
    {
        CreateList(h.bucket[i]);
    }
}

int hashfunc(float data)
{
    return abs((int)data % M);
}
void Insert(HASHTABLE &h,float data)
{
    //B1:Băm để xác định vị trí
    int b=hashfunc(data);
    //b2:Thêm vào
   // NODE *p =CreateNode (data);
   // AddTail(h.bucket[b],p);
    //Hoặc :
     AddTail(h.bucket[b],CreateNode(data));
}
void show_HashTable (HASHTABLE h)
{
    for (int i=0;i<M;i++)
    {
        cout << "[BUCKET #" << i << "]:\t";
        //Print_BK(h.bucket[i]);
        LIST l=h.bucket[i];
        for (NODE *i=l.Head;i!=NULL;i=i->pNext)
        {
            cout << i->data << "\t";
        }
        cout << endl;
    }
}

/*
 Câu 2: Khởi tạo ngẫu nhiên giá trị cho bảng băm
 +Input :  Số lượng giá trị (n)
 +Output : giá trị chạy ngẫu nhiên theo điều kiện và theo n
*/
void auto_input_array(HASHTABLE &h)
{
    cout << "So phan tu duoc tao ngau nhien: ";
    srand(time(NULL));
    int n = 14 + rand() % (24-14+1);
    cout << n << endl;
    for(int i = 0; i < n; i++)
    {
       float x  = -261 + rand() % (521+261+1);
        Insert (h,x);

      cout << "\t" << fixed << setprecision(2) << x << endl;
    }
}

/*
Câu 3: Nhập giá trị cho bảng băm từ mảng 1D
 + Input : mảng 1D, Số lượng n
 + Output : Gía trị trong mảng 1D
*/
void input_array(HASHTABLE &h,float a[],double n)
{
    for (int i=0;i<n;i++)
    {
        Insert(h, a[i]);
    }
}

/*
Câu 4 : Nhập thủ công từ bàn phím
 + Input : Nhập từng giá trị
 + Output : Hien thi ra cac giá tri đó
*/
void NhapThuCong(HASHTABLE &h)
{
    float x;
    do
    {
        int chon = 0;
        cout << "Nhap phan tu de gan vao bang bam: ";
        cin >> x;
        if(x != 0)
        {
            Insert (h,x);
        }
        else
        {
            cout << "Nhap phim 1 de nhap 0 vao bang bam, nhan phim 0 de ket thuc nhap: ";
            cin >> chon;
            if (chon != 0)
            {
                Insert(h,0);
                NhapThuCong(h);
            }
            else
                return;
        }
    }while(x != 0);
}
/*
Câu 5: Đếm bucket rỗng trong bang băm
 + Input : bảng băm ,LIST
+ Output : Số lượng bucket không rỗng
*/
int Count_bucket(HASHTABLE h)
{
    int count = 0;

    for (int i = 0;i < M;i++)
    {
         LIST l = h.bucket[i];
	      if (l.Head!=NULL)
		count++;

    }
	return count;
}
/*
  Câu 6: Đếm giá trị âm lẻ  trong bang băm
  + Input : bảng băm ,LIST
  + Output : Số lượng các giá trị
*/
int Count_Value(HASHTABLE h,int &count)
{
    for (int i = 0;i < M;i++)
    {
     for (NODE *p=h.bucket[i].Head;p!=NULL;p=p->pNext)
	  {
	      if ((int)p->data % 2 !=0 && (int)p->data < 0)
		count++;
	  }
    }
	return count;
}
/*
Câu 7 : Tìm X Y trong bảng băm
 + Input : hàm băm , LIST
 + Output : địa chỉ x y tìm thấy
*/
NODE *Search_XY(HASHTABLE h,float x)
{

    int iBucket = hashfunc(x);
    LIST l = h.bucket[iBucket];

     for (NODE *p=l.Head;p!=NULL;p=p->pNext)
     {
         if (x == p->data)
            return p;
     }
    return NULL;
}
/*
 Câu 8: Sao chép bangt băm
 + Input : tham chiếu max min, bucket
 + Output : Gía trị max , min
*/

/*
Câu 9: Tìm bucket có số phần tử dương ít nhất

*/


int main()
{
    HASHTABLE h;
    InitBuckets(h);

while (true)
   {
       cout << endl;
       cout <<"=======================MENU======================="<<endl;
       cout <<">>\t1.Nhap tu dong cho bang bam."<<endl;
       cout <<">>\t2.Tao du lieu cho bang bam tu mang 1 chieu"<<endl;
       cout <<">>\t3.Tao du lieu thu cong nhap tu ban phim." << endl;
       cout <<">>\t4.Print HashTable." << endl;
       cout <<">>\t5.Dem bucket khong rong."<<endl;
       cout <<">>\t6.Dem cac gia tri am le ."<<endl;
       cout <<">>\t7.Dem cac gia tri XY  trong bang bam."<<endl;
       cout <<">>\t8.Sao chep bang bam."<<endl;
       cout <<">>\t9.Tim vi tri bucket co so luong phan tu duong it nhat."<<endl;
       cout << endl;
       cout <<"================================================="<<endl;

       cout << "Xin moi lua chon : ";

       int chon;
       cin >> chon;

    switch (chon)
    {
       case 0:
           {
           cout << "\tChuong trinh ket thuc."<<endl;
           return 0;
           }
       case 1:
        {
            cout << "\tCac gia tri duoc nhap tu dong:"<<endl;
             auto_input_array(h);
             break;
        }
       case 2:
        {
            cout << "\n\tTao du lieu cho bang bam tu 1D."<<endl;
            float arr[] = {50.1,-75.2,25.3,-30.4,10.5,-90.6,70.7,60.8,30.9,-70.1,90.3};
             input_array(h,arr,11);
            cout << "\tDa tao thanh cong."<<endl;

             break;
        }
        case 3:
        {
            cout << "\n\tNhap thu cong tu ban phim:\n";
            NhapThuCong(h);
            break;
        }
       case 4:
        {
           cout << "Print HashTable." << endl;
            show_HashTable(h);
            break;
        }

       case 5:
        {
            int dem = Count_bucket(h);
             cout <<"Dem bucket khong rong."<<endl;
             cout << dem << endl;

            break;
        }
       case 6:
          {
             int dem = 0;
             Count_Value(h,dem);
             cout << "\n\tCo " << dem << " gia tri am le trong bang bam" << endl;
             break;
          }

        case 7:
          {
            cout << "\tTim 1 gia tri :";
            double x;
            cin >> x;
            NODE *p=Search_XY(h,x);
            cout <<"\tDia chi tim thay :" << p  << endl;
            break;
         }


    }

 }

  return 0;
}
