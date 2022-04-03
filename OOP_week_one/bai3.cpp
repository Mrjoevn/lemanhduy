#include <iostream.h>
using namespace std;
struct PhanSo
{
	int tuso;
	int mauso;	
};
int UCLN(int a ,int b)
{
	while( a != b)
	{
		if( a > b)
		{
			a = a - b;
		}
		else{
			b = b - a;
		}
	}
	return a;
}
PhanSo rut_Gon(PhanSo &ps1)
{
	PhanSo temp;
	int k = UCLN(ps1.tuso , ps1.mauso);
	ps1.tuso = ps1.tuso / k;
	ps1.mauso = ps1.mauso / k;
	return ps1;
}
void nhap_Phanso(PhanSo ps[] ,int n)
{
	for(int i = 0 ;i < n ;i++)
	{
		cout << "\nNhap Phan So thu "<< i+1 << " la :";
		cout << "\nTU SO :";cin >> ps[i].tuso;
		do{
			cout << "\nMAU SO :";cin >> ps[i].mauso;
			if(ps[i].mauso == 0) cout<<"\nNhap sai ";
		}while(ps[i].mauso == 0);
	}
}
void xuat(PhanSo &ps)
{
	if(ps.tuso == 0)
	{
		cout << "(" << 0 << ")";
		}	
		else if( ps.mauso < 0)
		{
		cout << "(-" <<ps.tuso << "/" << ps.mauso * (-1) <<")";
		}
			else{
			cout << "(" << ps.tuso << "/" << ps.mauso <<")";
			}
}
void xuat_Phanso(PhanSo ps[] ,int n)
{
	for(int i = 0 ;i< n ;i ++)
	{
	rut_Gon(ps[i]);
		xuat(ps[i]);
		cout<<" ";
	}
}
PhanSo tinh_tong(PhanSo *ps , int n)
{	
	PhanSo tong = ps[0];
	for(int i =1 ;i<n ;i++)
	{
		tong.tuso = (tong.tuso *ps[i].mauso) + (tong.mauso * ps[i].tuso);
		tong.mauso = (tong.mauso * ps[i].mauso);
	}
	return tong;
}
int main(int argc, char *argv[])
{
	PhanSo ps[20];
	int n;
	cout<<"\nnhap so luong PhanSo la :";cin >> n;
	nhap_Phanso(ps , n);
	cout<<"\ndanh sach PhanSo da nhap :";
	xuat_Phanso(ps , n);
	PhanSo result = tinh_tong(ps , n);
	rut_Gon(result);
	cout<<"\nTong cua cac Phan So trong danh sach la :";
	xuat(result);
	return 0;
}