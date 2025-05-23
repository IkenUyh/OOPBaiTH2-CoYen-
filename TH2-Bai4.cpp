#include<iostream>
#include<cmath>
using namespace std;
#define epsilon 0.000000001
class TamGiac{
    private:
        double a, b, c;
        static int dem;
    public:
        ~TamGiac();
        TamGiac();
        TamGiac(double, double, double);
        TamGiac& operator=(const TamGiac& tg);
        void Nhap();
        void Xuat() const;
        double GetA() const;
        double GetB() const;
        double GetC() const;
        static int GetDem();
        void SetA(double);
        void SetB(double);
        void SetC(double);
        friend istream& operator>>(istream& in, TamGiac& tg);
        friend ostream& operator<<(ostream& out, const TamGiac& tg);
        bool KiemTraTamGiacHopLe() const;
        string PhanLoaiTamGiac() const;
        double ChuViTamGiac() const;
        double DienTichTamGiac() const;
};
int TamGiac::dem=0;
TamGiac::~TamGiac(){

}
TamGiac::TamGiac(){
    a=b=c=1;
}
TamGiac::TamGiac(double a, double b, double c){
    this->a=a;
    this->b=b;
    this->c=c;
}
TamGiac& TamGiac::operator=(const TamGiac& tg){
    a=tg.a; b=tg.b; c=tg.c;
}
double TamGiac::GetA() const{
    return this->a;
}
double TamGiac::GetB() const{
    return this->b;
}
double TamGiac::GetC() const{
    return this->c;
}
int TamGiac::GetDem(){
    return dem;
}
void TamGiac::SetA(double a){
    this->a=a;
}
void TamGiac::SetB(double b){
    this->b=b;
}
void TamGiac::SetC(double c){
    this->c=c;
}
istream& operator>>(istream& in, TamGiac& tg){
    tg.Nhap(); 
    return in;
}
ostream& operator<<(ostream& out, const TamGiac& tg){
    tg.Xuat();
    return out;
}
void TamGiac::Nhap(){
    cout<<"Nhap do dai ba canh cua tam giac "<<endl;
    cout<<"Nhap do dai canh thu nhat: "; cin>>a;
    cout<<"Nhap do dai canh thu hai: "; cin>>b;
    cout<<"Nhap do dai canh thu ba: "; cin>>c;
}
bool TamGiac::KiemTraTamGiacHopLe() const{
    return a>0&&b>0&&c>0&&a+b>c&&a+c>b&&b+c>a;
}
string TamGiac::PhanLoaiTamGiac() const{
    if(!KiemTraTamGiacHopLe()) return "TG khong hop le";
    else if(a==b&&b==c) return "TG deu";
    else if(a==b||b==c||c==a){
        if(abs(a*a+b*b-c*c)<=epsilon||abs(a*a+c*c-b*b)<=epsilon||abs(b*b+c*c-a*a)<=epsilon) return "TG vuong can";
        else return "TG can";
    }
    else if(abs(a*a+b*b-c*c)<=epsilon||abs(a*a+c*c-b*b)<=epsilon||abs(b*b+c*c-a*a)<=epsilon) return "TG vuong";
    else return "TG thuong";
}
double TamGiac::ChuViTamGiac() const{
    return KiemTraTamGiacHopLe()?a+b+c:0;
}
double TamGiac::DienTichTamGiac() const{
    double p=ChuViTamGiac()/2.0;
    return KiemTraTamGiacHopLe()?sqrt(p*(p-a)*(p-b)*(p-c)):0;
}
void TamGiac::Xuat() const{
    cout<<"Do dai ba canh cua tam giac: "<<a<<", "<<b<<", "<<c<<endl;
    if(KiemTraTamGiacHopLe()){
        cout<<"Tam giac thuoc loai "<<PhanLoaiTamGiac()<<endl;
        cout<<"Chu vi tam giac: "<<ChuViTamGiac()<<endl;
        cout<<"Dien tich tam giac: "<<DienTichTamGiac()<<endl;
    }
    else cout<<"Ba canh cua tam giac khong hop le "<<endl;
}
int main(){
    TamGiac tg;
    tg.Nhap(); tg.Xuat();
    return 0;
}