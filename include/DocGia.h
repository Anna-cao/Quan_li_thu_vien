#ifndef DOCGIA_H
#define DOCGIA_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "TheMuon.h"

using namespace std;

class DocGia {
private:
    static int autoID;

    string maDocGia;
    string hoTen;
    string sdt;
    string email;
    string diachi;
    Date ngayLapThe;

    int soLuotMuon;
    vector<string> dsMaSachDangMuon;

    TheMuon* theMuon;

public:
    DocGia();
    DocGia(string ma, string ten, int soLuotMuon);
    DocGia(string ma, string ten, TheMuon* tm);
    ~DocGia();

    static string generateMaDocGia();

    string getMaDocGia() const;
    string getHoTen() const;
    int getSoLuotMuon() const;
    TheMuon* getTheMuon() const;
    const vector<string>& getDsMaSachDangMuon() const;

    void setTheMuon(TheMuon* tm);
    void setDsMaSachDangMuon(const vector<string>& ds);
    void setSoLuotMuon(int s);

    void nhap();
    void hienThiThongTin() const;

    
    void hienThiDong() const;
    static void hienThiTieuDe();

    bool muonSach(const string& maSach, const Date& ngayHienTai);
    void traSach(const string& maSach);

    void suaDocGia(const string& ma);
    void capNhatTheMuon();

    static int docFileDocGia(DocGia ds[], int soLuongToiDa, const string& duongDan);
    static void ghiFileDocGia(const DocGia ds[], int soLuong, const string& duongDan);
};

#endif