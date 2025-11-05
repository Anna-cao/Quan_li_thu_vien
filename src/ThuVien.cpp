#include "../include/ThuVien.h"
#include <iostream>
using namespace std;

// ===================== CONSTRUCTOR / DESTRUCTOR =====================

ThuVien::ThuVien() {
    n = 0;
    soDocGia = 0;
    soHoaDon = 0;
    soNXB = 0;

    for (int i = 0; i < 100; ++i) {
        danhSachNXB[i] = nullptr;
    }
    docFileSach();
    docFileDocGia();
    docFileHoaDon();
    docFileNXB();
    docFileTheMuon();
}

ThuVien::~ThuVien() {
    ghiFileSach();
    ghiFileDocGia();
    ghiFileHoaDon();
    ghiFileNXB();
    ghiFileTheMuon();
    for (int i = 0; i < soDocGia; i++) {
        delete danhSachDocGia[i];
    }
    for (int i = 0; i < soNXB; i++) {
        delete danhSachNXB[i];
    }
}

// ===================== QUẢN LÝ SÁCH =====================

void ThuVien::themSach() {
    if (n >= Max_sach) {
        cout << "Thu vien da day, khong the them sach moi!" <<endl;
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
        cout << "\nThong tin cua sach thu " << i + 1 << " la:" << endl;
        danhSach[i].hienThiThongTin();
    }
}

void ThuVien::timTheoTen(string ten) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (danhSach[i].getTenSach() == ten) {
            danhSach[i].hienThiThongTin();
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay sach co ten \"" << ten << "\"" << endl;
}

void ThuVien::suaSachTheoMa(string ma) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (danhSach[i].getMaSach() == ma) {
            cout << "Nhap lai thong tin sach: " << endl;
            danhSach[i].nhap();
            cout << "Da sua thanh cong!" << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Khong tim thay thong tin sach co ma: " << ma << endl;
}

void ThuVien::xoaSachTheoMa(string ma) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (danhSach[i].getMaSach() == ma) {
            for (int j = i; j < n - 1; j++) {
                danhSach[j] = danhSach[j + 1];
            }
            n--;
            cout << "Da xoa sach co ma " << ma << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Khong tim thay sach co ma: " << ma << endl;
}

// ===================== QUẢN LÝ ĐỘC GIẢ =====================

bool ThuVien::themDocGia(DocGia* dg) {
    for (int i = 0; i < soDocGia; i++) {
        if (dg == danhSachDocGia[i]) {
            cout << "Doc gia da ton tai trong danh sach" << endl;
            return false;
        }
    }

    if (soDocGia >= Max_docgia) {
        cout << "Danh sach doc gia da day!\n";
        delete dg;
        return false;
    }

    danhSachDocGia[soDocGia++] = dg;
    cout << "Them doc gia: " << dg->getHoTen() << "\n";
    return true;
}

void ThuVien::hienThiDanhSachDocGia() const {
    if (soDocGia == 0) {
        cout << "Chua co doc gia nao!" << endl;
        return;
    }
    cout << "\n----- DANH SACH DOC GIA -----\n";
    for (int i = 0; i < soDocGia; ++i) {
        cout << "\nThong tin doc gia thu " << i + 1 << " la\n";
        danhSachDocGia[i]->hienThiThongTin();
    }
}

DocGia* ThuVien::timDocGiaTheoMa(const string& ma) const {
    for (int i = 0; i < soDocGia; ++i)
        if (danhSachDocGia[i]->getMaDocGia() == ma)
            return danhSachDocGia[i];
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

// ===================== QUẢN LÝ HÓA ĐƠN =====================

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
    cout << "Tong tien phat qua han cho doc gia " << maDocGia
         << ": " << tongPhat << " VND" << endl;
}

// ===================== QUẢN LÝ NHÀ XUẤT BẢN =====================

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
    if (soNXB == 0) {
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
        if (danhSachNXB[i]->getNXB() == tenNXB)
            return danhSachNXB[i];
    }
    return nullptr;
}
// ===================== ĐỌC / GHI FILE =====================
#include <fstream>
#include <sstream>

// Tên file cố định
const string FILE_SACH = "data/sach.txt";
const string FILE_DOCGIA = "data/docgia.txt";
const string FILE_HOADON = "data/hoadon.txt";
const string FILE_NXB = "data/nhaxuatban.txt";
const string FILE_THEMUON = "data/themuon.txt";

void ThuVien::ghiFileSach() const {
    ofstream out(FILE_SACH);
    for (int i = 0; i < n; ++i)
        danhSach[i].ghiFile(out);
    out.close();
    cout << "Da ghi " << n << " sach vao " << FILE_SACH << endl;
}

