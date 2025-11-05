#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../include/Sach.h"
#include "../include/DocGia.h"
#include "../include/HoiVien.h"
#include "../include/DocGiaThuong.h"
#include "../include/TheMuon.h"
#include "../include/HoaDon.h"
#include "../include/NhaXuatBan.h"

using namespace std;

namespace Utils {
    bool KiemTraNgayHopLe(int ngay, int thang, int nam);
    int SoNgayTrongThang(int thang, int nam);
    bool KiemTraFileTonTai(const string& tenFile);

    vector<Sach> DocSach(const string& tenFile);
    void GhiSach(const string& tenFile, const vector<Sach>& dsSach);

    vector<DocGia> DocDocGia(const string& tenFile);
    void GhiDocGia(const string& tenFile, const vector<DocGia>& dsDocGia);

    vector<HoiVien> DocHoiVien(const string& tenFile);
    void GhiHoiVien(const string& tenFile, const vector<HoiVien>& dsHoiVien);

    vector<DocGiaThuong> DocDocGiaThuong(const string& tenFile);
    void GhiDocGiaThuong(const string& tenFile, const vector<DocGiaThuong>& dsDGThuong);

    vector<TheMuon> DocTheMuon(const string& tenFile);
    void GhiTheMuon(const string& tenFile, const vector<TheMuon>& dsTheMuon);

    void GhiHoaDon(const string& tenFile, const HoaDon& hd);

    vector<NhaXuatBan> DocNhaXuatBan(const string& tenFile);
    void GhiNhaXuatBan(const string& tenFile, const vector<NhaXuatBan>& dsNXB);
}
