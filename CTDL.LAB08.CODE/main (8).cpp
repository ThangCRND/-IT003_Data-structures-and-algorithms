#include <iostream>
#include <ctime>
#include <cstdlib>

#define M 9

using namespace std;

//Tạo cấu trúc Node
struct Node
{
    double data;
    Node* pNext;
};

//Tạo cấu trúc List
struct List
{
    Node* pHead;
    Node* pTail;
};

//Tạo Node* từ một giá trị số thực
Node* createNode(double x)
{
    Node* p = new Node;
    if (p == NULL)
        return NULL;
    p->data = x;
    p->pNext = NULL;
    return p;
}

//Khởi tạo List mới
void createList(List& l)
{
    l.pHead = l.pTail = NULL;
}

//Thêm cuối List
//Input: List l, và một Node* p
//Output: List l đã được thêm Node p ở cuối
void addTail(List& l, Node* p)
{
    if (l.pHead == NULL) //List ban đầu rỗng
    {
        l.pHead = l.pTail = p;
    }
    else //List khác rỗng
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

//Xuất list ra màn hình
void printList(List l)
{
    for (Node* i = l.pHead; i != NULL; i = i->pNext)
    {
        cout << i->data << "\t";
    }
    cout << endl;
}

//B1: Tạo struct HashTable
struct HashTable
{
    List bucket[M];
};

//Câu 1:
//B2: Viết hàm băm HashFunction để tìm ra địa chỉ cho khóa
int hashFunc(double data)
{
    return (int) data % M;
}

//B3: Khởi động các bucket
void initBuckets(HashTable& h)
{
    for (int i = 0; i < M; i++)
    {
        createList(h.bucket[i]);
    }
}

//B4: Insert data vào hashTable
void insert(HashTable& h, double data)
{
    //B1: băm để xác định vị trí cho data
    int b = hashFunc(data);
    //B2: Chèn data vào bảng băm
    addTail(h.bucket[b], createNode(data));
}

//Các thao tác khác

//Câu 2:
//Khởi tạo bảng băm tự động
void input_auto(HashTable& h)
{
    int n = rand() % (95 - 45 + 1) + 45;
    double data;
    for (int i = 0; i < n; i++)
    {
        data = rand() % (988 - 856 + 1) + 856;
        insert(h, data);
    }
}

//Câu 3: Khởi tạo bảng băm từ mảng 1 chiều
void input_from_array(HashTable& h, double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        insert(h, a[i]);
    }
}

//Câu 4: Nhập giá trị cho bảng băm thủ công từ bàn phím
//Điều kiện kết thúc: nhập 0 sẽ hỏi muốn dừng hay không
//Tiếp tục nhập 0 thì dừng, ngược lại tiếp tục
void input_thucong(HashTable& h)
{
    double data;
    while(true)
    {
        cout << "Gia tri muon them vao HashTable la: ";
        cin >> data;
        if (data == 0)
        {
            int chon;
            cout << "Ban muon them 0 vao HashTable hay dung lai?" << endl;
            cout << "\t0. Dung lai1" << endl;
            cout << "\t1. Tiep tuc va them 0 vao HashTable" << endl;
            cout << "Lua chon cua ban la: ";
            cin >> chon;
            if (chon == 0)
                break;
        }
        insert(h, data);
    }
}

//Câu 5: Kiểm tra bảng băm có rỗng hay không, rỗng -> True, ngược lại -> False;
//Ý tưởng: Nếu một bucket có bất kì có phần từ -> False;
bool Is_empty(HashTable h)
{
    for (int i = 0; i < M; i++)
    {
        if (h.bucket[i].pHead != NULL)
            return false;
    }
    return true;
}

//Câu 6: Viết hàm đếm các giá trị lưu trong bảng băm
int count_numer_of_elements(HashTable h)
{
    int count = 0;
    for (int i = 0; i < M; i++)
    {
        for (Node* p = h.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            count++;
        }
    }
    return count;
}

//Câu 7: Viết hàm tìm giá trị X trong bảng băm.
//Tìm thấy trả về True, ngược lại trả về False
bool find_ValueX(HashTable h, double x)
{
    for (int i = 0; i < M; i++)
    {
        for (Node* p = h.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            if (p->data == x)
                return true;
        }
    }
    return false;
}

//Câu 8: Tìm max, min (viết 1 hàm)
//Như vậy thì phải truyền tham số đầu vào theo kiểu tham chiếu &
void find_max_min(HashTable h, double& max, double& min)
{
    if (Is_empty(h))
    {
        cout << "HashTable is empty!" << endl;
        return;
    }

    max = min = h.bucket[0].pHead->data;
    for (int i = 0; i < M; i++)
    {
        for (Node* p = h.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            if (p->data > max)
            {
                max = p->data;
            }
            if (p->data < min)
            {
                min = p->data;
            }
        }
    }
}

