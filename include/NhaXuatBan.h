#ifndef NHAXUATBAN_H
#define NHAXUATBAN_H
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
    string getNXB() const;
    vector<string> getSoSachXB() const;
    void hienThiDSNXB() const;
    void setNXB(const string& tenMoi) { NXB = tenMoi; }

    static int docFileNXB(NhaXuatBan* danhSach[], int soLuongToiDa, const string& duongDan);
    static void ghiFileNXB(NhaXuatBan* danhSach[], int soLuong, const string& duongDan);
};
#endif