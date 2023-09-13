#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAXN 100
using namespace std;

struct NODE
{
    int data;
    int count;
    NODE *left;
    NODE *right;
};

struct Tree
{
    NODE *root;
};

void creatTree(Tree &t)
{
    t.root = NULL;
}

NODE* createNode(int x)
{
    NODE *p = new NODE;
    if(p == NULL)
        return 0;
    p->count = 0;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}


// Xuất giá trị và địa chỉ Node
void Xuat_Node(NODE *p)
{
    cout << "\t";
    if (p->left != NULL)
        cout << "<L:" << p->left << ">\t";
    else
        cout << "<L:NULL>\t" ;
    cout << "(" <<p->data << "~" << p << ")\t";

     if (p->right !=NULL)
        cout << "<R:" << p->right << ">\n";
     else
        cout << "<R:NULL>\n";
}


/*
 Câu 2: Nhỏ hơn Node gốc -> qua trái ,lớn hơn -> qua phải
        Nếu có Node bằng nhau thì tăng biến đếm
 */
void addNode(Tree &t, NODE *p)
{

    if(t.root == NULL) //Step #1
    {
        t.root = p;
        cout <<"\t\t + Chen vao Root: " << t.root <<endl;
    }
    else //Step #2:   (1) Tìm Node cần chèn,
             //sau đó (2) thiết lập địa chỉ.
    {
       NODE *i = t.root;
       NODE *vitri = NULL; // Giai quyết (1)
        while(i != NULL) //(1) Tìm NODE cần chèn
        {
            vitri = i;
            if(i->data < p->data)
            {
                i = i->right;
            }
            else if(i->data > p->data)
            {
                i = i->left;
            }
            else if(i->data == p->data)
            {
                i->count++;
                cout << "\nPhan tu da co san trong cay va tang bien dem len.\n";
                return;
            }
        }
         //(2) Thiết lập địa chỉ để gắn kết vào
        if(vitri->data < p->data)
        {
            cout << "\t\t + Chen ben phai Node: " <<vitri << endl;
            vitri->right = p;
        }
        else if(vitri->data > p->data)
        {
            cout << "\t\t + Chen ben trai Node: " <<vitri << endl;
            vitri->left = p;
        }
    }
}

/*
 Câu 3: Nhap gia tri cho cay theo dieu kien thu cong
 + Nhap tung giá trị
 */
void NhapThuCong(Tree &t)
{
    int x;
    do
    {
        int chon = 0;
        cout << "Nhap phan tu de gan vao cay: ";
        cin >> x;
        if(x != 0)
        {
            addNode(t,createNode(x));
        }
        else
        {
            cout << "Nhap phim 1 de nhap 0 vao cay, nhan phim 0 de ket thuc nhap: ";
            cin >> chon;
            if (chon != 0)
            {
                addNode(t,createNode(0));
                NhapThuCong(t);
            }
            else
                return;
        }
    }while(x != 0);

}

/*
 Câu: Tạo mảng cây tự động
 + các giá trị duoc nhập tự động
 + Số phần tử được tạo
*/

void auto_input_array(Tree &t, int a[])
{
    cout << "So phan tu duoc tao ngau nhien: ";
    srand(time(NULL));
      int n = 10 + rand() % 11;
    cout << n << endl;
    for(int i = 0; i < n; i++)
    {
        a[i] = -358 + rand() % 1716;
        addNode(t, createNode(a[i]));
    }
}

/*
 Cau 5: Duyệt cây theo : LNR, NLR ,LRN

 */

void LNR(NODE *p)
{
    if(p != NULL)
   {
        LNR(p->left);
        cout <<"Gia tri " << p->data << ":\t";
        Xuat_Node(p);
        LNR(p->right);
    }
}
void NLR(NODE *p)
{
    if(p != NULL)
   {
        cout <<"Gia tri " << p->data << ":\t";
        Xuat_Node(p);
        LNR(p->left);
        LNR(p->right);
    }
}
void LRN(NODE *p)
{
    if(p != NULL)
   {
        LNR(p->left);
        LNR(p->right);
        cout <<"Gia tri " << p->data << ":\t";
        Xuat_Node(p);
    }
}

/*
 Cau 6:
 Tim kiem bang gia tri trong cay
 +Input: x
 +Tìm thấy ->return true ,ngược lại ->return false
 */

NODE *Search_value_NodeX(Tree t, int x)
{
     NODE *i=t.root;
     while (i!=NULL)
     {
         if (x == i->data)
            return i;

         if (x < i->data)
          {
             i=i->left;
          }
         else if (x > i->data)
          {
            i=i->right;
          }
     }
     return NULL;
}
/*
 Cau 7: Xóa Node có giá trị X
 +Nhap gia tri muon xoa
 +Neu co trong cay thi se xoa, khong co trong cay la khong xoa
 +Neu co node chua 2 la
 */


