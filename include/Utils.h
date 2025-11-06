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
}
