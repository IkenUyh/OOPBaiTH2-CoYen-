#include<iostream>
#include<cmath>
using namespace std;
class PTBac1{
    private:
        double a, b;
    public:
        ~PTBac1();
        PTBac1();
        PTBac1(double);
        PTBac1(double, double);
        double GetA() const;
        double GetB() const;
        void SetA(double);
        void SetB(double);
        void Nhap();
        void GiaiPT();
        void Xuat();
};
PTBac1::~PTBac1(){

}
PTBac1::PTBac1(){
    a=b=0;
}
PTBac1::PTBac1(double b){
    a=0;
    this->b=b;
}
PTBac1::PTBac1(double a, double b){
    this->a=a;
    this->b=b;
}
double PTBac1::GetA() const{
    return this->a;
}
double PTBac1::GetB() const{
    return this->b;
}
void PTBac1::SetA(double a){
    this->a=a;
}
void PTBac1::SetB(double b){
    this->b=b;
}
void PTBac1::Nhap(){
    cout<<"Nhap he so a: "; cin>>a;
    cout<<"Nhap he so b: "; cin>>b;
}
void PTBac1::GiaiPT(){
    if(a==0){
        if(b==0) cout<<"Phuong trinh vo so nghiem "<<endl;
        else cout<<"Phuong trinh vo nghiem "<<endl;
    }
    else{
        double x=-b/a;
        cout<<"PT co nghiem x = "<<x<<endl;
    }
}
void PTBac1::Xuat(){
    cout<<a<<"x";
    if(b>=0) cout<<" + "<<b;
    else cout<<" - "<<-b;
    cout<<" = 0 => ";
    GiaiPT();
}
class PTBac2{
    private:
        double a, b, c;
    public:
        ~PTBac2();
        PTBac2();
        PTBac2(double, double, double);
        double GetA() const;
        double GetB() const;
        double GetC() const;
        void SetA(double);
        void SetB(double);
        void SetC(double);
        void Nhap();
        void GiaiPT();
        void Xuat();
};
PTBac2::~PTBac2(){

}
PTBac2::PTBac2(){
    a=b=c=0;
}
PTBac2::PTBac2(double a, double b, double c){
    this->a=a;
    this->b=b;
    this->c=c;
}
double PTBac2::GetA() const{
    return this->a;
}
double PTBac2::GetB() const{
    return this->b;
}
double PTBac2::GetC() const{
    return this->c;
}
void PTBac2::SetA(double a){
    this->a=a;
}
void PTBac2::SetB(double b){
    this->b=b;
}
void PTBac2::SetC(double c){
    this->c=c;
}
void PTBac2::Nhap(){
    cout<<"Nhap he so a: "; cin>>a;
    cout<<"Nhap he so b: "; cin>>b;
    cout<<"Nhap he so c: "; cin>>c;
}
void PTBac2::GiaiPT(){
    if(a==0){
        if(b==0){
            if(c==0) cout<<"Phuong trinh vo so nghiem"<<endl;
            else cout<<"Phuong trinh vo nghiem";
        }
        else cout<<-c/b;
    }
    else{
        double delta=b*b-4*a*c;
        if(delta>0){
            cout<<"PT co hai nghiem phan biet: "<<endl;
            double x1=(-b+sqrt(delta))/(2*a);
            double x2=(-b-sqrt(delta))/(2*a);
            cout<<"x1 = "<<x1<<endl;
            cout<<"x2 = "<<x2<<endl;
        } 
        else if(delta==0) cout<<"PT co nghiem kep: x1 = x2 = "<<-b/(2*a);
        else cout<<"Phuong trinh vo nghiem";
    }
}
void PTBac2::Xuat(){
    cout<<a<<"x^2";
    if(b>=0) cout<<" + "<<b<<"x";
    else cout<<" - "<<-b<<"x";
    if(c>=0) cout<<" + "<<c;
    else cout<<" - "<<-c;
    cout<<" = 0 => ";
    GiaiPT();
}
int main(){
    cout<<"\n===== TINH PT BAC 1 =====\n";
    PTBac1 pt1;
    pt1.Nhap();
    cout<<"\n===== TINH PT BAC 2 =====\n";
    PTBac2 pt2;
    pt2.Nhap();
    pt1.Xuat(); pt2.Xuat();
    return 0;
}