<<<<<<< HEAD
#include "../include/Utils.h"

namespace Utils {
    bool KiemTraNgayHopLe(int ngay, int thang, int nam) {
        return (ngay > 0 && thang > 0 && thang <= 12 && nam > 0);
    }

    int SoNgayTrongThang(int thang, int nam) {
        if (thang == 2)
            return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0) ? 29 : 28;
        if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
            return 30;
        return 31;
    }

    bool KiemTraFileTonTai(const string & tenFile) {
        ifstream f(tenFile);
        return f.good();
    }

    void DocFile(const string& tenFile) {
        ifstream f(tenFile);
        if (!f) {
            cout << "Khong mo duoc file!\n";
            return;
        }
        string line;
        while (getline(f, line)) cout << line << endl;
        f.close();
    }

    void GhiFile(const string& tenFile) {
        ofstream f(tenFile, ios::app);
        if (!f) {
            cout << "Khong mo duoc file de ghi!\n";
            return;
        }
        f << "Ghi du lieu vao file.\n";
        f.close();
    }
}
=======
#include "Utils.h"

namespace Utils {
    bool KiemTraNgayHopLe(int ngay, int thang, int nam) {
        return (ngay > 0 && thang > 0 && thang <= 12 && nam > 0);
    }

    int SoNgayTrongThang(int thang, int nam) {
        if (thang == 2)
            return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0) ? 29 : 28;
        if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
            return 30;
        return 31;
    }

    bool KiemTraFileTonTai(const string& tenFile) {
        ifstream f(tenFile);
        return f.good();
    }

    void DocFile(const string& tenFile) {
        ifstream f(tenFile);
        if (!f) {
            cout << "Khong mo duoc file!\n";
            return;
        }
        string line;
        while (getline(f, line)) cout << line << endl;
        f.close();
    }

    void GhiFile(const string& tenFile) {
        ofstream f(tenFile, ios::app);
        if (!f) {
            cout << "Khong mo duoc file de ghi!\n";
            return;
        }
        f << "Ghi du lieu vao file.\n";
        f.close();
    }
}
>>>>>>> 74423b19114229b785bf3b5c8acf80655272a129
