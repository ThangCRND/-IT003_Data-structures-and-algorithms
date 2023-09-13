
#include <iostream>
#include <time.h>
#include <cstdlib>
#define MAXN 100

using namespace std;

//Tao cau truc Node
struct Node
{
	int data; //Luu du lieu
	Node* pNext; //Luu dia chia Node tiep theo
};

//Tao cau truc List
struct List
{
	Node* pHead; //Luu dia chi Node dau tien cua List
	Node* pTail; //Luu dua chi Node cuoi cung cua List
};

//Khoi tao Node tu mot so nguyen x
Node* createNode(int x)
{
	Node* p = new Node; //Xin cap phat vung nho
	if (p == NULL) //Truong hop cap phat khong thanh cong
		return NULL;
	p->data = x; //Luu du lieu x
	p->pNext = NULL; //Chua co lien ket
	return p;
}

//Khoi tao List
void createList(List& l)
{
	l.pHead = l.pTail = NULL; //Khoi tao List rong
}

//Thêm đầu
void addHead(List& l, Node* p)
{
	if (l.pHead == NULL) //List rong
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead; //Moc dia chi
		l.pHead = p; //Cap nhat lai Head
	}
}

//Thêm cuối
void addTail(List& l, Node* p)
{
	if (l.pHead == NULL) //List rong
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p; //Moc dia chi
		l.pTail = p; //Cap nhat lai Tail
	}
}
//*Câu 5:
//Nhập thủ công ,áp dụng AddHead
int nhapDanhSach(List& l)
{
	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	createList(l); //Khoi tao danh sach rong
	int x;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap gia tri thu " << i + 1 << ": ";
		cin >> x;
		Node* p = createNode(x);
		if (p != NULL) //Cap phat vung nho thanh cong
		{
			addHead(l, p); //Them vao dau danh sach
		}
		else // p == NULL
		{
			cout << "Cap phat vung nho khong thanh cong!" << endl;
			return 0;
		}
	}
	return 1;
}
//Câu 6:
//Tạo list random
int taoNgauNhien(List& l)
{
	int n;
	cout << "So phan tu duoc tao ngau nhien la: ";
	srand(time(NULL));
	n = rand() % (59 - 39 + 1) + 39; // [39, 59]
	cout << n << endl;
	createList(l);
	int x;
	for (int i = 0; i < n; i++)
	{
		x = rand() % (99 + 99 + 1) - 99;
		Node* p = createNode(x);
		if (p != NULL)
		{
			addTail(l, p); //Them vao cuoi danh sach
		}
		else
		{
			cout << "Cap phat vung nho khong thanh cong!" << endl;
			return 0;
		}
	}
	return 1;
}
//Câu 7:
//Nhap gia  tri cho mang 1D
void nhapMang(int a[], int& n)
{
	cout << "Nhap so luong phan tu mang 1D: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}
//Nhập danh sách từ mảng 1 chiều//
int nhapTuMang1D(List& l)
{
	int a[MAXN], n;
	nhapMang(a, n);
	createList(l);
	for (int i = 0; i < n; i++)
	{
		Node* p = createNode(a[i]);
		if (p != NULL)
		{
			addTail(l, p); //Them vao cuoi list
		}
		else
		{
			cout << "Cap phat vung nho khong thanh cong!" << endl;
			return 0;
		}
	}
	return 1;
}
//*Câu 19:
//Đếm số lượng phần tử
int sizeOfList(List l)
{
	int count = 0;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		count++;
	}
	return count;
}
//*Câu 8:
//Chèn vào giữa danh sách
void addMid(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
		return;
	}
	int n = sizeOfList(l); //Lấy số lượng phần tử trong List (từ câu 19)
	int pos;
	do
	{
		cout << "Nhap vi tri can chen: " << endl;
		cin >> pos;
		if (pos < 0 || pos > n)
		{
			cout << "Vi tri khong hop le, vui long nhap lai!" << endl;
		}
	} while (pos < 0 || pos > n);
	if (pos == 0)
	{
		addHead(l, p);
	}
	else if (pos == n)
	{
		addTail(l, p);
	}
	else
	{
		Node* k = l.pHead;
		Node* q = NULL;
		int i = 0;
		while (k != NULL)
		{
			if (i == pos)
				break;
			q = k;
			k = k->pNext;
			i++;
		}
		p->pNext = q->pNext;

		q->pNext = p;
	}
}
void insertAfterQ(List& l, Node* q, Node* p)
{
	if (q != NULL) //q nam trong list
	{
		p->pNext = q->pNext;
		q->pNext = p;
		if (q == l.pTail)
			l.pTail = p;
	}
	else
	{
		addHead(l, p);
	}
}

