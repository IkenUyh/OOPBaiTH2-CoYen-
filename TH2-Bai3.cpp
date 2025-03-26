#include<iostream>
using namespace std;
class SoPhuc{
    private:
        double real, imag;
    public:
        ~SoPhuc();
        SoPhuc();
        SoPhuc(double, double);
        void Nhap();
        void Xuat();
        friend SoPhuc operator+(const SoPhuc& a, const SoPhuc& b);
        friend SoPhuc operator-(const SoPhuc& a, const SoPhuc& b);
        friend SoPhuc operator*(const SoPhuc& a, const SoPhuc& b);
        friend SoPhuc operator/(const SoPhuc& a, const SoPhuc& b);
};
SoPhuc::SoPhuc(){
    real=imag=0;
}
SoPhuc::SoPhuc(double real, double imag){
    this->real=real;
    this->imag=imag;
}
SoPhuc::~SoPhuc(){

}
void SoPhuc::Nhap(){
    cout<<"Nhap phan thuc: "; cin>>real;
    cout<<"Nhap phan ao: "; cin>>imag;
}
void SoPhuc::Xuat(){
    if(imag<0) cout<<real<<" - "<<-imag<<"i"<<endl;
    else cout<<real<<" + "<<imag<<"i"<<endl;
}
SoPhuc operator+(const SoPhuc& a, const SoPhuc& b){
    return SoPhuc(a.real+b.real, a.imag+b.imag);
}
SoPhuc operator-(const SoPhuc& a, const SoPhuc& b){
    return SoPhuc(a.real-b.real, a.imag-b.imag);
}
SoPhuc operator*(const SoPhuc& a, const SoPhuc& b){
    return SoPhuc(a.real*b.real-a.imag*b.imag, a.real*b.imag+a.imag*b.real);
}
SoPhuc operator/(const SoPhuc& a, const SoPhuc& b){
    double mau=b.real*b.real+b.imag*b.imag;
    if(mau==0){
        cout<<"Loi: khong the chia het cho so phuc (0, 0)!"<<endl;
        return SoPhuc(0, 0);
    }
    return SoPhuc((a.real*b.real+a.imag*b.imag)/(double)mau, (a.imag*b.real-a.real*b.imag)/(double)mau);
}
int main(){
    SoPhuc a, b;
    do{
        cout<<"Nhap so phuc thu nhat: "; a.Nhap();
        cout<<"Nhap so phuc thu hai: "; b.Nhap();
        while(true){
            cout<<"\n===== CHUONG TRINH TINH TOAN SO PHUC =====\n";
            cout<<"1. Thoat chuong trinh"<<endl;
            cout<<"2. Tinh tong 2 so phuc"<<endl;
            cout<<"3. Tinh hieu 2 so phuc"<<endl;
            cout<<"4. Tinh tich 2 so phuc"<<endl;
            cout<<"5. Tinh thuong 2 so phuc"<<endl;
            cout<<"6. Toi muon doi so phuc khac"<<endl;
            cout<<"Lua chon cua ban la:"<<endl;
            int chon; cin>>chon;
            if(chon==1){
                cout<<"Dang thoat chuong trinh...."<<endl;
                return 0;
            }
            else if(chon==2){
                cout<<"Tong 2 so phuc la: "; (a+b).Xuat();
            }
            else if(chon==3){
                cout<<"Hieu 2 so phuc la: "; (a-b).Xuat(); 
            }
            else if(chon==4){
                cout<<"Tich 2 so phuc la: "; (a*b).Xuat();
            }
            else if(chon==5){
                cout<<"Thuong 2 so phuc la: "; (a/b).Xuat(); 
            }
            else if(chon==6) break;
            else cout<<"Ban nhap sai roi, moi ban nhap lai"<<endl;
        }
    } while(true);
}