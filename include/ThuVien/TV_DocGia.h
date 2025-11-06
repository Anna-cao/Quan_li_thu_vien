#ifndef THUVIEN_DOCGIA_H
#define THUVIEN_DOCGIA_H
#include "../include/DocGia.h"
using namespace std;
class ThuVien {
private:
    DocGia* danhSachDocGia[200];
    int soDocGia;

public:
    bool themDocGia(DocGia* dg);
    void hienThiDanhSachDocGia() const;
    bool suaThongTinDocGia(const std::string& maDocGia);
    bool xoaDocGia(const std::string& maDocGia);
    DocGia* timDocGiaTheoMa(const std::string& ma) const;
    void suaDocGia(const std::string& ma, const DocGia& dgMoi);
    void capNhatTheMuonChoDocGia(const std::string& maDocGia, TheMuon* the);
};

#endif