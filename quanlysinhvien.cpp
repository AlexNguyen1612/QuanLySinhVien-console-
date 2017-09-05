#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<stdlib.h>
struct sv{
	char hoten[30];
	char lop[10];
	float diem;
};
int i = 0;
void nhapsv(sv sinhvien[],int n){
 system("cls");
 while (i<n){
  printf("Nhap sinh vien thu %d ",i+1);
  printf("\n Ho va ten: ");
  gets(sinhvien[i].hoten);
  if(sinhvien[i].hoten[0]=='\0') break;
  printf("Lop: ");
  gets(sinhvien[i].lop);
  printf("Diem : ");
  scanf("%f",&sinhvien[i].diem);
  fflush(stdin);
  i++;
 }
}
void inds(sv sinhvien[],int n){
	 system("cls");
	 printf("1.In danh sach theo lop.\n");
	 printf("2.In tat ca danh sach cac lop.\n");
	 char input =getch();
	if(input=='1'){
	printf("Nhap ten lop: \n");
	printf("Goi y: \n");
	for (int i=0;i<n-1;i++){
	 if(strcmp(sinhvien[i].lop,sinhvien[i+1].lop)!=0){
	  printf("%s \n",sinhvien[i].lop);
	  if(i==n-2) printf("%s \n",sinhvien[i+1].lop);
	 }
	}
	char dslop[10];
	gets(dslop);
	printf("%-20s %-15s %-10s \n","Ho va Ten","Lop","Diem");
for(int i = 0;i<n;i++){
  if(strcmp(sinhvien[i].lop,dslop)==0){
  printf("%-20s %-15s %-10.1f \n",sinhvien[i].hoten,sinhvien[i].lop,sinhvien[i].diem);
  }
  }
}
else if(input=='2'){
 printf("%-20s %-15s %-10s \n","Ho va Ten","Lop","Diem");
 for(int i = 0;i<n;i++){
  printf("%-20s %-15s %-10.1f \n",sinhvien[i].hoten,sinhvien[i].lop,sinhvien[i].diem);
  }
}
}
void sxlop(sv sinhvien[],int n){
	for(int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			if(strcmp(sinhvien[i].lop,sinhvien[j].lop)>0){
				sv temp;
				temp = sinhvien[i];
				sinhvien[i]=sinhvien[j];
				sinhvien[j]=temp;
		
			}
		}
	}
}
int vitriten(sv sinhvien[],int n){
	int m = strlen(sinhvien[n].hoten)-1;
	while(sinhvien[n].hoten[m]==' ') m--;
	while(sinhvien[n].hoten[m]!=' '&& m>0) m--;
	return m>0?m+1:0;
}
void sapxepvn(sv sinhvien[],int n){
	system("cls");
	for(int i = 0;i<n-1;i++){
		for(int j= i+1;j<n;j++) {
			if(strcmp(sinhvien[i].lop,sinhvien[j].lop)==0){
			if(strcmp(sinhvien[i].hoten+ vitriten(sinhvien,i),sinhvien[j].hoten+ vitriten(sinhvien,j))>0){
			 sv temp;
			 temp = sinhvien[i];
			 sinhvien[i]=sinhvien[j];
			 sinhvien[j]=temp;
			}
			else if(strcmp(sinhvien[i].hoten+ vitriten(sinhvien,i),sinhvien[j].hoten+ vitriten(sinhvien,j))==0) {
			 if(strcmp(sinhvien[i].hoten,sinhvien[j].hoten)>0){
			 sv temp;
			 temp = sinhvien[i];
			 sinhvien[i]=sinhvien[j];
			 sinhvien[j]=temp;
			 }
			}
			}
	}
}
printf("Danh sach da duoc sap xep! \n");
}
int main(){
 int n ;
 printf("Nhap so luong sinh vien: ");
 scanf("%d",&n);
 fflush(stdin);
 sv sinhvien[n]; 
  system("cls");
 while(1){
 printf("1.Nhap sinh vien \n");
 printf("2.Sap xep danh sach\n");
 printf("3.In danh sach\n");
 printf("Nhan 1,2,3 de chon hanh dong tuong ung. \n");
 printf("Nhan phim bat ki de thoat! \n");
 char ch = getch();
 if(ch=='1'){
 nhapsv(sinhvien,n);
 }
 else if (ch=='2'){
  sxlop(sinhvien,n);
  sapxepvn(sinhvien,n);
 }
 else if(ch=='3'){
 inds(sinhvien,n);
}
else break;
 }
 }
