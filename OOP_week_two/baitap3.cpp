#include<iostream.h>
using namespace std;
class DaThuc3
{
	private:
	int hs_bac3 , hs_bac2 , hs_bac1 , hs_bac0;
	public:
	DaThuc3(int bac3 = 0 ,int bac2 = 0 , int bac1 = 0 , int bac0 = 0)
	{
		this->hs_bac3 = bac3;
		this->hs_bac2 = bac2;
		this->hs_bac1 = bac1;
		this->hs_bac0 = bac0;
	}
	~DaThuc3(){}
	void HienThi()
	{
		if(hs_bac3 == 0)
		{
			cout << hs_bac2 << "X^2 + " << hs_bac1 << "X + " <<hs_bac0;
		}
		else{
			if(hs_bac2 == 0)
			{
				cout << hs_bac3 << "X^3" << " + " << hs_bac1 << "X + " << hs_bac0;
			}
			else if( hs_bac1 == 0)
			{
				cout << hs_bac3 << "X^3 + " << hs_bac2 <<"X^2 + " << hs_bac0;
			}
			else{
				cout << hs_bac3 << "X^3 + " << hs_bac2 << "X^2 + " << hs_bac1 << "X + " <<hs_bac0;
			}
		}
	}
	void Nhap()
	{
		cout << "\nNhap bac 3 :"; cin >> hs_bac3;
		cout << "\nNhap bac 2 :"; cin >> hs_bac2;
		cout << "\nNhap bac 1 :"; cin >> hs_bac1;
		cout << "\nNhap hang so :"; cin >> hs_bac0;
	}
	DaThuc3 tong(DaThuc3 dt)
	{
		DaThuc3 s;
		s.hs_bac3 = this->hs_bac3 + dt.hs_bac3;
		s.hs_bac2 = this->hs_bac2 + dt.hs_bac2;
		s.hs_bac1 = this->hs_bac1 + dt.hs_bac1;
		s.hs_bac0 = this->hs_bac0 + dt.hs_bac0;
		return s;
	}
};
int main()
{
	DaThuc3 dt1;
	cout << "\n\t Nhap Da Thuc thu 1 :";
	dt1.Nhap();
	cout << "\n\tDa thuc thu nhat :";
	dt1.HienThi();
	cout << "\n\t Nhap Da Thuc thu 2 :";
	DaThuc3 dt2;
	dt2.Nhap();
	cout << "\n\tDa thuc thu hai :";
	dt2.HienThi();
	DaThuc3 result;
	result = dt1.tong(dt2);
	cout << "\nTong cua hai Da thuc :";
	result.HienThi();
	return 0;
}