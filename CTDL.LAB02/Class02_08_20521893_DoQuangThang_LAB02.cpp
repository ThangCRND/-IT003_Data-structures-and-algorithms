#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
#define MAXN 100

void Nhap(int a[], int &n)
{
    cout << "Nhap so luong phan tu: \n" ;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }

}
void Input_auto(int a[], int &n)
{
    n = rand() % 21 + 30;

    for (int i=0; i < n; i++)
    {
        a[i] = rand() % 900 + 100;
    }
    cout << endl;
}
void Output_auto(int a[], int n)
{
    for (int i=0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
NhapTuDongTangDan(int a[], int &n)
{
	  srand(time(NULL));
	   n = rand() % 21 + 30;
	   a[0] = rand() % 131;

	  for (int i = 1; i < n; i++)
	  {
		a[i] = a[i - 1] + rand() % 16;
	  }

     cout<<endl;
}

int TimKiemTuyenTinh(int a[],int n, int x)
{
		int i=0;
		while((a[i]!=x) && (i<n))
			i++;
		if(i==n)
			return 0;
		else
			return 1;
}
int TimKiemNhiPhan(int a[],int n,int x)
{	int left, right, mid; left=0; right = n-1;
	do
    {
			mid = left + (left + right) / 2;
			if (a[mid]==x) return 1;
			else
                {
				if(a[mid]< x)
			         left = mid + 1;
				else  right = mid - 1;
                }
	} while(left <= right);
	return 0;
}
int TimKiemNoiSuy(int a[], int n, int x)
{
  int left = 0;
  int right = n-1;
  while (left <= right && x >= a[left] && x <= a[right])
  {
    double value1 = (double) (x - a[left]) / (a[right]-a[left]);
    int value2 = (right-left);
    int pos = left + value1*value2;

    if (a[pos] == x)
      return pos;
void  
    if (a[pos] < x)
      left = pos + 1;
    else
      right = pos - 1;
  }
  return -1;
}

void menu ()
{

    while (true)
    {
        cout << endl;
        cout << "===================MENU=================="  << endl;
        cout << "\t0.Chuong trinh ket thuc." << endl;
        cout << "\t1. Tao mang\n";
        cout << "   A. Tao mang arrayX\n";
        cout << "   B. Tao mang arrayY\n";
        cout << "\t2. Tao mang tang dan\n";
        cout << "   A. Tao mang tang dan arrayX\n";
        cout << "   B. Tao mang tang dan arrayY\n";
        cout << "\t3. Xuat mang\n";
        cout << "   A. Xuat mang arrayX\n";
        cout << "   B. Xuat mang arrayY\n";
        cout << "\t4. Tim kiem tuyen tinh\n";
        cout << "   A. Ap dung mang arrayX\n";
        cout << "   B. Ap dung mang arrayY\n";
        cout << "\t5. Tim kiem nhi phan, ap dung mang arrayY\n";
        cout << "\t6. Tim kiem noi suy, ap dung mang arrayY\n";
        cout << "\t7. So sanh so lan tim kiem, ap dung arrayY\n";
        cout << "===================END!==================="  << endl;

        cout << "Nhap cau lua chon:  " << endl;

    int cau;
    cin >> cau;

    int X[MAXN],Y[MAXN],n,x;
    int KTgiatri;

    switch(cau)
 {
   case 0:
        	cout << "Chuong trinh ket thuc." << endl;
          return;
   case 1:
    cout << "1. Tao mang\n";
        cout << "  A. Tao mang arrayX\n";
            Nhap(X,n);
            Input_auto(X,n);
        cout << "  B. Tao mang arrayY\n";
             Nhap(Y,n);
            Input_auto(Y,n);
        break;
   case 2:
      cout << "2. Tao mang tang dan\n";
        cout << "   A. Tao mang tang dan arrayX\n";
             Nhap(X,n);
            NhapTuDongTangDan(X,n);
        cout << "   B. Tao mang tang dan arrayY\n";
             Nhap(Y,n);
            NhapTuDongTangDan(Y,n);
        break;
   case 3:
    cout << "3. Xuat mang\n";
        cout << "   A. Xuat mang arrayX\n";
           Output_auto(X,n);
            cout << endl;
        cout << "   B. Xuat mang arrayY\n";
            Output_auto(Y,n);
            cout << endl;
        break;
   case 4:
    cout << "4.Tim kiem tuyen tinh\n";
    cout << "Nhap x de thuc hien tim kiem. ";
    cin >> x;
        cout << " A. Ap dung mang arrayX\n";
        if(TimKiemTuyenTinh(X,n,x) == 1)
            cout << "Da tim thay "<< x << " o arrayX\n";
        else
            cout << "Khong tim thay "<< x <<" o arrayX\n";
        cout << " B. Ap dung mang arrayY\n";
        if(TimKiemTuyenTinh(Y,n,x) == 1)
            cout << "Da tim thay "<< x <<" o arrayY\n";
        else
            cout << "Khong tim thay "<< x <<" o arrayY\n";
            cout << "Chay lai chuong trinh: \n";
        break;
    case 5:
       cout << "5. Tim kiem nhi phan, ap dung mang arrayY\n";
       cout << "Nhap x de thuc hien tim kiem. ";
        cin >> x;
    if (TimKiemNhiPhan(Y,n,x) == 1)
        cout << "Da tim thay " << x << " o arrayY\n";
    else
        cout << "Khong tim thay " << x << " o arrayY\n";
        cout << "Chay lai chuong trinh: \n";

        break;
    case 6:
      cout << "6. Tim kiem noi suy, ap dung mang arrayY\n";
      cout << "Nhap x de thuc hien tim kiem. ";
      cin >> x;
      KTgiatri = TimKiemNoiSuy(Y,n,x);
      if (KTgiatri != -1)
        cout << "Da tim thay " << KTgiatri << " o arrayY\n";
      else
        cout << "Khong tim thay " << KTgiatri << " o arrayY\n";
        cout << "Chay lai chuong trinh: \n";
     break;
    case 7:
         cout << "7. So sanh so lan tim kiem, ap dung arrayY\n";
        break;

  }
 }
}

int main()
{
    menu();
    return 0;
}
