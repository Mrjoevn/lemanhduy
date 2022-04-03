#include <iostream.h>
using namespace std;

struct SoPhuc
{
	int phanthuc , phanao ;	
};
void xuat_SP(SoPhuc &sp)
{
	if(sp.phanthuc == 0)
	{
		cout << sp.phanao<<"*j ";
	}
		else{
			if( sp.phanao == 0)
			{
				cout << sp.phanthuc ;
			}
			else if( sp.phanao < 0)
			{
				cout << sp.phanthuc << " " << sp.phanao << " *j"; 	
			}
			else {
				cout << sp.phanthuc << " + "<<sp.phanao << " *j";
			}
	}
}
SoPhuc tong(SoPhuc &sp1 , SoPhuc &sp2)
{
	SoPhuc tong;
	tong.phanthuc = sp1.phanthuc + sp2.phanthuc ;
	tong.phanao = sp1.phanao + sp2.phanao ;
	return tong;
}
SoPhuc hieu(SoPhuc &sp1 , SoPhuc &sp2)
{
	SoPhuc hieu;
	hieu.phanthuc = sp1.phanthuc - sp2.phanthuc ;
	hieu.phanao = sp1.phanao - sp2.phanao ;
	return hieu;
}
int main()
{
	SoPhuc sp1;
	SoPhuc sp2;
	cout << "\n\tNhap so Phuc thu nhat la :";	
	cout << "\n Nhap phan thuc :" ; cin>>sp1.phanthuc;
	cout << "\n Nhap phan ao :" ; cin>>sp1.phanao;
	cout << "\n\tNhap so Phuc thu hai la :";
	cout << "\n Nhap phan thuc :" ; cin>>sp2.phanthuc;
	cout << "\n Nhap phan ao :" ; cin>>sp2.phanao;
	cout<<"\n\tSo phuc thu nhat la :";
	xuat_SP(sp1);
	cout<<"\n\tSo phuc thu hai la :";
	xuat_SP(sp2);
	cout<<"\n\tTong cau Hai so phuc la :";
	SoPhuc sp3 = tong(sp1 ,sp2);
	xuat_SP(sp3);
	cout<<"\n\tHieu cau Hai so phuc la :";
	SoPhuc sp4 = hieu(sp1 ,sp2);
	xuat_SP(sp4);
	return 0;
}