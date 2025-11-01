 #ifndef SACH_H
#define SACH_H

#include<iostream>
#include<string>
using namespace std;

class Sach {
private:
    string maSach, tenSach, tacGia, NXB, type;
    int soTrang, soLuongTong, soLuongDaMuon;
    double giaTien;

public:
    Sach();
    Sach(string maSach, string tenSach, string tacGia, string NXB, string type, int soTrang, int soLuongTong, int soLuongDaMuon, double giaTien);

    string getMaSach() const { return maSach; }
    string getTenSach() const { return tenSach; }
    string getTacGia() const { return tacGia; }
    string getNXB() const { return NXB; }
    string getType() const { return type; }
    int getSoTrang() const { return soTrang; }
    int getSoLuongTong() const { return soLuongTong; }
    int getSoLuongDaMuon() const { return soLuongDaMuon; }
    double getGiaTien() const { return giaTien; }

    void setSoLuongTong(int sl) { soLuongTong = sl; }
    void setSoLuongDaMuon(int sl) { soLuongDaMuon = sl; }

    bool muonSach();
    bool traSach();
    virtual void nhap();
    virtual void hienThiThongTin();
    int soSachConLai() const;

    ~Sach() {}
};

#endif
