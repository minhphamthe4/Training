#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class PhanSo {
    private:
        int tu;
        int mau;
    public:
        bool nhap(istream &in) {
            cout << "Nhap tu so: ";
            in >> tu;
            cout << "Nhap mau so: ";
            in >> mau;
            if(mau == 0) {
                throw invalid_argument("Mau so khong duoc bang 0");

            }
            return true;
        }
        bool is_toi_gian() {
            return __gcd(tu, mau) == 1;
        }
        void toi_gian(){
            int gcd = __gcd(tu, mau);
            tu /= gcd;
            mau /= gcd;
        }
        string xuat(){
            if (tu<mau || tu%mau!=0) return to_string(tu) + "/" + to_string(mau);
            return to_string(tu/mau);
        }
        friend istream& operator >>(istream &in, PhanSo &ps) {
            ps.nhap(in);
            return in;
        }
        friend ostream& operator <<(ostream &out, PhanSo &ps) {
            out << ps.xuat();
            return out;
        }
        string operator + (const PhanSo &other) {
            int newTu = tu * other.mau + other.tu * mau;
            int newMau = mau * other.mau;
            return to_string(newTu) + "/" + to_string(newMau);
        }
        string operator - (const PhanSo &other) {
            int newTu = tu * other.mau - other.tu * mau;
            int newMau = mau * other.mau;
            return to_string(newTu) + "/" + to_string(newMau);
        }
        string operator * (const PhanSo &other) {
            int newTu = tu * other.tu;
            int newMau = mau * other.mau;
            return to_string(newTu) + "/" + to_string(newMau);
        }
        string operator / (const PhanSo &other) {
            int newTu = tu * other.mau;
            int newMau = mau * other.tu;
            return to_string(newTu) + "/" + to_string(newMau);
        }
        friend bool operator < (const PhanSo &a, const PhanSo &b) {
            return a.tu * b.mau < b.tu * a.mau;
        }
        friend bool operator > (const PhanSo &a, const PhanSo &b) {
            return a.tu * b.mau > b.tu * a.mau;
        }
        friend bool operator == (const PhanSo &a, const PhanSo &b) {
            return a.tu * b.mau == b.tu * a.mau;
        }
};
int main() {
    vector <PhanSo> p;
    cout << "Nhap so luong phan so: ";
    long n;
    cin >> n;
    for(long long i = 0; i < n; i++) {
        cout << "Nhap phan so " << i + 1 << ":" << endl;
        try {
            PhanSo ps;
            cin >> ps;
            p.push_back(ps);
        } 
        catch (const invalid_argument& e) {
            cerr << "Loi: " << e.what() << endl;
            i--;
        }
    }
    long k = 0;
    for(auto &ps : p) {
        if(!ps.is_toi_gian()) {
            cout << "Phan so " << k+1 << " chua toi gian." << endl;
        }
        k++;
    }
    cout << "Phan so sau khi nhap va toi gian: " << endl;
    for(auto &ps : p) {
        ps.toi_gian();
        cout << ps << endl;
    }
    sort(p.begin(), p.end());
    cout << "Phan so sau khi sap xep: " << endl;
    for(auto &ps : p) {
        cout << ps << endl;
    }
    return 0;
}