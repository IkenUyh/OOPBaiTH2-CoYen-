#include<iostream>
#include<cmath>
using namespace std;
#define epsilon 0.000000001
class DIEM{
    private:
        double x, y;
    public:
        ~DIEM();
        DIEM(double=0, double=0);
        double GetX() const;
        double GetY() const;
        void SetX(double);
        void SetY(double);
        void SetXY(double, double);
        void Nhap();
        void Xuat();
        void DiChuyen(double, double);
        bool KiemTraTrung(const DIEM&) const;
        double TinhKhoangCach(const DIEM&) const;
        DIEM TimDoixung() const;
        bool KiemTraTamGiacHopLe(const DIEM&, const DIEM&) const;
        double TinhChuViTamGiac(const DIEM&, const DIEM&) const;
        double TinhDienTichTamGiac(const DIEM&, const DIEM&) const;
        string PhanLoaiTamGiac(const DIEM&, const DIEM&) const;
};
DIEM::~DIEM(){
    cout << "Da huy 1 DIEM\n";
}
DIEM::DIEM(double x, double y){
    this->x=x;
    this->y=y;
}
double DIEM::GetX() const{
    return x;
}
double DIEM::GetY() const{
    return y;
}
void DIEM::SetX(double x){
    this->x=x;
}
void DIEM::SetY(double y){
    this->y=y;
}
void DIEM::SetXY(double x, double y){
    this->x=x;
    this->y=y;
}
void DIEM::Nhap(){
    cout<<"Nhap hoanh do: "; cin>>x;
    cout<<"Nhap tung do: "; cin>>y;
}
void DIEM::Xuat(){
    cout<<x<<", "<<y;
}
void DIEM::DiChuyen(double dx, double dy){
    x+=dx; y+=dy;
}
bool DIEM::KiemTraTrung(const DIEM& d) const{
    return x==d.x&&y==d.y;
}
double DIEM::TinhKhoangCach(const DIEM& d) const{
    return sqrt(pow(x-d.x, 2)+pow(y-d.y, 2));
}
DIEM DIEM::TimDoixung() const{
    return DIEM(-x==0?x:-x, -y==0?y:-y);
}
bool DIEM::KiemTraTamGiacHopLe(const DIEM& d1, const DIEM& d2) const{
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    return a>0&&b>0&&c>0&&a+b>c&&a+c>b&&b+c>a;
}
double DIEM::TinhChuViTamGiac(const DIEM& d1, const DIEM& d2) const{
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    return KiemTraTamGiacHopLe(d1, d2)?a+b+c:0;
}
double DIEM::TinhDienTichTamGiac(const DIEM& d1, const DIEM& d2) const{
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    double p=TinhChuViTamGiac(d1, d2)/2.0;
    return KiemTraTamGiacHopLe(d1, d2)?sqrt(p*(p-a)*(p-b)*(p-c)):0;
}
string DIEM::PhanLoaiTamGiac(const DIEM& d1, const DIEM& d2) const{
    double a=this->TinhKhoangCach(d1);
    double b=d1.TinhKhoangCach(d2);
    double c=d2.TinhKhoangCach(*this);
    string chuoikq="";
    if(!KiemTraTamGiacHopLe(d1, d2)) chuoikq="TG khong hop le";
    else if(a==b&&b==c) chuoikq="TG deu";
    else if(a==b||b==c||c==a){
        if(abs(a*a+b*b-c*c)<=epsilon||abs(a*a+c*c-b*b)<=epsilon||abs(b*b+c*c-a*a)<=epsilon) chuoikq="TG vuong can";
        else chuoikq="TG can";
    }
    else if(abs(a*a+b*b-c*c)<=epsilon||abs(a*a+c*c-b*b)<=epsilon||abs(b*b+c*c-a*a)<=epsilon) chuoikq="TG vuong";
    else chuoikq="TG thuong";
    return chuoikq; 
}
int main(){
    DIEM d1, d2, d3;
    int chon;
    do{
        cout<<"\n===== CHUONG TRINH XU LY DIEM =====\n";
        cout<<"1. Nhap toa do 3 diem \n";
        cout<<"2. Xuat toa do 3 diem\n";
        cout<<"3. Di chuyen 1 diem\n";
        cout<<"4. Kiem tra cac diem trung nhau\n";
        cout<<"5. Tinh khoang cach 2 diem\n";
        cout<<"6. Tim diem doi xung cua 1 diem\n";
        cout<<"7. Tinh chu vi TG qua 3 diem\n";
        cout<<"8. Tinh dien tich TG qua 3 diem\n";
        cout<<"9. Phan loai TG qua 3 diem\n";
        cout<<"0. Thoat CT\n";
        cout<<"===================================\n";
        cout<<"Ban chon: "; cin>>chon;
        switch (chon){
            case 0:
                cout<<"Dang thoat chuong trinh...\n";
                break;
            case 1:
                cout<<"Nhap toa do diem d1:\n";
                d1.Nhap();
                cout<<"Nhap toa do diem d2:\n";
                d2.Nhap();
                cout<<"Nhap toa do diem d3:\n";
                d3.Nhap();
                break;
            case 2:
                cout<<"d1("; d1.Xuat(); cout<<")\n";
                cout<<"d2("; d2.Xuat(); cout<<")\n";
                cout<<"d3("; d3.Xuat(); cout<<")\n";
                break;
            case 3:{
                int diemchon;
                double dx, dy;
                do{
                    cout<<"Chon diem can di chuyen (1 - d1, 2 - d2, 3 - d3): ";
                    cin>>diemchon;
                }while(diemchon<1||diemchon>3);
                cout<<"Nhap khoang cach ngang, doc can di chuyen diem: ";
                cin>>dx>>dy;
                if(diemchon == 1) d1.DiChuyen(dx, dy);
                else if(diemchon == 2) d2.DiChuyen(dx, dy);
                else d3.DiChuyen(dx, dy);
                cout<<"Da di chuyen diem\n";
                break;
            }
            case 4:
                if(d1.KiemTraTrung(d2)&&d1.KiemTraTrung(d3))
                    cout<<"3 diem d1, d2, d3 trung nhau\n";
                else if(d1.KiemTraTrung(d2))
                    cout<<"d1 trung d2\n";
                else if(d1.KiemTraTrung(d3))
                    cout<<"d1 trung d3\n";
                else if(d2.KiemTraTrung(d3))
                    cout<<"d2 trung d3\n";
                else
                    cout<<"3 diem d1, d2, d3 khong trung nhau\n";
                break;
            case 5:
                cout<<"Khoang cach tu d1 den d2: "<< d1.TinhKhoangCach(d2)<<endl;
                cout<<"Khoang cach tu d2 den d3: "<< d2.TinhKhoangCach(d3)<<endl;
                cout<<"Khoang cach tu d1 den d3: "<< d1.TinhKhoangCach(d3)<<endl;
                break;
            case 6:{
                DIEM ddx;
                int diemchon;
                do{
                    cout<<"Chon diem can tim diem doi xung (1 - d1, 2 - d2, 3 - d3): ";
                    cin>>diemchon;
                } while(diemchon<1||diemchon>3);
                if(diemchon==1) ddx=d1.TimDoixung();
                else if(diemchon == 2) ddx=d2.TimDoixung();
                else ddx=d3.TimDoixung();
                cout<<"Diem doi xung: "; ddx.Xuat(); cout<<"\n";
                break;
            }
            case 7:
                if(d1.KiemTraTamGiacHopLe(d2, d3))
                    cout<<"Chu vi tam giac: "<< d1.TinhChuViTamGiac(d2, d3)<<endl;
                else
                    cout<<"3 diem khong tao thanh tam giac hop le\n";
                break;
            case 8:
                if(d1.KiemTraTamGiacHopLe(d2, d3))
                    cout<<"Dien tich tam giac: "<<d1.TinhDienTichTamGiac(d2, d3)<<endl;
                else
                    cout<<"3 diem khong tao thanh tam giac hop le\n";
                break;
            case 9:
                if(d1.KiemTraTamGiacHopLe(d2, d3))
                    cout<<"Loai tam giac: "<< d1.PhanLoaiTamGiac(d2, d3)<<endl;
                else
                    cout<<"3 diem khong tao thanh tam giac hop le\n";
                break;
            default:
                cout<<"Ban chon sai. Moi chon lai\n";
                break;
        }
    } while(chon!=0);
}