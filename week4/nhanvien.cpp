#include<iostream>
using namespace std;
class NhanVien{
    private:
        string tenNV;
        double luongcb=1000;
        double hesoluong=1;
        double luongmax=50000;
    public:
        void nhap(){
            cout << "Nhap ten nhan vien: ";
            cin>> tenNV;
        }
        bool tangLuong(){
            double tang;
            cout << "Nhap so tang luong: ";
            cin >> tang;
            if (luongcb*(hesoluong+tang)<luongmax) 
            {
                hesoluong+=tang;
                return true;
            }
            else return false;
        }
        double tinhluong()
        {
            return luongcb*hesoluong;
        }
        void xuat(){
            cout << "Ten nhan vien: " << tenNV << endl;
            cout << "Luong co ban: " << luongcb << endl;
            cout << "He so luong: " << hesoluong << endl;
        }
};
int main(){
    // Tạo đối tượng NhanVien và thực hiện các thao tác
    NhanVien nv;
    nv.nhap();
    if(nv.tangLuong()){
        cout << "Co the tang luong!" << endl;
    }
    else{
        cout << "Khong the tang luong!" << endl;
    }
    nv.xuat();
    cout << "Luong hien tai: " << nv.tinhluong() << endl;
    return 0;
}