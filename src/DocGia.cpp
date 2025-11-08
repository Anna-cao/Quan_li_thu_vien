#include "../include/DocGia.h"
#include <algorithm> 
#include <fstream>
#include <vector>
#include <sstream>

DocGia::DocGia() : soLuotMuon(0), theMuon(nullptr) {}
DocGia::DocGia(string ma, string ten, int soLuotMuon)
    : maDocGia(ma), hoTen(ten), soLuotMuon(soLuotMuon), theMuon(nullptr) {}
DocGia::DocGia(string ma, string ten, TheMuon* tm)
    : maDocGia(ma), hoTen(ten), soLuotMuon(0), theMuon(tm) {}

DocGia::~DocGia() {}

string DocGia::getMaDocGia() const { return maDocGia; }
string DocGia::getHoTen() const { return hoTen; }
int DocGia::getSoLuotMuon() const { return soLuotMuon; }
TheMuon* DocGia::getTheMuon() const { return theMuon; }
void DocGia::setTheMuon(TheMuon* tm) { theMuon = tm; }
const vector<string>& DocGia::getDsMaSachDangMuon() const {
    return dsMaSachDangMuon;
}
void DocGia::setDsMaSachDangMuon(const vector<string>& ds) {
    dsMaSachDangMuon = ds;
}
void DocGia::setSoLuotMuon(int s) {
    soLuotMuon = s;
}
void DocGia::nhap() {
    cout << "Nhap ma doc gia: ";   getline(cin, maDocGia);
    cout << "Nhap ho ten: ";       getline(cin, hoTen);
    cout << "Nhap SDT: ";          getline(cin, sdt);
    cout << "Nhap email: ";        getline(cin, email);
    cout << "Nhap dia chi: ";      getline(cin, diachi);
    soLuotMuon = 0;
}

bool DocGia::muonSach(const string& maSach, const Date& ngayHienTai) 
{
    if (theMuon == nullptr) 
    {
        cout << "Doc gia chua co the muon.\n";
        return false;
    }

    if (!theMuon->kiemTraHieuLuc(ngayHienTai)) 
    { 
        cout << "The muon da het han, khong the muon sach.\n";
        return false;
    }

    if ((int)dsMaSachDangMuon.size() >= theMuon->getGioiHanMuon()) 
    {
        cout << "Vuot gioi han muon (" << theMuon->getGioiHanMuon() << " sach).\n";
        return false;
    }
    if (find(dsMaSachDangMuon.begin(), dsMaSachDangMuon.end(), maSach) != dsMaSachDangMuon.end()) 
	{
        cout << "Sach nay da duoc muon truoc do.\n";
        return false;
    }

    dsMaSachDangMuon.push_back(maSach);
    soLuotMuon++;
    cout << "Muon sach thanh cong: " << maSach << endl;
    return true;
}

void DocGia::traSach(const string& maSach) 
{
    vector<string>::iterator it = find(dsMaSachDangMuon.begin(), dsMaSachDangMuon.end(), maSach);
    if (it != dsMaSachDangMuon.end()) 
    {
        dsMaSachDangMuon.erase(it);
        cout << "Tra sach thanh cong: " << maSach << endl;
    } 
    else 
    {
        cout << "Doc gia khong muon sach co ma: " << maSach << endl;
    }
}

void DocGia::hienThiThongTin() const 
{
    cout << "Ma doc gia: " << maDocGia << " | Ho ten: " << hoTen
         << " | So luot muon: " << soLuotMuon << endl;

    if (theMuon != nullptr)
        cout << "  -> Gioi han muon: " << theMuon->getGioiHanMuon()
             << ", Trang thai: " << (theMuon->getStatus() ? "Con han" : "Het han") << endl;

    cout << "  -> Danh sach sach dang muon (" << dsMaSachDangMuon.size() << "): ";
    for (size_t i = 0; i < dsMaSachDangMuon.size(); ++i)
        cout << dsMaSachDangMuon[i] << " ";
    cout << endl;
}

istream& operator>>(istream& in, DocGia& dg) 
{
    cout << "Nhap ma doc gia: ";
    getline(in, dg.maDocGia);
    cout << "Nhap ho ten: ";
    getline(in, dg.hoTen);
    dg.soLuotMuon = 0;
    return in;
}

ostream& operator<<(ostream& out, const DocGia& dg) 
{
    out << "Ma doc gia: " << dg.maDocGia << ", Ho ten: " << dg.hoTen
        << ", So luot muon: " << dg.soLuotMuon << endl;
    return out;
}

void DocGia::suaDocGia(const string& maDocGia) {
    if (this->maDocGia == maDocGia) {
        cout << "Nhap ten moi: ";
        getline(cin, hoTen);  
        cout << "Nhap dia chi moi: ";
        getline(cin, diachi);
        cout << "Nhap so dien thoai moi: ";
        getline(cin, sdt);
        cout << "Da cap nhat thong tin doc gia!\n";
    } else {
        cout << "Khong tim thay doc gia!\n";
    }
}

void DocGia::xoaDocGia(const string& maDocGia) {
    if (this->maDocGia == maDocGia) {
        cout << "Da xoa doc gia: " << hoTen << endl;
    } else {
        cout << "Khong tim thay doc gia de xoa!\n";
    }
}


static vector<DocGia> docFileDocGia_vector(const string& path) {
    vector<DocGia> list;
    ifstream in(path);
    if (!in.is_open()) return list;
    string ma;
    while (true) {
        if (!getline(in, ma)) break;
        if (ma.size() == 0) continue;
        string ten;
        getline(in, ten);
        string line;
        getline(in, line);
        int k = 0; if (line.size()>0) k = stoi(line);
        vector<string> ds;
        for (int i = 0; i < k; ++i) {
            string ms; getline(in, ms);
            if (ms.size()>0) ds.push_back(ms);
        }
        DocGia dg(ma, ten, (int)ds.size());
        dg.setDsMaSachDangMuon(ds);
        dg.setSoLuotMuon((int)ds.size());
        list.push_back(dg);
    }
    in.close();
    return list;
}

static void ghiFileDocGia_vector(const vector<DocGia>& list, const string& path) {
    ofstream out(path);
    if (!out.is_open()) return;
    for (const auto& dg : list) {
        out << dg.getMaDocGia() << "\n";
        out << dg.getHoTen() << "\n";
        const auto& ds = dg.getDsMaSachDangMuon();
        out << ds.size() << "\n";
        for (const auto& ms : ds) out << ms << "\n";
        out << "\n";
    }
    out.close();
}

int DocGia::docFileDocGia(DocGia danhSach[], int soLuongToiDa, const string& duongDan) {
    vector<DocGia> list = docFileDocGia_vector(duongDan);
    int n = (int)list.size();
    int cap = min(n, soLuongToiDa);
    for (int i = 0; i < cap; ++i) danhSach[i] = list[i];
    return cap;
}

void DocGia::ghiFileDocGia(const DocGia danhSach[], int soLuong, const string& duongDan) {
    vector<DocGia> list;
    list.reserve(soLuong);
    for (int i = 0; i < soLuong; ++i) list.push_back(danhSach[i]);
    ghiFileDocGia_vector(list, duongDan);
}