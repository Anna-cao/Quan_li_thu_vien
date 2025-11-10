#include "../include/HoaDon.h"
#include"../include/Date.h"
#include"../include/DocGia.h"
#include <iomanip>
#include <algorithm>
using namespace std;

HoaDon::HoaDon() : phiQuaHan(0), tongPhi(0)  {}

HoaDon::HoaDon(string maHD, string maT, Date muon, Date tra, double phi, double tong)
    : maHoaDon(maHD), maThe(maT), ngMuon(muon), ngTraThucTe(tra), phiQuaHan(phi), tongPhi(tong) {
        status =1;
        tinhPhiQuaHan(NULL, ngTraThucTe);
    }

HoaDon::~HoaDon() {}

void HoaDon::tinhPhiQuaHan(const DocGia* dg, const Date& ngayTra) {
    if(status ==0) return;
    if(status ==1)
    {
        int soNgay = ngMuon.TinhSoNgay(ngayTra);
        int quahan = soNgay -14;
        int soTuan = 0;
    if (quahan > 0) {
        soTuan = (quahan + 6) / 7;  
    }
        double phi1Tuan = 10000;
        if(dg != NULL && dg->getLoaiDocGia()=="HoiVien"){
            phi1Tuan = 5000;
        }
        phiQuaHan = soTuan*phi1Tuan;
        tongPhi = phiQuaHan + tiencoc;
    }
}
void HoaDon::setDaTra(const Date& ngayTra)
{
    ngTraThucTe = ngayTra;
    status = 1;
}
void HoaDon::hienThiThongTin() const {
    cout << left << setw(8) << maHoaDon
         << setw(10) << maThe
         << setw(12); ngMuon.Xuat();
    cout << setw(12); ngTraThucTe.Xuat();
    cout << setw(10) << fixed << setprecision(0) << phiQuaHan
         << setw(10) << tongPhi << setw(8)<< status<<endl;
}

// int HoaDon::docFileHoaDon(HoaDon danhSach[], int soLuongToiDa, const string& duongDan) {
//     ifstream in(duongDan);
//     if (!in.is_open()) return 0;
//     int soLuong = 0;
//     while (!in.eof() && soLuong < soLuongToiDa) {
//         HoaDon hd;
//         hd.DocFile(in);
//         if (hd.getMaHoaDon().size() == 0) break;
//         danhSach[soLuong++] = hd;
//     }
//     in.close();
//     return soLuong;
// }

// void HoaDon::ghiFileHoaDon(const HoaDon danhSach[], int soLuong, const string& duongDan) {
//     ofstream out(duongDan);
//     if (!out.is_open()) return;
//     for (int i = 0; i < soLuong; ++i) {
//         const HoaDon &h = danhSach[i];
//         out << h.getMaHoaDon() << "\n";
//         out << h.getMaThe() << "\n";
//         Date d1 = h.getNgayMuon();
//         Date d2 = h.getNgayTraThucTe();
//         out << d1.getNgay() << " " << d1.getThang() << " " << d1.getNam() << " ";
//         out << d2.getNgay() << " " << d2.getThang() << " " << d2.getNam() << "\n";
//         out << h.getPhiQuaHan() << " " << h.getTongPhi() << "\n\n";
//     }
//     out.close();

// }