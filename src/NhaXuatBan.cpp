#include "../include/NhaXuatBan.h"

NhaXuatBan::NhaXuatBan() = default;
NhaXuatBan::NhaXuatBan(const string& nxb) : NXB(nxb) {}

void NhaXuatBan::ThemSach(const string& maSach) {
    SoSachXB.push_back(maSach);
}

void NhaXuatBan::hienThiDSNXB() const {
    cout << "NXB: " << NXB << "\nDanh sach sach: ";
    for (auto& s : SoSachXB) cout << s << " ";
    cout << endl;
}

string NhaXuatBan::getNXB() const { return NXB; }
vector<string> NhaXuatBan::getSoSachXB() const { return SoSachXB; }

bool NhaXuatBan::ghiFile(ofstream& out) const {
    if (!out.good()) return false;
    out << NXB;
    for (auto& s : SoSachXB) out << "," << s;
    out << "\n";
    return true;
}

bool NhaXuatBan::docFile(ifstream& in) {
    string line;
    if (!getline(in, line) || line.empty()) return false;
    stringstream ss(line);
    getline(ss, NXB, ',');
    SoSachXB.clear();
    string sach;
    while (getline(ss, sach, ',')) {
        if (!sach.empty()) SoSachXB.push_back(sach);
    }
    return true;
}