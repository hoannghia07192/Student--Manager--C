#include "monhoc.h"
#include <time.h>
void ghiFile(MonHoc *ds, int n) {
    FILE *f = fopen("data.txt", "w");
    if (f == NULL) {
        printf("Loi: Khong the mo file de ghi!\n");
        return;
    }

    fprintf(f, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s|%s|%d|%f|%f\n", 
            ds[i].maMon, ds[i].tenMon, ds[i].SoTinChi, ds[i].DiemQuaTrinh, ds[i].Tylequatrinh);
    }
    fclose(f);
    printf("\n[System] Da luu du lieu vao file data.txt!\n");
}

void docFile(MonHoc *ds, int *n) {
    FILE *f = fopen("data.txt", "r");
    if (f == NULL) return; // Nếu chưa có file thì thôi

    if (fscanf(f, "%d\n", n) != 1) { 
        *n = 0; // File rỗng
        fclose(f);
        return;
    }

    for (int i = 0; i < *n; i++) {
        fscanf(f, "%[^|]|%[^|]|%d|%f|%f\n", 
            ds[i].maMon, ds[i].tenMon, &ds[i].SoTinChi, &ds[i].DiemQuaTrinh, &ds[i].Tylequatrinh);
        ds[i].DiemCuoiki = -1;
    }
    fclose(f);
    printf("\n[System] Da khoi phuc %d mon hoc tu du lieu cu!\n", *n);
}
void ghiFileTask(Task *ds, int n) {
    FILE *f = fopen("todo.txt", "w");
    if (f == NULL) return;

    fprintf(f, "%d\n", n);
    for (int i = 0; i < n; i++) {
        // Format: Nội dung|Ngày|Tháng|Năm|Trạng thái
        fprintf(f, "%s|%d|%d|%d|%d\n", 
            ds[i].NoiDUng, ds[i].deadline.ngay, ds[i].deadline.thang, ds[i].deadline.nam, ds[i].TrangThai);
    }
    fclose(f);
    printf("\n[System] Da luu To-Do List.\n");
}

void docFileTask(Task *ds, int *n) {
    FILE *f = fopen("todo.txt", "r");
    if (f == NULL) return;

    if (fscanf(f, "%d\n", n) != 1) {
        *n = 0;
        fclose(f);
        return;
    }

    for (int i = 0; i < *n; i++) {
        int stt; // Biến tạm để đọc trạng thái (vì bool đôi khi kén scanf)
        fscanf(f, "%[^|]|%d|%d|%d|%d\n", 
            ds[i].NoiDUng, &ds[i].deadline.ngay, &ds[i].deadline.thang, &ds[i].deadline.nam, &stt);
        ds[i].TrangThai = (stt == 1);
        ds[i].id = i + 1; // Tái tạo lại ID
    }
    fclose(f);
    printf("\n[System] Da khoi phuc %d cong viec.\n", *n);
}