#include <iostream>
#include <string>
using namespace std;
class sieu_nhan
{
    private:
        string ten,vukhi,mausac;
    public:
        void nhap(string a,string b,string c)
        {
            ten=a;
            vukhi=b;
            mausac=c;
        }
        void xuat()
        {
            cout<<ten<<" "<<vukhi<<" "<<mausac<<'\n';
        }
};
int main()
{
    sieu_nhan ds[1000],sna,snb;
    sna.nhap("A","kiem","do");
    snb.nhap("B","khien","xanh");
    sna.xuat();
    snb.xuat();
    bool empty;
    string x,y,z;
    long i=1;
    cout<<"Nhap lan luot cac thuoc tinh cua tung phan tu, nhan -1 de thoat:"<<'\n';
    while(true)
    {
        cin>>x;
        if(x=="-1") break;
        else 
        {
            cin>>y>>z;
            ds[i].nhap(x,y,z);
            i++;
        } 
    }
    for(long h=1;h<=i;h++) ds[h].xuat();
}
