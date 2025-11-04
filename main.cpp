#include <iostream>
#include "../include/ThuVien.h"
#include "../include/NhaXuatBan.h"

using namespace std;

int main() {
    ThuVien thuVien;
    int chon;
    do {
        cout << "\n--- MENU QUAN LY THU VIEN ---\n";
        cout << "1. Quan li sach" <<endl;
        cout << "2. Quan li khach hang" <<endl;
        cout << "3. Quan li hoa don" <<endl;
        cout <<"4. Quan li nha cung cap"<<endl;
        cout <<"5. Thong ke"<<endl;
        cout <<"6. Thoat"<<endl;
        cout <<"-----Moi nhap lua chon cua ban-----"<<endl;
        cin >> chon;
        cin.ignore();
        switch (chon)
        {
        case 1: 
            {
            int chon1;
            do
            {
                cout<<"-----Quan li sach-----"<<endl;
                cout <<"1.Hien thi thong tin quan li sach"<<endl;
                cout <<"2.Them sach"<<endl;
                cout <<"3.Tim sach theo ten"<<endl;
                cout <<"4. Sua sach theo ma"<<endl;
                cout <<"5.Xoa sach theo ma"<<endl;
                cout <<"6.Thoat"<<endl;
                cout <<"=====MOI NHAP LUA CHON====="<<endl;
                cin >>chon1;
                cin.ignore();      

                switch (chon1) 
                {
                    case 1: thuVien.hienThi(); break;
                    case 2: thuVien.themSach(); break;
                    case 3: 
                    {
                        string ten;
                        cout <<"Nhap danh sach ten sach can tim: " ;
                        getline(cin, ten);
                        thuVien.timTheoTen(ten);
                        break;
                    }
                    case 4: 
                    {
                        string Ma;
                        cout << "Nhap ma sach can sua: ";
                        getline(cin,Ma);
                        thuVien.suaSachTheoMa(Ma);
                        break;
                    }
                    case 5:
                    {
                        string Ma;
                        cout << "Nhap ma sach can xoa: ";
                        getline(cin, Ma);
                        thuVien.xoaSachTheoMa(Ma);
                        break;
                    } 
                    case 6: cout <<"Quay lai chuong trinh chinh"; break;
                    default: cout <<"Lua chon khong hop le!"<<endl;
                }
            }
                while(chon1 != 6);
                break;
            }
        case 2:
            {
            int chon2;
            do
            {
                cout<<"-----Quan li khach hang-----"<<endl;
                cout <<"1.Them doc gia"<<endl;
                cout <<"2.Hien thi danh sach doc gia"<<endl;
                cout <<"3.Tim doc gia theo ma"<<endl;
                cout <<"4. Cap nhap the muon cho doc gia "<<endl;
                cout <<"5.Thoat"<<endl;
                cout <<"=====MOI NHAP LUA CHON====="<<endl;
                cin >>chon2;
                cin.ignore();      
                switch (chon2) 
                {
                    case 1: {
                            int loai;
                            cout << "Loai (1: Thuong, 2: Hoi vien): "; cin >> loai; cin.ignore();
                            DocGia* dg = nullptr;
                            if (loai == 1) dg = new DocGiaThuong();
                            else if (loai == 2) dg = new HoiVien();
                            else { cout << "Sai!\n"; break; }
                            cout << "Nhap thong tin:\n";
                            dg->nhap(); 
                            thuVien.themDocGia(dg);
                            break;
                        }
                    case 2: thuVien.hienThiDanhSachDocGia(); break;
                    case 3: 
                    {
                        string ma; cout << "Ma doc gia la: "; 
                        getline(cin,ma);
                        DocGia* dg = thuVien.timDocGiaTheoMa(ma);
                        if (dg) dg->hienThiThongTin();
                        else cout << "Khong tim thay doc gia!\n";
                        break;
                    }
                    case 4:
                     thuVien.capNhatTheMuonChoDocGia(); break;
                    case 5: cout <<"Quay lai chuong trinh chinh"; break;
                    default: cout <<"Lua chon khong hop le!"<<endl;
                }
            }
                while(chon2 != 5);
                break;
            }

        case 3:
            {
            int chon3;
            do
            {
                cout<<"-----Quan li khach hang-----"<<endl;
                cout <<"1.Them hoa don"<<endl;
                cout <<"2.Hien thi danh sach hoa don"<<endl;
                cout <<"3.Thoat"<<endl;
                cout <<"=====MOI NHAP LUA CHON====="<<endl;
                cin >>chon3;
                cin.ignore();      
                switch (chon3) 
                {
                    case 1: thuVien.themHoaDon(); break;
                    case 2: thuVien.hienThiDanhSachHoaDon(); break;
                    case 3: cout <<"Quay lai chuong trinh chinh"; break;
                    default: cout <<"Lua chon khong hop le!"<<endl;
                }
            }
                while(chon3 != 3)
            }

        case 4:
            {
            int chon4;
            do
            {
                cout<<"-----Quan li nha cung cap-----"<<endl;
                cout <<"1.Them nha xuat ban"<<endl;
                cout <<"2.Hien thi danh sach nha xuat ban"<<endl;
                cout <<"3.Tim doc nha xuat ban theo ten"<<endl;
                cout <<"4.Thoat"<<endl;
                cout <<"=====MOI NHAP LUA CHON====="<<endl;
                cin >>chon4;
                cin.ignore();      
                switch (chon4) 
                {
                    case 1: thuVien.themNXB(); break;
                    case 2: thuVien.hienThiDanhSachNXB(); break;
                    case 3: thuVien.timNXBTheoTen() ; break;
                    case 3: cout <<"Quay lai chuong trinh chinh"; break;
                    default: cout <<"Lua chon khong hop le!"<<endl;
                }
            }
                while(chon4 != 3)
            }
        case 5: 
        {
            int chon5;
            do
            {
                cout<<"-----Quan li nha cung cap-----"<<endl;
                cout <<"1.Them nha xuat ban"<<endl;
                cout <<"2.Hien thi danh sach nha xuat ban"<<endl;
                cout <<"3.Tim doc nha xuat ban theo ten"<<endl;
                cout <<"4.Thoat"<<endl;
                cout <<"=====MOI NHAP LUA CHON====="<<endl;
                cin >>chon5;
                cin.ignore();      
                switch (chon5) 
                {
                    case 1: thuVien.themNXB(); break;
                    case 2: thuVien.hienThiDanhSachNXB(); break;
                    case 3: thuVien.timNXBTheoTen() ; break;
                    case 4: cout <<"Quay lai chuong trinh chinh"; break;
                    default: cout <<"Lua chon khong hop le!"<<endl;
                }
            }
                while(chon5 != 4)
            }



    while()
