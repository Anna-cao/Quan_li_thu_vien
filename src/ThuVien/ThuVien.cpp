#include "../include/ThuVien.h"
#include "../include/Kho.h"

#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

ThuVien::ThuVien() {
    soLuongTong = 0;
    soDocGia = 0;
    soHoaDon = 0;
    soNXB = 0; 
    for (int i = 0; i < Max_NXB; ++i) {
        danhSachNXB[i] = nullptr;
    }
}

ThuVien::~ThuVien() {
    for (int i = 0; i < soDocGia; i++) delete danhSachDocGia[i];
    for (int i = 0; i < soNXB; i++) delete danhSachNXB[i];
}