//Cau 16
Node* search(List l, int y)
{
	Node* p = l.pHead;
	while (p != NULL && p->data != y)
		p = p->pNext;
	return p;
}
//*Câu 9:Chèn X sau Y //

int insertXAfterY(List& l)
{
	int x, y;
	cout << "Nhap so x: ";
	cin >> x;
	cout << "Nhap so y: ";
	cin >> y;
	Node* q = search(l, y);
	if (q == NULL)
	{
		cout << "Khong tim thay y trong danh sach!" << endl;
		return 0;
	}
	Node* NodeX = createNode(x);
	insertAfterQ(l, q, NodeX);
	return 1;
}

//*Câu 10:Chèn X trước Y //

int insertXBehindY(List& l)
{
	int x, y;
	cout << "Nhap so x: ";
	cin >> x;
	cout << "Nhap so y: ";
	cin >> y;
	Node* q = search(l, y);
	if (q == NULL)
	{
		cout << "Khong tim thay y trong danh sach!" << endl;
		return 0;
	}
	Node* NodeX = createNode(x);
	if (q == l.pHead)
	{
		addHead(l, NodeX);
		return 1;
	}
	Node* k = l.pHead;
	while (k != NULL && k->pNext != q)
		k = k->pNext;
	insertAfterQ(l, k, NodeX);
	return 1;
}
//*Câu 11: In danh sách //

void printList(List l)
{
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
		cout << p->data << " ";
	cout << endl;
}
//*Câu 12:
// In giá trị kèm địa chỉ của từng node
void printListIncludeAddress(List l)
{
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
		cout << "Gia tri: " << p->data << " Address: " << p << endl;
}

//câu 13:
// In giá trị và địa chỉ 2 node đầu và cuối
void printHeadAndTail(List l)
{
	cout << "Gia tri cua Node dau tien: " << l.pHead->data << endl;
	cout << "Address: " << l.pHead << endl;
	cout << "Gia tri cua Node cuoi cung: " << l.pTail->data << endl;
	cout << "Address: " << l.pTail << endl;
}

//* Câu 14: Kiểm tra list rỗng
bool isEmpty(List l)
{
	if (l.pHead == NULL)
		return true;
	return false;
}
//*Câu 17:
// Tìm các Node có giá trị X
List search_All_X(const List l, int x)
{
	List list;
	createList(list);
	for (Node* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == x)
			addTail(list, createNode(k->data));
	}
	return list;
}
Node* searchNodeN(const List l, int n)
{
	if (l.pHead == NULL)
		return NULL;
	Node* p = l.pHead;
	for (int i = 2; i <= n; i++)
		p = p->pNext;
	return p;
}

//Cau 18
int tinhTongNode(List l)
{
	int sum = 0;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
		sum += p->data;
	return sum;
}

//Cau 20
int numberOfEvenNode(List l)
{
	int count = 0;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
		if (p->data % 2 == 0)
			count++;
	return count;
}

//Cau 20
int numberOfOddNode(List l)
{
	int count = 0;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
		if (p->data % 2 != 0)
			count++;
	return count;
}

