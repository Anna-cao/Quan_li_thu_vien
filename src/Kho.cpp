#include <iostream>
#include <string>
#include<vector>
using namespace std;
#include "../include/Kho.h"
#include "../include/NhaXuatBan.h"
#include"../include/Sach.h"
#include "../include/ThuVien.h"

void Kho:: HienThiKho() const
{
    cout <<"-----THONG TIN TRONG KHO-----"<<endl;
    cout << "Tong sach trong: " << soLuongTong << endl;
    cout << "So luong sach da muon: " << soLuongDaMuon << endl;
    cout << "So luong sach con lai: " << soSachConLai() << endl;
    cout << "Danh sach nha xuat ban: "<<endl;
    if(soNXB ==0) cout <<"Khong co nha xuat ban nao";
    else
    {
        for(int i =0; i<soNXB; i++)
        {
            cout << i+1 <<". "<< danhSachNXB[i]->getNXB()<<endl;
        }
    }
    
}