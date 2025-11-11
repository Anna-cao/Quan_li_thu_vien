// Kho.h
#ifndef KHO_H
#define KHO_H

#include <string>
#include "NhaXuatBan.h"
#include "Sach.h"

#define Max_NXB 200  
class Kho {
private:
    int soLuongTong;
    int soLuongDaMuon;
    NhaXuatBan* danhSachNXB[Max_NXB];  
    int soNXB;

public:
    Kho(int tong = 0, int muon = 0);
    ~Kho();

    void HienThiKho() const;
    int soSachConLai() const { return soLuongTong - soLuongDaMuon; }
    int getSoLuongTong() const { return soLuongTong; }
    int getSoLuongDaMuon() const { return soLuongDaMuon; }
    bool coNXB(const string& ten) const;
    bool themNXB(NhaXuatBan* nxb);
    const NhaXuatBan* const* getDSNXB() const { return danhSachNXB; }
    int getSoNXB() const { return soNXB; }
};

#endif