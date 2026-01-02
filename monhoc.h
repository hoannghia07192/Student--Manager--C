#ifndef MONHOC_H
#define MONHOC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//ĐỊNH NGHĨA STRUCT

typedef struct {
    int ngay, thang, nam;
} Date;

typedef struct {
    char maMon[20];
    char tenMon[50];
    int SoTinChi;
    float DiemQuaTrinh;
    float Tylequatrinh;
    float DiemCuoiki;
} MonHoc;

typedef struct {
    int id;
    char NoiDUng[150];
    bool TrangThai;
    Date deadline;
} Task;

// KHAI BÁO HÀM


void themMonHoc(MonHoc *ds, int *n);
void hienThiDanhSach(MonHoc *ds, int n);
void canhBaoRotMon(MonHoc *ds, int n);
void xoaMonHoc(MonHoc *ds, int *n);    
void suaDiemMon(MonHoc *ds, int n);    
void themTask(Task *ds, int *n);
void hienThiTask(Task *ds, int n);
void hoanThanhTask(Task *ds, int n);
void kiemTraDeadline(Task *ds, int n);

void ghiFile(MonHoc *ds, int n);
void docFile(MonHoc *ds, int *n);
void ghiFileTask(Task *ds, int n);
void docFileTask(Task *ds, int *n);
#endif