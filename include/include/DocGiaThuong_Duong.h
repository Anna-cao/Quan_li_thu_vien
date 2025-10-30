#ifndef DOCGIATHUONG_DUONG_H
#define DOCGIATHUONG_DUONG_H

#include "DocGia.h"
#include <string>

class DocGiaThuong : public DocGia {
private:
    int gioiHanMuon;

public:
    DocGiaThuong();
    DocGiaThuong(std::string ten, std::string maSo, int soSachDaMuon, int gioiHanMuon);
    
    int getGioiHanMuon() const;
    void setGioiHanMuon(int gioiHan);
    
    void hienThiThongTin() const override;
};

#endif
