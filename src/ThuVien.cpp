#include "../include/ThuVien.h"
#include <iostream>
using namespace std;

ThuVien::ThuVien() {
    n = 0;
    soDocGia =0;
    soHoaDon =0;
}
ThuVien::~ThuVien() {
    for (int i = 0; i < soDocGia; i++) {
        delete danhSachDocGia[i];
    }
}
//SACH
void ThuVien::themSach() {
    if (n >= Max_sach) {
        cout << "Thu vien da day, khong the them sach moi!" << endl;
        return;
    }
    Sach s;
    s.nhap();
    danhSach[n++] = s;
    cout << "Da them sach thanh cong!" << endl;
}
void ThuVien::hienThi() {
    if (n == 0) {
        cout << "Thu vien trong!" << endl;
        return;
    }
    cout << "\n----- DANH SACH SACH TRONG THU VIEN -----\n";
    for (int i = 0; i < n; i++) {
        cout << "\nThong tin cua sach thu " << i + 1 << "la:" << endl;
        danhSach[i].hienThiThongTin();
    }
}
void ThuVien::timTheoTen(string ten) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (danhSach[i].getTenSach() == ten)
        {
            danhSach[i].hienThiThongTin();
            found = true;
        }
    }
    if (found==false) cout << "Khong tim thay sach co ten \"" << ten << "\"" << endl;
}

void ThuVien::suaSachTheoMa(string ma) 
{
    bool found = false;
    for (int i = 0; i < n; i++) 
    {
        if (danhSach[i].getMaSach() == ma) 
        {
            cout << "Nhap lai thong tin sach: " << endl;
            danhSach[i].nhap();
            cout << "Da sua thanh cong!" << endl;
            found = true;
            break;
        }
    }
    if (found==false)
        cout << "Khong tim thay thong tin sach co ma: "<<ma <<endl;
}
void ThuVien::xoaSachTheoMa(string ma) 
{
    bool found = false;
    for (int i = 0; i < n; i++) 
    {
        if (danhSach[i].getMaSach() == ma)
        {
            for (int j = i; j < n - 1; j++) 
            {
                danhSach[j] = danhSach[j + 1];
            }
            n--;
            cout << "Da xoa sach co ma " << ma << endl;
            found = true;
            break;
        }
    }
    if (found==false)
        cout << "Khong tim thay sach co ma: "<<ma<<endl;
}
// DOCGIA
bool ThuVien::themDocGia(DocGia* dg) 
{
    for (int i =0; i<n; i++)
    {
        if(dg == danhSachDocGia[i])
        {
            cout <<"Doc gia da ton tai trong danh sach"<<endl;
        }
    }
    if (soDocGia >= Max_docgia) 
    {
        cout << "Danh sach doc gia da day!\n";
        delete dg;
        return false;
    }
    danhSachDocGia[soDocGia++] = dg;
    cout << "Them doc gia: " << dg->getHoTen() << "\n";
    return true;
}
void ThuVien::hienThiDanhSachDocGia() const 
{
    if (soDocGia == 0)
    {
        cout << "Chua co doc gia nao!"<<endl;
        return;
    }
    cout << "\n-----DANH SACH DOC GIA -----\n";
    for (int i = 0; i < soDocGia; ++i) {
        cout << "\nThong tin doc gia thu " << i + 1 << " la\n";
        danhSachDocGia[i]->hienThiThongTin();
    }
}
DocGia* ThuVien::timDocGiaTheoMa(const string& ma) const 
{
    for (int i = 0; i < soDocGia; ++i)
        if (danhSachDocGia[i]->getMaDocGia() == ma) return danhSachDocGia[i];
    return nullptr;
}
void ThuVien::capNhatTheMuonChoDocGia(const string& maDocGia, TheMuon* the) {
    DocGia* dg = timDocGiaTheoMa(maDocGia);
    if (dg) {
        dg->setTheMuon(the);
        cout << "Cap nhat the muon cho doc gia " << maDocGia << "\n";
    } else {
        cout << "Khong tim thay doc gia " << maDocGia << "\n";
        delete the;               
    }
}
//HOA DON
void ThuVien::themHoaDon(const HoaDon& hd) {
    if (soHoaDon >= Max_hoadon) {
        cout << "Danh sach hoa don da day!" << endl;
        return;
    }
    danhSachHoaDon[soHoaDon++] = hd;
    cout << "Them hoa don thanh cong!" << endl;
}

void ThuVien::hienThiDanhSachHoaDon() const {
    if (soHoaDon == 0) {
        cout << "Chua co hoa don nao!" << endl;
        return;
    }
    cout << "\n----- DANH SACH HOA DON -----\n";
    for (int i = 0; i < soHoaDon; ++i) {
        cout << "\n--- Hoa don " << i + 1 << " ---\n";
        danhSachHoaDon[i].hienThiThongTin();
    }
}

