#include<iostream.h>
#include<string.h>
#include<iomanip.h>
#include<ctime>

using namespace std;
struct date
{
	int dd , mm ,yyyy;	
};

class KhachHang
{
	private:
	char ho_ten[30];
	date ns;
	char so_cmt[10];
	char ho_khau[50];
	public:
	void nhap()
	{
		fflush(stdin);
		cout << "\nNhap ho ten Khach Hang :"; cin.getline(ho_ten ,31);
		cout << "\nNhap Ngay Thang Nam la :"; cin >> ns.dd >> ns.mm >>ns.yyyy;
		fflush(stdin);
		cout << "\nNhap so chung minh thu la :"; cin.getline(so_cmt ,11);
		cout << "\nNhap so Ho Khau la :"; cin.getline(ho_khau ,51);
	}
	void xuat()
	{
		cout << "\n";
		cout << setw(30) <<ho_ten
			<< setw(10) << ns.dd << "-" << ns.mm << "-" << ns.yyyy <<" "
			<< setw(15) << so_cmt 
			<< setw(40) << ho_khau;
	}
	friend istream &operator >>(istream &is , KhachHang &kh)
	{
		kh.nhap();
		return is;
	}
	friend ostream &operator <<(ostream &os ,KhachHang kh)
	{
		kh.xuat();
		return os;
	}
	int tuoi()
	{
		//current date or time based on current system .
		time_t hientai= time(0);
		//time_t là tra ve so giay tu nam 1970 den nay .
		//s? d?ng hàm localtime() d? chuy?n d?i format cho curr_time
		tm *ltm = localtime(&hientai);
		return (1970 + ltm->tm_year) - ns.yyyy;
	}
 	friend bool operator >(KhachHang &kh1 , KhachHang &kh2)
	{
		return (kh1.tuoi() > kh2.tuoi()) ? true : false;
	}
	
	int get_Thangsn()
	{
		return ns.mm;
	}
	char *get_Hoten()
	{
		return ho_ten;
	}
	char *get_HoKhau()
	{
		return ho_khau;
	}
};
void nhap_KH(KhachHang *kh ,int n)
{
	for(int i = 0 ;i < n ;i++)
	{
		cout << "\nNhap thong tin cho KH thu " << i+1 << ":";
		cin >> kh[i];
	}
}
void xuat_KH(KhachHang kh[] , int n)
{
	for( int i = 0 ;i < n ;i++)
	{
		cout << kh[i];
	}
}
void tieu_de()
{
	cout << "\n";
		cout << setw(30) <<" Ho ten"
			<< setw(10) << " Date " 
			<< setw(15) << " So cmt"
			<< setw(40) << "Ho Khau";
}
void thangSinhNhat(KhachHang *kh ,int n)
{
	bool check = false;
	for(int i = 0 ;i < n;i++)
	{
		if(kh[i].get_Thangsn() == 12)
		{
			check = true;
		}
	}
	if(!check)
	{
		cout << "\nKhong co sinh vien Sinh nhat thang 12 ";	
	}
	else
	{
		cout << "\nDanh sach sinh vien Sinh Nhat thang 12 :";
		tieu_de();
		for(int i = 0 ;i < n ;i++)
		{
			if(kh[i].get_Thangsn() == 12)
			{
				cout << kh[i];
			}
		}
	}
}
void swap(KhachHang &kh1 , KhachHang &kh2)
{
	KhachHang temp;
	temp = kh1 ;
	kh1 = kh2 ;
	kh2 = temp;
}
void sap_Xep(KhachHang *kh ,int n)
{
	int min;
	for(int i = 0 ;i < n-1;i++)
	{
		min = i;
		for(int j = i+1 ;j < n ;j++)
		{
			if( strcmpi(kh[min].get_Hoten() ,kh[j].get_Hoten()) >0)
			{
				min = j;
			}
		}
		swap(kh[min] , kh[i]);
	}
	cout << "\n\tDanh sach sau khi sap xep la :";
	tieu_de();
	for(int i = 0; i < n ; i++)
	{
		cout << kh[i];
	}
}
void check_HK_Hanoi(KhachHang *kh , int n)
{
	cout << "\n\t Khach Hang co ho khau 'Ha noi' la :";
	for( int i = 0 ; i < n ; i++)
	{
		if(strcmpi(kh[i].get_HoKhau() , "Ha noi") == 0)
		{
			cout << kh[i];
		}
	}
}
void Sapxep_Tuoi(KhachHang *kh , int n)
{
	for(int i = 0 ; i < n-1 ;i++)
	{
		for(int j = i+1 ;j < n ;j++)
		{
			if( kh[j] > kh[i] )
			{
				swap(kh[i] , kh[j]);
			}
		}
	}
}
int main()
{
	int n;
	do{
		cout << "\nNhap so luong KH la :" ;cin >> n;
		if( n <= 0)
		{
			cout << "\nNhap sai .";
		}
	}while( n <= 0);
	KhachHang kh[n];
	nhap_KH( kh ,n);
	tieu_de();
	xuat_KH( kh ,n);
	sap_Xep( kh , n);
	thangSinhNhat(kh , n);
	check_HK_Hanoi( kh , n);
	Sapxep_Tuoi( kh , n);
	cout << "\nDanh sach tang giam dan theo tuoi la :";
	xuat_KH( kh , n);
	return 0;
}