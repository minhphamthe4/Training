#include <iostream>
#include <string>
using namespace std;
class Hanghoa{
    protected:
        long Mahang;
        string Tenhang;
        string Nhasanxuat;
        long Gia;
    public:
        virtual void setInfo(){
            cout << "Nhap ma hang: ";
            cin >> Mahang;
            cout << "Nhap ten hang: ";
            cin.ignore();
            getline(cin, Tenhang);
            cout << "Nhap nha san xuat: ";
            getline(cin, Nhasanxuat);
            cout << "Nhap gia: ";
            cin >> Gia;
        }
        virtual void getInfo(){
            cout << "Ma hang: " << Mahang << endl;
            cout << "Ten hang: " << Tenhang << endl;
            cout << "Nha san xuat: " << Nhasanxuat << endl;
            cout << "Gia: " << Gia << endl;
        }
};
class Hangdienmay : public Hanghoa{
    private:
        long CongSuat;
        string Baohanh;
        long Dienap;
    public:
        void setInfo() override{
            Hanghoa::setInfo();
            cout << "Nhap cong suat: ";
            cin >> CongSuat;
            cout << "Nhap bao hanh: ";
            cin.ignore();
            getline(cin, Baohanh);
            cout << "Nhap dien ap: ";
            cin >> Dienap;
        }
        void getInfo() override {
            Hanghoa::getInfo();
            cout << "Cong suat: " << CongSuat << endl;
            cout << "Bao hanh: " << Baohanh << endl;
            cout << "Dien ap: " << Dienap << endl;
        }
};
class Hangsanhsu : public Hanghoa{
    private:
        string Chatlieu;
    public:
        void setInfo() override{
            Hanghoa::setInfo();
            cout << "Nhap chat lieu: ";
            cin.ignore();
            getline(cin, Chatlieu);
        }
        void getInfo() override {
            Hanghoa::getInfo();
            cout << "Chat lieu: " << Chatlieu << endl;
        }
};
class Hangthucpham : public Hanghoa{
    private:
        string NgaySX;
        string NgayHH;
    public:
        void setInfo() override{
            Hanghoa::setInfo();
            cout << "Nhap ngay san xuat: ";
            cin.ignore();
            getline(cin, NgaySX);
            cout << "Nhap ngay het han: ";
            getline(cin, NgayHH);
        }
        void getInfo() override {
            Hanghoa::getInfo();
            cout << "Ngay san xuat: " << NgaySX << endl;
            cout << "Ngay het han: " << NgayHH << endl;
        }
};
int main(){
    //Chuong trinh thu
    Hangdienmay dm;
    Hangsanhsu ss;
    Hangthucpham tp;

    cout << "Nhap thong tin hang dien may" << endl;
    dm.setInfo();
    cout << "\nThong tin hang dien may" << endl;
    dm.getInfo();

    cout << "\nNhap thong tin hang sanh su" << endl;
    ss.setInfo();
    cout << "\nThong tin hang sanh su" << endl;
    ss.getInfo();

    cout << "\nNhap thong tin hang thuc pham" << endl;
    tp.setInfo();
    cout << "\nThong tin hang thuc pham" << endl;
    tp.getInfo();

    return 0;
}