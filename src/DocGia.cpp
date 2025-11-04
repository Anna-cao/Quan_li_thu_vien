#include "../include/DocGia.h"
#include <algorithm> 

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
void DocGia::nhap()
{
    cout << "Nhap ma doc gia: ";
    getline(cin, this->maDocGia);
    cout << "Nhap ho ten: ";
    getline(cin, this->hoTen);
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
