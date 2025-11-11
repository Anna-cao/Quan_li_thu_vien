#include "../include/NhaXuatBan.h"
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

NhaXuatBan::NhaXuatBan() = default;
NhaXuatBan::NhaXuatBan(const string& nxb) : NXB(nxb) {}

void NhaXuatBan::ThemSach(const string& maSach) {
    SoSachXB.push_back(maSach);
}

void NhaXuatBan::hienThiDSNXB() const {
    cout << "NXB: " << NXB << "\nDanh sach sach: ";
    if (SoSachXB.empty()) {
        cout << "Khong co sach nao";
    } else {
        for (const auto& s : SoSachXB) cout << s << " ";
    }
    cout << endl;
}

string NhaXuatBan::getNXB() const { return NXB; }
vector<string> NhaXuatBan::getSoSachXB() const { return SoSachXB; }

static vector<NhaXuatBan> docFileNXB_vector(const string& duongDan) {
    vector<NhaXuatBan> list;
    ifstream in(duongDan);
    if (!in.is_open()) {
        cerr << "LOI: Khong mo duoc file NXB: " << duongDan << endl;
        return list;
    }

    string line;
    NhaXuatBan cur;
    bool inBlock = false;

    while (getline(in, line)) {
        if (line.empty()) {
            if (inBlock) {
                list.push_back(cur);
                inBlock = false;
            }
            continue;
        }

        if (line.rfind("NXB ", 0) == 0) {
            if (inBlock) list.push_back(cur);
            string ten = line.substr(4);
            cur = NhaXuatBan(ten);
            inBlock = true;
        } else if (inBlock) {
            string s = line;
            size_t p = s.find_first_not_of(" \t");
            if (p != string::npos) s = s.substr(p);
            size_t dash = s.find(" - ");
            string ma = (dash == string::npos) ? s : s.substr(0, dash);
            if (!ma.empty()) cur.ThemSach(ma);
        }
    }
    if (inBlock) list.push_back(cur);
    in.close();
    return list;
}

static void ghiFileNXB_vector(const vector<NhaXuatBan>& list, const string& duongDan) {
    ofstream out(duongDan);
    if (!out.is_open()) return;
    for (const auto& nx : list) {
        out << "NXB " << nx.getNXB() << "\n";
        for (const auto& m : nx.getSoSachXB())
            out << "  " << m << " - \n";
        out << "\n";
    }
    out.close();
}

// === ĐỌC VÀO MẢNG CON TRỎ ===
int NhaXuatBan::docFileNXB(NhaXuatBan* danhSach[], int soLuongToiDa, const string& duongDan) {
    vector<NhaXuatBan> list = docFileNXB_vector(duongDan);
    int n = min((int)list.size(), soLuongToiDa);
    for (int i = 0; i < n; ++i) {
        danhSach[i] = new NhaXuatBan(list[i].getNXB());
        for (const auto& ma : list[i].getSoSachXB())
            danhSach[i]->ThemSach(ma);
    }
    return n;
}

void NhaXuatBan::ghiFileNXB(NhaXuatBan* danhSach[], int soLuong, const string& duongDan) {
    vector<NhaXuatBan> list;
    list.reserve(soLuong);
    for (int i = 0; i < soLuong; ++i)
        if (danhSach[i]) list.push_back(*danhSach[i]);
    ghiFileNXB_vector(list, duongDan);
}