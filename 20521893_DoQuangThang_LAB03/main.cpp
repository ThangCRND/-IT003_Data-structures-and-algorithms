#include <iostream>
#include <math.h>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
#define MAXN 100000
using namespace std;
void Nhap( double a[], int &n)
{
    cout<<"Nhap so phan tu: ";
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>> a[i];
    }
}
void NhapTuDong1(double a[], int &n)
{
    //srand(time(NULL));
   // n=100000;
    for (int i=0; i<n; i++)
    {
        a[i]=rand() + (double (rand()%1001)/1000);
    }
    cout << endl;

}
void NhapTuDong2(double a[], int &n)
{
    //srand(time(NULL));
    //n=100000;
    for (int i=0; i<n; i++)
    {
        a[i]=(double) (39000+rand()+rand()%(27233) + double (rand()%1001)/1000);
    }
    cout << endl;

}
void Xuat( double a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<setprecision(3);
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void swap(double &a, double &b)
{
	double x = a;
	       a = b;
           b = x;
}
void Sapxep(double a[], int n)
{
	for (int i = 0; i < n-1;i++)
		for (int j = i + 1; j < n;j++)
		if (a[i]>a[j])
			swap(a[i], a[j]);
}
double TinhThoiGian1(double a[], int n)
{
    clock_t start, end;
   double cpu_time_used;

    start = clock();
       Sapxep(a,n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
       return cpu_time_used;
}
void SapXep2(double a[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = a[i];
       j = i-1;

       while (j >= 0 && a[j] > key)
       {
           a[j+1] = a[j];
           j = j-1;
       }
       a[j+1] = key;
   }
}
double TinhThoiGian2(double a[(int) MAXN], int n)
{
     clock_t start, end;
         double cpu_time_used;

        start = clock();
        SapXep2(a,n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     return cpu_time_used;
}
void menu()
{
    while(true)
    {
    cout << setw(30) << "MENU" << endl << endl;
    cout << "Cau 1. Nhap gia tri cho mang thu cong: \n";
    cout << "Cau 2. Khoi tao tu dong  : \n";
    cout << "Cau 3. Khoi tao tu dong trong khoang [] \n";
    cout << "Cau 4. Xuat mang: \n";
    cout << "Cau 5. Thuat toan sap xep chon truc tiep: \n";
    cout << "Cau 6. Tinh thoi gian sap xep chon truc tiep: \n";
    cout << "cau 7. Thuat toan sap xep chen truc tiep: \n";
    cout << "cau 8. Tinh toans thoi gian chen truc tiep: \n";
    cout << setw(30) << "END" << endl << endl;

    cout << "xin moi lua chon:  ";

    int chon;
    cin >> chon;
    double a[MAXN];
    int n ;

    switch(chon)
    {
        case 1:
            cout << "Cau 1. Nhap gia tri cho mang thu cong: \n";
            Nhap(a,n);
            break;
        case 2:
            cout << "Cau 2. Khoi tao tu dong  : \n";
            NhapTuDong1(a,n);
            Xuat(a,n);
            break;
        case 3:
            cout << "Cau 3. Khoi tao tu dong trong khoang [] \n";
            NhapTuDong2 (a,n);
            Xuat(a,n);
            break;
        case 4:
            cout << "Cau 4. Xuat mang: \n";
            Xuat(a,n);
            break;
        case 5:
            cout << "Cau 5. Thuat toan sap xep chon truc tiep: \n";
            Sapxep(a,n);
            Xuat(a,n);
            break;
        case 6:
            cout << "Cau 6. Tinh thoi gian sap xep: \n";
            cout<<TinhThoiGian1(a,n)<<endl;
            break;
        case 7:
            cout << "cau 7. Thuat toan sap xep chen truc tiep: \n";
            SapXep2(a,n);
            Xuat(a,n);
            break;
        case 8:
            cout << "cau 8. Tinh toans thoi gian chen truc tiep: \n";
            cout<<TinhThoiGian2(a,n)<<endl;
            break;






    }
    }
}
int main()
{
    menu();
    return 0;
}
