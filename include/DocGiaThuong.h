#ifndef DOCGIATHUONG_H
#define DOCGIATHUONG_H

#include "DocGia.h"
#include <string>
#include <fstream>

class DocGiaThuong : public DocGia {
private:
    int gioiHanMuon;

public:
    DocGiaThuong();
    DocGiaThuong(std::string ten, std::string maSo, int soSachDaMuon, int gioiHanMuon);
    
    int getGioiHanMuon() const;
    void setGioiHanMuon(int gioiHan);
    
    void hienThiThongTin() const override;

    bool ghiFile(std::ofstream &out) const ;
    bool docFile(std::ifstream &in);

    bool docFileFromString(const std::string& line);
};

#endif
