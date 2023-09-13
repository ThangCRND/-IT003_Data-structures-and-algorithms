#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct NODE
{
    int mdh;
    int Sl_hang;
    float tong_tien;
    int SoLanTrungLap = 1;
    NODE *left;
    NODE *right;
};

struct Tree
{
    NODE *Root;
};

void createTree(Tree &t)
{
    t.Root = NULL;
}

NODE* createNode(int madonhang, int soluong, int tongtien)
{
    NODE *p = new NODE;
      if(p == NULL)
        return 0;
    else
    {
      p->mdh = madonhang;
      p->Sl_hang = soluong;
      p->tong_tien = tongtien;
      p->left = NULL;
      p->right = NULL;
    }
    return p;
}

void addNode(Tree &t, NODE *p)
{

    if(t.Root == NULL)
    {
        t.Root = p;
        cout <<"\t\t + Chen vao Root: " << t.Root <<endl;
    }
    else
    {
        NODE *i = t.Root;
        NODE *vitri = NULL;
        while(i != NULL)
        {
            vitri = i;
            if(i->tong_tien < p->tong_tien)
            {
                i = i->left;
            }
            else if(i->tong_tien > p->tong_tien)
            {
                i = i->right;
            }
            else if (i->tong_tien == p->tong_tien)
            {
                i->SoLanTrungLap++;
                return ;
            }
        }
        if(vitri->tong_tien > p->tong_tien)
        {
             cout << "\t\t + Chen ben trai : " <<vitri << endl;
            vitri->left = p;
        }
        else if(vitri->tong_tien < p->tong_tien)
        {
             cout << "\t\t + Chen ben phai : " <<vitri << endl;
            vitri->right = p;
        }
    }
}

/*
 Cau 4: Nhap tu dong
 */

void auto_input(Tree &t)
{
    srand(time(0));
    double masodonhang = size_t(1e4) + rand() % (size_t(5e5) - size_t(1e4));
    double soluong = 10 + rand() % 104;
    //double tongtien = 985e3 + rand() % (size_t(3e6) - 985e3);

}

/*
 Cau 5: Xuat thong tin theo LNR, LRN, NLR
 */

void Xuat_Node(NODE *p)
{
    cout << endl ;
    cout << "Ma don hang: " << p->mdh << endl;
    cout << " So luong: " << p->Sl_hang << endl;
    cout << " Tong tien: " << p->tong_tien << endl;
}

void LNR(NODE *p)
{
    if(p != NULL)
    {
        LNR(p->left);
        Xuat_Node(p);
        LNR(p->right);
    }
}

void LRN(NODE *p)
{
    if(p != NULL)
    {
        LRN(p->left);
        LRN(p->right);
        Xuat_Node(p);
    }
}

void NLR(NODE *p)
{
    if(p != NULL)
    {
        Xuat_Node(p);
        NLR(p->left);
        NLR(p->right);
    }
}

/*
 Câu 6: Tính hóa đơn
 */

void Sum(NODE *t, int &sum)
{
    if(t == NULL)
        return ;
    else
    {
        // theo trình tự LRN
        Sum(t->left, sum);
        sum += t->tong_tien;
        Sum(t->right, sum);
    }
    return;
}

/*
 Caau7: Tim kiếm thông tin don hang theo mdh
 */
void Find_Node_mdh(NODE *t, NODE *&p, int mdh)
{
    if(t == NULL)
        return ;
    else
    {
        // theo trình tự LRN
        if(t->mdh == mdh)
        {
            p = t;
            return;
        }
        else
        {
            Find_Node_mdh(t->left, p, mdh);
            Find_Node_mdh(t->right,p, mdh);
        }
    }
}
/*
 Câu 8: Tim kiem thông tin (node) theo tổng tiền
 */
void find_node_tongtien(NODE *t, NODE *&a, int tien)
{
    if(t == NULL)
        return ;
    else
    {
        // theo co che LRN
        if(t->mdh == tien)
        {
            a = t;
            return;
        }
        else
        {
            find_node_tongtien(t->left, a, tien);
            find_node_tongtien(t->right, a, tien);
        }
    }
}

/*
 Câu 8: Tim kiem thông tin (node) theo số lượng hàng
 */
void find_node_soluong(NODE *t, NODE *&p, int soluong)
{
    if(t == NULL)
        return ;
    else
    {
        // theo co che LRN
        if(t->mdh == soluong)
        {
            p = t;
            return;
        }
        else
        {
            find_node_soluong(t->left, p, soluong);
            find_node_soluong(t->right,p, soluong);
        }
    }
}

int main()
{

    Tree t;
    createTree(t);

    while(true)
    {
        cout << "============================MENU==========================="<<endl;
        cout << ">>\t0.Chuong trinh ket thuc" << endl;
        cout << ">>\t1.Xay dung cau truc node: " << endl;
        cout << ">>\t2.Chen cac node: " << endl;
        cout << ">>\t3.Xuat thong tin theo NLR LNR LRN: " << endl;
        cout << ">>\t4.Tong tien cac  hoa don: " << endl;
        cout << ">>\t5.Tim kiem thong tin don hang (node) theo mhd: " << endl;
        cout << ">>\t6.Tim kiem thong tin don hang node theo tong tien: " << endl;
        cout << endl;
         cout <<"==========================================================="<<endl;

        int chon;
        cin >> chon;
        switch (chon)
        {
            case 0:
            {
                cout << "Chuong trinh ket thuc." << endl;
                return 0;
            }
            case 1: case 2:
            {
                int mdh, Sl_hang, tien;
                cout << "\nNhap ma don hang: ";
                cin >> mdh;
                cout << "\nNhap so luong: ";
                cin >> Sl_hang;
                cout << "\nNhap tong tien: ";
                cin >> tien;
                addNode(t,createNode(mdh, Sl_hang, tien));
                break;
            }
            case 3:
            {
                cout << "Chon kieu xuat thong tin(1:NLR, 2:LNR, 3:LRN) ";
                int chon;
                cin >> chon;
                if(chon == 1)
                    NLR(t.Root);
                else if(chon == 2)
                    LRN(t.Root);
                else
                    LRN(t.Root);
                break;
            }
            case 4:
            {
                int tong = 0;
                Sum(t.Root, tong);
                cout << "Tong tien la: " << tong << endl;
                break;
            }
            case 5:
            {
                cout << "\nNhap thong tin don hang (theo mdh) muon tim: ";
                int mhd;
                cin >> mhd;
                NODE *p = NULL;
                Find_Node_mdh(t.Root, p, mhd);
                cout <<"Output: " << endl;
                Xuat_Node(p);
                break;
            }
            case 6:
            {
                cout << "\nNhap tong tien muon tim: ";
                int tien;
                cin >> tien;
                NODE *p = NULL;
                find_node_tongtien(t.Root, p, tien);
                cout <<"Output: " << endl;
                Xuat_Node(p);
                break;
            }
            case 7:
            {
                cout << "\nNhap thong tin so luong muon tim: ";
                int soluong;
                cin >> soluong;
                NODE *p = NULL;
                find_node_soluong(t.Root, p, soluong);
                cout <<"Output: " << endl;
                Xuat_Node(p);
                break;
            }

        }
    }
    return 0;
}
