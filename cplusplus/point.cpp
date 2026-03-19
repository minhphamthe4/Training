#include <iostream>
#include <math.h>
using namespace std;
class point
{
    private:
        float x,y;
    public:
        void nhap(float a,float b)
        {
            x=a;
            y=b;
        }
        void xuat()
        {
            cout<<x<<" "<<y<<'\n';
        }
        float dis(point b)
        {
            return sqrt(pow(x-b.x,2)+pow(y-b.y,2));
        }
        point doixung()
        {
            point dx;
            dx.nhap(-x,-y);
            return dx;
        }
};
int main()
{
    point diem0,diema,diemb,kq;
    diem0.nhap(0,0);
    diema.nhap(3,4);
    diema.xuat();
    float a,b;
    cin>>a>>b;
    diemb.nhap(a,b);
    kq=diemb.doixung();
    kq.xuat();
    cout<<diemb.dis(diem0)<<'\n'<<diemb.dis(diema);
}