void delete_Node(NODE *&t, int x)
{
    if(t == NULL)
        return;
    else if(x < t->data)
    {
        delete_Node(t->left, x);
    }
    else if(x > t->data)
    {
        delete_Node(t->right, x);
    }
    else
    {
        NODE *X = t;
        if(t->right == NULL)
            t = t->left;
        else if(t->left == NULL)
            t = t->right;

        else
        {
            NODE *Y = t->right;
            delete_Node(Y->left, x);
            t = Y;
        }
        delete X;
        return;
    }
}


/*
 Cau 8: Xóa tất cả Node
 */

void Delete_All_Node(NODE *&p)
{
    if(p == NULL)
    return ;
    Delete_All_Node(p->left);
    Delete_All_Node(p->right);
    NODE *X = p;
    delete X;
}

/*
 Cau 9: Đếm toàn bộ Node trên cây
 */

void Count_All_Node(NODE *t, int &count)
{
    if(t == NULL)
        return ;
    else
    {
        Count_All_Node(t->left, count);
        Count_All_Node(t->right, count);
        if(t != NULL)
        count++;
    }
}
/*
Câu 9:In ra các Node nhánh từ 1 Node duoc nhập
*/
void Print_Node_nhanh(NODE *t ,int x)
{
    NODE *X = t;
    while(X != NULL)
    {
         if(x < X->data)
         {
            X = X->left;
         }
        else if(x > X->data)
          {
            X = X->right;
          }
        else
        {
            break;
        }
    }
    if(X == NULL)
    {
        cout << "\nGia tri khong co trong cay.";
        return;
    }
    NLR(X);
    return;
}
/*
 Cau 12: Đếm Node có giá trị nhỏ hơn X
*/

void DemNode_NhohonX(NODE *p, int x, int &count)
{
    if(p == NULL)
        return ;
    else
    {
        // theo trình tự LRN
         DemNode_NhohonX(p->left, x, count);
        if(p->data < x)
            count ++;
        DemNode_NhohonX(p->right, x, count);
    }
    return;
}

/*
 Cau 13:Đếm Node có giá trị lớn hơn X
 */

void DemNode_LonhonX(NODE *t, int x, int &dem)
{
    if(t == NULL)
        return ;
    else
    {
        // theo trình tự LRN
        DemNode_LonhonX(t->left, x, dem);
        if(t->data > x)
            dem++;
        DemNode_LonhonX(t->right, x, dem);
    }
    return;
}

/*
 Cau 14: Đếm Node có giá trị (X < Node < Y)
 */

void Count_Node(NODE *t, int X,int Y, int &dem)
{
    if(t == NULL)
        return ;
    else
    {
        // theo co che LRN
        Count_Node(t->left, X,Y, dem);
        if( t->data > X && t->data < Y )
            dem++;
        Count_Node(t->right, X, Y, dem);
    }
    return;
}

/*
 Câu16  :Đếm chẵn-lẻ ,so sánh
 */
void Sosanh_ChanLe(NODE *t ,int &dem, int &count, int &sum)
{
    if(t == NULL)
        return ;
    else
    {
        //theo trình tự LRN
        Sosanh_ChanLe(t->left, dem, count, sum);
        sum += t->data;
        if(t->data % 2 == 0)
            dem++;
        else
            count++;
        Sosanh_ChanLe(t->right, dem, count, sum);
    }
    return;
}

/*
 Cau cuoi: gia tri nho nhat gia tri lon nhat trong cay
 */

void find_max_min(NODE *t, int &min, int &max)
{

    if(t == NULL)
        return;
    else
    {
    // min = max = t->data;
    // theo trình tự LNR
    find_max_min(t->left, min, max);
    if(min > t->data)
        min = t->data;
    if(t->data > max)
        max = t->data;
    find_max_min(t->right, min, max);
    }
}


