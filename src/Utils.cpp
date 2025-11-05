#include "../include/Utils.h"

namespace Utils {

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

