#include <iostream>
using namespace std;
class diem
{
    public: 
        float x,y;
        void nhap(float a,float b)
        {
            x=a;
            y=b;
        }
};
class hinhtron
{
    private:
        float bk=75,tamx=150,tamy=100;
    public:
        bool point_in_circle(diem a)
        {
            if((tamx-a.x)*(tamx-a.x)+(tamy-a.y)*(tamy-a.y)<=bk*bk) return true;
            else return false;
        }
        bool rec_in_circle(diem a1,diem a2,diem a3,diem a4)
        {
            if(point_in_circle(a1)==false) return false;
            if(point_in_circle(a2)==false) return false;
            if(point_in_circle(a3)==false) return false;
            if(point_in_circle(a4)==false) return false;
            return true;
        }
};
int main()
{
    hinhtron f;
    diem d,hcn[5];
    float a,b;
    //Test ham point_in_circle
    cin>>a>>b;
    d.nhap(a,b);
    cout<<f.point_in_circle(d);
    //Test ham rec_in_circle
    for(long i=1;i<=4;i++)
    {
        cin>>a>>b;
        hcn[i].nhap(a,b);
    }
    cout<<f.rec_in_circle(hcn[1],hcn[2],hcn[3],hcn[4]);
}