//Câu 9: So sánh số lượng chẵn lẻ
//Case <= trả về True;
//Case > trả về False;
bool compare_odds_evens(HashTable h, int& numberOfOdd, int& numberOfEven)
{
    for (int i = 0; i < M; i++)
    {
        for (Node* p = h.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            if ((int) p->data % 2 == 0)
            {
                numberOfEven++;
            }
            else
            {
               numberOfOdd++;
            }
        }
    }
    if (numberOfEven <= numberOfOdd)
        return true;
    else
        return false;

}
//Xuất bảng băm
void show_HashTable(HashTable h)
{
    for (int i = 0; i < M; i++)
    {
        cout << "[Bucket #" << i << "]: \t";
        printList(h.bucket[i]);
    }
}

void menu()
{
    cout << "\n==============================MENU==============================" << endl;
    cout << "\t1. Exit" << endl;
    cout << "\t2. Khoi tao HashTable tu dong" << endl;
    cout << "\t3. Khoi tao HashTable tu mang 1D" << endl;
    cout << "\t4. Khoi tao HashTable thu cong tu ban phim" << endl;
    cout << "\t5. Kiem tra HashTable co rong hay khong" << endl;
    cout << "\t6. Dem so luong cac gia tri luu tru trong HashTable" << endl;
    cout << "\t7. Tim gia tri X" << endl;
    cout << "\t8. Tim max, min trong HashTable" << endl;
    cout << "\t9. So sanh so luong so chan va so le trong HashTable" << endl;
    cout << "\t10. Xuat HashTable" << endl;
    cout << "==============================END==============================" << endl;
}

////Xuất bảng băm
//void show_HashTable(HashTable h)
//{
//    for (int i = 0; i < M; i++)
//    {
//        cout << "[Bucket #" << i << "]: \t";
//        printList(h.bucket[i]);
//    }
//}

int main()
{
    HashTable h;
    initBuckets(h);

    int chon;
    do
    {
        menu();
        cout << "Lua chon cua ban la: ";
        cin >> chon;
        switch(chon)
        {
        case 1:
            {
                cout << "Thoat khoi chuong trinh!!" << endl << endl;
                break;
            }
        case 2:
            {
                //initBuckets(h);
                input_auto(h);
                cout << "Khoi tao HashTable thanh cong!" << endl;
                break;
            }
        case 3:
            {
                //initBuckets(h);
                double a[] = {50, 75, 25, 30, 10, 90, 70, 60, 30, 70, 90};
                input_from_array(h, a, sizeof(a) / sizeof(double));
                cout << "Khoi tao HashTable thanh cong!" << endl;
                break;
            }
        case 4:
            {
                //initBuckets(h);
                input_thucong(h);
                cout << "Khoi tao HashTable thanh cong!" << endl;
                break;
            }
        case 5:
            {
                show_HashTable(h);
                break;
            }
        case 10:
            {
                cout << "HashTable is empty: " << boolalpha << Is_empty(h) << endl;
                break;
            }
        case 6:
            {
                cout << "So luong gia tri luu tru trong HashTable la: " << count_numer_of_elements(h) << endl;
                break;
            }
        case 7:
            {
                double x;
                cout << "Nhap gia tri x can tim, x = ";
                cin >> x;
                if (find_ValueX(h, x))
                {
                    cout << "Gia tri " << x <<  " co trong HashTable" << endl;
                }
                else
                {
                    cout << "Khong tim thay gia tri " << x << " trong HashTable" << endl;
                }
                break;
            }
        case 8:
            {
                double max = 0;
                double min = 0;
                find_max_min(h, max, min);
                cout << "Gia tri Max la: " << max << endl;
                cout << "Gia tri Min la: " << min << endl;
                break;
            }
        case 9:
            {
                int numberOfEven = 0;
                int numberOfOdd = 0;
                if (compare_odds_evens(h, numberOfOdd, numberOfEven))
                {
                    cout << "So luong cac so chan la: " << numberOfEven << endl;
                    cout << "So luong cac so le la: " << numberOfOdd << endl;
                    cout << "So luong so chan < so luong so le."<< boolalpha << compare_odds_evens(h, numberOfOdd, numberOfEven) << endl;

                }
                else
                {
                    cout << "So luong cac so chan la: " << numberOfEven << endl;
                    cout << "So luong cac so le la: " << numberOfOdd << endl;
                    cout << "So luong so chan > so luong so le. "<< boolalpha << compare_odds_evens(h, numberOfOdd, numberOfEven) << endl;
                }
                break;
            }
//        case 10:
//            {
//                show_HashTable(h);
//                break;
//            }
        default:
            cout << "Nhap lua chon trong khoang [1, 9]!" << endl;
        }
    } while (chon != 1);
    return 0;
}
