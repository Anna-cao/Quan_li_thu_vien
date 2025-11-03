<<<<<<< HEAD
#include "../include/NhaXuatBan.h"

NhaXuatBan::NhaXuatBan() = default;
NhaXuatBan::NhaXuatBan(const string& nxb) : NXB(nxb) {}

void NhaXuatBan::ThemSach(const string& maSach) {
    SoSachXB.push_back(maSach);
}

void NhaXuatBan::Xuat() const {
    cout << "NXB: " << NXB << "\nDanh sach sach: ";
    for (auto& s : SoSachXB) cout << s << " ";
    cout << endl;
}

string NhaXuatBan::getNXB() const { return NXB; }
vector<string> NhaXuatBan::getSoSachXB() const { return SoSachXB; }
=======
#include "NhaXuatBan.h"

NhaXuatBan::NhaXuatBan() = default;
NhaXuatBan::NhaXuatBan(const string& nxb) : NXB(nxb) {}

void NhaXuatBan::ThemSach(const string& maSach) {
    SoSachXB.push_back(maSach);
}

void NhaXuatBan::Xuat() const {
    cout << "NXB: " << NXB << "\nDanh sach sach: ";
    for (auto& s : SoSachXB) cout << s << " ";
    cout << endl;
}

string NhaXuatBan::getNXB() const { return NXB; }
vector<string> NhaXuatBan::getSoSachXB() const { return SoSachXB; }
>>>>>>> 74423b19114229b785bf3b5c8acf80655272a129
