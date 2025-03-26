#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Vehicle{
    private:
        string chuxe, type;
        double value;
        int xylanh;
    public:
        Vehicle();
        Vehicle(string, string, double, int);
        ~Vehicle();
        friend istream& operator>>(istream& in, Vehicle& xe);
        friend ostream& operator<<(ostream& out, const Vehicle& xe);
        string GetChuxe() const;
        string GetType() const;
        double GetValue() const;
        int GetXylanh() const;
        void SetChuxe(string);
        void SetType(string);
        void SetValue(double);
        void SetXylanh(int);
        double Calc() const;
};
Vehicle::Vehicle(){
    chuxe=type="";
    value=xylanh=0;
}
Vehicle::Vehicle(string chuxe, string type, double value, int xylanh){
    this->chuxe=chuxe;
    this->type=type;
    this->value=(value>=0)?value:0;
    this->xylanh=(xylanh>=0)?xylanh:0;
}
Vehicle::~Vehicle(){

}
string Vehicle::GetChuxe() const{
    return this->chuxe;
}
string Vehicle::GetType() const{
    return this->type;
}
double Vehicle::GetValue() const{
    return this->value;
}
int Vehicle::GetXylanh() const{
    return this->xylanh;
}
void Vehicle::SetChuxe(string chuxe){
    this->chuxe=chuxe;
}
void Vehicle::SetType(string type){
    this->type=type;
}
void Vehicle::SetValue(double value){
    if(value>=0) this->value=value;
    else cout<<"Tri gia xe phai >=0";
}
void Vehicle::SetXylanh(int xylanh){
    if(xylanh>=0) this->xylanh=xylanh;
    else cout<<"Dung tich xy-lanh phai >=0";
}
istream& operator>>(istream& in, Vehicle& xe){
    cout<<"Nhap thong tin chu xe: "; getline(in, xe.chuxe);
    cout<<"Nhap thong tin loai xe: "; getline(in, xe.type);
    do{
        cout<<"Nhap thong tin tri gia xe: "; in>>xe.value;
        if(xe.value<0) cout<<"Tri gia xe phai >=0, moi ban nhap lai!"<<endl;
    } while(xe.value<0);
    do{
        cout<<"Nhap thong tin dung tich xy-lanh xe: "; in>>xe.xylanh;
        if(xe.xylanh<0) cout<<"Dung tich xy-lanh xe phai >=0, moi ban nhap lai! "<<endl;
    } while(xe.xylanh<0);
    return in;
}
ostream& operator<<(ostream& out, const Vehicle& xe){
    out<<"\n===== Bang Thong Ke Xe =====\n";
    out<<"Chu xe: "<<xe.chuxe<<endl;
    out<<"Loai xe: "<<xe.type<<endl;
    out<<"Tri gia xe: "<<fixed<<setprecision(2)<<xe.value<<endl;
    out<<"Dung tich xy-lanh xe: "<<xe.xylanh<<endl;
    out<<"Thue truoc ba: "<<xe.Calc()<<endl;
    out<<"===================================\n";
    return out;
}
double Vehicle::Calc() const{
    if(xylanh<100) return value*0.01;
    else if(xylanh>=100&&xylanh<=200) return value*0.03;
    else return value*0.05;
}
int main(){
    Vehicle x1("Pham Tran Cong Bao Anh", "Xe may", 30000000, 110);
    Vehicle x2("Nguyen Minh Duy", "Xe may", 45000000, 250);
    Vehicle x3; cin>>x3;
    cout<<"\n===== BANG KE KHAI THONG TIN XE VA THUE TRUOC BA =====\n";
    cout<<x1<<x2<<x3;
    return 0;
}