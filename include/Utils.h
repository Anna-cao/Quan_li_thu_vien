#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace Utils {
    bool KiemTraNgayHopLe(int ngay, int thang, int nam);
    int SoNgayTrongThang(int thang, int nam);
    bool KiemTraFileTonTai(const string& tenFile);
    void DocFile(const string& tenFile);
    void GhiFile(const string& tenFile);
}
