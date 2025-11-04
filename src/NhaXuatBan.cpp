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


