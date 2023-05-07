//employee management system
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
//#include<windows.h>
void insert_record();
void append_record();
void display_record();
void search_record();
void update_record();
void sort_record();
void del_record();
struct employee{
    int id_number;
    char first_name[50];
    char last_name[50];
    int salary;
    char address[50];

}e;
void main(){
    int ch;
    while(1){
        system("cls");
        printf("\t****************************************************\n");
        printf("\t\tWelcome to Employment Management System\n");
        printf("\t****************************************************\n\n\n");
            printf("\t*** Available Functionalities(Choices)***\n\n");
            printf("\t\tPress 1 to insert employment record\n");
            printf("\t\tPress 2 to  display employment record\n");
            printf("\t\tPress 3 to search in a employment record\n");
            printf("\t\tPress 4 to update employment record\n");
            printf("\t\tPress 5 to sort employment record\n");
            printf("\t\tPress 6 to delete a  employment record\n");
            printf("\t\tPress 7 to append record\n");
            printf("\t\tPress 8 to exit\n");
            printf("Enter your choice that you want to perform\n");
            scanf("%d",&ch);
            switch(ch){

                case 1:
                insert_record();
                break;
                case 2:
                display_record();
                break;
                case 3:
                search_record();
                break;
                case 4:
                update_record();
                break;
                case 5:
                sort_record();
                break;
                case 6:
                del_record();
                break;
                case 7:
                append_record();
                break;
                case 8:
                exit(1);
                default:
                printf("Wrong choice.Please choose from above 1 to 7 choices.\n");


            }
            printf("\nPress any key to continue\n");
            getch();
    }
}
void insert_record(){
    FILE  *fp;
    char ch='y';
    fp=fopen("Employe.txt","w");
    if(fp==NULL){
        printf("Error!file cannot be opened\n");
    }
    printf("\t\t**Enter the data of employee**\n\n");
    while(ch=='y'){//lets you enter the data as long as you press y
        printf("Enter the id:");
        scanf("%d",&e.id_number);
        fflush(stdin);
        printf("Enter the first name:");
        gets(e.first_name);
        fflush(stdin);
        printf("Enter the last name:");
        gets(e.last_name);
        fflush(stdin);
        printf("Enter the salary: ");
        scanf("%d",&e.salary);
        fflush(stdin);
        printf("Enter the address:");
        gets(e.address);
        fprintf(fp,"%s %s %d %s %d",e.first_name,e.last_name,e.id_number,e.address,e.salary);//writes to the file
        printf("do you want to enter more record(y/n?)\n");
        ch=getche();
        printf("\n");

        }
        fclose(fp);
    }