//Cau 21 :
// + Tìm Node có giá trị dương
int numberOfPositiveNode(List l)
{
	int count = 0;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
		if (p->data > 0 )
			count++;
	return count;
}
// + Tìm Node có giá trị âm
int numberOfNegativeNode(List l)
{
	int count = 0;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
		if (p->data < 0)
			count++;
	return count;
}
//* Câu 22:
// + Tìm Node max
Node* findMax(List l)
{
	Node* Max = new Node;
	Max = l.pHead;
	for (Node* p = l.pHead->pNext; p != NULL; p = p->pNext)
	{
		if (p->data > Max->data)
			Max = p;
	}
	return Max;
}
// + Tìm Node min
Node* findMin(List l)
{
	Node* Min= new Node;
	Min = l.pHead;
	for (Node* p = l.pHead->pNext; p != NULL; p = p->pNext)
	{
		if (p->data < Min->data)
			Min = p;
	}
	return Min;
}
//* Câu 23:
// +Tim Node có giá trị âm lớn nhất
Node* findMaxNegative(List l)
{
	Node* MaxNegative = new Node;

	Node* p = new Node;
	p = l.pHead;
	while (p != NULL && p->data > 0) //Tim so am dau tien
	{
		p = p->pNext;
	}
	MaxNegative = p;
	for (p; p != NULL; p = p->pNext)
	{
		if (p->data < 0 && p->data > MaxNegative->data)
			MaxNegative = p;
	}
	return MaxNegative;
}
// +Tìm Node có giá trị lẻ nhỏ nhất
Node* findMinOdd(List l)
{
	Node* MinOdd = new Node;
	MinOdd = l.pHead;
	for (Node* p = l.pHead->pNext; p != NULL; p = p->pNext)
	{
		if (p->data % 2 != 0 && p->data < MinOdd->data)
			MinOdd = p;
	}
	return MinOdd;
}
void menu()
{
	cout << "\n\n================================= MENU =================================" << endl;
	cout << "\t0. Exit." << endl;
	cout << "\t1. Khoi tao danh sach moi" << endl;
	cout << "\t2. Khoi tao Node tu mot so nguyen x" << endl;
	cout << "\t3. Chen Node vao dau danh sach" << endl;
	cout << "\t4. Chen Node vao cuoi danh sach" << endl;
	cout << "\t5. Nhap danh sach (nhap thu cong) - addHead" << endl;
	cout << "\t6. Nhap danh sach (nhap tu dong) - addTail" << endl;
	cout << "\t7. Nhap gia tri cho danh sach tu mang 1 chieu" << endl;
	cout << "\t8. Chen Node vao giua danh sach" << endl;
	cout << "\t9. Chen gia tri X sau gia tri Y" << endl;
	cout << "\t10. Chen gia tri X truoc gia tri Y" << endl;
	cout << "\t11. In gia tri danh sach da nhap" << endl;
	cout << "\t12. In Gia Tri kem Dia Chi cua tung Node trong danh sach" << endl;
	cout << "\t13. In Node dau va Node cuoi" << endl;
	cout << "\t14. Kiem tra danh sach rong" << endl;
	cout << "\t15. In ra Node thu n trong danh sach" << endl;
	cout << "\t16. Tim Node dau tien co gia tri x" << endl;
	cout << "\t17. Tim cac Node co gia tri x" << endl;
	cout << "\t18. Tinh tong cac Node co trong danh sach" << endl;
	cout << "\t19. Dem so luong cac Node hien co" << endl;
	cout << "\t20. Dem so luong cac Node:" << endl;
	cout << "\t\t1. Node co gia tri chan" << endl;
	cout << "\t\t0. Node co gia tri le" << endl;
	cout << "\t21. Dem so luong cac Node:" << endl;
	cout << "\t\t1. Node co gia tri duong" << endl;
	cout << "\t\t0. Node co gia tri am" << endl;
	cout << "\t22. Tim Node co gia tri:" << endl;
	cout << "\t\t1. MAX" << endl;
	cout << "\t\t0. MIN" << endl;
	cout << "\t23. Tim Node co gia tri:" << endl;
	cout << "\t\t1. Am lon nhat" << endl;
	cout << "\t\t0. Le nho nhat" << endl;
	cout << "\t24. Tim Node:" << endl;
	cout << "\t\t1. Max cac so am" << endl;
	cout << "\t\t0. Min cac so le" << endl;
	cout << "\t25. Cap nhat Node co gia tri x bang gia tri y:" << endl;
	cout << "================================= END =================================" << endl;
}


