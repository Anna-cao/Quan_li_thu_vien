#ifndef KHO_H
#define KHO_H
#include <string>
#include <vector>
#include "Nhaxuatban.h"
#include"Sach.h"
#include "ThuVien.h"
using namespace std;
class ThuVien;
class Kho: public ThuVien {
private:
    Kho();
    ThuVien * tv;
    NhaXuatBan NXB;
    int soLuongTong, soLuongDaMuon;
public:
    Kho (const NhaXuatBan &NXB, int soLuongTong, int soLuongDaMuon):NXB(NXB), soLuongTong(soLuongTong), soLuongDaMuon(soLuongDaMuon) {}
    void HienThiKho()const;
    int soSachConLai() const {return soLuongTong - soLuongDaMuon;}
    int getSoLuongTong(){return soLuongTong;};
    bool coNXB(string& ten)const;
    int getSoLuongDaMuon(){return soLuongDaMuon;}
};

#endif

