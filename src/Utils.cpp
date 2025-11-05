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

    bool KiemTraFileTonTai(const string& tenFile) {
        ifstream f(tenFile);
        return f.good();
    }
    //SACH
    vector<Sach> DocSach(const string& tenFile) {
        vector<Sach> dsSach;
        ifstream file(tenFile);
        if (!file) {
            cout << "Khong mo duoc file " << tenFile << endl;
            return dsSach;
        }

        string ma, ten, tacGia, nxb, loai;
        int trang, tong, daMuon;
        double gia;

        while (file >> ma >> ten >> tacGia >> nxb >> loai >> trang >> tong >> daMuon >> gia) {
            Sach s(ma, ten, tacGia, nxb, loai, trang, tong, daMuon, gia);
            dsSach.push_back(s);
        }

        file.close();
        return dsSach;
    }

    void GhiSach(const string& tenFile, const vector<Sach>& dsSach) {
        ofstream file(tenFile);
        if (!file) {
            cout << "Khong mo duoc file de ghi " << tenFile << endl;
            return;
        }
        for (auto &s : dsSach) {
            file << s.getMaSach() << " "
                 << s.getTenSach() << " "
                 << s.getTacGia() << " "
                 << s.getNXB() << " "
                 << s.getType() << " "
                 << s.getSoTrang() << " "
                 << s.getSoLuongTong() << " "
                 << s.getSoLuongDaMuon() << " "
                 << s.getGiaTien() << "\n";
        }

        file.close();
    }
//DOC GIA
vector<DocGia> DocDocGia(const string& tenFile) {
        vector<DocGia> ds;
        ifstream file(tenFile);
        if (!file) {
            cout << "Khong mo duoc file " << tenFile << endl;
            return ds;
        }

        string ma, ten;
        int soLuot;

        // mỗi dòng: ma hoTen soLuotMuon
        while (file >> ma >> ten >> soLuot) {
            DocGia dg(ma, ten, soLuot);
            ds.push_back(dg);
        }

        file.close();
        return ds;
    }

    void GhiDocGia(const string& tenFile, const vector<DocGia>& ds) {
        ofstream file(tenFile);
        if (!file) {
            cout << "Khong mo duoc file de ghi " << tenFile << endl;
            return;
        }

        for (auto &dg : ds) {
            file << dg.getMaDocGia() << " "
                 << dg.getHoTen() << " "
                 << dg.getSoLuotMuon() << "\n";
        }

        file.close();
    }
//DOC GIA THUONG
}



