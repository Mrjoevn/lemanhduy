#include<iostream.h>
using namespace std;

void nhap_mang(int *a , int n)
{
	for (int i = 0 ;i < n ;i++)
	{
		cout <<"\n a[ "<< i+1 << " ]=";
		cin >>a[i];
	}	
}
void xuat_mangltr(int *a ,int n)
{
	for(int i = 0 ;i < n ;i++)
	{
		cout << a[i] << " " ;
	}
}
void xuat_mangrtf(int *a , int n)
{
	for(int i =  n-1 ;i >= 0 ;i--)
	{
		cout << a[i] << " ";
	}
}
void tim_kiem(int *a , int n ,int search)
{
	int location = 0 ;
	for( int i = 0 ;i < n ;i ++)
	{
		if(a[i] == search )
		{
			location += (i+1) ;
		}
	}
	if( location != 0)
	{
		cout<<"\nVi tri cua "<< search <<" can tim la vitri thu "<< location ;
	}
	else{
		cout<< search <<" Khong tim thay trong mang .";
	}
}
void swap(int &a , int &b);
void sap_xeptangdan(int *a ,int n)
{
	int min;
	for( int i = 0 ;i < n-1 ;i ++)
	{
		min = i;
		for( int j = i+1 ;j < n ;j ++)
		{
			if( a[j] < a[min])
			{
				min = j;
			}
		}
		swap(a[min] , a[i]);
	}	
}
void swap(int &a , int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int main()
{
	int n;
	cout << "\n Nhap so luong trong mang la :"; cin >> n;
	int *a = new int [n];
	cout << "\n\tNhap Mang :";
	nhap_mang(a , n);
	cout << "\n\t Mang vua nhap la :";
	xuat_mangltr(a , n);
	cout << "\n\t Mang theo chieu nguoc la :";
	xuat_mangrtf(a , n);
	int socantim ;
	cout<<"\n Nhap so can tim la:";cin >> socantim;
	tim_kiem(a , n , socantim);
	sap_xeptangdan(a , n);
	cout<< "\n\t Danh sach sap xep tang dan la :";
	xuat_mangltr(a , n);
	delete []a ;
	return 0;
}