#include <iostream>
#include <time.h>
#include <iomanip>
#define MAXN 1e4
using namespace std;

void auto_input(float a[], int &n)
{
    srand(time(NULL));
    for (int i=0; i<n; i++)
    {
        a[i] = rand() + (float (rand()%10001) / 1000);
    }
    cout << endl;

}
void Output(float a[], int &n)
{
    for (int i = 0; i < n; i++)
        cout  <<setprecision(3) << fixed <<a[i] << " ";
}

void swap(float &a, float &b)
{
	float x = a;
	      a = b;
          b = x;
}

void QuickSort(float a[], int left, int right)
{
      int i, j;
      float x;
        x = a[(left+right)/2];
        i = left;
        j = right;
  	do
	{
        while(a[i] < x)
         i++;
        while(a[j] > x)
         j--;
          if(i <= j)
		  {
			swap(a[i],a[j]);
       		i++ ;
       		j--;
	 	  }
	} while(i <= j);

	 if(left<j)
		QuickSort(a, left, j);
	 if(i<right)
		QuickSort(a, i, right);
}

void Shift(float a[],float l,float r)
{
	int x,i,j;
	i=l;
	j=2*i+1;
	x=a[i];
	 while(j<=r)
    {
	     if(j<r)
	    {
          if(a[j]<a[j+1])
            j++;
		  if(a[j]<=x)
            return;
	    }
		else
		{	a[i]=a[j];
			a[j]=x;
			i=j;
			j=2*i+1;
			x=a[i];
        }
     }
}

void CreateHeap(float a[],int n)
{
        float l;
		 l=n/2-1;
		 while(l>=0)
		 {
			Shift(a,l,n-1);
			l=l-1;
		 }
}


void HeapSort(float a[],int n)
{
    int r;
    CreateHeap(a,n);
      r=n-1;
     while(r>0)
     {
        swap(a[0],a[r]);
         r--;
        if(r>0)
         Shift(a,0,r);
     }
}

void merge(float arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m-l + 1;
    int n2 = r - m;

    float L[n1], R[n2];

     for (i = 0; i < n1; i++)
     {
        L[i] = arr[l + i];
     }
     for (j = 0; j < n2; j++)
     {
        R[j] = arr[m + 1+ j];
     }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
           k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void MergeSort(float a[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        MergeSort(a, l, m);
        MergeSort(a, m+1, r);

        merge(a, l, m, r);
    }
}

float QuickTime(float a[], int n)
{
    clock_t start, end;
    float cpu_time_used;
    start = clock();
    QuickSort(a,0,10000);
    end = clock();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

float HeapTime(float a[], int n)
{
    clock_t start, end;
    float cpu_time_used;
    start = clock();
    HeapSort(a,n);
    end = clock();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

float MergeTime(float a[], int n)
{
    clock_t start, end;
    float cpu_time_used;
    start = clock();
    MergeSort(a,0,10000);
    end = clock();
    cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

void Compare(float c[15][(int)MAXN], int n, float a[(int)MAXN], float b[(int)MAXN], float d[(int)MAXN])
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[j] = c[i][j];
            b[j] = c[i][j];
            d[j] = c[i][j];
        }
        cout << "|\t" << "Dataset " << i + 1 << "\t|\t\t";
        float t1 = QuickTime(a,n);
        cout << t1 << "\t\t|\t\t";
        float t2 = HeapTime(b,n);
        cout << t2 << "\t\t|\t\t";
        float t3 = MergeTime(d,n);
        cout << t3 << "\t\t|" << endl;
    }
}

int main()
{
    float a[10000],b[10000],d[10000];
    float c[15][10000];
    int n=10000;
    while (true)
    {
        cout << "=================== MENU =================" << endl;
        cout << ">>\t1. Tao tu dong day so thuc." << endl;
        cout << ">>\t2.Thuat toan QuickSort." << endl;
        cout << ">>\t3.Thuat toan HeapSort. " << endl;
        cout << ">>\t4.Thuat toan MergeSort." << endl;
        cout << ">>\t5.Xuat day so trong thoi gian da thuc hien." << endl;
        cout << "===========================================" <<endl;
        cout << endl;
        cout << "Vui long nhap lua chon: ";

        int chon;
        cin >> chon;

      switch(chon)
     {
        case 0:
            cout << "Ket thuc chuong trinh." << endl;
             return 0;
        case 1:
            cout << "Cau 1. Tao tu dong day so thuc: " << endl;
            auto_input(a,n);
            break;
        case 2:
            cout << "Cau 2.Thuc hien thuat toan QuickSort: " << endl;
            QuickSort(a,0,10000);
            Output(a,n);
            break;
        case 3:
            cout << "Cau 3.Thuc hien thuat toan HeapSort: " << endl;
            HeapSort(a,n);
            Output(a,n);
            break;
        case 4:
            cout << "Cau 4.Thuc hien thuat toan MergeSort: " << endl;
            MergeSort(a,0,10000);
            Output(a,n);
            break;
        case 5:
         {
                cout << "|=======================================================================================================================|" << endl;
                cout << "|\t" << "Dataset " << "\t|\t\t" << "Quick Sort" << "\t|\t\t" << "Heap Sort" << "\t|\t\t" << "Merge Sort" << "\t|" << endl;
                cout << "|=======================================================================================================================|" << endl;
                Compare(c,n,a,b,d);
                break;
         }
            default:
            break;
      }
    }

    return 0;
}