int main()
{
	srand(time(NULL));
	int chon;
	int x;
	List l;
	createList(l);
	Node* p = NULL;
	bool flag = false;
	menu();
	do
	{
		cout << "Nhap lua chon: ";
		cin >> chon;
		switch (chon)
		{
		case 0:
			cout << "\n======== Chuong trinh ket thuc =========" << endl;
			break;
		case 1:
			createList(l);
			cout << "Khoi tao list thanh cong!" << endl;
			break;
		case 2:
			cout << "Nhap so nguyen x: ";
			cin >> x;
			p = createNode(x);
			cout << "Khoi tao Node thanh cong!" << endl;
			break;
		case 3:
			if (p == NULL)
			{
				cout << "Ban chua khoi tao Node!" << endl;
				break;
			}
			else
			{
				addHead(l, p);
				cout << "Them thanh cong!" << endl;
				flag = true;
				break;
			}
		case 4:
			if (p == NULL)
			{
				cout << "Ban chua khoi tao Node!" << endl;
				break;
			}
			else
			{
				addTail(l, p);
				cout << "Them thanh cong!" << endl;
				flag = true;
				break;
			}
		case 5:
			if (nhapDanhSach(l))
			{
				cout << "Nhap danh sach thanh cong!" << endl;
				flag = true;
				break;
			}
			else
			{
				cout << "Nhap that bai, hay thu lai sau!" << endl;
				break;
			}
		case 6:
			if (taoNgauNhien(l))
			{
				cout << "Nhap danh sach thanh cong!" << endl;
				flag = true;
				break;
			}
			else
			{
				cout << "Nhap that bai, hay thu lai sau!" << endl;
				break;
			}
		case 7:
			if (nhapTuMang1D(l))
			{
				cout << "Nhap danh sach thanh cong!" << endl;
				flag = true;
				break;
			}
			else
			{
				cout << "Nhap that bai, hay thu lai sau!" << endl;
				break;
			}
		case 8:
			cout << "Vui long khoi tao Node!" << endl;
			cout << "Nhap so nguyen x: ";
			cin >> x;
			p = createNode(x);
			addMid(l, p);
			flag = true;
			break;
		case 9:
			if (insertXAfterY(l))
			{
				cout << "Chen thanh cong!" << endl;
			}
			else
			{
				cout << "Chen that bai!" << endl;
			}
			break;
		case 10:
			if (insertXBehindY(l))
			{
				cout << "Chen thanh cong!" << endl;
			}
			else
			{
				cout << "Chen that bai!" << endl;
			}
			break;
		case 11:
			if (flag == false)
			{
				cout << "Ban chua nhap danh sach!" << endl;
			}
			else
			{
				cout << "Danh sach da nhap la: ";
				printList(l);
			}
			break;
		case 12:
			if (flag == false)
			{
				cout << "Ban chua nhap danh sach!" << endl;
				break;
			}
			else
			{
				cout << "Danh sach da nhap la: " << endl;
				printListIncludeAddress(l);
				break;
			}
		case 13:
			if (flag == false)
			{
				cout << "Ban chua nhap danh sach!" << endl;
				break;
			}
			else
			{
				printHeadAndTail(l);
			}
			break;
		case 14:

			cout << "Kiem tra list rong: ";
			cout << boolalpha << isEmpty(l) << endl;
			break;
		case 15:
			if (flag == false)
			{
				cout << "Ban chua nhap danh sach!" << endl;
				break;
			}
			cout << "Nhap n = ";
			cin >> x;
			p = searchNodeN(l, x);
			cout << "Node thu " << x << " co gia tri la: " << p->data << " Address: " << p << endl;
			break;
		case 16:
			if (flag == false)
			{
				cout << "Ban chua nhap danh sach!" << endl;
				break;
			}
			cout << "Nhap data x can tim: ";
			cin >> x;
			cout << "Dia chi cua Node can tim la: " << search(l, x) << endl;
			break;
		case 17:
			if (flag == false)
			{
				cout << "Ban chua nhap danh sach!" << endl;
				break;
			}
			cout << "Nhap data x can tim: ";
			cin >> x;
			List newList;
			createList(newList);
			newList = search_All_X(l, x);
			if (newList.pHead != NULL)
				printListIncludeAddress(newList);
			else
				cout << "Khong tim thay x!" << endl;
			break;
		case 18:
			if (flag == false)
			{
				cout << "Ban chua nhap danh sach!" << endl;
			}
			else
			{
				cout << "Tong gia tri cac Node trong danh sach la: " << tinhTongNode(l) << endl;
			}
			break;

		case 19:
			cout << "So phan tu hien tai la: " << sizeOfList(l) << endl;
			break;

		case 20:
			if (flag == false)
			{
				cout << "Ban chua nhap danh sach!" << endl;
				break;
			}
			cin >> chon;
			switch (chon)
			{
			case 1:
				cout << "So luong Node co gia tri chan la: " << numberOfEvenNode(l) << endl;
				break;
			case 0:
				cout << "So luong Node co gia tri le la: " << numberOfOddNode(l) << endl;
				break;
			}
			break;
		case 21:
			if (flag == false)
			{
				cout << "Ban chua nhap danh sach!" << endl;
				break;
			}
			cin >> chon;
			switch (chon)
			{
			case 1:
				cout << "So luong Node co gia tri duong la: " << numberOfPositiveNode(l) << endl;
				break;
			case 0:
				cout << "So luong Node co gia tri am la: " << numberOfNegativeNode(l) << endl;
				break;
			}
			break;
		case 22:
			if (flag == false)
			{
				cout << "Ban chua nhap danh sach!" << endl;
				break;
			}
			cin >> chon;
			switch (chon)
			{
			case 1:
				p = findMax(l);
				cout << "Node co gia tri lon nhat la: " << p->data << endl;
				break;
			case 0:
				p = findMin(l);
				cout << "Node co gia tri nho nhat la: " << p->data << endl;
				break;
			}
			break;
		case 23:
			if (flag == false)
			{
				cout << "Ban chua nhap danh sach!" << endl;
				break;
			}
			cin >> chon;
			switch (chon)
			{
			case 1:
				p = findMaxNegative(l);
				cout << "Node co gia tri am lon nhat la: " << p->data << endl;
				break;
			case 0:
				p = findMinOdd(l);
				cout << "Node co gia tri le nho nhat la: " << p->data << endl;
				break;
			}
			break;
		case 24:
			if (flag == false)
			{
				cout << "Ban chua nhap danh sach!" << endl;
				break;
			}
			cin >> chon;
			switch (chon)
			{
			case 1:
				p = findMaxNegative(l);
				cout << "Max cac so am: " << p->data << endl;
				break;
			case 0:
				p = findMinOdd(l);
				cout << "Min cac so le: " << p->data << endl;
				break;
			}
			break;
		case 25:
			cout << "Nhap gia x can tim: ";
			cin >> x;
			p = search(l, x);
			if (p == NULL)
			{
				cout << "Khong tim thay gia tri x!" << endl;
				break;
			}
			cout << "Nhap gia thi y can thay the: ";
			cin >> x;
			p->data = x;
			break;
	}
	} while (chon != 0);
	return 0;
}
