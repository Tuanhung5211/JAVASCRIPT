// Quan ly danh sach sinh vien
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

// Khai bao cau truc du lieu cho sinh vien
typedef struct {
    char maSV[15];         
    char hoTen[50];        
    char ngaySinh[15];     
    char lop[20];          
    char gioiTinh[10];     
    char sdt[15];          
    char diaChi[100];      
    float gpa;             
} SinhVien;

SinhVien ds[MAX]; 
int soLuong = 0;   

void xoaXuongDong(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void clearBuffer() {
    while (getchar() != '\n');
}

int kiemTraMaSVTrung(char *maSV) {
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(ds[i].maSV, maSV) == 0) {
            return 1;
        }
    }
    return 0;  
}

int kiemTraSdtTrung(char *sdt) {
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(ds[i].sdt, sdt) == 0) {
            return 1;  
        }
    }
    return 0; 
}

void nhapSinhVien() {
    int n;
    printf("Nhap so luong sinh vien can them: ");
    scanf("%d", &n);
    clearBuffer();
    if (soLuong + n > MAX) {
        printf("Khong the them %d sinh vien. Chi con %d cho trong.\n", n, MAX - soLuong);
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        do {
            printf("Nhap ma sinh vien: ");
            fgets(ds[soLuong].maSV, sizeof(ds[soLuong].maSV), stdin);
            xoaXuongDong(ds[soLuong].maSV);
            if (kiemTraMaSVTrung(ds[soLuong].maSV)) {
                printf("Ma sinh vien da ton tai, vui long nhap lai.\n");
            } else {
                break;
            }
        } while (1);
        printf("Nhap ho va ten: ");
        fgets(ds[soLuong].hoTen, sizeof(ds[soLuong].hoTen), stdin);
        xoaXuongDong(ds[soLuong].hoTen);
        printf("Nhap ngay sinh (dd/mm/yyyy): ");
        fgets(ds[soLuong].ngaySinh, sizeof(ds[soLuong].ngaySinh), stdin);
        xoaXuongDong(ds[soLuong].ngaySinh);
        printf("Nhap lop: ");
        fgets(ds[soLuong].lop, sizeof(ds[soLuong].lop), stdin);
        xoaXuongDong(ds[soLuong].lop);
        printf("Nhap gioi tinh: ");
        fgets(ds[soLuong].gioiTinh, sizeof(ds[soLuong].gioiTinh), stdin);
        xoaXuongDong(ds[soLuong].gioiTinh);
        do {
            printf("Nhap so dien thoai: ");
            fgets(ds[soLuong].sdt, sizeof(ds[soLuong].sdt), stdin);
            xoaXuongDong(ds[soLuong].sdt);
            if (kiemTraSdtTrung(ds[soLuong].sdt)) {
                printf("So dien thoai da ton tai, vui long nhap lai.\n");
            } else {
                break;
            }
        } while (1);
        printf("Nhap dia chi: ");
        fgets(ds[soLuong].diaChi, sizeof(ds[soLuong].diaChi), stdin);
        xoaXuongDong(ds[soLuong].diaChi);
        printf("Nhap GPA: ");
        scanf("%f", &ds[soLuong].gpa);
        clearBuffer();
        soLuong++;
        printf("________________________________________________________________\n");
    }
    printf("\nDa them %d sinh vien thanh cong!\n", n);
}
// Ham hien thi danh sach sinh vien theo bang cot
void hienThiDanhSach() {
    if (soLuong == 0) {
        printf("Danh sach trong.\n");
        return;
    }
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-8s   | %-25s | %-10s | %-10s | %-8s | %-12s | %-20s | %-5s |\n",
           "MaSV", "Ho va Ten", "Ngay Sinh", "Lop", "Gioi Tinh", "So DT", "Dia Chi", "GPA");
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < soLuong; i++) {
        printf("| %-8s | %-25s | %-10s | %-10s | %-8s  | %-12s | %-20s | %-5.2f |\n",
               ds[i].maSV, ds[i].hoTen, ds[i].ngaySinh, ds[i].lop,
               ds[i].gioiTinh, ds[i].sdt, ds[i].diaChi, ds[i].gpa);
    }	
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");
}

