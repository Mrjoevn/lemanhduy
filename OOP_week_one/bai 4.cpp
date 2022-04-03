#include<iostream.h>
#include<iomanip.h>
#include<string.h>
#include<fstream.h>
using namespace std;
struct HangHoa
{
	char ma_hang[8];
	char ten_hang[30];
	int so_luong;
	float don_gia;
	float thanh_tien;	
};
void nhap_HH(HangHoa *hh , int n)
{
	for(int i = 0 ;i < n ;i ++)
	{
		cout << "\n\tnhap thong tin Hang Hoa thu "<< i+1 <<" la :";
		fflush( stdin );
		goback:
		cout << "\nnhap Ma :";cin.getline(hh[i].ma_hang ,8);
		//Check ma hang hoa .
		for(int j = 0 ;j < i;j ++)
		{
			if( strcmpi(hh[i].ma_hang, hh[j].ma_hang)==0)
			{
				goto goback;
			}
		}
		cout << "\nnhap Ten :"; cin.getline(hh[i].ten_hang ,31);
		cout << "\nnhap So luong :"; cin >> hh[i].so_luong;
		cout << "\nnhap Don gia :"; cin >> hh[i].don_gia;
	}
}
float thanhTien(HangHoa hh)
{
	hh.thanh_tien = hh.so_luong * hh.don_gia ;
	return size_t( hh.thanh_tien);
}

void xuat(HangHoa hh)
{
	cout<< "\n";
		cout << setw(10) << hh.ma_hang
			<< setw(30) << hh.ten_hang
			<< setw(5) << hh.so_luong << "chiec"
			<< setw(8) << hh.don_gia 
			<< setw(10) << thanhTien( hh);
		cout << endl ;
}
void tieude()
{
	cout<< "\n";
		cout << setw(10) << "Ma hh"
			<< setw(30) << "Ten hh"
			<< setw(5) << "So luong "
			<< setw(8) << " Don gia" 
			<< setw(10) << "Thanh tien";
		cout << endl ;
}
void doc_file(HangHoa *hh, int &n)
{
	ifstream input;
	input.open("C:\\Users\\ACER\\OneDrive\\Desktop\\hanghoa.txt");
	input >> n;
	for (int i = 0 ;i < n ;i ++)
	{
		input >> hh[i].ma_hang;
		input >> hh[i].ten_hang;
	 	input >> hh[i].so_luong;
	 	input >> hh[i].don_gia;
	}
	cout << "\n Da doc xong file .";
	input.close();
}
void luu_file(HangHoa *hh ,int n)
{
	ofstream output;
	output.open("C:\\Users\\ACER\\OneDrive\\Desktop\\luuhanghoa.txt");
	output << "\n\tSo luong Hang Hoa La : " << n << "chiec ";
	output << "\n";
		output << setw(10) << "Ma hh"
			<< setw(30) << "Ten hh"
			<< setw(5) << "So luong "
			<< setw(8) << " Don gia" 
			<< setw(10) << "Thanh tien";
		output << endl ;
	for(int i = 0 ;i < n ;i ++)
	{
		output<< "\n";
		output << setw(10) << hh[i].ma_hang
			<< setw(30) << hh[i].ten_hang
			<< setw(5) << hh[i].so_luong << "chiec"
			<< setw(8) << hh[i].don_gia 
			<< setw(10) << thanhTien( hh[i]);
		output << endl ;
	}
	cout << "\n\tDa luu file vao 'luuhanghoa.txt' .";
	output.close();
}
int main()
{
	int n;
	HangHoa *hh = new HangHoa [n];
/*
do{
		cout << "\nnhap so luong Hang Hoa la :";
		cin>>n;
		if(n <= 0)cout << "\nNhap sai ";
	}while( n <= 0);
	
	hh = new HangHoa [n];
	nhap_HH( hh , n);
	cout << "\n danh sach da nhap la :";
	for(int i = 0 ;i < n ;i++)
	{
		xuat( hh[i]);
	}*/

	doc_file(hh , n);
	cout << "\n danh sach da nhap la :";
	tieude();
	for(int i = 0 ;i < n ;i++)
	{
		xuat( hh[i]);
	}
	cout << "\nthong tin mat hang co don gia > 50 :";
	tieude();
	for( int i =0 ;i < n ;i++)
	{
		if( hh[i].don_gia > 50 )
		{
			xuat(hh[i]);
		}
	}
	luu_file( hh ,n);
	delete[]hh;
	
	return 0;
}