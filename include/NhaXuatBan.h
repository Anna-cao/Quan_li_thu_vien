#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NhaXuatBan {
private:
    string NXB;
    vector<string> SoSachXB;
public:
    NhaXuatBan();
    NhaXuatBan(const string& nxb);
    void ThemSach(const string& maSach);
    void Xuat() const;
    string getNXB() const;
    vector<string> getSoSachXB() const;
};