// Ham xem danh sach sinh vien
void xemDanhSach() {
    hienThiDanhSach();
}

// Ham hien thi thong tin chi tiet cua mot sinh vien
void hienThiSinhVien(SinhVien sv) {
    printf("MaSV: %s\n", sv.maSV);
    printf("Ho ten: %s\n", sv.hoTen);
    printf("Ngay sinh: %s\n", sv.ngaySinh);
    printf("Lop: %s\n", sv.lop);
    printf("Gioi tinh: %s\n", sv.gioiTinh);
    printf("So dien thoai: %s\n", sv.sdt);
    printf("Dia chi: %s\n", sv.diaChi);
    printf("GPA: %.2f\n", sv.gpa);
    printf("----------------------------\n");
}

// Ham chinh sua thong tin sinh vien theo maSV
void chinhSua() {
    char ma[10];
    printf("Nhap ma sinh vien can sua: ");
    scanf("%s", ma);
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(ds[i].maSV, ma) == 0) {
            printf("Nhap lai thong tin cho sinh vien %s:\n", ds[i].maSV);
            printf("Nhap ho va ten: ");
            fflush(stdin);
            gets(ds[i].hoTen);
            printf("Nhap ngay sinh: ");
            scanf("%s", ds[i].ngaySinh);
            printf("Nhap lop: ");
            scanf("%s", ds[i].lop);
            printf("Nhap gioi tinh: ");
            scanf("%s", ds[i].gioiTinh);
            printf("Nhap so dien thoai: ");
            scanf("%s", ds[i].sdt);
            printf("Nhap dia chi: ");
            fflush(stdin);
            gets(ds[i].diaChi);
            printf("Nhap GPA: ");
            scanf("%f", &ds[i].gpa);
            printf("Chinh sua thanh cong!\n");
            printf("Thong tin sinh vien sau khi chinh sua:\n");
            hienThiSinhVien(ds[i]);
            return;
        }
    }
    printf("Khong tim thay sinh vien!\n");
}

// Ham xoa sinh vien theo maSV
void xoaSinhVien() {
    char ma[10];
    printf("Nhap ma sinh vien can xoa: ");
    scanf("%s", ma);
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(ds[i].maSV, ma) == 0) {
            for (int j = i; j < soLuong - 1; j++) {
                ds[j] = ds[j + 1];
            }
            soLuong--;
            printf("Xoa thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien!\n");
}

// Ham tim kiem sinh vien theo maSV
void timKiemTheoMssv() {
    char ma[10];
    printf("Nhap ma sinh vien can tim: ");
    scanf("%s", ma);
    int found = 0;
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(ds[i].maSV, ma) == 0) {
            hienThiSinhVien(ds[i]);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Khong tim thay sinh vien!\n");
}

// Ham sap xep sinh vien theo maSV tang dan
void sapXepTheoMa(SinhVien arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i].maSV, arr[j].maSV) > 0) {
                SinhVien temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
        }
    }
}

// Ham sap xep sinh vien theo GPA giam dan
void sapXepTheoGPA(SinhVien arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].gpa < arr[j].gpa) {
                SinhVien temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
        }
    }
}

// Ham thong ke tong so va GPA trung binh
void thongKe() {
    printf("Tong so sinh vien: %d\n", soLuong);
    float tongGPA = 0;
    for (int i = 0; i < soLuong; i++) tongGPA += ds[i].gpa;
    printf("GPA trung binh: %.2f\n", soLuong ? tongGPA / soLuong : 0);
}

// Ham hien thi sinh vien theo lop
void hienThiTheoLop() {
    char lop[20];
    printf("Nhap ten lop: ");
    scanf("%s", lop);
    int dem = 0;
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(ds[i].lop, lop) == 0) {
            hienThiSinhVien(ds[i]);
            dem++;
        }
    }
    if (dem == 0)
        printf("Khong co sinh vien nao trong lop %s.\n", lop);
}

