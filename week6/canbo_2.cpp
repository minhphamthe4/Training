#include <iostream>
#include <string>
#include <vector>
using namespace std;
class CanBo {
    protected:
        string name;
        int age;
        string sex;
        string address;
        string type;
        virtual void settype() = 0;
    public:
        virtual ~CanBo() = default; // FIX: Thêm virtual destructor để tránh rò rỉ bộ nhớ
        virtual bool setInfo(istream &in) {
            in >> name;
            in >> age;
            if(in.fail()) {
                in.clear();
                in.ignore(1000, '\n');
                throw invalid_argument("Tuoi khong hop le");
            }
            in >> sex;
            in >> address;
            return true;
        }
        virtual string getInfo() {
            return "Ten: " + name + "\nTuoi: " + to_string(age) + "\nGioi tinh: " + sex + "\nDia chi: " + address + "\n";
        }
        string getName() {
            return name;
        }
        friend istream& operator >>(istream &in, CanBo &cb) {
            cb.setInfo(in);
            return in;
        }
        friend ostream& operator <<(ostream &out, CanBo &cb) {
            out << cb.getInfo();
            return out;
        }
};
class CongNhan : public CanBo {
    private:
        int level;
        void settype() override {
            type = "Cong_Nhan";
        }
    public:
        CongNhan() { settype(); }
        bool setInfo(istream &in) override{
            if(CanBo::setInfo(in) == false) return false;
            in >> level;
            if(in.fail() || level < 1 || level > 10) {
                in.clear();
                in.ignore(1000, '\n');
                throw invalid_argument("Cap bac khong hop le");
            }
            return true;
        }
        string getInfo() override {
            return CanBo::getInfo() + "Loai: " + type + "\nCap bac: " + to_string(level) + "\n";
        }
};
class KiSu : public CanBo {
    private:
        string field;
        void settype() override {
            type = "Ki_Su";
        }
    public:
        KiSu() { settype(); }
        bool setInfo(istream &in) override{
            if(CanBo::setInfo(in) == false) return false;
            in >> field;
            return true;
        }
        string getInfo() override {
            return CanBo::getInfo() + "Loai: " + type + "\nLinh vuc: " + field + "\n";
        }
};
class NhanVien : public CanBo {
    private:
        string job;
        void settype() override {
            type = "Nhan_Vien";
        }
    public:
        NhanVien() { settype(); }
        bool setInfo(istream &in) override{
            if(CanBo::setInfo(in) == false) return false;
            in >> job;
            return true;
        }
        string getInfo() override {
            return CanBo::getInfo() + "Loai: " + type + "\nCong viec: " + job + "\n";
        }
};
class QuanLyCanBo {
    private:
        vector<CanBo*> canbos;
        int count;
    public:
        QuanLyCanBo() {
            count = 0;
        }
        void addCanBo(CanBo* cb) {
            canbos.push_back(cb);
        }
        void displayAll() {
            for (const auto& cb : canbos) {
                cout << cb->getInfo();
            }
        }
        void searchByName(string name) {
            for (const auto& cb : canbos) {
                if (cb->getName() == name) {
                    cout << cb->getInfo();
                    return;
                }
            }
            cout << "Not found" << endl;
        }
};
int main() {
    //Chuong trinh thu
    int type=0;
    QuanLyCanBo ql;
    while(type!=-1)
    {
        cout << "Nhap lua chon (1: Them, 2: Tim kiem, 3: In tat ca, -1: Thoat): ";
        cin >> type;
        cin.ignore();
        switch(type)
        {
            case 1: {
                int choice, n;
                cout << "Nhap so luong can bo can them: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Nhap loai (1: Cong Nhan, 2: Ki Su, 3: Nhan Vien): ";
                    cin >> choice;
                    CanBo* nhap = nullptr;
                    switch(choice)
                    {
                        case 1: nhap = new CongNhan(); break;
                        case 2: nhap = new KiSu(); break;
                        case 3: nhap = new NhanVien(); break;
                    }
                    try {
                        cin >> *nhap;
                        ql.addCanBo(nhap);
                    } 
                    catch (const invalid_argument& e) {
                        cerr << "Loi: " << e.what() << ". Nhap lai tu dau." << endl;
                        delete nhap; // FIX: Giải phóng bộ nhớ nếu nhập không hợp lệ
                        i--; // Lùi lại 1 bước để bắt nhập lại
                    }
                }
                break;
            }
            case 2: {
                string name;
                cout << "Nhap ten can bo can tim: ";
                cin >> name;
                ql.searchByName(name);
                break;
            }
            case 3: {
                ql.displayAll();
                break;
            }
        }
    }
    return 0;
}