void append_record(){
    FILE  *fp;
    fp=fopen("Employe.txt","a+");
    if(fp==NULL){
        printf("Error:File cannot be open!!\n");
    }
    printf("***Previously stored record are:***\n\n");
    display_record();
    printf("\t\t***Enter the data of new employee***\n");
    printf("Enter the employee id no:");
    scanf("%d",&e.id_number);
    fflush(stdin);
    printf("Enter the employee first name: ");
    gets(e.first_name);
    fflush(stdin);
    printf("Enter the employee last name: ");
    gets(e.last_name);
    fflush(stdin);
    printf("Enter the salary of employee:");
    scanf("%d",&e.salary);
    fflush(stdin);
    printf("Enter the address of employee:");
    gets(e.address);
    fprintf(fp,"%s %s %d %s %d",e.first_name,e.last_name,e.id_number,e.address,e.salary);
    fclose(fp);

     printf("\n\t\t!!Record of new employee inserted sucessfully!!\n\n");
    printf("\t\tUpdated record is:\n");
    display_record();

}
void display_record(){
    FILE *fp;
    fp=fopen("Employe.txt","r");
    if(fp==NULL){
        printf("Error:file cannot be opened\n");
    }

    while(fscanf(fp,"%s %s %d %s %d",e.first_name,e.last_name,&e.id_number,e.address,&e.salary)!=EOF){
        printf("First Name :%s\nLast name:%s\nId number:%d\nAddress:%s\nSalary:%d\n",e.first_name,e.last_name,e.id_number,e.address,e.salary);
        fflush(stdin);
        printf("\n");
    }
    fclose(fp);
}
void search_record(){
    int id,flag=0;
    FILE *fp;
    fp=fopen("Employe.txt","r");
    if(fp==NULL){
        printf("Error!File cannot be opened\n");
    }
    printf("Enter the id of employee that you want to search for\n");
    scanf("%d",&id);
    while(fscanf(fp,"%s %s %d %s %d",e.first_name,e.last_name,&e.id_number,e.address,&e.salary)!=EOF && flag==0){//reads until the end of file
        if(e.id_number==id){//check whether the given id is among the data in the file
            flag=1;

            fflush(stdin);
            printf("Name:%s %s\nId no:%d\nAddress:%s\nSalary:%d\n",e.first_name,e.last_name,e.id_number,e.address,e.salary);
        }
    }
    if (flag==0){
        printf("No such record is found\n");
    }
    fclose(fp);
}
void del_record(){
    char name[40];
    int flag=0;
    FILE *fp ,*ft;
    fp=fopen("Employe.txt","r");
    ft=fopen("temp_employee.txt","a");
    if(fp==NULL){
        printf("Error:file cannot be opened\n");
    }
    printf("Enter the first name of employee which you want to delete\n");
    fflush(stdin);
    gets(name);
    fflush(stdin);
    while(fscanf(fp,"%s %s %d %s %d",e.first_name,e.last_name,&e.id_number,e.address,&e.salary)!=EOF){
        if(strcmp(e.first_name,name)!=0){

             fprintf(ft,"%s %s %d %s %d",e.first_name,e.last_name,e.id_number,e.address,e.salary);//writes in the temporary file
        }
        else{
            flag=1;
        }
    }
        if (flag==0){
            printf("\t!!No such record is found!!\n");
        }
        else{
            printf("\t\t!!The record deleted sucessfully!!\n");
        }
        fclose(fp);
        fclose(ft);
        remove("Employe.txt");
        rename("temp_employee.txt","Employe.txt");
        printf("\t\t!!The new record is!!\n");
        display_record();
}
void update_record(){
    struct employee et;
    FILE *fp,*ft;
    int id,flag=0;
    fp=fopen("Employe.txt","r+");
    ft=fopen("temp_employee.txt","w+");
    if(fp==NULL){
        printf("Error:File cannot be opened\n");
    }
    printf("Enter the Id number of employee which you want to update\n");
    scanf("%d",&id);
    fflush(stdin);
    while(fscanf(fp,"%s %s %d %s %d",e.first_name,e.last_name,&e.id_number,e.address,&e.salary)!=EOF) {
        if(id!=e.id_number){
            //flag=1;

              fprintf(ft,"%s %s %d %s %d",e.first_name,e.last_name,e.id_number,e.address,e.salary);//writes all data except the one to update
        }
        else{
            printf("\n\n***Previously stored record of given Id number***\n");
            printf("First Name:%s\nLast name:%s\nId no:%d\nAddress:%s\nSalary:%d\n",e.first_name,e.last_name,e.id_number,e.address,e.salary);
        }


    }
    printf("\n\nUpdated Id number:");
            scanf("%d",&et.id_number);
            fflush(stdin);
            printf("updated first name:");
            gets(et.first_name);
            printf("updated last name:");
            gets(et.last_name);
            fflush(stdin);
            printf("Updated salary:");
            scanf("%d",&et.salary);
            fflush(stdin);
            printf("Updatd address:");
            gets(et.address);
            fprintf(ft,"%s %s %d %s %d",et.first_name,et.last_name,et.id_number,et.address,et.salary);
        fclose(fp);
        fclose(ft);
     remove("Employe.txt");
     rename("temp_employee.txt","Employe.txt");
     printf("\n\n**Record updated successfully.Please check the display option**\n\n");
}


void sort_record(){


    struct employee temp;
    struct employee arr[30];

    int j,i,k=0;
    FILE *fp;
    fp=fopen("Employe.txt","r");
    if (fp==NULL){
        printf("Error!File cannot be opened\n");

    }
    i=0;
while(fscanf(fp,"%s %s %d %s %d",e.first_name,e.last_name,&e.id_number,e.address,&e.salary)!=EOF){

    arr[i]=e;//transfers the data in to array[0] at first and increases value of i until it reaches eof
    k++;//counts the no of data
    i++;

}
for(i=0;i<k;i++){
    for(j=i+1;j<k;j++){

        if(arr[i].id_number>arr[j].id_number){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;

    }
}
}
fflush(stdin);
printf("\n**After Sorting Employee information**\n");
printf("First Name  last name  ID  Address  salary\n");
for(j=0;j<k;j++){
    printf("First Name:%s\nLast name:%s\nID:%d\nAddress:%s\nSalary:%d\n",arr[j].first_name,arr[j].last_name,arr[j].id_number,arr[j].address,arr[j].salary);
printf("\n");
}
fclose(fp);

}

