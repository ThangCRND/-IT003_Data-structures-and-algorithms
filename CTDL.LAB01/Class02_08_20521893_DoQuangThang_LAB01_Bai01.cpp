#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
#define MAXN 100

struct Donthuc
{
    float heso;
    int mu;
};

void NhapDonThuc(Donthuc &a)
{
    cout << "nhap he so: ";
    cin >> a.heso;
    cout << "nhap mu: ";
    cin >> a.mu;
    cout << endl;
}
void XuatDonThuc(Donthuc A)
{
   if(A.heso==0)
    {
       cout << A.heso <<endl;
    }
     else if (A.heso==1)
     {
         cout << "x^" << A.mu;
     }
    else if(A.mu==0)
    {
        cout << A.heso << endl;
    }
     else
        cout << A.heso << "x^"<< A.mu ; 
}

void input_auto(Donthuc a[], int &n)
{
    n = 1 + rand() % 10;
    for(int i = 0; i < n;i++)
    {
        a[i].heso = 39 + rand() % 41;
        a[i].mu = rand() % 10;
    }
    cout << endl;
}

void Output(Donthuc a[], int n)
{
    XuatDonThuc(a[0]);
    for(int i = 1; i < n; i++)
    {
        if(a[i].mu == 0)
            cout << " + " << a[i].heso;
        else if(a[i].mu == 1)
            cout << " + " << a[i].heso << "x";
        else
            cout << " + " << a[i].heso << "x^" << a[i].mu;
    }
    cout << endl;
}
void SoMuGiamDan(Donthuc a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i].mu < a[j].mu)
            {
                Donthuc temp = a[i]; 
                   a[i] = a[j];
                   a[j] = temp;
            }
        }
    }
}

long TinhGiaTriBieuThuc(Donthuc a[], int n, int &x)
{
    cout << "Nhap x = " ;
    cin >> x;
    long sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += a[i].heso * pow(x,a[i].mu);
    }
    return sum;
}

Donthuc BacLonNhat(Donthuc a[], int n)
{
    Donthuc max = a[0];
    int k = a[0].mu;
    for(int i = 1; i < n; i++)
    {
        if(k < a[i].mu)
        {
            k = a[i].mu;
            max = a[i];
        }
    }
    return max;
}

Donthuc BacNhoNhat(Donthuc a[], int n)
{
    Donthuc min = a[0];
    int k = a[0].mu;
    for(int i = 1; i < n; i++)
    {
        if(k > a[i].mu)
        {
            k = a[i].mu;
            min = a[i];
        }
    }
    return min;
}

Donthuc* TimBacMaxMin(Donthuc a[], int n, Donthuc *e)
{

     e[0] = BacLonNhat(a,n);
     e[1] = BacNhoNhat(a,n);
    return e;
}

long TongBieuThuc(Donthuc a[], int &x)
{
    cout << "input x: " << endl;
    cin >> x;
    long sum = a[0].heso * pow(x,a[0].mu) + a[1].heso * pow(x,a[1].mu);
    return sum;
}

double ThuongBieuThuc(Donthuc a[], int &x)
{
    cout << "Nhap x: " << endl;
    cin >> x;
    double thuong = (float)a[0].heso * pow(x,a[0].mu) / a[1].heso * pow(x,a[1].mu);
    return thuong;
}

void swap(Donthuc &a, Donthuc &b)
{
    Donthuc  c = a;
             a = b;
             b = c;
}

void SwapSoMuGiamDan(Donthuc a[], int n)
{
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - 1 - i; j++)
            if(a[j].mu < a[j + 1].mu)
                swap(a[j], a[j + 1]);

}

