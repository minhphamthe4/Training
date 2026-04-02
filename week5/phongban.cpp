#include <iostream>
#include <string>
using namespace std;
class NhanVien {
    protected:
        long MaNv;
        string Ten;
        long NamSinh;
        string DiaChi;
        long HeSoLuong;
        long LuongToiDa;
    public:
        virtual void setInfo() {
            cout << "Nhap ma nhan vien: ";
            cin >> MaNv;
            cout << "Nhap ten nhan vien: ";
            cin.ignore();
            getline(cin, Ten);
            cout << "Nhap nam sinh: ";
            cin >> NamSinh;
            cout << "Nhap dia chi: ";
            cin.ignore();
            getline(cin, DiaChi);
            cout << "Nhap he so luong (Nho hon 1): ";
            cin >> HeSoLuong;
            cout << "Nhap luong toi da: ";
            cin >> LuongToiDa;
        }
        virtual void getInfo() {
            cout << "Ma nhan vien: " << MaNv << endl;
            cout << "Ten nhan vien: " << Ten << endl;
            cout << "Nam sinh: " << NamSinh << endl;
            cout << "Dia chi: " << DiaChi << endl;
            cout << "He so luong: " << HeSoLuong << endl;
        }
};
class CongTacVien: public NhanVien {
    private:
        int ThoiHan;
        long PhuCap;
    public:
        void setInfo() override {
            NhanVien::setInfo();
            cout << "Nhap thoi han hop dong (Nhap cac gia tri 1, 2, 3): ";
            cin >> ThoiHan;
            cout << "Nhap phu cap: ";
            cin >> PhuCap;
        }
        void getInfo() override {
            NhanVien::getInfo();
            cout << "Thoi han hop dong: ";
            switch (ThoiHan) {
                case 1:
                    cout << "3 thang";
                    break;
                case 2:
                    cout << "6 thang";
                    break;
                case 3:
                    cout << "1 nam";
                    break;
                default:
                    cout << "Khong xac dinh";
            }
            cout << endl;
            cout << "Luong: " << PhuCap + LuongToiDa * HeSoLuong << endl;
        }
};
class NVChinhThuc : public NhanVien {
    private:
        string ChucVu;
    public:
        void setInfo() override {
            NhanVien::setInfo();
            cout << "Nhap chuc vu: ";
            cin.ignore();
            getline(cin, ChucVu);
        }
        void getInfo() override {
            NhanVien::getInfo();
            cout << "Chuc vu: " << ChucVu << endl;
            cout << "Luong: " << LuongToiDa * HeSoLuong << endl;
        }
};
class TruongPhong : public NhanVien {
    private:
        long PhuCap;
        string NgayBatDau;
    public:
        void setInfo() override {
            NhanVien::setInfo();
            cout << "Nhap phu cap: ";
            cin >> PhuCap;
            cout << "Nhap ngay bat dau quan ly (dd/mm/yyyy): ";
            cin.ignore();
            getline(cin, NgayBatDau);
        }
        void getInfo() override {
            NhanVien::getInfo();
            cout << "Ngay bat dau: " << NgayBatDau << endl;
            cout << "Luong: " << PhuCap + LuongToiDa * HeSoLuong << endl;
        }
};
int main(){
    //Chuong trinh thu
    CongTacVien ctv;
    ctv.setInfo();
    ctv.getInfo();
    NVChinhThuc nv;
    nv.setInfo();
    nv.getInfo();
    TruongPhong tp;
    tp.setInfo();
    tp.getInfo();
}