#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//B1: tạo struct Node cho cây, khóa kiểu double
struct Node
{
    double data;
    Node* pLeft;
    Node* pRight;
};

//B2: tạo struct cây nhị phân
struct Tree
{
    Node* root;
};

//B3: Khởi tạo Node mới từ một data x;
Node* createNode(double x)
{
    Node* p = new Node;
    if (p == NULL)
        return NULL;
    p->data = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

//B4: Khởi tạo cây mới
void createTree(Tree& t)
{
    t.root = NULL;
}

    //Các thao tác khác//

//Câu 1:
//Thêm Node vào cây nhị phân (không dùng đệ quy)
//Input: Tree t, Node* p
//Output: Tree t đã được thêm Node* p => Tree& t
void addNode(Tree& t, Node* p)
{
    //Nếu cây ban đầu là rỗng
    if (t.root == NULL)
    {
        cout << "\t\t + Chen root: " << t.root << endl;
        t.root = p;
    }
    else
    {
        //Tìm vị trí để chèn
        Node* vt = NULL;
        Node* i = t.root;
        while (i != NULL)
        {
            vt = i;
            if (p->data < i->data)
            {
                i = i->pLeft;
            }
            else if (p->data > i->data)
            {
                i = i->pRight;
            }
            else
            {
                return; //Nếu giá trị đã tồn tại trong cây thì bỏ qua
            }
        }

        //Chèn (gắn kết lại)
        if (p->data < vt->data)
        {
            cout << "\t\t + Chen trai node: " << vt << endl;
            vt->pLeft = p;
        }
        else
        {
            cout << "\t\t + Chen phai node: " << vt << endl;
            vt->pRight = p;
        }
    }
}

//Câu 2: tạo cây tự động
//Input: Tree t
//Output: Tree t đã được thêm các giá trị
void input_auto(Tree& t)
{
    int n = rand() % (60 - 50 + 1) + 50;
    double x;
    for (int i = 0; i < n; i++)
    {
        x = rand() % (723 - 512 + 1) + 512;
        addNode(t, createNode((x)));
    }
}

//Câu 3: tạo cây tự động từ một mảng n phần tử
//Input: Tree t, mảng 1D, số lượng phần tử của mang
//Output: Tree t đã được thêm n giá trị từ mảng 1D
void input_from_array(Tree& t, double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        addNode(t, createNode(a[i]));
    }
}

//in node ra màn hình
void in_node(Node* p)
{
    cout << "\t\t";
    if (p->pLeft != NULL)
        cout << "<L: " << p->pLeft << ">";
    else
        cout << "<L: NULL>";

    cout << " (" << p->data << "~" << p << ") ";

    if (p->pRight != NULL)
        cout << "<R: " << p->pRight << ">\n";
    else
        cout << "<R: NULL>\n";
}

//Câu 4: duyệt cây theo NLR, LRN, LNR (in kèm địa chỉ node, pLeft, pRight)
void NLR(Node* i)
{
    if (i != NULL)
    {
        cout << i->data;
        in_node((i));
        NLR(i->pLeft);
        NLR(i->pRight);
    }
}

void LRN(Node* i)
{
    if (i != NULL)
    {
        LRN(i->pLeft);
        LRN(i->pRight);
        cout << i->data;
        in_node((i));
    }
}

void LNR(Node* i)
{
    if (i != NULL)
    {
        LNR(i->pLeft);
        cout << i->data;
        in_node((i));
        LNR(i->pRight);
    }
}

//Câu 5: Tìm giá trị X nhập từ bàn phím, tìm thấy trả về địa chỉ, ngược lại trả về NULL
//Input: Tree t, double x
//Output: địa chỉ của X hoặc NULL
Node* search_value(Tree t, double x)
{
    Node* i = t.root;
    while (i != NULL)
    {
        if (x == i->data)
            return i;
        else if (x < i->data)
            i = i->pLeft;
        else if (x > i->data)
            i = i->pRight;
    }
    return NULL;
}