void ThuVien::tinhTienPhatQuaHan(const string& maDocGia, const Date& ngayHienTai) {
    DocGia* dg = timDocGiaTheoMa(maDocGia);
    if (!dg) {
        cout << "Khong tim thay doc gia!" << endl;
        return;
    }

    double tongPhat = 0.0;
    const double phatMoiNgay = 1000.0;  

    for (int i = 0; i < soHoaDon; ++i) {
        if (danhSachHoaDon[i].getMaThe() == dg->getTheMuon()->getMaThe()) {
            Date ngTraDuKien = danhSachHoaDon[i].getNgMuon();
            ngTraDuKien.congNgay(14);  

            if (ngayHienTai > ngTraDuKien) {
                int ngayQuaHan = ngayHienTai - ngTraDuKien;
                tongPhat += ngayQuaHan * phatMoiNgay;
            }
        }
    }
    cout << "Tong tien phat qua han cho doc gia " << maDocGia << ": " << tongPhat << " VND" << endl;
}
// QL NXB
ThuVien::ThuVien() 
{
    n = 0;
    soDocGia = 0;
    soHoaDon = 0;
    soNXB = 0;  
    for (int i = 0; i < 100; ++i) {
        danhSachNXB[i] = nullptr;
    }
}
ThuVien::~ThuVien() {
    for (int i = 0; i < soDocGia; i++) {
        delete danhSachDocGia[i];
    }
    for (int i = 0; i < soNXB; i++) {
        delete danhSachNXB[i];  
    }
}
bool ThuVien::themNXB(const string& tenNXB) {
    if (soNXB >= 100) {
        cout << "Danh sach nha xuat ban da day!" << endl;
        return false;
    }

    if (timNXBTheoTen(tenNXB) != nullptr) {
        cout << "Nha xuat ban '" << tenNXB << "' da ton tai!" << endl;
        return false;
    }

    danhSachNXB[soNXB++] = new NhaXuatBan(tenNXB);
    cout << "Them nha xuat ban '" << tenNXB << "' thanh cong!" << endl;
    return true;
}

void ThuVien::hienThiDanhSachNXB() const {
    if (soNXB == 0)
    {
        cout << "Chua co nha xuat ban nao!" << endl;
        return;
    }
    cout << "\n===== DANH SACH NHA XUAT BAN =====\n";
    for (int i = 0; i < soNXB; ++i) {
        cout << "\nNXB thu " << i + 1 << ":\n";
        danhSachNXB[i]->hienThiDSNXB();
    }
}

NhaXuatBan* ThuVien::timNXBTheoTen(const string& tenNXB) const {
    for (int i = 0; i < soNXB; ++i) {
        if (danhSachNXB[i]->getNXB() == tenNXB) {
            return danhSachNXB[i];
        }
    }
    return nullptr;
}
// TK
void ThuVien::thongKeSachTheoNXB() const {
    if (soNXB == 0) {
        cout << "Khong co nha xuat ban nao de thong ke!" << endl;
        return;
    }

    cout << "\n===== THONG KE SACH THEO NHA XUAT BAN =====\n";
    for (int i = 0; i < soNXB; ++i) {
        const vector<string>& dsSach = danhSachNXB[i]->getSoSachXB();
        cout << "NXB: " << danhSachNXB[i]->getNXB()
             << " | So luong sach: " << dsSach.size() << endl;
    }
}
void ThuVien::thongKeMuonTra(const Date &ngayHienTai) const {
    if (soHoaDon == 0) {
        cout << "Chua co hoa don nao!\n";
        return;
    }

    int countBorrowed = 0;
    int countReturned = 0;
    int countOverDue = 0;

    const int hanMuon = 14;

    for (int i = 0; i < soHoaDon; i++) {
        const HoaDon &hd = danhSachHoaDon[i];

        if (hd.getNgayTraThucTe().HopLe()) {
            countReturned++;
        } 
        else {
            countBorrowed++;

            Date due = hd.getNgayMuon();
            due.congNgay(hanMuon);

            if (due < ngayHienTai) {
                countOverDue++;
            }
        }
    }

    cout << "\n===== THONG KE MUON / TRA =====\n";
    cout << "Tong hoa don: " << soHoaDon << "\n";
    cout << "Da tra: " << countReturned << "\n";
    cout << "Dang muon: " << countBorrowed << "\n";
    cout << "Qua han: " << countOverDue << "\n";
    cout << "================================\n";
}