// Ham ghi danh sach sinh vien ra file theo lua chon
void ghiDanhSachRaFileTheoLuaChon(SinhVien arr[], int n, const char* tenFile) {
    FILE *f = fopen(tenFile, "w");
    if (f == NULL) {
        printf("Khong the mo file %s!\n", tenFile);
        return;
    }
    fprintf(f, "----------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(f, "| %-8s  | %-25s | %-10s | %-10s | %-8s | %-12s | %-20s | %-5s |\n",
            "MaSV", "Ho va Ten", "Ngay Sinh", "Lop", "Gioi Tinh", "So DT", "Dia Chi", "GPA");
    fprintf(f, "----------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        fprintf(f, "| %-8s | %-25s | %-10s | %-10s | %-8s  | %-12s | %-20s | %-5.2f |\n",
                arr[i].maSV, arr[i].hoTen, arr[i].ngaySinh, arr[i].lop,
                arr[i].gioiTinh, arr[i].sdt, arr[i].diaChi, arr[i].gpa);
    }
    fprintf(f, "----------------------------------------------------------------------------------------------------------------------------\n");
    fclose(f);
    printf("Da ghi danh sach vao file '%s'\n", tenFile);
}

// Menu in file
void inFileMenu() {
    int luaChon;
    char tenFile[100];
    printf("Nhap ten file de ghi: ");
    scanf("%s", tenFile);
    printf("\nChon cach in danh sach:\n");
    printf("1. Sap xep theo ma sinh vien\n");
    printf("2. Sap xep theo GPA\n");
    printf("3. Danh sach theo lop\n");
    printf("Lua chon: ");
    scanf("%d", &luaChon);
    SinhVien temp[MAX];
    int count = 0;
    switch (luaChon) {
        case 1:
            memcpy(temp, ds, sizeof(SinhVien) * soLuong);
            sapXepTheoMa(temp, soLuong);
            ghiDanhSachRaFileTheoLuaChon(temp, soLuong, tenFile);
            break;
        case 2:
            memcpy(temp, ds, sizeof(SinhVien) * soLuong);
            sapXepTheoGPA(temp, soLuong);
            ghiDanhSachRaFileTheoLuaChon(temp, soLuong, tenFile);
            break;
        case 3:
            {
                char lop[20];
                printf("Nhap ten lop: ");
                scanf("%s", lop);
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(ds[i].lop, lop) == 0) {
                        temp[count++] = ds[i];
                    }
                }
                if (count > 0)
                    ghiDanhSachRaFileTheoLuaChon(temp, count, tenFile);
                else
                    printf("Khong co sinh vien trong lop %s\n", lop);
            }
            break;
        default:
            printf("Lua chon khong hop le!\n");
    }
}

// Ham menu hien thi chuc nang
void menu() {
    printf("\n                    +==============================================================+\n");
    printf("                    |                       MENU CHUONG TRINH                      |\n");
    printf("                    +--------------------------------------------------------------+\n");
    printf("                    |  1. Them sinh vien                                           |\n");
    printf("                    |  2. Xem danh sach sinh vien                                  |\n");
    printf("                    |  3. Chinh sua sinh vien                                      |\n");
    printf("                    |  4. Xoa sinh vien                                            |\n");
    printf("                    |  5. Tim sinh vien theo Mssv                                  |\n");
    printf("                    |  6. Sap xep theo ma sinh vien                                |\n");
    printf("                    |  7. Sap xep theo GPA                                         |\n");
    printf("                    |  8. Thong ke                                                 |\n");
    printf("                    |  9. Hien thi theo lop                                        |\n");
    printf("                    | 10. In danh sach sinh vien ra file                           |\n");
    printf("                    |  0. Thoat                                                    |\n");
    printf("                    +==============================================================+\n");
    printf("                    Chon chuc nang: ");
}


// Ham main chinh
int main() {
    int luaChon;
    do {
        menu();
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1: nhapSinhVien(); break;
            case 2: hienThiDanhSach(); break;
            case 3: chinhSua(); break;
            case 4: xoaSinhVien(); break;
            case 5: timKiemTheoMssv(); break;
            case 6: sapXepTheoMa(ds, soLuong); printf("Da sap xep theo ma.\n"); break;
            case 7: sapXepTheoGPA(ds, soLuong); printf("Da sap xep theo GPA.\n"); break;
            case 8: thongKe(); break;
            case 9: hienThiTheoLop(); break;
            case 10: inFileMenu(); break;
            case 0: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 0);
    return 0;
}


