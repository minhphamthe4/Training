#include <iostream>
#include <string>
using namespace std;
class CanBo {
    protected:
        string name;
        int age;
        string sex;
        string address;
    public:
        virtual void setInfo() {
            cout << "Nhap ten: ";
            cin.ignore();
            getline(cin, name);
            cout << "Nhap tuoi: ";
            cin >> age;
            cout << "Nhap gioi tinh: ";
            cin.ignore();
            getline(cin, sex);
            cout << "Nhap dia chi: ";
            getline(cin, address);
        }
        virtual void getInfo() {
            cout << "Ten: " << name << endl;
            cout << "Tuoi: " << age << endl;
            cout << "Gioi tinh: " << sex << endl;
            cout << "Dia chi: " << address << endl;
        }
        string getName() {
            return name;
        }
};
class CongNhan : public CanBo {
    private:
        int level;
    public:
        void setInfo() override{
            CanBo::setInfo();
            cout << "Nhap cap bac: ";
            cin >> level;
        }
        void getInfo() override {
            CanBo::getInfo();
            cout << "Cap bac: " << level << endl;
        }
};
class KiSu : public CanBo {
    private:
        string field;
    public:
        void setInfo() override{
            CanBo::setInfo();
            cout << "Nhap linh vuc: ";
            getline(cin, field);
        }
        void getInfo() override {
            CanBo::getInfo();
            cout << "Linh vuc: " << field << endl;
        }
};
class NhanVien : public CanBo {
    private:
        string job;
    public:
        void setInfo() override{
            CanBo::setInfo();
            cout << "Nhap cong viec: ";
            getline(cin, job);
        }
        void getInfo() override {
            CanBo::getInfo();
            cout << "Cong viec: " << job << endl;
        }
};
class QuanLyCanBo {
    private:
        CanBo* canbos[10000];
        int count;
    public:
        QuanLyCanBo() {
            count = 0;
        }
        void addCanBo(CanBo* cb) {
            if (count < 10000) {
                canbos[count++] = cb;
            }
        }
        void displayAll() {
            for (int i = 0; i < count; i++) {
                canbos[i]->getInfo();
                cout << endl;
            }
        }
        void searchByName(string name) {
            for (int i = 0; i < count; i++) {
                if (canbos[i]->getName() == name) {
                    canbos[i]->getInfo();
                    cout << endl;
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
                    switch(choice)
                    {
                        case 1: {
                        CongNhan* cn = new CongNhan();
                        cn->setInfo();
                        ql.addCanBo(cn);
                        break;
                    }
                        case 2: {
                            KiSu* ks = new KiSu();
                            ks->setInfo();
                            ql.addCanBo(ks);
                            break;
                        } 
                        case 3: {
                            NhanVien* nv = new NhanVien();
                            nv->setInfo();
                            ql.addCanBo(nv);
                            break;
                        }
                    }
                }
                break;
            }
            case 2: {
                string name;
                cout << "Nhap ten can bo can tim: ";
                cin.ignore();
                getline(cin, name);
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