//Câu 6: Đếm toàn bộ số Node của cây
//Input: Node root của cây, biến đếm
//Output: biến đếm chứa số lượng Node => &
void count_all_node(Node* i, int& dem)
{
    if (i != NULL)
    {
        dem++;
        count_all_node(i->pLeft, dem);
        count_all_node(i->pRight, dem);
    }
}

//Câu 7: In ra các Node còn lại từ một Node nhập từ bàn phím theo cách duyệt LNR
//Input: Tree t, giá trị X
//Output: in ra các Node duyệt từ Node X;
void print_node_from_node(Tree t, double x)
{
    if (search_value(t, x) == NULL)
    {
        cout << "Gia tri " << x << " khong ton tai trong cay!" << endl;
        return;
    }

    LNR(search_value(t, x));
}

//Câu 8: Viết hàm đếm các Node nhỏ hơn Y và lớn hơn X, X và Y là tham số truyền vào (tham chiếu)
void count_node_XY(Node* i, double X, double Y, int& dem)
{
    if (i != NULL)
    {
        if (i->data > X && i->data < Y)
            dem++;
        count_node_XY(i->pLeft, X, Y, dem);
        count_node_XY(i->pRight, X, Y, dem);
    }
}

//Câu 9: Đếm các node có giá trị chẵn và lẻ
//Trả về số nên dùng int
void count_chan_le(Node* i, int& chan, int& le)
{
    if (i != NULL)
    {
        if ((int) i->data % 2 == 0)
            chan++;
        else
            le++;
        count_chan_le(i->pLeft, chan, le);
        count_chan_le(i->pRight, chan, le);
    }
}

bool count_chan_le(Tree t)
{
    Node* i = t.root;
    int chan = 0;
    int le = 0;
    count_chan_le(i, chan, le);
    if (chan < le)
        return -1;
    else if (chan == le)
        return 0;
    else
        return 1;
}

//Câu 10: menu
void menu()
{
    cout << "\n==============================MENU==============================" << endl;
    cout << "\t0. Exit" << endl;
    cout << "\t1. Chen gia tri X vao cay" << endl;
    cout << "\t2. Tao cay tu dong" << endl;
    cout << "\t3. Tao cay tu mang 1D" << endl;
    cout << "\t4. Duyet cay" << endl;
    cout << "\t\t1. NLR" << endl;
    cout << "\t\t2. LRN" << endl;
    cout << "\t\t3. LNR" << endl;
    cout << "\t5. Tim kiem gia tri X" << endl;
    cout << "\t6. Dem toan bo so Node cua cay" << endl;
    cout << "\t7. Duyet cay tu 1 Node nhap tu ban phim" << endl;
    cout << "\t8. Dem so Node > X va < Y (X < NODE < Y)" << endl;
    cout << "\t9. So sanh gia tri chan va le" << endl;
    cout << "===============================END===============================" << endl;
}

