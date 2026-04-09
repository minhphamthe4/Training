#include <iostream>
#include <string>
using namespace std;
class NhanVien {
    protected:
        long MaNv;
        string Ten;
        long NamSinh;
        string DiaChi;
        double HeSoLuong;
        double LuongToiDa;
        string loai;
        virtual void setLoai() = 0;
    public:
        virtual ~NhanVien() = default; // FIX: Thêm virtual destructor để tránh rò rỉ bộ nhớ
        virtual bool setInfo(istream &in) {
            in >> MaNv;
            if(in.fail()) {
                in.clear();
                in.ignore(1000, '\n');
                throw invalid_argument("Ma nhan vien khong hop le");
            }
            in >> Ten;
            in >> NamSinh;
             if(in.fail()) {
                in.clear();
                in.ignore(1000, '\n');
                throw invalid_argument("Nam sinh khong hop le");
            }
            in >> DiaChi;
            in >> HeSoLuong;
            if(in.fail() || HeSoLuong <= 0 || HeSoLuong >= 1) {
                in.clear();
                in.ignore(1000, '\n');
                throw invalid_argument("He so luong khong hop le");
            }
            in >> LuongToiDa;
            if(in.fail() || LuongToiDa <= 0) {
                in.clear();
                in.ignore(1000, '\n');
                throw invalid_argument("Luong toi da khong hop le");
            }
            return true;
        }
        virtual string getInfo() {
            string info = "Ma nhan vien: " + to_string(MaNv) + "\n";
            info += "Ten nhan vien: " + Ten + "\n";
            info += "Nam sinh: " + to_string(NamSinh) + "\n";
            info += "Dia chi: " + DiaChi + "\n";
            info += "He so luong: " + to_string(HeSoLuong) + "\n";
            return info;
        }
        friend istream& operator >>(istream &in, NhanVien &nv) {
            nv.setInfo(in);
            return in;
        }
        friend ostream& operator <<(ostream &out, NhanVien &nv) {
            out << nv.getInfo();
            return out;
        }
};
class CongTacVien: public NhanVien {
    private:
        int ThoiHan;
        double PhuCap;
        void setLoai() override {
            loai = "Cong Tac Vien";
        }
    public:
        CongTacVien() { setLoai(); }
        bool setInfo(istream &in) override {
            if (!NhanVien::setInfo(in)) {
                return false;
            }
            in >> ThoiHan;
            if(in.fail() || ThoiHan <= 0) {
                in.clear();
                in.ignore(1000, '\n');
                throw invalid_argument("Thoi han khong hop le");
            }
            in >> PhuCap;
            if(in.fail() || PhuCap < 0) {
                in.clear();
                in.ignore(1000, '\n');
                throw invalid_argument("Phu cap khong hop le");
            }
            return true;
        }
        string getInfo() override {
            string info = NhanVien::getInfo();
            info += "Loai: " + loai + "\n";
            info += "Thoi han (thang): " + to_string(ThoiHan) + "\n";
            info += "Luong: " + to_string(PhuCap + LuongToiDa * HeSoLuong) + "\n";
            return info;
        }
};
class NVChinhThuc : public NhanVien {
    private:
        string ChucVu;
        void setLoai() override {
            loai = "Nhan Vien Chinh Thuc";
        }
    public:
        NVChinhThuc() { setLoai(); }
        bool setInfo(istream &in) override {
            if (!NhanVien::setInfo(in)) {
                return false;
            }
            in >> ChucVu;
            return true;
        }
        string getInfo() override {
            string info = NhanVien::getInfo();
            info += "Loai: " + loai + "\n";
            info += "Chuc vu: " + ChucVu + "\n";
            info += "Luong: " + to_string(LuongToiDa * HeSoLuong) + "\n";
            return info;
        }
};
class TruongPhong : public NhanVien {
    private:
        long PhuCap;
        string NgayBatDau;
        void setLoai() override {
            loai = "Truong Phong";
        }
    public:
        TruongPhong() { setLoai(); }
        bool setInfo(istream &in) override {
            if (!NhanVien::setInfo(in)) {
                return false;
            }
            in >> PhuCap;
            if(in.fail() || PhuCap < 0) {
                in.clear();
                in.ignore(1000, '\n');
                throw invalid_argument("Phu cap khong hop le");
            }
            in >> NgayBatDau;
            return true;
        }
        string getInfo() override {
            string info = NhanVien::getInfo();
            info += "Loai: " + loai + "\n";
            info += "Ngay bat dau (dd/mm/yyyy): " + NgayBatDau + "\n";
            info += "Luong: " + to_string(PhuCap + LuongToiDa * HeSoLuong) + "\n";
            return info;
        }
};
int main(){
    //Chuong trinh thu
    CongTacVien ctv;
    try{
        cin>>ctv;
    }
    catch(const invalid_argument& e) {
        cerr << "Loi: " << e.what() << endl;
        return 1; // Thoát chương trình nếu có lỗi nhập
    }
    cout<<ctv;
    NVChinhThuc nv;
    try{
        cin>>nv;
    }
    catch(const invalid_argument& e) {
        cerr << "Loi: " << e.what() << endl;
        return 1; // Thoát chương trình nếu có lỗi nhập
    }
    cout<<nv;
    TruongPhong tp;
    try{
        cin>>tp;
    }
    catch(const invalid_argument& e) {
        cerr << "Loi: " << e.what() << endl;
        return 1; // Thoát chương trình nếu có lỗi nhập
    }
    cout<<tp;
}