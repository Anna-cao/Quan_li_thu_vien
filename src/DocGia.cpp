#include "DocGia.h"
#include <iomanip>
#include <iostream>
using namespace std;


void DocGia::ghiFileDocGia(const DocGia ds[], int soLuong, const string& path) {
    ofstream out(path);
    if (!out.is_open()) return;

    out << soLuong << "\n";
    for (int i = 0; i < soLuong; i++) {
        out << ds[i].maDocGia << "\n";
        out << ds[i].hoTen << "\n";
        out << ds[i].sdt << "\n";
        out << ds[i].email << "\n";
        out << ds[i].diachi << "\n";

        ds[i].ngayLapThe.ghiFile(out);

        const auto& v = ds[i].dsMaSachDangMuon;
        out << v.size() << "\n";
        for (auto& s : v) out << s << "\n";

        out << "\n";
    }
}


void DocGia::hienThiTieuDe() {
    cout << left
         << setw(8) << "MaDG"
         << setw(20) << "Ho Ten"
         << setw(15) << "SDT"
         << setw(25) << "Email"
         << setw(15) << "TrangThai"
         << setw(10) << "LuotMuon"
         << endl;

    cout << string(93, '-') << endl;
}

void DocGia::hienThiDong() const {
    cout << left
         << setw(8)  << maDocGia
         << setw(20) << hoTen
         << setw(15) << sdt
         << setw(25) << email;

    if (theMuon != nullptr) {
        string st = theMuon->getStatus();

        
        if (st == "Hoáº¡t Ä‘á»™ng" || st == "Hoat dong")
            cout << setw(15) << "CÃ²n háº¡n";
        else if (st == "Háº¿t háº¡n" || st == "Het han")
            cout << setw(15) << "Háº¿t háº¡n";
        else
            cout << setw(15) << st; 
    } else {
        cout << setw(15) << "ChÆ°a cÃ³ tháº»";
    }

    cout << setw(10) << soLuotMuon << endl;
}