int main()
{
    Tree t;
    createTree(t);

    int chon;
    do
    {
        menu();
        cout << "Lua chon cua ban la: ";
        cin >> chon;
        switch(chon)
        {
        case 0:
            {
                cout << "Thoat khoi chuong trinh!" << endl << endl;
                break;
            }
        case 1:
            {
                double x;
                cout << "Nhap gia tri can chen: x = ";
                cin >> x;
                addNode(t, createNode(x));
                cout << "Chen Node thanh cong!" << endl;
                break;
            }
        case 2:
            {
                input_auto(t);
                cout << "Tao cay tu dong thanh cong!" << endl;
                break;
            }
        case 3:
            {
                double a[] = {50, 75, 25, 30, 10, 90, 70, 60, 30, 70, 90};
                input_from_array(t, a, sizeof(a) / sizeof(double));
                cout << "Tao cay tu mang 1D thanh cong" << endl;
                break;
            }
        case 4:
            {
                cout << "\t\t1. NLR" << endl;
                cout << "\t\t2. LRN" << endl;
                cout << "\t\t3. LNR" << endl;
                int luachon;
                cout << "\t\tLua chon cua ban la: ";
                cin >> luachon;
                if (luachon == 1)
                {
                    NLR(t.root);
                }
                else if (luachon == 2)
                {
                    LRN(t.root);
                }
                else
                {
                    LNR(t.root);
                }
                break;
            }
        case 5:
            {
                double x;
                cout << "Nhap gia tri X can tim: ";
                cin >> x;
                if (search_value(t, x) == NULL)
                {
                    cout << "Khong tim thay gia tri " << x << " trong cay!" << endl;
                }
                else
                {
                    cout << "Da tim thay gia tri " << x << "!" << endl;
                    in_node(search_value(t, x));
                }
                break;
            }
        case 6:
            {
                int dem = 0;
                count_all_node(t.root, dem);
                cout << "Tong so Node cua cay la: " << dem << endl;
                break;
            }
        case 7:
            {
                double x;
                cout << "Nhap vi tri Node duyet: ";
                cin >> x;
                print_node_from_node(t, x);
                break;
            }
        case 8:
            {
                double X, Y;
                cout << "Nhap gia tri X = ";
                cin >> X;
                cout << "Nhap gia tri Y = ";
                cin >> Y;
                int dem = 0;
                count_node_XY(t.root, X, Y, dem);
                cout << "So luong cac Node > " << X << " va < " << Y << " la: " << dem << endl;
                break;
            }
        case 9:
            {
                cout << "So sanh so luong chan le: " << count_chan_le(t);
                break;
            }
        }
    } while (chon != 0);
    return 0;
}


