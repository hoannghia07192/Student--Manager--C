#include "monhoc.h"
#include <time.h>

void themMonHoc(MonHoc *ds, int *n) {
    printf("\n------- NHAP THONG TIN MON HOC -------\n");
    
    printf("Nhap ma Mon hoc: ");
    
    scanf("%19s", ds[*n].maMon); 

    printf("Nhap ten mon hoc: ");
    while(getchar() != '\n'); 
    fgets(ds[*n].tenMon, 50, stdin);
    ds[*n].tenMon[strcspn(ds[*n].tenMon, "\n")] = 0; 

    do {
        printf("So tin chi (>= 1): ");
        scanf("%d", &ds[*n].SoTinChi);
    } while (ds[*n].SoTinChi <= 0);

    do {
        printf("Nhap diem Qua trinh (0 - 10): ");
        scanf("%f", &ds[*n].DiemQuaTrinh);
    } while (ds[*n].DiemQuaTrinh < 0 || ds[*n].DiemQuaTrinh > 10);

    do {
        printf("Ty le qua trinh (0.1 - 0.9): ");
        scanf("%f", &ds[*n].Tylequatrinh);
        if (ds[*n].Tylequatrinh <= 0 || ds[*n].Tylequatrinh >= 1) {
            printf(">> Loi: Ty le phai la so thap phan (VD: 0.3). Nhap lai!\n");
        }
    } while (ds[*n].Tylequatrinh <= 0 || ds[*n].Tylequatrinh >= 1);

    ds[*n].DiemCuoiki = -1;
    (*n)++;
    printf(">>> THEM MON HOC THANH CONG! <<<\n");
}

//Hiển thị
void hienThiDanhSach(MonHoc *ds, int n) {
    printf("\n%-10s %-25s %-10s %-10s %-10s\n", "MA MON", "TEN MON", "TIN CHI", "DIEM QT", "TY LE");
    printf("---------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++){
        printf("%-10s %-25s %-10d %-10.2f %-10.2f\n", 
            ds[i].maMon, ds[i].tenMon, ds[i].SoTinChi, ds[i].DiemQuaTrinh, ds[i].Tylequatrinh);
    }
}

//Cảnh báo
void canhBaoRotMon(MonHoc *ds, int n) {
    printf("\n===========================================================\n");
    printf("%-20s %-10s %-15s %-20s\n", "TEN MON", "DIEM QT", "TY LE QT", "CAN THI >= ?");
    printf("===========================================================\n");

    for(int i=0; i<n; i++){
        float tyLeThi = 1.0 - ds[i].Tylequatrinh;
        float diemHienCo = ds[i].DiemQuaTrinh * ds[i].Tylequatrinh;
        float diemCanThi = (4.0 - diemHienCo) / tyLeThi;
        
        printf("%-20s %-10.2f %-15.2f ", ds[i].tenMon, ds[i].DiemQuaTrinh, ds[i].Tylequatrinh);
        
        if (diemCanThi <= 0) {
            printf("\033[0;32mDA QUA MON (0.0)");
        } else if (diemCanThi > 10) {
            printf("\033[1;31mROT CHAC (Can > 10)");
        } else if (diemCanThi >= 7) {
            printf("\033[1;33mNGUY HIEM (%.2f)", diemCanThi);
        } else {
            printf("\033[0;37mKha thi (%.2f)", diemCanThi);
        }
        printf("\033[0m\n"); 
    }
    printf("===========================================================\n");
}

//Xóa
void xoaMonHoc(MonHoc *ds, int *n) {
    char maCanXoa[20];
    printf("\nNhap MA MON muon xoa: ");
    scanf("%19s", maCanXoa); 

    int viTri = -1;
    for (int i = 0; i < *n; i++) {
        if (strcmp(ds[i].maMon, maCanXoa) == 0) {
            viTri = i;
            break;
        }
    }

    if (viTri == -1) {
        printf(">>> Loi: Khong tim thay ma mon %s!\n", maCanXoa);
    } else {
        for (int i = viTri; i < *n - 1; i++) {
            ds[i] = ds[i+1];
        }
        (*n)--;
        printf(">>> Da xoa thanh cong mon %s!\n", maCanXoa);
    }
}

