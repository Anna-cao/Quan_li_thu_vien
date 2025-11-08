#ifndef DOCGIATHUONG_H
#define DOCGIATHUONG_H

#include "DocGia.h"
#include <string>

class DocGiaThuong : public DocGia {
private:
    int gioiHanMuon;

public:
    DocGiaThuong();
    DocGiaThuong(string ten, string maSo, int soSachDaMuon, int gioiHanMuon);
    
    int getGioiHanMuon() const;
    void setGioiHanMuon(int gioiHan);
    
    void hienThiThongTin() const override;
};

#endif
