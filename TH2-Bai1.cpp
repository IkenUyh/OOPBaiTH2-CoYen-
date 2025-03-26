#include<iostream>
using namespace std;
#define ll long long
#define endl "\n"
inline ll gcd(ll a, ll b){ll r; while(b){r=a%b;a=b;b=r;} return a;}
inline ll lcm(ll a, ll b){return a/gcd(a, b)*b;}
class cPhanSo{
    private:
        int tu, mau;
    public:
        ~cPhanSo();
        cPhanSo();
        cPhanSo(int, int); 
        void Nhap();
        void Xuat();
        void rutgon(); 
        friend cPhanSo operator+(cPhanSo a, cPhanSo b); 
        friend cPhanSo operator-(cPhanSo a, cPhanSo b); 
        friend cPhanSo operator*(cPhanSo a, cPhanSo b); 
        friend cPhanSo operator/(cPhanSo a, cPhanSo b);
};
cPhanSo::cPhanSo(){
    tu=0; mau=1;
}
cPhanSo::cPhanSo(int tu, int mau){
    this->tu=tu;
    this->mau=mau;
}
cPhanSo::~cPhanSo(){
    
}
void cPhanSo::Nhap(){
    cout<<"Nhap tu so: "; cin>>tu;
    cout<<"Nhap mau so: "; cin>>mau;
    while(!mau){
        cout<<"Nhap lai mau so khac 0: ";
        cin>>mau;
    }
}
void cPhanSo::rutgon(){
    int ucln=gcd(abs(tu), abs(mau)); 
    tu/=ucln; mau/=ucln; 
    if(mau<0){
        tu=-tu;
        mau=-mau;
    }
}
void cPhanSo::Xuat(){
    rutgon();
    if(!tu){
        cout<<"Phan so la so 0"<<endl;
    }
    else if(mau==1) cout<<"Phan So la so "<<tu<<endl;
    else cout<<"Phan So la so "<<tu<<"/"<<mau<<endl;
}
cPhanSo operator+(cPhanSo a, cPhanSo b){
    a.rutgon(); b.rutgon();
    int bcnn=lcm(a.mau, b.mau); 
    a.tu*=(bcnn/a.mau); b.tu*=(bcnn/b.mau);
    cPhanSo c;
    c.tu=a.tu+b.tu; c.mau=bcnn;
    return c;
}
cPhanSo operator-(cPhanSo a, cPhanSo b){
    a.rutgon(); b.rutgon();
    int bcnn=lcm(a.mau, b.mau);
    a.tu*=(bcnn/a.mau); b.tu*=(bcnn/b.mau);
    cPhanSo c;
    c.tu=a.tu-b.tu;
    c.mau=bcnn;
    return c;
}
cPhanSo operator*(cPhanSo a, cPhanSo b){
    a.rutgon(); b.rutgon();
    cPhanSo c;
    c.tu=a.tu*b.tu; c.mau=a.mau*b.mau;
    return c;
}
cPhanSo operator/(cPhanSo a, cPhanSo b){
    a.rutgon(); b.rutgon();
    cPhanSo c;
    if(!b.tu){ 
        cout<<"Phan so thu 2 tu khong duoc la 0"<<endl;
        return cPhanSo(0, 1);
    }
    c.tu=a.tu*b.mau; c.mau=a.mau*b.tu;
    return c;
}
int main(){
    cPhanSo a, b;
    do{
        cout<<"Nhap phan so thu nhat: "<<endl; a.Nhap();
        cout<<"Nhap phan so thu hai: "<<endl; b.Nhap();
        while(true){
            cout<<"\n===== CHUONG TRINH TINH TOAN PHAN SO =====\n";
            cout<<"1. Thoat chuong trinh"<<endl;
            cout<<"2. Tinh tong 2 phan so"<<endl;
            cout<<"3. Tinh hieu 2 phan so"<<endl;
            cout<<"4. Tinh tich 2 phan so"<<endl;
            cout<<"5. Tinh thuong 2 phan so"<<endl;
            cout<<"6. Toi muon doi phan so khac"<<endl;
            cout<<"Lua chon cua ban la:"<<endl;
            int chon; cin>>chon;
            if(chon==1){
                cout<<"Dang thoat chuong trinh...."<<endl;
                return 0;
            }
            else if(chon==2){
                cout<<"Tong 2 phan so la: "; (a+b).Xuat();
            }
            else if(chon==3){
                cout<<"Hieu 2 phan so la: "; (a-b).Xuat(); 
            }
            else if(chon==4){
                cout<<"Tich 2 phan so la: "; (a*b).Xuat();
            }
            else if(chon==5){
                cout<<"Thuong 2 phan so la: "; (a/b).Xuat(); 
            }
            else if(chon==6) break;
            else cout<<"Ban nhap sai roi, moi ban nhap lai"<<endl;
        }
    } while(true);
}