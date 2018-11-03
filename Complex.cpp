#include <iostream>

using namespace std;

class Complex {
    private: 
        float phanthuc, phanao;
    public: 
        Complex() {
            phanthuc=0;
            phanao=0;
        }

        void nhap() {
            cout << "Nhap vao phan thuc: ";
            cin >> phanthuc;
            cout << "Nhap vao phan ao: ";
            cin >> phanao;
        }

        void xuat() {
            cout << phanthuc << "+ " << phanao << "i\n";
        }

        friend Complex operator* (Complex &a, Complex &b) {
            Complex tich;
            tich.phanthuc=a.phanthuc*b.phanthuc - a.phanao*b.phanao;
            tich.phanao=a.phanthuc*b.phanao + b.phanthuc*a.phanao;
            return tich;
        }

        friend bool operator== (Complex &a, Complex &b) {
            if(a.phanthuc==b.phanthuc && a.phanao==b.phanao)
                return true;
            else    
                return false;
        }
};

int main() {
    Complex a;
    Complex b;
    cout << "Nhap vao so phuc 1:\n";
    a.nhap();
    cout << "Nhap vao so phuc 2:\n";
    b.nhap();
    cout << "Hai so phuc vua nhap:\n";
    a.xuat();
    b.xuat();
    Complex tich;
    tich = a*b;
    cout << "Tich cua 2 so phuc la: ";
    tich.xuat();
    if (a==b)
        cout << "Hai so phuc bang nhau.\n";
    else    
        cout << "Hai so phuc khong bang nhau.\n";
    return 0;
}