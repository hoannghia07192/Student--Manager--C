#include <stdio.h>
#include <stdlib.h>
#include "monhoc.h" 

int main() {
    // KHAI BÁO DỮ LIỆU 
    MonHoc dsMon[100];
    int nMon = 0;

    Task dsTask[100]; 
    int nTask = 0;

    int luachon;

   
    docFile(dsMon, &nMon);
    docFileTask(dsTask, &nTask); 

    
    kiemTraDeadline(dsTask, nTask); 

    do {
        printf("\n=== QUAN LY HOC TAP (Mon: %d | Task: %d) ===\n", nMon, nTask);
        printf("1. Quan ly Mon Hoc (Them, Xoa, Sua)\n");
        printf("2. Quan ly To-Do List (Deadline)\n");
        printf("3. Canh Bao Rot Mon & Check Deadline\n");
        printf("0. Luu va Thoat\n");
        printf("Chon: ");
        scanf("%d", &luachon);

        switch(luachon) {
            case 1: {
                
                int subChoice;
                printf("\n--- QUAN LY MON HOC ---\n");
                printf("1. Them Mon\n2. Xem DS\n3. Xoa Mon\n4. Sua Diem\nChon: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) themMonHoc(dsMon, &nMon);
                else if (subChoice == 2) hienThiDanhSach(dsMon, nMon);
                else if (subChoice == 3) xoaMonHoc(dsMon, &nMon);
                else if (subChoice == 4) suaDiemMon(dsMon, nMon);
                break;
            }
            case 2: {
                
                int subChoice;
                printf("\n--- TO-DO LIST ---\n");
                printf("1. Them Task\n2. Xem DS Task\n3. Danh dau da xong\nChon: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) themTask(dsTask, &nTask);
                else if (subChoice == 2) hienThiTask(dsTask, nTask);
                else if (subChoice == 3) hoanThanhTask(dsTask, nTask);
                break;
            }
            case 3: 
                canhBaoRotMon(dsMon, nMon);
                kiemTraDeadline(dsTask, nTask);
                break;
            case 0: 
                ghiFile(dsMon, nMon); 
                ghiFileTask(dsTask, nTask); 
                printf("Tam biet!\n"); 
                break;
            default: printf("Chon sai!\n");
        }
    } while (luachon != 0);

    return 0;
}