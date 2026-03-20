#include <iostream>
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
};
class lineSegment
{
    private:
        point d1;
        point d2;
    public:
        void line()
        {
            d1.nhap(8.0,5.0);
            d2.nhap(1.0,0.0);
        }
        void line(point a,point b)
        {
            d1=a;
            d2=b;
        }
        void line(float a1,float a2,float b1,float b2)
        {
            d1.nhap(a1,a2);
            d2.nhap(b1,b2);
        }
        void line(lineSegment a)
        {
            d1=a.d1;
            d2=a.d2;
        }
        void xuat()
        {
            d1.xuat();
            d2.xuat();
            cout<<'\n';
        }
};
int main()
{
    //Chuong trinh kiem thu cac ham khoi tao cua class lineSegment
    point x,y;
    lineSegment doan1,doan2,doan3,doan4,mau;
    x.nhap(1,1);
    y.nhap(2,2);
    mau.line(2,3,4,5);
    doan1.line();
    doan2.line(x,y);
    doan3.line(1,2,3,4);
    doan4.line(mau);
    doan1.xuat();
    doan2.xuat();
    doan3.xuat();
    doan4.xuat();
}