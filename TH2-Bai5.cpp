#include<iostream>
using namespace std;
class Ngay{
    private:
        int ngay, thang, nam;
    public:
        ~Ngay();
        Ngay();
        Ngay(int, int, int);
        friend bool namNhuan(int);
        friend int soNgaytrongThang(int, int);
        friend istream& operator>>(istream& in, Ngay& a);
        friend ostream& operator<<(ostream& out,const Ngay& a);
        int GetNgay() const;
        int GetThang() const;
        int GetNam() const;
        void SetNgay(int);
        void SetThang(int);
        void SetNam(int);
        void ThemNgay(int);
        void BotNgay(int);
        Ngay ngayketiep() const;
        Ngay ngaytruocdo() const;
        int thututrongnam() const;
        int thututrongtuan() const;
};
void Ngay::ThemNgay(int day){
    ngay+=day;
    while(ngay>soNgaytrongThang(thang, nam)){
        ngay-=soNgaytrongThang(thang, nam);
        thang++;
        if(thang>12){
            thang=1; nam++;
        }
    }
}
void Ngay::BotNgay(int day){
    ngay-=day;
    while(ngay<1){
        thang--;
        if(thang<1){
            thang=12; nam--;
            if(nam<1){
                cout<<"Khong the giam xuong duoi ngay 1/1/1"<<endl;
                ngay=1; thang=1; nam=1;
                return;
            }
        }
        ngay+=soNgaytrongThang(thang, nam);
    }
}
Ngay::Ngay(){
    ngay=1;
    thang=1;
    nam=1970;
}
Ngay::Ngay(int ngay, int thang, int nam){
    this->ngay=ngay;
    this->thang=thang;
    this->nam=nam;
}
Ngay::~Ngay(){

}
int Ngay::GetNgay() const{
    return this->ngay;
}
int Ngay::GetThang() const{
    return this->thang;
}
int Ngay::GetNam() const{
    return this->nam;
}
void Ngay::SetNgay(int ngay){
    if(ngay>=1&&ngay<=soNgaytrongThang(thang, nam)) this->ngay=ngay;
    else cout<<"Ngay khong hop le!"<<endl;
}
void Ngay::SetThang(int thang){
    if(thang>=1&&thang<=12) this->thang=thang;
    else cout<<"Thang khong hop le!"<<endl;
}
void Ngay::SetNam(int nam){
    if(nam>=1) this->nam = nam;
    else cout<<"Nam khong hop le!"<<endl;
}
bool namNhuan(int n){
    return (n%4==0&&n%100!=0)||(n%400==0);
}
int soNgaytrongThang(int thang, int nam){
    int nthang[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(thang==2&&namNhuan(nam)) return 29;
    else return nthang[thang];
}
istream& operator>>(istream &in, Ngay &a){
    cout<<"Nhap ngay: "; in>>a.ngay;
    cout<<"Nhap thang: "; in>>a.thang;
    cout<<"Nhap nam: "; in>>a.nam;
    while(a.nam<1||a.thang<1||a.thang>12||a.ngay<1||a.ngay>soNgaytrongThang(a.thang, a.nam)){
        cout<<"Ban nhap sai roi, moi ban nhap lai ";
        cout<<"Nhap ngay: "; in>>a.ngay;
        cout<<"Nhap thang: "; in>>a.thang;
        cout<<"Nhap nam: "; in>>a.nam;
    }
    return in;
}
ostream& operator<<(ostream &out,const Ngay& a){
    out<<a.ngay<<"/"<<a.thang<<"/"<<a.nam<<endl; 
    return out;
}
Ngay Ngay::ngayketiep() const{
    Ngay next=*this;
    if(next.ngay<soNgaytrongThang(next.thang, next.nam)) next.ngay++;
    else{
        next.ngay=1;
        if(next.thang==12){
            next.thang=1; next.nam++;
        }
        else next.thang++;
    }
    return next;
}
Ngay Ngay::ngaytruocdo() const{
    Ngay prev=*this;
    if(prev.ngay>1) prev.ngay--;
    else{
        if(prev.thang==1){
            prev.thang=12; prev.nam--;
        }
        else prev.thang--;
        prev.ngay=soNgaytrongThang(prev.thang, prev.nam);
    }
    return prev;
}
int Ngay::thututrongtuan() const{
    int tongngay=(nam-1)*365+(nam-1)/4-(nam-1)/100+(nam-1)/400+thututrongnam();
    return tongngay%7;
}
int Ngay::thututrongnam() const {
    int dem=ngay;
    for(int i=1; i<thang; i++) dem+=soNgaytrongThang(i, nam);
    return dem;
}
string week(int thu){
    string day[]={"chu nhat", "thu hai", "thu ba", "thu tu", "thu nam", "thu sau", "thu bay"};
    return day[thu];
}
int main(){
    Ngay a;
    do{
        cin>>a;
        while(true){
            cout<<"\n===== CHUONG TRINH KIEM TRA NGAY =====\n";
            cout<<"1. Dang thoat chuong trinh"<<endl;
            cout<<"2. In ra ngay thang nam vua nhap"<<endl;
            cout<<"3. Xem ngay tiep theo"<<endl;
            cout<<"4. Xem ngay truoc do"<<endl;
            cout<<"5. Xem ngay do la thu may trong tuan"<<endl;
            cout<<"6. Xem ngay do la ngay thu may trong nam"<<endl;
            cout<<"7. Tang len bao nhieu ngay"<<endl;
            cout<<"8. Bot di bao nhieu ngay"<<endl;
            cout<<"9. Toi muon doi ngay khac "<<endl;
            cout<<"Lua chon cua ban la:"<<endl;
            int chon; cin>>chon;
            if(chon==1){
                cout<<"Dang thoat chuong trinh...."<<endl;
                return 0;
            }
            else if(chon==2) cout<<"Ngay hien tai: "<<a;
            else if(chon==3) cout<<"Ngay ke tiep: "<<a.ngayketiep();
            else if(chon==4) cout<<"Ngay truoc do: "<<a.ngaytruocdo();
            else if(chon==5) cout<<"Hom nay la "<<week(a.thututrongtuan())<<endl;
            else if(chon==6) cout<<"Ngay nay la ngay thu "<<a.thututrongnam()<<" trong nam"<<endl;
            else if(chon==7){
                int up;
                cout<<"Nhap so ngay muon tang len: "; cin>>up;
                a.ThemNgay(up); cout<<a;
            }
            else if(chon==8){
                int down;
                cout<<"Nhap so ngay muon bot di: "; cin>>down;
                a.BotNgay(down); cout<<a;
            }
            else if(chon==9) break;
            else cout<<"Ban nhap sai roi, moi ban nhap lai"<<endl;
        }
    } while(true);
}