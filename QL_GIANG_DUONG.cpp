#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class giangduong {
private:
    string mgd, tgd, ml, tl, tgv, mgv;
    int tt, ss;

public:
    void nhapgd() {
        cin.ignore(32767, '\n');
        cout << "\t\t +| Ma giang duong: ";
        getline(cin, mgd);
        cout << "\t\t +| Ten giang duong: ";
        getline(cin, tgd);
        cout << "\t\t +| Ma lop: ";
        getline(cin, ml);
        cout << "\t\t +| ten lop: ";
        getline(cin, tl);
        cout << "\t\t +| Ten giao vien: ";
        getline(cin, tgv);
        cout << "\t\t +| Ma giao vien: ";
        getline(cin, mgv);
        cout << "\t\t +| Tinh trang giang duong: ( co su dung = 1, khong su dung = 0 )";
        cin >> tt;
        cout << "\t\t +| Si so: ";
        cin >> ss;
    }

    void luugd(string mgd, string tgd, int tt, int ss, string ml, string tl, string tgv, string mgv) {
        this->mgd = mgd;
        this->tgd = tgd;
        this->tt = tt;
        this->ml = ml;
        this->tl = tl;
        this->tgv = tgv;
        this->mgv = mgv;
        this->ss = ss;
    }

    void show() {
        cout << "\tlt +|Ma giang duong: " << mgd << endl;
        cout << "\tlt +|Ten giang duong: " << tgd << endl;
        if (tt == 0) {
            cout << "\t +|Tinh trang su dung : khong" << endl;
        }
        if (tt == 1) {
            cout << "\t +|Ting trang su dung : co" << endl;
        }
        cout << "\t +|Ma lop: " << ml << endl;
        cout << "\t +|ten lop: " << tl << endl;
        cout << "\t +|Ten giao vien: " << tgv << endl;
        cout << "\t +|ma giao vien: " << mgv << endl;
        cout << "\t +|si so: " << ss << endl;
    }

    int sisomax() {
        ss = ss * 1;
        return ss;
    }

    void showss() {
        cout << "\t +|Giang duong: " << tgd << "\n\t +|Si so: " << ss;
    }
};

class ngaythang : public giangduong {
private:
    int ngay, thang, nam;
    string tietdau, tietcuoi;

public:
    void nhapngay() {
        cout << "\t\t +| ngay: ";
        cin >> ngay;
        cout << "\t\t +| thang: ";
        cin >> thang;
        cout << "\t\t +| nam: ";
        cin >> nam;
        cout << "\t\t +| tiet bat dau: ";
        cin >> tietdau;
        cout << "\t\t +| tiet ket thuc: ";
        cin >> tietcuoi;
    }

    void luungay(int ngay, int thang, int nam, string tietdau, string tietcuoi) {
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
        this->tietdau = tietdau;
        this->tietcuoi = tietcuoi;
    }

    void showngay() {
        cout << "\t +|tiet bat dau: " << tietdau << endl;
        cout << "\t +|tiet ket thuc: " << tietcuoi << endl;
    }

    int chonngay() {
        ngay = ngay * 1;
        return ngay;
    }
};

ngaythang b[100];
int n = 0;
int x;

void themgd() {
    int sogd;
    cout << "them bao nhieu giang duong ?";
    cin >> sogd;
    cout << endl;
    for (int i = (n + 1); i <= (n + sogd); i++) {
        cout << "Nhap thong tin giang duong " << i << ": \n;";
        b[i].nhapgd();
        b[i].nhapngay();
        if (b[i + 1].chonngay() != b[i].chonngay()) {
            x++;
        }
    }
    n += sogd;
    cout << endl;
    system("pause");
}

void hienthi() {
    int so;
    cout << "dang co " << x << " giang duong trong du lieu " << endl;

    if (x != 0) {
        cout << "ban muon xem thong tin giang duong cua ngay nao ?\t\n";
        for (int i = 1; i <= x; i++) {
            cout << "[" << i << "]";
            b[i].showngay();
            cout << endl;
        }
        cin >> so;
        if (so > x) {
            cout << "khong co lua chon nay nen chon lai.";
        } else {
            b[so].show();
            b[so].showss();
            cout << endl;
        }
        system("pause");
    } else {
        cout << "hien chua co thong tin ve giang duong xin moi them thong tin giang duong.\n";
        system("pause");
    }
}

void timgd() {
    if (n == 0) {
        cout << "khong co giang duong nao xin moi nhap thong tin giang duong" << endl;
        system("pause");
        system("cls");
    } else {
        cout << endl;
        float max = b[1].sisomax(), diem;
        int vt_max = 1;
        for (int i = 2; i <= n; i++) {
            diem = b[i].sisomax();
            if (diem > max) {
                max = diem;
                vt_max = i;
            }
        }
        cout << "giang duong dong sinh vien nhat la:  \n";
        b[vt_max].showss();
        cout << "\n\t +|ngay: " << b[vt_max].chonngay() << endl;
        system("pause");
        system("cls");
    }
}

void timtong() {
    cout << endl;
    if (n == 0)
    {
    cout << "khong co giang duong nao xin moi nhap thong tin giang duong" << endl;
    system("pause");
    system("cls");

} else {
    int tong = 0;
    for (int i = 1; i <= n; i++) {
        tong += b[i].sisomax();
    }
    cout << "Tong sinh vien o tat ca gian duong moi ngay la : " << tong << endl;
    system("pause");
    system("cls");
}
}

int main() {
    time_t now = time(0);
    string tg = ctime(&now);
    int lap = 1;
    while (lap) {
        system("cls");
        cout << "\t\t\t\t thoi gian hien tai:" << tg << endl;
        cout << "\t\t\t\t\t\t\t MENU \n";
        cout << "\t\t\t\t\t\t\t[1] bo sung thong tin giang duong \n"
             << "\t\t\t\t\t\t\t[2] hien thi thong tin giang duong \n"
             << "\t\t\t\t\t\t\t[3] hien thi giang duong dong sv nhat\n"
             << "\t\t\t\t\t\t\t[4] hient hi tong sinh vien di hoc\n";
        int cauhoi;
        cout << "\n\t\t\t\t\t\ Moi lua chon: \t";
        cin >> cauhoi;
        switch (cauhoi) {
        case 1:
            system("cls");
            cout << "\t\t\t\t thoi gian hien tai: " << tg << endl;
            cout << "\t[1] bo sung thong tin giang duong \n";
            themgd();
            break;
        case 2:
            system("cls");
            cout << "\t\t\t\t thoi gian hien tai: " << tg << endl;
            cout << "\t[2] hien thi thong tin giang duong\n";
            hienthi();
            break;
        case 3:
            system("cls");
            cout << "\t\t\t\t thoi gian hien tai: " << tg << endl;
            cout << "\t[3] hien thi giang duong dong sinh vien nhat\n";
            timgd();
            break;
        case 4:
            system("cls");
            cout << "\t\t\t\t thoi gian hien tai: " << tg << endl;
            cout << "\t[4] hien thi tong sinh vien di hoc\n";
            timtong();
            break;
        }
        system("cls");
        cout << "\n\n\t\t BACK TO MENU ? (co =1 ,khong = 0)\t";
        cin >> lap; //diu kien de while lap
    }
    return 0;
}


