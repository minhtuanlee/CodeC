#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
struct city_st;
void hienthiDSSS(struct city_st*, int n);
void hienthitheoCot();

    struct city_st
	  {
		  char city_nm[30];
		  char country[30];
		  int year,Stt;
	  }; 
	  
	 typedef struct city_st cs;
	  	  
	  	void NhapN(city_st fc[],int n )
	  {
	  	 for(int i=0;i<n;i++)
	       {  
		       printf("\n\tNhap thong tin  thanh pho thu:%d",i+1);
		       printf("\nNhap so thu tu cho thanh pho thu %d :",i+1);
		       scanf("%d",&fc[i].Stt);
		       printf("\n\tNhap ten thanh pho:");
		       fflush(stdin);
		       gets(fc[i].city_nm);
		       printf("\n\tNhap quoc gia :");
		       fflush(stdin);
		       gets(fc[i].country);
		       printf("\n\tNhap nam thanh lap :");
		       scanf("%d",&fc[i].year);
		   } 
	  }
	void XuatN(city_st fc[],int n)
	{
      	    for(int i=0;i<n;i++)
      	   {
      	   	    printf("Thong tin thanh pho thu %d :\n",i++);
      	   	    printf("So thu tu cua thanh pho la %d\n",fc[i].Stt);
      	   	    printf("Ten thanh pho :%s\n",fc[i].city_nm);
      	   	    printf("Quoc gia :%s\n",fc[i].country);
      	   	    printf("Nam :%d\n",fc[i].year);
      	   }
       }
           void hienthithongtinthanhpho(struct city_st ht)
              {
              	printf("||%-3d||%-20s ||%-20s ||%-20d \n",ht.Stt, ht.city_nm,ht.country,ht.year);
            
			  }
			void sapxeptheoten(struct city_st *fc,int n)
			  {
			  	int i,j;
			  	for(i=0;i<n-1;i++)
                    {
                    	for(j=n-1;j>i;j--)
                    	   {
                    	   	   if(strcmp(fc[j].city_nm,fc[j-1].city_nm)>0)
                    	   	   {
                    	   	   	struct city_st a=fc[j];
                    	   	   	fc[j]=fc[j-1];
                    	   	   	fc[j-1]=a;
								}
						   }
					}
				}
		void timtheoquocgia(struct city_st *fc,int n)
		   {
		   	char city_nm[30];
		   	printf("Nhap Quoc Gia :");
		   	fflush(stdin);
		   	gets(city_nm);
		   	hienthitheoCot();
		   	int i,timS=0;
		   	for(i=0;i<n;i++)
		   	   {
		   	   	 if(strcmp(city_nm,fc[i].country)==0)
		   	   	       { 
		   	   	     hienthithongtinthanhpho(fc[i]);
		   	   	     timS =1;
					   }
			   }
				  if(timS ==0)
				     {
				       	printf("\n Khong co thanh pho thuoc quoc gia nay !",city_nm);
				     }
		   	
		   }
		   void timtheonam(struct city_st *fc,int n)
		    {
		    	int nam;
		    	printf("\nNhap nam :");
		    	scanf("%d",&nam);
		    	hienthitheoCot();
		    	int timS=0;
		    	for(int i=0;i<n;i++)
		    	{
		    		if(nam == fc[i].year)
		    		{
		    			hienthithongtinthanhpho(fc[i]);
		    			timS=1;
					}
				}
				if(timS ==0)
				{
					printf("\n khong co thanh pho thuoc nam nay!");
				}
			}
			  void hienthitheoCot(){
			printf("-----------------------------------------------------""-----------------------------\n");
	printf("||%-2s||%-20s ||%-20s ||%-30s \n", "STT" , "Ten", "Quoc Gia", "Nam" );
				
				
			   }
			   void hienthiDSSS(struct city_st *fc,int n)
			    {
			    	hienthitheoCot();
			    	for(int i=0;i<n;i++)
			    	  {
			    	  	hienthithongtinthanhpho(fc[i]);
					  }
					  	printf("------------------------------------------""-----------------------------\n");
				}
				void ghiFile(struct city_st* fc,int n)
				  {
				  	getchar();
				  	char fName[27];
				  	printf("Nhap ten file : ");
				  	gets(fName);
				  	FILE* fOut=fopen(fName, "a");
				  	for(int i=0;i<n;i++)
				  	    {
				  	  	   struct city_st cs=fc[i];
				  	  	   fprintf(fOut,"%-10d %-10s %-20s %-20d\n",cs.Stt,cs.city_nm,cs.country,cs.year);
						}
					fclose(fOut);
				   }
				void docFile(struct city_st* fc,int* n)
				   {
				   	  FILE*fOut =fopen("city.txt","r");
				   	  int i=0;
				   	  if(fOut)
				   	{
				   		for(;;)
				   		 {
				   			struct city_st cs;
				   			fscanf(fOut,"%10d %10s %20s %20d\n",&cs.Stt,cs.city_nm,cs.country,&cs.year);
				   			fc[i++] = cs;
				   			if(feof(fOut))
				   			{
				   				break;
							}
						 }
					}
					   fclose(fOut);
					   *n=i;
		}