//
//
////Bước #1: tạo cấu trúc Node
//struct Node
//{
//    int data;
//    Node* pLeft;
//    Node* pRight;
//};
//
////Bước #2: tạo cấu trúc cây nhị phân tìm kiếm
//struct Tree
//{
//    Node* root;
//};
//
////Bước 3: khởi tạo Node* từ một giá trị x
//Node* createNode(int x)
//{
//    Node* p = new Node;
//    if (p == NULL)
//        return NULL;
//    p->data = x;
//    p->pLeft = NULL;
//    p->pRight = NULL;
//    return p;
//}
//
////Bước 4: Khởi tạo cây nhị phân
//void createTree(Tree& t)
//{
//    t.root = NULL;
//}
//
////Thêm Node chứa giá trị vào cây (không dùng đệ qui)
////input: một cây và một Node*: Tree& , Node*
////output: cây đã được thêm Node* mới
//void addNode(Tree& t, Node* p)
//{
//    //Trường hợp cây nhị phân đang rỗng
//    if (t.root == NULL)
//    {
//        t.root = p;
//        cout << "\t\t + Chen vao root: " << t.root << endl;
//    }
//    else
//    {
//        Node* i = t.root;
//        Node* vi_tri = NULL; //Giải quyết (1)
//        while (i != NULL) //(1). Tìm Node cần chèn
//        {
//            vi_tri = i;
//            if (p->data < i->data)
//            {
//                i = i->pLeft;
//            }
//            else if (p->data > i->data)
//            {
//                i = i->pRight;
//            }
//        }
//        //(2) Thiết lập địa chỉ (gắn kết vào)
//        if (p->data < vi_tri->data)
//        {
//            cout << "\t\t + Chen trai node: " << vi_tri << endl;
//            vi_tri->pLeft = p;
//        }
//        else if (p->data > vi_tri->data)
//        {
//            cout << "\t\t + Chen phai node: " << vi_tri << endl;
//            vi_tri->pRight = p;
//        }
//    }
//}
//
////ví dụ hiển thị:       <L: NULL> (20~abcxyz) <R: NULL> //endl//
//void in_node(Node* p)
//{
//    cout << "\t\t";
//    if (p->pLeft != NULL)
//        cout << "<L: " << p->pLeft << ">";
//    else
//        cout << "<L: NULL>";
//
//    cout << " (" << p->data << "~" << p << ") ";
//
//    if (p->pRight != NULL)
//        cout << "<R: " << p->pRight << ">\n";
//    else
//        cout << "<R: NULL>\n";
//}
//
//void LNR(Node* i)
//{
//    if (i != NULL)
//    {
//        LNR(i->pLeft);
//        cout << i->data << "\t";
//        in_node(i);
//        LNR(i->pRight);
//    }
//}
//
//void NLR(Node* i)
//{
//    if (i != NULL)
//    {
//        cout << i->data << "\t";
//        in_node(i);
//        NLR(i->pLeft);
//        NLR(i->pRight);
//    }
//}
//
//void LRN(Node* i)
//{
//    if (i != NULL)
//    {
//        LRN(i->pLeft);
//        LRN(i->pRight);
//        cout << i->data << "\t";
//        in_node(i);
//    }
//}
//
////Tìm kiếm Node* có key x, không dùng đệ qui
////input: Tree t và key X
////output: địa chỉ Node chứa key X hoặc NULLL (không tìm thấy)
//Node* search_value_node(Tree t, int x)
//{
//    Node* i = t.root;
//    while(i != NULL)
//    {
//        if (x == i->data)
//            return i;
//        if (x < i->data)
//        {
//            i = i->pLeft;
//        }
//        else if (x > i->data)
//        {
//            i = i->pRight;
//        }
//    }
//    return NULL;
//}
//
//void dem_tat_ca(Node* i, int& dem, int& sola)
//{
//    if (i != NULL)
//    {
//        dem++;
//        if (i->pLeft == NULL && i->pRight == NULL)
//            sola++;
//        dem_tat_ca(i->pLeft, dem, sola);
//        dem_tat_ca(i->pRight, dem, sola);
//    }
//}
//
//void nhapThuCong(Tree& t)
//{
//    int x;
//    while(1)
//    {
//        cout << "Nhap gia tri x = ";
//        cin >> x;
//        if (x == 0)
//        {
//            int chon;
//            cout << "\n!!Ban muon dung lai?" << endl;
//            cout << "\tNhap 0 de thoat!" << endl;
//            cout << "\tNhap 1 de them x = 0 vao cay!" << endl;
//            cout << "Lua chon: ";
//            cin >> chon;
//            if (chon == 0)
//            {
//                break;
//            }
//            else
//            {
//                addNode(t, createNode(x));
//                continue;
//            }
//        }
//        addNode(t, createNode(x));
//    }
//}
//
//void nhapTuDong(Tree& t)
//{
//    int x;
//    int n = rand() % 11 + 10;
//    for (int i = 0; i < n; i++)
//    {
//        x = rand() % 1717 - 358;
//        cout << "\tx = " << x << endl;
//        addNode(t, createNode(x));
//    }
//
//}
//void menu()
//{
//    cout << "\n============================== MENU ==============================" << endl;
//    cout << "\t0. Exit" << endl;
//    cout << "\t1. Nhap gia tri cho cay (thu cong)" << endl;
//    cout << "\t2. Nhap gia tri cho cay (tu dong)" << endl;
//    cout << "\t3. NLR" << endl;
//    cout << "\t4. LNR" << endl;
//    cout << "\t5. LRN"<< endl;
//    cout << "\t6. Tim kiem tu gia tri X" << endl;
//}
//
//int main()
//{
//    srand(time(NULL));
//    int chon;
//    Tree t;
//    createTree(t);
//    int dem, sola;
//    do
//    {
//        menu();
//        cout << "Lua chon cua ban la: ";
//        cin >> chon;
//        switch (chon)
//        {
//        case 0:
//            cout << "Thoat khoi chuong trinh!";
//            break;
//        case 1:
//            nhapThuCong(t);
//            break;
//        case 2:
//            nhapTuDong(t);
//            break;
//        case 3:
//            NLR(t.root);
//            break;
//        case 4:
//            LNR(t.root);
//            break;
//        case 5:
//            LRN(t.root);
//            break;
//        case 6:
//            int x;
//            cout << "Nhap gia tri x can tim: ";
//            cin >> x;
//            Node* temp = search_value_node(t, x);
//            if (temp)
//            {
//                in_node(temp);
//            }
//            else
//            {
//                cout << "Khong tim thay x!" << endl;
//            }
//            break;
//        }
//    } while (chon != 0);
//
//    return 0;
//}
//
//

