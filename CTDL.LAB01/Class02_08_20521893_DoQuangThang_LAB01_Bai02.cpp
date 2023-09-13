#include <iostream>
#include <cmath>
#include <time.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;
#define MAXN 200

void Nhap(int a[], int &n)
{
    cout << "Nhap so luong phan tu: \n" ;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }

}
void NhapTuDong(int a[], int &n)
{
    n = 10 + rand()%41;
    for (int i=0; i<n; i++)
        {
          a[i] = -999 + rand() % 1999;
        }
    cout << endl;
}
void Xuat(int a[],int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int kiemtra(int a[],int n,int i)
{
    int t=a[i]; 
    for (int j=0;j<i;j++)
        if (t==a[j])return 0;
    return 1;
}
int dem (int a[],int n,int i)
{
    int t=a[i],j=0;
    for (;i<n;i++)
    {
        if (t==a[i]) j++;
    }
    return (j);
}
void DemPhanTu_1(int a[],int &n)
{
    int b[n];
    int x=1;
    b[0]=a[0];
    for(int i=1;i<n;i++)
    {
        int dem=0;
        for(int j=0;j<x;j++)
        {
            if(a[i]==b[j])
                dem++;
        }
        if(dem==0)
        {
            b[x]=a[i];
            x++;
        }
    }
    int c[x];
    
    for(int i=0;i<x;i++)
        c[i]=0;
        
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]==b[i])
                c[i]++;
        }
    }
    
    int max=c[0], vtri=0, y=1;

    for(int i=1;i<x;i++)
    {
        if(c[i]>max)
        {
            max=c[i];
            vtri=i;
            y=1;
        }
        if(c[i]==max)
        {
            y++;
        }
    }

    if(y==1)
        {
        cout<<"\nPhan tu xuat hien nhieu nhat la: "<<b[vtri];
        }
    else
    {
        int d[y];
        int z=0;
        for(int i=0;i<x;i++)
            if(c[i]==max)
            {
                d[z]=i;
                break;
            }

        cout<<"\nPhan tu xuat hien nhieu nhat la: ";
            cout<<b[d[z]]<<" ";

    }
}
void DemPhanTu_2(int a[],int &n)
{
    int b[n];
    int x=1;
    b[0]=a[0];
    for(int i=1;i<n;i++)
    {
        int dem=0;
        for(int j=0;j<x;j++)
        {
            if(a[i]==b[j])
                dem++;
        }
        if(dem==0)
        {
            b[x]=a[i];
            x++;
        }
    }

    int c[x];
    
    for(int i=0;i<x;i++)
        c[i]=0;

    for(int i=0;i<x;i++)
	{
        for(int j=0;j<n;j++)
        {
            if(a[j]==b[i])
                c[i]++;
        }
    }


    int max=c[0], vtri=0, y=1;


    for(int i=1;i<x;i++)
    {
        if(c[i] > max)
        {
            max=c[i];
            vtri=i;
            y=1;
        }
        if(c[i]==max)
        {
            y++;
        }
    }


    if(y==1)
    {
        cout<<"\nPhan tu xuat hien nhieu nhat la: "<<b[vtri];

    }
    else
    {
        int d[y];
        int z=0;
        for(int i=0;i<x;i++)
            if(c[i]==max)
            {
                d[z]=i;
                z++;
            }
        cout<<"\nPhan tu xuat hien nhieu nhat la: ";

        for(int i=0;i<z;i++ )

            cout<< b[d[i]] <<" ";

    }
}
void DemPhanTuLe(int a[],int n)
{
    int b[n];
    int x=1;
    b[0]=a[0];

    for(int i=1;i<n;i++)
    {
        int dem=0;
        for(int j=0;j<x;j++)
        {
            if(a[i] == b[j])
                dem++;
        }
        if(dem==0)
        {
            b[x]=a[i];
            x++;
        }
    }

    int c[x];
    for(int i=0;i<x;i++)
        c[i]=0;

    for(int i=0;i<x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if( a[j]==b[i] && a[j]%2!=0 )
                c[i]++;
        }
    }


    int max=c[0], vtri=0, y=1;


    for(int i=1;i<x;i++)
        {
        if( c[i]%2!=0 && c[i]>max )
        {
            max=c[i];
            vtri=i;
            y=1;
        }
        if(c[i] % 2 != 0 && c[i] == max)
        {
            y++;
        }
    }

    if(y==1)
    {
        cout<<"\nPhan tu le xuat hien nhieu nhat la: "<<b[vtri];
    }


    else
    {
        int d[y];
        int z=0;
        for(int i=0;i<x;i++)
            if(c[i]%2!=0&&c[i]==max)
            {
                d[z]=i;
                z++;
            }
        cout<<"\nPhan tu le xuat hien nhieu nhat la: ";
        for(int i=0;i<z;i++ )
            cout<<b[d[i]]<<" ";
    }
}
void swap(int &a, int &b)
{
	int x = a;
	    a = b;
	    b = x;
}

void menu()
{
    int a[MAXN],n;

    while(true)
    {
    cout << endl;
    cout << "===================MENU=================="  << endl;
    cout << "Cau 1.Nhap gia tri cho day theo phuong phap thu cong: \n";
    cout << "Cau 2,3. Nhap,xuat ham tu dong:  \n";
    cout << "Cau 4. Thong ke so luong cac phan tu co trong day: \n";
    cout << "Cau 5. Phan tu xuat hien nhieu nhat trong mang(tra ve phan tu dau tien): \n";
    cout << "Cau 6. Phan tu xuat hien nhieu nhat trong mang(tra ve het cac phan tu): \n";
    cout << "Cau 7. Phan tu le xuat hien nhieu nhat trong mang(tra ve het cac phan tu): \n";
     cout << "===================END!==================="  << endl;

    cout << "Nhap cau lua chon: ! " << endl;

    int cau;
    cin >> cau;


    switch (cau)
       {
    case 1:
        cout << "Cau 1.Nhap gia tri cho day theo phuong phap thu cong: \n";
        Nhap(a,n);
        Xuat(a,n);
        break;
    case 2: case 3:
        cout << "Cau 2,3. Nhap,xuat ham tu dong:  \n"; 
        NhapTuDong(a,n);
        Xuat(a,n);
        break;
    case 4:
        cout << "Cau 4. Thong ke so luong cac phan tu co trong day: \n";
        Nhap(a,n);
           cout<<a[0]<<" co "<<dem(a,n,0)<<" ptu\n";
       for (int i=1;i<n;i++)
      {
        if (kiemtra(a,n,i)) cout<<a[i]<<" co "<<dem(a,n,i)<<" ptu\n"; 
      }
        break;
    case 5:
        cout << "Cau 5. Phan tu xuat hien nhieu nhat trong mang(tra ve phan tu dau tien): \n";
        Nhap(a,n);
        DemPhanTu_1(a,n);
        break;
    case 6:
        cout << "Cau 6. Phan tu xuat hien nhieu nhat trong mang(tra ve het cac phan tu): \n";
        Nhap(a,n);
        DemPhanTu_2(a,n);
        break;
    case 7:
        cout << "Cau 7. Phan tu le xuat hien nhieu nhat trong mang(tra ve het cac phan tu): \n";
        Nhap(a,n);
        DemPhanTuLe(a,n);
        break;

    default:
        break;
       }
    }
}
int main()
{
    menu();
    return 0;
}
