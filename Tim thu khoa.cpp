#include <stdio.h>
#include <string.h>

typedef struct {
    int ma;              
    char ten[100];       
    char ngay_sinh[20];  
    float diem_m1;       
    float diem_m2;       
    float diem_m3;      
    float tong_diem;    
} ThiSinh;


void tinh_tong_diem(ThiSinh *ts) {
    ts->tong_diem = ts->diem_m1 + ts->diem_m2 + ts->diem_m3;
}

void nhap_thi_sinh(ThiSinh *ts, int ma) {
    ts->ma = ma;
    printf("Nhap ten thí sinh: ");
    getchar();  
    fgets(ts->ten, sizeof(ts->ten), stdin);
    ts->ten[strcspn(ts->ten, "\n")] = '\0';
    printf("Nhap ngay sinh (dd/mm/yyyy): ");
    fgets(ts->ngay_sinh, sizeof(ts->ngay_sinh), stdin);
    ts->ngay_sinh[strcspn(ts->ngay_sinh, "\n")] = '\0'; 
    printf("Nhap diem mon 1: ");
    scanf("%f", &ts->diem_m1);
    printf("Nhap diem mon 2: ");
    scanf("%f", &ts->diem_m2);
    printf("Nhap diem mon 3: ");
    scanf("%f", &ts->diem_m3);
    tinh_tong_diem(ts);
}

void in_thi_sinh(ThiSinh ts) {
    printf("Ma thi sinh: %d\n", ts.ma);
    printf("Ten thi sinh: %s\n", ts.ten);
    printf("Ngay sinh: %s\n", ts.ngay_sinh);
    printf("Diem mon 1: %.2f\n", ts.diem_m1);
    printf("Diem mon 2: %.2f\n", ts.diem_m2);
    printf("Diem mon 3: %.2f\n", ts.diem_m3);
    printf("Tong diem: %.2f\n", ts.tong_diem);
}


void tim_thu_khoa(ThiSinh ds[], int n) {
    float diem_cao_nhat = ds[0].tong_diem;
    
    for (int i = 1; i < n; i++) {
        if (ds[i].tong_diem > diem_cao_nhat) {
            diem_cao_nhat = ds[i].tong_diem;
        }
    }

    
    printf("Thu khoa:\n");
    for (int i = 0; i < n; i++) {
        if (ds[i].tong_diem == diem_cao_nhat) {
            in_thi_sinh(ds[i]);
            printf("\n");
        }
    }
}

int main() {
    int n;
    printf("Nhap so luong thi sinh: ");
    scanf("%d", &n);

    ThiSinh ds[n];

    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin thi sinh %d:\n", i + 1);
        nhap_thi_sinh(&ds[i], i + 1);
    }

    tim_thu_khoa(ds, n);

    return 0;
}

