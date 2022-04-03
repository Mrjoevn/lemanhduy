#include<iostream.h>
#include<string.h>
#include<iomanip.h>
using namespace std;
class GV
{
	private:
	char hoTen[30];
	int tuoi;
	char bangCap[15];
	char chuyenNganh[20];
	float bacLuong;
	public:
	GV()
	{
		strcpy(hoTen ," ");
		tuoi = 1;
		strcpy(bangCap ," ");
		strcpy(chuyenNganh ," ");
		bacLuong = 0;
	}
	void Nhap()
	{
		fflush(stdin);
		cout << "\nNhap ho Ten GV :"; cin.getline(hoTen ,31);
		cout << "\nNhap tuoi GV :"; cin >>tuoi;
		fflush(stdin);
		cout << "\nNhap bang Cap GV :"; cin.getline(bangCap ,16);
		cout << "\nNhap chuyen Nganh Gv :"; cin.getline(chuyenNganh ,21);
		cout << "\nNhap bac Luong :" ; cin >> bacLuong;
	}
	float Luongcoban()
	{
		return bacLuong * 610 ;
	}
	void Xuat()
	{
		cout << "\n";
		cout << setw(30) << hoTen
			<< setw(5) << tuoi
			<< setw(15) << bangCap
			<< setw(30) << chuyenNganh
			<< setw(5) << bacLuong
			<< setw(10) << Luongcoban();
	}
	char *get_chuyennganh()
	{
		return chuyenNganh;
	}
	friend istream &operator >> (istream &is ,GV &gv);
	friend ostream &operator << (ostream &os ,GV gv);
	friend bool operator == (GV &gv1 , GV &gv2)
	{
		return strcmpi(gv1.bangCap , gv2.bangCap)==0 ? true :false;
	}
};
istream &operator >> (istream &is ,GV &gv)
{
	gv.GV ::Nhap();
	return is;
}
ostream &operator << (ostream &os ,GV gv)
{
	gv.GV ::Xuat();
	return os;
}
void Check_lcb( GV *gv , int n)
{
	for( int i = 0 ;i < n ;i++)
	{
		if(gv[i].Luongcoban() < 2000)
		{
			gv[i].Xuat();
		}
	}
}
void Sap_xeptheoCN(GV *gv , int n)
{
	for( int i = 0 ;i < n ;i++)
	{
		for(int j = i+1 ;j < n ;j++)
		{
			if( strcmpi(gv[i].get_chuyennganh() ,gv[j].get_chuyennganh())>0)
			{
				GV temp;
				temp = gv[i];
				gv[i] = gv[j];
				gv[j] = temp ;
			}
		}
	}
}
int main()
{
	int n;
	do{
		cout << "\nnhap so luong Giao Vien la :"; cin >> n;
		if(n <= 0)cout<<"\nnhap sai roi .";
	}while(n <= 0);
	GV gv[n];
	for(int i = 0 ;i < n ; i++)
	{
		cout << "\nNhap Giao Vien thu "<< i+1 << " la :";
		gv[i].Nhap();
	}
	cout << "\n\tDanh sach da nhap :";
	for( int i = 0 ;i < n ; i++)
	{
		gv[i].Xuat();
	}
	cout << "\nGiao vien co Lcb < 2000 la :";
	Check_lcb(gv , n);
	cout << "\nDanh sach Gv sau khi sap xep tang dan la :";
	Sap_xeptheoCN(gv , n);
		for( int i = 0 ;i < n ; i++)
	{
		gv[i].Xuat();
	}
	return 0;
}