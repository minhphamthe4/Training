#include <iostream>
#include <string>
#include <vector> // FIX: Thêm thư viện vector
using namespace std;

class Hanghoa {
    protected:
        long Mahang;
        string Tenhang;
        string Nhasanxuat;
        long Gia;
        string Loaihang;
        virtual void loaihang() = 0;
    public:
        virtual ~Hanghoa() = default; // FIX: Thêm virtual destructor để tránh rò rỉ bộ nhớ

        virtual bool NhapTT(istream &in) {
            in >> Mahang;
            if(in.fail()) {
                in.clear();
                in.ignore(1000, '\n');
                throw invalid_argument("Ma hang khong hop le");
            }
            in >> Tenhang >> Nhasanxuat;
            in >> Gia;
            if(in.fail() || Gia < 0) {
                in.clear();
                in.ignore(1000, '\n');
                throw invalid_argument("Gia khong hop le");
            }
            return true;
        }

        virtual string XuatTT() {
            return to_string(Mahang) + " " + Tenhang + " " + Nhasanxuat + " " + to_string(Gia) + " " + Loaihang;
        }

        // FIX: Đưa nạp chồng toán tử lên lớp cha, áp dụng tính đa hình qua NhapTT và XuatTT
        friend istream& operator >>(istream &in, Hanghoa &hh) {
            hh.NhapTT(in);
            return in;
        }

        friend ostream& operator <<(ostream &out, Hanghoa &hh) {
            out << hh.XuatTT();
            return out;
        }
};

class Hangdienmay : public Hanghoa {
    private:
        long CongSuat;
        string Baohanh;
        long Dienap;
        void loaihang() override {
            Loaihang = "Dien may";
        }
    public:
        Hangdienmay() { loaihang(); } // FIX: Gọi để gán Loaihang ngay khi khởi tạo

        bool NhapTT(istream &in) override {
            if (!Hanghoa::NhapTT(in)) return false;
            in >> CongSuat;
            if(in.fail() || CongSuat < 0) {
                in.clear();
                in.ignore(1000, '\n');
                throw invalid_argument("Cong suat khong hop le");
            }
            in >> Baohanh;
            in >> Dienap;
            if(in.fail() || Dienap < 0) {
                in.clear();
                in.ignore(1000, '\n');
                throw invalid_argument("Dien ap khong hop le");
            }
            return true;
        }
        string XuatTT() override {
            return Hanghoa::XuatTT() + " " + to_string(CongSuat) + " " + Baohanh + " " + to_string(Dienap);
        }
};

class Hangsanhsu : public Hanghoa {
    private:
        string Chatlieu;
        void loaihang() override {
            Loaihang = "Sanh su";
        }
    public:
        Hangsanhsu() { loaihang(); }

        bool NhapTT(istream &in) override {
            if (!Hanghoa::NhapTT(in)) return false;
            in >> Chatlieu;
            return true;
        }   
        // FIX: Thêm XuatTT() bị thiếu
        string XuatTT() override {
            return Hanghoa::XuatTT() + " " + Chatlieu;
        }
};

class Hangthucpham : public Hanghoa {
    private:
        string NgaySX;
        string NgayHH;
        void loaihang() override {
            Loaihang = "Thuc pham";
        }
    public:
        Hangthucpham() { loaihang(); }

        bool NhapTT(istream &in) override {
            if (!Hanghoa::NhapTT(in)) return false;
            in >> NgaySX >> NgayHH;
            return true;
        }
        // FIX: Thêm XuatTT() bị thiếu
        string XuatTT() override {
            return Hanghoa::XuatTT() + " " + NgaySX + " " + NgayHH;
        }
};

int main() {
    vector <Hanghoa*> list_hang; // FIX: Đổi tên vector tránh nhầm lẫn
    long Soluong;
    cout << "Nhap so luong hang: ";
    cin >> Soluong;
    
    for (long i = 0; i < Soluong; i++) {
        cout << "Nhap loai hang (1: Dien may, 2: Sanh su, 3: Thuc pham): ";
        int loai;
        cin >> loai;
        if (cin.fail() || loai < 1 || loai > 3) {
            cerr << "Loi: Loai hang khong hop le. " << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            i--; // Lùi lại 1 bước để bắt nhập lại
            continue;
        }
        
        Hanghoa* sp = nullptr; // FIX: Đổi tên biến con trỏ
        switch (loai) {
            case 1: sp = new Hangdienmay(); break;
            case 2: sp = new Hangsanhsu(); break;
            case 3: sp = new Hangthucpham(); break;
        }
        
        cout << "Nhap thong tin hang (Ma, Ten, NSX, Gia...): ";
        try {
            cin >> *sp;
            list_hang.push_back(sp);
        } catch (const exception &e) { // Bắt lỗi throw từ NhapTT
            cerr << "Loi: " << e.what() << endl;
            delete sp; // Xóa con trỏ nếu nhập lỗi
            i--;
        }
    }
    
    cout << "\n--- DANH SACH HANG HOA ---" << endl;
    for (auto &hang : list_hang) {
         cout << *hang << endl;
    }

    // FIX: Giải phóng bộ nhớ ở cuối chương trình
    for (auto &hang : list_hang) {
        delete hang;
    }
    list_hang.clear();

    return 0;
}