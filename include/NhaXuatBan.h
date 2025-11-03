<<<<<<< HEAD
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NhaXuatBan {
private:
    string NXB;
    vector<string> SoSachXB;
public:
    NhaXuatBan();
    NhaXuatBan(const string& nxb);
    void ThemSach(const string& maSach);
    void Xuat() const;
    string getNXB() const;
    vector<string> getSoSachXB() const;
};
=======
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NhaXuatBan {
private:
    string NXB;
    vector<string> SoSachXB;
public:
    NhaXuatBan();
    NhaXuatBan(const string& nxb);
    void ThemSach(const string& maSach);
    void Xuat() const;
    string getNXB() const;
    vector<string> getSoSachXB() const;
};

>>>>>>> 74423b19114229b785bf3b5c8acf80655272a129