int main()
{
    Tree t;
    creatTree(t);
    int a[MAXN];


    while (true)
    {
        cout << "========================MENU========================"<<endl;
        cout << ">>\t0.Chuong trinh ket thuc" << endl;
        cout << ">>\t1.Them 1 gia tri Node: " <<endl;
        cout << ">>\t2.Nhap thu cong chen vao cay: " << endl;
        cout << ">>\t3.Nhap tu dong cho cay: " <<endl;
        cout << ">>\t4.Xuat gia tri theo LNR: " << endl;
        cout << ">>\t5.Tim node mang gia tri x: " << endl;
        cout << ">>\t6.Xoa node mang gia tri x: " <<endl;
        cout << ">>\t7.Xoa tat ca cac node: " << endl;
        cout << ">>\t8.Tong tat ca cac node: " << endl;
        cout << ">>\t9.Xuat NLR tu mot node nhap tu ban phim: " << endl;
        cout << ">>\t10.Xuat nodes co gia tri be hon x: " << endl;
        cout << ">>\t11.Xuat nodes co gia tri lon hon x: " <<endl;
        cout << ">>\t12.So sanh: " << endl;
        cout << ">>\t13.So sanh #10 #11: " << endl;
        cout << ">>\t14,15.So sanh gia tri chan le, tinh tong: " << endl;
        cout << ">>\t16.Tim min va max trong cay: " <<endl;
        cout << endl;
        cout <<"======================================================"<<endl;


        cout << "Vui long lua chon: ";

        int chon;
        cin >> chon;

        switch(chon)
        {
            case 0:
                cout << "Chuong trinh ket thuc." << endl;
                return 0;
            case 1:
              {
                cout << "Add 1 Node: " << endl;
                int x;
                cin >> x;
                addNode(t, createNode(x));
                break;
              }
            case 2:
              {
                cout << "Nhap thu cong tu ban phim: " <<endl;
                NhapThuCong(t);
                break;
              }
            case 3:
             {
                cout << "Cac gia tri duoc nhap tu dong:"<<endl;
                auto_input_array(t, a);
                 break;
             }
            case 4:
             {
                cout <<"Print tree: " <<endl;
                LNR(t.root);
                break;
             }
            case 5:
             {
                cout << "\nNhap gia tri muon tim: ";
                int x;
                cin >> x;
                NODE *p = Search_value_NodeX(t,x);
                cout <<"Dia chi cua Node tim thay la: "  << p << endl;
                break;
             }
            case 6:
             {
                cout << "Nhap gia tri muon xoa trong cay: ";
                int x;
                cin >> x;
                delete_Node(t.root, x);
                cout << "Cay duoc cap nhat lai :" << endl;
                LNR(t.root);
                break;
             }
            case 7:
             {
                cout << "\nXoa tat ca nodes: ";
                Delete_All_Node(t.root);
                cout << "Cay duoc cap nhat lai :" << endl;
                LNR(t.root);
                break;
             }
            case 8:
             {
                cout << "\nTong so Node tren cay: ";
                int count = 0;
                Count_All_Node(t.root, count);
                cout << count << endl;
                break;
             }
            case 9:
             {
                cout << "\nNhap mot gia tri(node goc cua cay): ";
                int x;
                cin >> x;

               Print_Node_nhanh(t.root,x);
               cout << "Node nhanh ben trai: " << t.root->left->data << endl;
               cout << "Node nhanh ben phai: " << t.root->right->data << endl;

                break;
             }
            case 10:
             {
                cout << "Nhap 1 gia tri de so sanh: ";
                int x;
                cin >>x;
                int count = 0;
                DemNode_NhohonX(t.root, x, count);
                cout << "Cac gia tri NODE nho hon X: " << count << endl;
                break;
             }
            case 11:
             {
                cout << "Nhap 1 gia tri de so sanh: ";
                 int x;
                 cin >>x;
                int count =0;
                DemNode_LonhonX(t.root, x, count);
                cout << "Cac gia tri NODE lon hon X: " << count << endl;
                break;
             }
            case 12:
             {
                cout << "\nNhap mot gia tri muon so sanh voi X: ";
                int x;
                cin >>x;
                cout << "\nNhap mot gia tri muon so sanh voi Y: ";
                int y;
                cin >>y;
                int dem = 0;
                Count_Node(t.root, x, y, dem);
                cout << "\nSo nodes: " << dem << endl;
                break;
             }
            case 13:
             {
                cout << "\nNhap mot gia tri muon so sanh: ";
                int x;
                cin >>x;
                int dem = 0;
                DemNode_NhohonX(t.root, x, dem);

                cout << "\nNhap mot gia tri muon so sanh: ";
                int y;
                cin >> y;
                int count = 0;
                DemNode_LonhonX(t.root, y, count);
                if(dem < count)
                    cout << 1;
                else if(dem > count)
                    cout << 2;
                else cout << 3;
                break;
             }
            case 14: case 15:
             {
                int count = 0, dem = 0, sum = 0;
                Sosanh_ChanLe(t.root, count, dem, sum);
                cout << "\nTong la: " << sum << endl;
                  if(dem < count)
                    cout << 1;
                  else if(dem > count)
                    cout << 2;
                else
                    cout << 3;
                break;
             }
            case 16:
            {
                int min , max;
                min = max = t.root->data;
                find_max_min(t.root, min, max);
                cout << "Value of min: " << min << endl;
                cout << "value of max: " << max << endl;
                break;
            }
        }
    }
  return 0;
}