void ThuVien::docFileSach() {
    ifstream in(FILE_SACH);
    n = 0;
    while (n < Max_sach && danhSach[n].docFile(in))
        n++;
    in.close();
    cout << "Da doc " << n << " sach tu " << FILE_SACH << endl;
}

void ThuVien::ghiFileDocGia() const {
    ofstream out(FILE_DOCGIA);
    for (int i = 0; i < soDocGia; ++i)
        danhSachDocGia[i]->ghiFile(out);
    out.close();
    cout << "Da ghi " << soDocGia << " doc gia vao " << FILE_DOCGIA << endl;
}

void ThuVien::docFileDocGia() {
    ifstream in(FILE_DOCGIA);
    soDocGia = 0;
    while (soDocGia < Max_docgia) {
        DocGia* dg = new DocGiaThuong();
        if (!dg->docFile(in)) {
            delete dg;
            break;
        }
        danhSachDocGia[soDocGia++] = dg;
    }
    in.close();
    cout << "Da doc " << soDocGia << " doc gia tu " << FILE_DOCGIA << endl;
}

void ThuVien::ghiFileHoaDon() const {
    ofstream out(FILE_HOADON);
    for (int i = 0; i < soHoaDon; ++i)
        danhSachHoaDon[i].ghiFile(out);
    out.close();
    cout << "Da ghi " << soHoaDon << " hoa don vao " << FILE_HOADON << endl;
}

void ThuVien::docFileHoaDon() {
    ifstream in(FILE_HOADON);
    soHoaDon = 0;
    while (soHoaDon < Max_hoadon && danhSachHoaDon[soHoaDon].docFile(in))
        soHoaDon++;
    in.close();
    cout << "Da doc " << soHoaDon << " hoa don tu " << FILE_HOADON << endl;
}

void ThuVien::ghiFileNXB() const {
    ofstream out(FILE_NXB);
    for (int i = 0; i < soNXB; ++i)
        danhSachNXB[i]->ghiFile(out);
    out.close();
    cout << "Da ghi " << soNXB << " nha xuat ban vao " << FILE_NXB << endl;
}

void ThuVien::docFileNXB() {
    ifstream in(FILE_NXB);
    soNXB = 0;
    while (!in.eof()) {
        string ten;
        getline(in, ten);
        if (!ten.empty())
            danhSachNXB[soNXB++] = new NhaXuatBan(ten);
    }
    in.close();
    cout << "Da doc " << soNXB << " nha xuat ban tu " << FILE_NXB << endl;
}

void ThuVien::ghiFileTheMuon() const {
    ofstream out(FILE_THEMUON);
    for (int i = 0; i < soDocGia; ++i)
        if (danhSachDocGia[i]->getTheMuon())
            danhSachDocGia[i]->getTheMuon()->ghiFile(out);
    out.close();
    cout << "Da ghi file the muon vao " << FILE_THEMUON << endl;
}

void ThuVien::docFileTheMuon() {
    ifstream in(FILE_THEMUON);
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string maThe, maDG;
        getline(ss, maThe, ',');
        getline(ss, maDG, ',');
        TheMuon* tm = new TheMuon(maThe, maDG, Date(), Date(), 0, true);
        DocGia* dg = timDocGiaTheoMa(maDG);
        if (dg) dg->setTheMuon(tm);
    }
    in.close();
    cout << "Da doc the muon tu " << FILE_THEMUON << endl;
}

// ===================== THỐNG KÊ =====================

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

void ThuVien::thongKeMuonTra(const Date& ngayHienTai) const {
    if (soHoaDon == 0) {
        cout << "Chua co hoa don nao!\n";
        return;
    }

    int countBorrowed = 0, countReturned = 0, countOverDue = 0;
    const int hanMuon = 14;

    for (int i = 0; i < soHoaDon; i++) {
        const HoaDon& hd = danhSachHoaDon[i];
        if (hd.getNgayTraThucTe().HopLe()) {
            countReturned++;
        } else {
            countBorrowed++;
            Date due = hd.getNgayMuon();
            due.congNgay(hanMuon);
            if (due < ngayHienTai) countOverDue++;
        }
    }

    cout << "\n===== THONG KE MUON / TRA =====\n";
    cout << "Tong hoa don: " << soHoaDon << "\n";
    cout << "Da tra: " << countReturned << "\n";
    cout << "Dang muon: " << countBorrowed << "\n";
    cout << "Qua han: " << countOverDue << "\n";
    cout << "================================\n";
}