//  Sửa
void suaDiemMon(MonHoc *ds, int n) {
    char maCanSua[20];
    printf("\nNhap MA MON muon sua diem: ");
    scanf("%19s", maCanSua); 

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].maMon, maCanSua) == 0) {
            found = 1;
            printf("--- Sua diem cho mon: %s ---\n", ds[i].tenMon);
            do {
                printf("Nhap diem Qua trinh MOI (0 - 10): ");
                scanf("%f", &ds[i].DiemQuaTrinh);
            } while (ds[i].DiemQuaTrinh < 0 || ds[i].DiemQuaTrinh > 10);
            
            printf(">>> Cap nhat diem thanh cong!\n");
            break;
        }
    }
    if (!found) printf(">>> Loi: Khong tim thay mon nay!\n");
}
#include "monhoc.h"
#include <time.h> // Thư viện xử lý thời gian

// ... (Các hàm MonHoc cũ giữ nguyên) ...

// --- PHẦN XỬ LÝ TO-DO LIST ---

void themTask(Task *ds, int *n) {
    printf("\n------- THEM CONG VIEC MOI -------\n");
    ds[*n].id = *n + 1; // Tự động tăng ID
    ds[*n].TrangThai = false; // Mặc định là chưa xong

    printf("Noi dung cong viec: ");
    while(getchar() != '\n'); 
    fgets(ds[*n].NoiDUng, 150, stdin);
    ds[*n].NoiDUng[strcspn(ds[*n].NoiDUng, "\n")] = 0;

    printf("Nhap Deadline (Ngay Thang Nam): ");
    scanf("%d %d %d", &ds[*n].deadline.ngay, &ds[*n].deadline.thang, &ds[*n].deadline.nam);

    (*n)++;
    printf(">>> Da them task thanh cong!\n");
}

void hienThiTask(Task *ds, int n) {
    printf("\n%-5s %-40s %-15s %-15s\n", "ID", "NOI DUNG", "DEADLINE", "TRANG THAI");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        char status[20];
        if (ds[i].TrangThai) strcpy(status, "[v] DA XONG");
        else strcpy(status, "[ ] CHUA XONG");

        printf("%-5d %-40s %02d/%02d/%d      %-15s\n", 
            ds[i].id, ds[i].NoiDUng, 
            ds[i].deadline.ngay, ds[i].deadline.thang, ds[i].deadline.nam, 
            status);
    }
}

void hoanThanhTask(Task *ds, int n) {
    int idChon;
    printf("\nNhap ID cong viec da lam xong: ");
    scanf("%d", &idChon);

    if (idChon > 0 && idChon <= n) {
        ds[idChon - 1].TrangThai = true; // Đánh dấu đã xong (Vì mảng bắt đầu từ 0 nên trừ 1)
        printf(">>>Da danh dau hoan thanh task so %d.\n", idChon);
    } else {
        printf(">>> Loi: Khong tim thay ID nay!\n");
    }
}
void kiemTraDeadline(Task *ds, int n) {
    //Lấy ngày giờ
    time_t t = time(NULL);
    struct tm hienTai = *localtime(&t);
    int ngayNay = hienTai.tm_mday;
    int thangNay = hienTai.tm_mon + 1; 
    int namNay = hienTai.tm_year + 1900; 

    printf("\n=== HOM NAY LA: %02d/%02d/%d ===\n", ngayNay, thangNay, namNay);
    printf("Cac Deadline sap den (trong 3 ngay toi):\n");
    
    int dem = 0;
    for (int i = 0; i < n; i++) {
        
        if (!ds[i].TrangThai && ds[i].deadline.nam == namNay && ds[i].deadline.thang == thangNay) {
            int khoangCach = ds[i].deadline.ngay - ngayNay;
            
            if (khoangCach >= 0 && khoangCach <= 3) {
                printf("!!! CANH BAO: '%s' het han trong %d ngay nua (%02d/%02d)\n", 
                    ds[i].NoiDUng, khoangCach, ds[i].deadline.ngay, ds[i].deadline.thang);
                dem++;
            }
            else if (khoangCach < 0) {
                 printf("QUA HAN: '%s' da tre han!\n", ds[i].NoiDUng);
                 dem++;
            }
        }
    }
    
    if (dem == 0) printf(">>> Khong co deadline nao.!\n");
}