int main(){
	int n,key;
	struct city_st fc[MAX];
	bool daNhap = false;
	do{
		printf("\nNhap so luong thanh pho ");
		scanf("%d",&n);
	}while(n<=0);
	while(true){
		system("cls");
		printf("                       ------------------------------------------------------\n");
		printf("                       |          Chuong Trinh Quan Li Thu Vien             |\n");
		printf("                       |      1. Nhap du lieu cua tung thanh pho.           |\n");
		printf("                       |      2. Hien thi thong tin cac thanh pho.          |\n");
		printf("                       |      3. Sap xep sach theo thu tu Z->A.             |\n");
		printf("                       |      4.Tim thanh pho theo quoc gia.                |\n");
		printf("                       |      5. Tim thanh pho theo nam.                    |\n");
		printf("                       |      6. Ghi vao tap tin nhi phan book.txt.         |\n");
		printf("                       |      0. Thoat chuong trinh.                        |\n");
		printf("                       ------------------------------------------------------\n");
		printf("                       ------------------- vui long chon !-------------------\n");
		scanf("%d",&key);
		switch(key){
			case 1:
				printf("Ban da chon nhap thong tin cho thanh pho\n");
				NhapN(fc,n);
				printf("Ban da nhap thanh cong !\n");
				daNhap = true;
				printf("Bam bat ki phim nao de tiep tuc !");
				getch();
				break;
			case 2:
			if (daNhap){
				printf("Ban da  chon hien thi thong tin thanh pho! \n");
				hienthiDSSS(fc,n);
				}
				else {
					printf("Ban can phai nhap thong tin thanh pho truoc! \n");
				}
				printf("Bam bat ki phim nao de tiep tuc\n");
				getch();
				break;
			case 3:
				if(daNhap){
					printf("Ban da chon sap xep theo thu tu Z -> A \n");
					printf("Thong tin thanh pho sau khi sap xep :\n");
					sapxeptheoten(fc,n);
					hienthiDSSS(fc,n);
				}
				else{
					printf("Ban phai nhap thong tin thanh pho truoc!\n");
				}
				printf("Bam bat ki phim nao de tiep tuc!");
				getch();
				break;
			
			case 4:
				if(daNhap){
					printf("Ban da chon tim thanh pho theo theo quoc gia !\n");
					timtheoquocgia(fc,n);
				}
				else{
					printf("Ban phai nhap thong tin cho thanh pho truoc!\n");
				}
				printf("Bam bat ki phim nao de tiep tuc\n");
				getch();
				break;
			case 5:
				if(daNhap){
					printf("Ban da chon tim thanh pho theo nam !\n");
					timtheonam(fc,n);
				}
				else{
					printf("Ban phai nhap thong tin cho thanh pho truoc!\n");
				}
				printf("Bam bat ki phim nao de tiep tuc\n");
				getch();
				break;
			case 6:
				if(daNhap){
					printf("Ban da chon ghi vao tap tin nhi phan city.txt !\n");
				ghiFile(fc,n);
				}
				else{
					printf("Ban phai nhap thong tin cho thanh pho truoc!\n");
				}
				printf("Bam bat ki phim nao de tiep tuc\n");
				getch();
				break;
			case 0:
				printf("May ban da bi loi !\n");
				getch();
				return 0;
			default :
				printf("Khong co chuc nang nay\n");
				printf("Bam phim bat ki de tiep tuc!");
				getch();
				break;	
			}	
		}
	}