void menu()
{
    while(true)
    {
    cout << endl;
    cout << "===================MENU=================="  << endl;
    cout << "\t0.Chuong trinh ket thuc." << endl;
    cout << "\t1. Nhap he so va mu cho 1 don thuc : " << endl;
    cout << "\t2. He so va mu cho da thuc: " << endl;
    cout << "\t3. Xuat ket qua: " << endl;
    cout << "\t4. Xuat da thuc theo mu giam dan: " << endl;
    cout << "\t5. Tinh gia tri y = f(x) voi gia tri x : " << endl;
    cout << "\t6. Don thuc co bac lon nhat trong da thuc : " << endl;
    cout << "\t7. Don thuc co bac nho nhat trong da thuc : " << endl;
    cout << "\t8. Tong hai da thuc: " << endl;
    cout << "\t9. Thuong hai da thuc: " << endl;
    cout << "\t10.Sap sap mu giam dan (dang bubble sort): " << endl;
    cout << "===================END!==================="  << endl;

    cout << "Nhap cau lua chon: ! " << endl;

    int chon;
    cin >> chon; 
	
    Donthuc d[MAXN], a, max, min, e[2]; 
    int n;
    int x;
    long ketqua; 
    

    switch(chon)
    {
        case 0:
        	cout << "Chuong trinh ket thuc." << endl; 
          return ;
        case 1:
            cout << "Cau 1. Nhap he so va mu cho 1 don thuc : " << endl;
                NhapDonThuc(a);
                XuatDonThuc(a);
            break;
        case 2:
            cout << "Cau 2. He so va mu cho da thuc: " << endl;
               input_auto(d, n);
               Output(d, n);
            break;
        case 3:
            cout << " Xuat ket qua: " << endl;
            input_auto(d, n);
            cout << "Da random " << n << " don thuc " << endl << endl << endl;
                Output(d, n);
            break;
        case 4:
            cout << "Cau 4. Xuat da thuc theo mu giam dan: " << endl;
            input_auto(d, n);
            SoMuGiamDan(d, n);
            Output(d, n);
            break;
        case 5:
            cout << "Cau 5. Tinh gia tri y = f(x) voi gia tri x: " << endl;
                input_auto(d, n);
                Output(d, n);
                ketqua = TinhGiaTriBieuThuc(d, n, x);
                cout << "y = f(x) " << ketqua;
                cout << endl;
            break;
        case 6:
            cout << "Cau 6. Don thuc co bac lon nhat trong da thuc: " << endl;
            input_auto(d, n);
            Output(d, n);
            max = BacLonNhat(d, n);
            cout << "Bac lon nhat : " << endl;
            XuatDonThuc(max);
            cout << endl;
            break;
        case 7:
            cout << "Cau 7. Don thuc co bac nho nhat trong da thuc: " << endl;
            input_auto(d, n);
            Output(d, n);
            min = BacNhoNhat(d, n);
            cout << "Bac nho nhat : " ;
            XuatDonThuc(min);
            cout << endl;
            break;
        case 8:
            cout << "Cau 8. Tong hai da thuc(Bac don thuc MAX_MIN): " << endl;
            input_auto(d, n);
            TimBacMaxMin(d, n, e);
            Output(e, 2);
            cout << "Ban co muon tinh phep tinh nay ? " << endl;
            char check;
            cout << " Nhap y or n: " << endl;
            cin >> check;
            if(check == 'y')
            {
                ketqua = TongBieuThuc(e, x);
                cout << ketqua << endl;
            }
            break;
        case 9:
            cout << "Cau 9. Thuong hai da thuc(MAX_MIN): " << endl;
            input_auto(d, n);
            TimBacMaxMin(d, n, e); 
            XuatDonThuc(e[0]);
            for(int i = 1; i < 2; i++)
            {
                if(e[i].mu == 0)
                    cout << " / " << e[i].heso;
                else if(e[i].mu == 1)
                    cout << " / " << e[i].heso << "x";
                else
                    cout << " / " << e[i].heso << "x^" << e[i].mu;
            }
            cout << endl;

            cout << "Ban co muon tinh phep tinh nay ? " << endl;
            char check1;
            cout << "Nhap y or n: " << endl;
            cin >> check1;
            if(check1 == 'y')
            {
                double value = ThuongBieuThuc(e, x);
                cout << value << endl;
            }
            break;
        case 10:
            cout << "Cau 10. Sap sap mu giam dan " << endl;
            input_auto(d, n);
            cout << "So mu duoc sap xep la: " << endl;
            SwapSoMuGiamDan(d, n);
            Output(d, n);
            break;
      }
    }
}

int main()
{
    menu();
    return 0;
}
