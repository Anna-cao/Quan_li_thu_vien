#include "../include/DocGia.h"
#include "../include/Date.h"

#include <iomanip>
#include <sstream>
using namespace std;
int DocGia::autoID = 1;

DocGia::DocGia() : soLuotMuon(0), theMuon() {
    stringstream ss;
    ss << "DG" << setw(3) << setfill('0') << autoID++;
    maDocGia = ss.str();
}

DocGia::DocGia(string ten, string loai) : hoTen(ten), theMuon(loai, Date::HomNay()), soLuotMuon(0) {
    stringstream ss;
    ss << "DG" << setw(3) << setfill('0') << autoID++;
    maDocGia = ss.str();
    ngayLapThe = Date::HomNay();
}

void DocGia::Nhap() {
    cout << "Ho ten: "; getline(cin, hoTen);
    cout << "SDT: "; cin >> sdt; cin.ignore();
    cout << "Email: "; getline(cin, email);
    cout << "Dia chi: "; getline(cin, diachi);

    string loai;
    cout << "Loai the (Thuong/HoiVien): "; cin >> loai; cin.ignore();
    theMuon.setLoaiThe(loai);
    theMuon.setNgayLap(Date::HomNay());
}

// ===== Xuất thông tin =====
void DocGia::Xuat() const {
    cout << left << setw(6) << maDocGia
         << setw(20) << hoTen
         << setw(15) << sdt
         << setw(25) << email
         << setw(20) << diachi;
    ngayLapThe.Xuat();
    cout << " | ";
    theMuon.hienThi();
}

void DocGia::docFileDocGia(istream& in) {
    in >> maDocGia;
    in.ignore();
    getline(in, hoTen);
    in >> sdt >> email;
    in.ignore();
    getline(in, diachi);
    ngayLapThe.doc(in);
    in >> soLuotMuon;
    theMuon.docFile(in);
}

void DocGia::ghiFileDocGia(ostream& out) const {
    out << maDocGia << endl
        << hoTen << endl
        << sdt << " " << email << endl
        << diachi << endl;
    ngayLapThe.ghi(out);
    out << " " << soLuotMuon << endl;
    theMuon.ghiFile(out);
}