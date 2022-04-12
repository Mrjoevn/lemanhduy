#include <iostream.h>
#include <iomanip.h>
#include <string.h>
#include <ctime>
using namespace std;
struct Date
{
	int day , mouth , year;
	Date()
	{
	//lay time hien tai dua tren he thong mtinh.
		time_t thoigian = time(0);
	//day la so giay ngay 1/1/1970 den hien tai.
		tm *ltm = localtime(&thoigian);
		day = ltm->tm_mday;
		mouth = ltm->tm_mon;
		year = ltm->tm_year;
	}
};
class SanPham
{
	protected:
		char ma_sp[10];
		char ten_sp[30];
		float don_gia;
	public:
		SanPham( char *ma =" " ,char *ten = "" ,float dg = 0.0)
		{
			strcpy(ma_sp , ma);
			strcpy(ten_sp , ten);
			don_gia = dg;
		}
		~SanPham(){}
		void nhaP()
		{
			fflush(stdin);
			cout << "\nNhap ma SP :" ; cin.getline( ma_sp ,11);
			cout << "\nNhap Ten SP :" ; cin.getline( ten_sp ,31);
			cout << "\nNhap don Gia :"; cin >> don_gia;
		}
		void xuaT()
		{
			cout << setw(20) << left << ma_sp
				<< setw(30) << left<<ten_sp
				<< setw(10) << left<<don_gia;
		}
			char *get_Ma()
			{
				return ma_sp;
			}
};
class Thuoc :public SanPham
{
	private:
		char loai_thuoc[30];
		Date hsd;
		char thanh_phan[30];
	public:
Thuoc( char *ma =" " ,char *ten = "" ,float dg = 0.0 , char *loai = " " , char *tp = " ")
		:SanPham(ma , ten , dg)
		{
			Date();
			strcpy(loai_thuoc ,loai);
			strcpy( thanh_phan ,tp);
		}
		~Thuoc(){}
		friend istream &operator >> (istream &is , Thuoc &t);
		float giaSauThue()
	{
		return size_t(don_gia + (don_gia * 0.1));
	}
	friend bool operator > ( Thuoc &mb ,float so)
	{
		return (mb.don_gia > so ) ? true : false;
	}
	friend ostream &operator << (ostream &os , Thuoc t);
	char *get_Thanhphan()
	{
		return thanh_phan;
	}
	float get_Dongia()
	{
		return don_gia;
	}
	char *get_Tensp()
	{
		return ten_sp;
	}
};
istream &operator >> (istream &is , Thuoc &t)
{
	cout << "\n";
	t.SanPham::nhaP();
	fflush(stdin);
	cout << "\nNhap loai Thuoc la :" ;is.getline(t.loai_thuoc ,31);
	cout << "\nNhap han su dung la :" ;is >> t.hsd.day >> t.hsd.mouth >> t.hsd.year;
	fflush(stdin);
	cout << "\nNhap thanh phan la :"; is.getline(t.thanh_phan ,31);
	return is;
}
ostream &operator << (ostream &os , Thuoc t)
{
	os << "\n";
	t.SanPham::xuaT();
	os << setw(30)<< left << t.loai_thuoc
	  << "(" << t.hsd.day << "-" << t.hsd.mouth <<")" << setw(6) << "  ";
	os << setw(30) << left<< t.thanh_phan ;
	return os;
}
void tieude()
{
	cout << "\n||===================================================================================================================||";
	
	cout << setw(10) << "\n||Ma Sp"
				<< setw(30) << "Ten Sp"
				<< setw(15) << "Don gia";
	cout << setw(30) << " Loai thuoc" 
		<< setw(10) << "Han sd"
		<< setw(30) << left <<"Thanh Phan";
	cout << "\n||===================================================================================================================||";
}
void swap(Thuoc &t , Thuoc &a)
{
	Thuoc temp = t ;
	t = a ;
	a = temp;
}
void sap_xep( Thuoc *t , int n)
{
	int min ;
	for( int i = 0 ;i < n-1 ;i++)
	{
		min = i;
 		for( int j = i+1 ;j <n ;j++)
 		{
		 	if( strcmpi(t[min].get_Tensp(), t[j].get_Tensp())>0)
		 	{
	 			min = j;
	 		}
		 }
		 swap(t[min] , t[i]);
	}
}
int main()
{
	int n;
	Thuoc *t;
	goback:
	cout << "\nNhap so Luong Thuoc la :" ; cin >> n;
	if( n <= 0)
	{
		cout << "\n nhap sai ! " << endl;
		goto goback;
	}
	t = new Thuoc[n];
	cout << "\n\t\tNhap Danh sach la : ";
	for( int i = 0 ; i < n ; i++)
	{
		
		cout << "\n\t Nhap Thuoc thu " << i+1 << " la :";
		cin >> t[i];
	}
	while(true)
	{
		system("cls");
		int luachon;
		cout << "\n||======================================= Menu ========================================================||";
		cout << "\n|| 1.In ra danh sach cac Thuoc da nhap .                                                               ||";
		cout << "\n|| 2.In ra Thuoc co ma nhap tu ban phim .                                                              ||";
		cout << "\n|| 3.Tim trong danh sach cac Thuoc co thanh phan 'Paracetamol' .                                       ||";
		cout << "\n|| 4.Dem so luong Thuoc co don gia 500.000 d .                                                         ||";
		cout << "\n|| 5.In ra danh sach Thuoc co Dg > 200.00 theo thu tu tang dan cua ten SP .                            ||";
		cout << "\n|| 0. Ket thuc chuong trinh .                                                                          ||";
		cout << "\n||======================================== End ========================================================||";
		do{
			cout << "\nNhap lua chon ( 0 -> 5 ) :";
			cin >> luachon;
			if(luachon <0 || luachon > 6)
			{
				cout << "\nNhap khong dung !" << endl;
			}
		}while(luachon <0 || luachon > 6);
		if( luachon == 0)
		{
			break;
		}
		else if(luachon == 1)
		{
			cout << "\nThuc hien chuc nang 1 .";
			cout << "\n\tDanh sach da nhap " <<endl;
			tieude();
			for( int i = 0 ;i < n ;i++)
			{
				cout << t[i];
			}
			system("pause");
		}
		else if( luachon == 2)
		{
			cout << "\nThuc hien chuc nang 2 .";
			char ma[10];
			fflush(stdin);
			cout << "\nNhap ma can tim :" ;cin.getline(ma ,11);
			for ( int i = 0 ;i < n;i++)
			{
				if (strcmpi(t[i].get_Ma(), ma) == 0)
				{
					cout <<t[i];
				}
			}
			system("pause");
		}
		else if( luachon == 3)
		{
			cout << "\nThuc hien chuc nang 3 .";
			cout << "\nCac thuoc co thanh phan 'Paracetamol' :"; 
			tieude();
			for( int i = 0 ;i < n ;i++)
			{
				if( _strcmpi(t[i].get_Thanhphan() ,"Paracetamol")== 0)
				{
					cout << t[i];
				}	
			}
			system("pause");
		}
		else if( luachon == 4 )
		{
			cout << "\nThuc hien chuc nang 4 .";
			int dem = 0;
			for( int i = 0 ;i < n; i++)
			{
				if(t[i].get_Dongia() == 500000)
				{
					dem++;
				}
			}
			cout << "\n So luong Thuoc co don gia 500.000 vnd la :" << dem <<endl;
			system("pause");
		}
		else if( luachon == 5)
		{
			 cout << "\nThuc hien chuc nang thu 5";
			 for(int i = 0 ; i < n ;i++)
			 {
 				if(t[i].get_Dongia() > 200000)
 				{
				 	sap_xep(t , n);
				 }
 			}
 			cout << "\n\tDanh sach Thuoc co don gia lon hon 200000 va tang dan theo ten Sp la :";
 			tieude();
 			for(int i = 0 ;i < n ;i++)
 			{
			 		if(t[i].get_Dongia() > 200000)
 				{
				 	cout << t[i];
				 }
			 }
			 system("pause");
		}
	}
	return 0;
}