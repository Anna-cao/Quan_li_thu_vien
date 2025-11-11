#ifndef SACH_H
#define SACH_H
#define Max_sach 200

#include <iostream>
#include <string>
using namespace std;

class Sach {
private:
    string maSach, tenSach, tacGia, NXB, type;
    int soLuongTong, soLuongDaMuon;
    double giaTien;
    static int autoID;
public:
    Sach();
    Sach (string maSach, string tenSach, double giaTien);

    string getMaSach() const { return maSach; }
    string getTenSach() const { return tenSach; }
    string getTacGia() const { return tacGia; }
    string getNXB() const { return NXB; }
    string getType() const { return type; }
    int getSoLuongTong() const { return soLuongTong; }
    int getSoLuongDaMuon() const { return soLuongDaMuon; }
    double getGiaTien() const { return giaTien; }

    void setMaSach(const string& ma) { maSach = ma; }
    void setTenSach(const string& ten) { tenSach = ten; }
    void setTacGia(const string& tg) { tacGia = tg; }
    void setNXB(const string& n) { NXB = n; }
    void setType(const string& t) { type = t; }
    void setSoLuongTong(int sl) { soLuongTong = sl; }
    void setSoLuongDaMuon(int sl) { soLuongDaMuon = sl; }
    void setGiaTien(double g) { giaTien = g; }

    bool muonSach();
    bool traSach();
    void nhap();
    void hienThiThongTin();
    int soSachConLai() const;
    static void capNhatAutoID(int id);
    static int docFileSach(Sach danhSach[], int soLuongTong, const string& duongDan = "data/sach.txt");
    static void ghiFileSach(const Sach danhSach[], int soLuong, const string& duongDan = "data/sach.txt");
    ~Sach() {}
};

#endif
