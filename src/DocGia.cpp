#include "../include/DocGia.h"
#include "../include/Date.h"
#include <iomanip>
#include <sstream>
using namespace std;

int DocGia::autoID = 1;

DocGia::DocGia() : soLuotMuon(0), theMuon(nullptr), status(1) {
    stringstream ss;
    ss << "DG" << setw(3) << setfill('0') << autoID++;
    maDocGia = ss.str();
    ngayLapThe = Date::HomNay();
}

DocGia::DocGia(string ten, string loai) : hoTen(ten), soLuotMuon(0), status(1) {
    stringstream ss;
    ss << "DG" << setw(3) << setfill('0') << autoID++;
    maDocGia = ss.str();
    ngayLapThe = Date::HomNay();
    theMuon = new TheMuon(loai, ngayLapThe);
}
DocGia::DocGia(string ma, string ten, int soLuotMuon)
    : maDocGia(ma), hoTen(ten), soLuotMuon(soLuotMuon), status(1)
{
    ngayLapThe = Date::HomNay();
    theMuon = nullptr;   
}
DocGia::~DocGia() {
    delete theMuon;
}

void DocGia::nhap() {
    cout << "Ho ten: "; getline(cin, hoTen);
    cout << "SDT: "; cin >> sdt; cin.ignore();
    cout << "Email: "; getline(cin, email);
    cout << "Dia chi: "; getline(cin, diachi);

    string loai;
    do {
        cout << "Loai the (Thuong/HoiVien): "; 
        getline(cin, loai);
        if (loai != "Doc Gia Thuong" && loai != "HoiVien") {
            cout << "Loai the khong hop le! Vui long nhap lai.\n";
        }
    } while (loai != "Doc Gia Thuong" && loai != "HoiVien");
    delete theMuon;
    theMuon = new TheMuon(loai, Date::HomNay());
}

void DocGia::hienThiThongTin() const {
    if (status == 0) return; 
    cout << left << setw(6) << maDocGia
         << setw(20) << hoTen
         << setw(15) << sdt
         << setw(25) << email
         << setw(20) << diachi;
    ngayLapThe.Xuat();
    cout << " | ";
    if (theMuon) theMuon->hienThi();
    else cout << "Chua co the";
    cout << endl;
}

void DocGia::hienThiDong() const {
    if (status == 0) return;
    hienThiThongTin();
}
void DocGia::hienThiTieuDe() {
    cout << left << setw(6) << "Ma DG"
         << setw(20) << "Ho Ten"
         << setw(15) << "SDT"
         << setw(25) << "Email"
         << setw(20) << "Dia chi"
         << "Ngay lap the     | Thong tin the\n";
    cout << string(100, '-') << endl;
}

bool DocGia::kiemTraNgayHopLe(const Date& d) {
    return d.HopLe() && d >= Date(1, 1, 2006) && d <= Date::HomNay();
}
