#include "../include/DocGia.h"
#include "../include/Date.h"
#include "../include/HoiVien.h"    
#include "../include/DocGiaThuong.h"
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
void DocGia::docFile(istream& in) {
    getline(in, maDocGia);
    getline(in, hoTen);
    getline(in, sdt);
    getline(in, email);
    getline(in, diachi);

    int d, m, y;
    in >> d >> m >> y; in.ignore();
    ngayLapThe = Date(d, m, y);

    in >> status; in.ignore();
    string line;
    getline(in, line);
    stringstream ss(line);
    dsMaSachDangMuon.clear();
    string ma;
    while (ss >> ma) dsMaSachDangMuon.push_back(ma);
}

void DocGia::ghiFile(ostream& out) const {
    out << maDocGia << "\n"
        << hoTen << "\n"
        << sdt << "\n"
        << email << "\n"
        << diachi << "\n"
        << ngayLapThe.getNgay() << " " << ngayLapThe.getThang() << " " << ngayLapThe.getNam() << "\n"
        << getLoaiDocGia() << "\n"
        << status << "\n";
    for (size_t i = 0; i < dsMaSachDangMuon.size(); ++i) {
        out << dsMaSachDangMuon[i] << (i < dsMaSachDangMuon.size()-1 ? " " : "\n");
    }
}
int DocGia::docFileDocGia(DocGia* ds[], int max, const string& file) {
    ifstream in(file);
    if (!in.is_open()) {
        cout << "LOI: Khong mo duoc file doc gia: " << file << endl;
        return 0;
    }

    int n = 0;
    string ma, ten, sdt, email, diachi, loai, status_line, masach_line;
    int d, m, y, status;

    while (n < max) {
        if (!getline(in, ma) || ma.empty()) break;
        if (!getline(in, ten)) break;
        if (!getline(in, sdt)) break;
        if (!getline(in, email)) break;
        if (!getline(in, diachi)) break;
        in >> d >> m >> y;
        if (in.fail()) break;
        in.ignore(); 
        if (!getline(in, loai)) break;
        if (!getline(in, status_line)) break;
        stringstream ss_status(status_line);
        ss_status >> status;
        if (ss_status.fail()) break;
        getline(in, masach_line);

        DocGia* dg = nullptr;
        if (loai == "HoiVien") {
            string extra1, dk, hh;
            getline(in, extra1);
            stringstream ss_extra(extra1);
            int tg; double tl;
            ss_extra >> tg >> tl;
            if (ss_extra.fail()) continue;
            getline(in, dk);
            getline(in, hh);
            dg = new HoiVien(ten, ma, 0, tg, tl, dk, hh);
        } else if (loai == "Doc Gia Thuong") {
            dg = new DocGiaThuong(ten, ma, 0, 5); 
        } else {
            continue;
        }
        dg->maDocGia = ma;
        dg->hoTen = ten;
        dg->sdt = sdt;
        dg->email = email;
        dg->diachi = diachi;
        dg->ngayLapThe = Date(d, m, y);
        dg->status = status;
        dg->dsMaSachDangMuon.clear();
        stringstream ss_masach(masach_line);
        string maSach;
        while (ss_masach >> maSach) {
            dg->dsMaSachDangMuon.push_back(maSach);
        }
        ds[n++] = dg;
        string temp;
        while (getline(in, temp) && temp.empty());
        if (!temp.empty()) {
            in.seekg(-static_cast<long long>(temp.size() + 1), ios::cur);
        }
    }
    in.close();
    return n;
}
void DocGia::ghiFileDocGia(const DocGia* ds[], int n, const string& file) {
    ofstream out(file);
    if (!out.is_open()) return;

    for (int i = 0; i < n; ++i) {
        if (ds[i] && ds[i]->getStatus() == 1) {
            ds[i]->ghiFile(out);
            out << "\n"; 
        }
    }
    out.close();
}

