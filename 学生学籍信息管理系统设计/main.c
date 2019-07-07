#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define MAX 100
typedef struct
{
    long stuNo;//ѧ�� int��Ϊlong
    char name[20];//����
    char sex[2];//�Ա�
    int domNum;//�����
    char tel[20];//�绰����
    int age;//���� ����
}Stulnfo;//ѧ��������Ϣ�ṹ��
typedef struct
{
  long stuNo;//ѧ��
  int courseNo;//�γ̱�� char��Ϊint
  char courseName[20];//�γ����� ��Ϊ����
  int creditHour;//ѧ��
  int triGrade;//ƽʱ�ɼ�
  int examGrade;//����ɼ�
  float totalGrade;//�ۺϳɼ�
  float finalCreHour;//ʵ��ѧ��
}StuGraInfo; //ѧ���ɼ�������Ϣ�ṹ��
void mainmenu()
{
    printf("\n\n\t\t\t\t\t\t==========================��ӭʹ��ѧ��ѧ����Ϣ����ϵͳ==========================\n\n");
    printf("\n\t\t\t\t\t\t=================================��ѡ��ִ�еĹ���===============================\n\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t1���鿴ѧ��������Ϣ\t\t\t\t====\n\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t2���鿴ѧ���ɼ���Ϣ\t\t\t\t====\n\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t0���˳�\t\t\t\t\t\t====\n\n");
    printf("\n\n\t\t\t\t\t\t================================================================================\n");
}
void message()
{
    printf("\n\n\t\t\t\t\t\t==========================��ӭʹ��ѧ��ѧ����Ϣ����ϵͳ==========================\n\n");
    printf("\n\t\t\t\t\t\t=================================��ѡ��ִ�еĹ���===============================\n\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t1�����ѧ��������Ϣ\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t2��ɾ��ѧ��������Ϣ\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t3����ѯѧ��������Ϣ\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t4��ѧ������\t\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t5����ӡѧ��������Ϣ\t\t\t\t=====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t0���˳�ϵͳ\t\t\t\t\t====\n");
    printf("\n\n\t\t\t\t\t\t================================================================================\n");
}
void score()
{
    printf("\n\n\t\t\t\t\t\t==========================��ӭʹ��ѧ��ѧ����Ϣ����ϵͳ==========================\n\n");
    printf("\n\t\t\t\t\t\t=================================��ѡ��鿴����Ϣ===============================\n\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t1�����ѧ���ɼ�\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t2��ɾ��ѧ���ɼ�\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t3����ѯѧ���ɼ�\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t4��ѧ���ɼ�����\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t5����ӡѧ���ɼ�\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t0���˳�ϵͳ\t\t\t\t====\n");
    printf("\n\n\t\t\t\t\t\t================================================================================\n");
}
int read_file(Stulnfo students[])//��ȡ������Ϣ
{
    FILE *fp;
    int  i=0;
	if((fp=fopen("stu.txt","rt"))==NULL)//�ж��ļ��Ƿ�ɹ���
	{
	    printf("\n\n*****û�гɹ���");
	    exit(0);
        }
    while((fread(&students[i],sizeof(Stulnfo),1,fp))==1)//�����ɹ�
    {
         i++;
    }
    fclose(fp);
    return i;
}
int read_file1(StuGraInfo stuGraInfo[])//��ȡ�ɼ�������Ϣ
{
     FILE *fp1;

    int  i=0;
	if((fp1=fopen("stu1.txt","rt"))==NULL)              //�ж��ļ��Ƿ�ɹ���
	{
	    printf("\n\n*****����ļ������ڣ��봴��");
	    exit(0);
	}
    while((fread(&stuGraInfo[i],sizeof(StuGraInfo),1,fp1))==1)
    {
         i++;
    }
     fclose(fp1);
    return i;
}
void save_file(Stulnfo students[],int sum)//���������Ϣ
{
     FILE  *fp;
     int i;
     if((fp=fopen("stu.txt","wb"))==NULL)
     {
       printf("\n");
       exit(0);
     }
     for(i=0;i<sum;i++)
	   if(fwrite(&students[i],sizeof(Stulnfo),1,fp)!=1)
        printf("\n");
	   fclose(fp);
}
void save_file1(StuGraInfo stuGraInfo[],int sum)//����ɼ�������Ϣ
{
     FILE  *fp1;
   int i;
   if((fp1=fopen("stu1.txt","wb+"))==NULL)
   {
       printf("\n");
       exit(0);
   }
   for(i=0;i<sum;i++)
	   if(fwrite(&stuGraInfo[i],sizeof(StuGraInfo),1,fp1)!=1)
        printf("\n");
        fclose(fp1);
}
int input(Stulnfo students[])//���������Ϣ
{
      int i=0,t;
      printf("\n\t\t\t\t\t\t================================================================================\n");
      printf("\n������ѧ������(���%d��)��",MAX);
      getchar();
      scanf("%d",&t);
	  printf("\n\t\t\t\t\t\t================================================================================\n");
	  do
	  {
	     printf("\n\t\t\t\t\t\t==================================��%d��ѧ����ѧ�ţ�",i+1);
		 scanf("%ld",&students[i].stuNo);
		 if(students[i].stuNo==0)
            break;
		 printf("������ѧ���Ļ�����Ϣ\n");
		 printf("\n\t\t\t\t\t\t==================================������");
		 scanf("%s",students[i].name);getchar();
		 printf("\n\t\t\t\t\t\t==================================�Ա�");
		 scanf("%s",students[i].sex);getchar();
		 printf("\n\t\t\t\t\t\t==================================����ţ�");
		 scanf("%d",&students[i].domNum);getchar();
		 printf("\n\t\t\t\t\t\t==================================�绰���룺");
		 scanf("%s",students[i].tel);getchar();
		 printf("\n\t\t\t\t\t\t==================================���䣺");
		 scanf("%d",&students[i].age);getchar();
		 i++;
	 }while(i<t);
	   save_file(students,t);//���������ѧ����Ϣ
	   printf("\n%d��ѧ����Ϣ¼�����!\n",t);
	   getch();
       return t;//��������ѧ���ĸ���ֵ
}
int input1(StuGraInfo stuGraInfo[])//����ɼ�������Ϣ
{
     int i=0,m;
     printf("\n\t\t\t\t\t\t================================================================================\n");                                               /*����Ҫ����ѧ���ĸ���*/
	 printf("\n������¼��ѧ������(���%d��)��\n",MAX);
	 getchar();
	 scanf("%d",&m);
	 printf("\n\t\t\t\t\t\t================================================================================\n");
	 do
	 {
	     printf("\n\t\t\t\t\t\t==================================��%d��ѧ����ѧ�ţ�",i+1);
		 scanf("%ld",&stuGraInfo[i].stuNo);
		 if(stuGraInfo[i].stuNo==0)   break;
		 printf("\n������ѧ���Ļ�����Ϣ\n");
		 printf("\n\t\t\t\t\t\t==================================�γ̱�ţ�");
		 scanf("%d",&stuGraInfo[i].courseNo);getchar();
		 printf("\n\t\t\t\t\t\t==================================�γ����ƣ�");
		 scanf("%s",stuGraInfo[i].courseName);getchar();
		 printf("\n\t\t\t\t\t\t==================================ѧ�֣�");
		 scanf("%d",&stuGraInfo[i].creditHour);getchar();
		 printf("\n\t\t\t\t\t\t==================================ƽʱ�ɼ���");
		 scanf("%d",&stuGraInfo[i].triGrade);getchar();
		 printf("\n\t\t\t\t\t\t==================================����ɼ���");
		 scanf("%d",&stuGraInfo[i].examGrade);getchar();
		 stuGraInfo[i].totalGrade=(float)(stuGraInfo[i].examGrade)*0.5+(float)(stuGraInfo[i].triGrade)*0.5;
		 stuGraInfo[i].finalCreHour=stuGraInfo[i].totalGrade*0.01*stuGraInfo[i].creditHour;
		 printf("\n\t\t\t\t\t\t==================================�ۺϳɼ���");
		 printf("%5.2f",stuGraInfo[i].totalGrade);getchar();
		 printf("\n\t\t\t\t\t\t==================================ʵ��ѧ�֣�");
		 printf("%5.2f",stuGraInfo[i].finalCreHour);getchar();
		 i++;
	 }while(i<m);
	   save_file1(stuGraInfo,m);//���������ѧ����Ϣ
	   printf("\n%d��ѧ����Ϣ¼�����!   \n",m);
	   getch();
       return m;//��������ѧ���ĸ���ֵ
  }
void output(Stulnfo students[],int sum)//�������ģ��
{
	    int i;
	    printf("\n\t\t\t\t\t\t================================================================================\n");
        printf("\n\t\t\t\t\t\t=============================ѧ���Ļ�����Ϣ���£�===============================\n");
        printf("\n\t\t\t\t\t\tѧ��         ����     �Ա�    �����       �绰����        ����\n");
        for(i=0;i<sum;i++)    //���ѧ������Ϣ
		{
		    printf("\t\t\t\t\t\t%5ld     %5s    %5s     %5d     %5s     %5d\n",
                    students[i].stuNo,students[i].name,students[i].sex,students[i].domNum,students[i].tel,students[i].age);
            printf("\n\t\t\t\t\t\t================================================================================\n");
		 }
	    getch();
        save_file(students,sum);
  }
void output1(StuGraInfo stuGraInfo[],int sum)//����ɼ�����ģ��
{
	    int i;
        printf("\n\t\t\t\t\t\t================================================================================\n");
        printf("\n\t\t\t\t\t\t================================���ѧ���ɼ�������Ϣ============================\n");
        printf("\n\t\t\t\t\t\t================================================================================\n");
        printf("\n\t\t\t\t\t\tѧ��     �γ̱��     �γ�����   ѧ��      ƽʱ�ɼ�     ����ɼ�    �ۺϳɼ�     ʵ��ѧ��\n");
        for(i=0;i<sum;i++)
		{
		     printf("\n\t\t\t\t\t\t%5ld   %5d       %5s    %5d      %5d       %5d        %5.2f       %5.2f \n",
             stuGraInfo[i].stuNo,stuGraInfo[i].courseNo,stuGraInfo[i].courseName,
             stuGraInfo[i].creditHour,stuGraInfo[i].triGrade,stuGraInfo[i].examGrade,
             stuGraInfo[i].totalGrade,stuGraInfo[i].finalCreHour);
             printf("\n\t\t\t\t\t\t================================================================================\n");
		 }
	    getch();
        save_file1(stuGraInfo,sum);
}
void inquire(Stulnfo students[],int sum)//��ѯ��Ϣģ��
{
		int i,flag;
		long inquire_stoNo;
		char choice;
        sum=read_file(students);//��ȡ�ļ�
        printf("%d\n",sum);
   do
    {
       printf("\n\t\t\t\t\t\t================================================================================\n");
       printf("\n����Ҫ��ѯ��ѧ��ѧ�ţ�");
       scanf("%ld",&inquire_stoNo); //����Ҫ��ѯ��ѧ��ѧ��
       for(i=0;i<sum;i++)
       {
           if(students[i].stuNo==inquire_stoNo)
           {
               printf("\n\t\t\t\t\t\t=================================��ѧ��������ϢΪ��=============================\n");
               printf("\n\t\t\t\t\t\t================================================================================\n");
               printf("\n\t\t\t\t\t\tѧ��         ����     �Ա�    �����       �绰����        ����\n");
               printf("\n");
               printf("\t\t\t\t\t\t%5ld     %5s    %5s     %5d     %5s     %5d\n",
                    students[i].stuNo,students[i].name,students[i].sex,students[i].domNum,students[i].tel,students[i].age);
               printf("\n\t\t\t\t\t\t================================================================================\n");
                  break;
           }
       }
       if(i==sum)
       {
            printf("\n δ�ҵ���ѧ����Ϣ��\n");
            getch();
       }
        printf("\n\n�Ƿ����?(Y/N)");
        choice=getch();
        if(choice=='Y'||choice=='y')
        {
            flag=1;
            printf("\n����!\n"); /*�Ƿ�Ҫ����*/
        }
        else
            flag=0;
   }while(flag==1);
    printf("\n��������������˵�!");
    getch();
}
void inquire1(StuGraInfo stuGraInfo[],int sum)//��ѯѧ���ɼ�������Ϣģ��
{
		int i,flag,inquire_stuNo;
		char choice;
	     sum=read_file1(stuGraInfo);//��ȡ�ļ�
		 printf("%d\n",sum);
	 do
	   {
       printf("\n\t\t\t\t\t\t================================================================================\n");
       printf("\n����Ҫ��ѯ��ѧ��ѧ�ţ�");
       scanf("%d",&inquire_stuNo); //����Ҫ��ѯ��ѧ��ѧ��
        for(i=0;i<sum;i++)
	   if(stuGraInfo[i].stuNo==inquire_stuNo)
	   {
	       printf("\n\t\t\t\t\t\t=============================��ѧ���ɼ�������ϢΪ��=============================\n");
	       printf("\n\t\t\t\t\t\t================================================================================\n");
   	       printf("\n\t\t\t\t\t\tѧ��     �γ̱��     �γ�����   ѧ��      ƽʱ�ɼ�     ����ɼ�    �ۺϳɼ�     ʵ��ѧ��\n");
           printf("\n");
           printf("\n\t\t\t\t\t\t%5ld   %5d       %5s    %5d      %5d       %5d        %5.2f       %5.2f \n",stuGraInfo[i].stuNo,stuGraInfo[i].courseNo,stuGraInfo[i].courseName,stuGraInfo[i].creditHour,stuGraInfo[i].triGrade,stuGraInfo[i].examGrade,stuGraInfo[i].totalGrade,stuGraInfo[i].finalCreHour);
           printf("\n\t\t\t\t\t\t================================================================================\n");
	          break;
	   }
	      if(i==sum)
		  {
		       printf("\nδ�ҵ���ѧ����Ϣ    \n");
		      getch();
		  }
		   printf("\n\n�Ƿ����?(Y/N)");
		   choice=getch();
		   if(choice=='Y'||choice=='y')
		   {
		       flag=1;
		      printf("\n������\n");
		   }
		    else
                flag=0;
   }while(flag==1);
	     printf("\n��������������˵���");
         getch();
}
int del(Stulnfo students[],int sum)//ɾ����Ϣģ��
{
	   int i,del_num;
      printf("\n\t\t\t\t\t\t================================================================================\n");
      printf("������Ҫɾ����ѧ��ѧ�ţ�");
	  scanf("%d",&del_num);
	  for(i=0;i<sum;i++)
	  {
	      if(del_num==students[i].stuNo)
	     {
	         for(;i<sum-1;i++){
		     students[i].stuNo=students[i+1].stuNo;
	       students[i].domNum=students[i+1].domNum;
	       students[i].age=students[i+1].age;
		    strcpy(students[i].name,students[i+1].name);
		    strcpy(students[i].sex,students[i+1].sex);
		    strcpy(students[i].tel,students[i+1].tel);
	         }
	         printf("ɾ���ɹ�");
		  }
	  }
	   getch();
		save_file(students,sum-1);//����ɾ�����ѧ����Ϣ��ԭ�ļ�
		return (sum-1) ;
	}
int del1(StuGraInfo stuGraInfo[],int sum)//ɾ��ѧ���ɼ�������Ϣģ��
{
	   int i,del_num;
      printf("\n\t\t\t\t\t\t================================================================================\n");
      printf("������Ҫɾ����ѧ��ѧ��");
	  scanf("%d",&del_num);
	  for(i=0;i<sum;i++)
	  {  if(del_num==stuGraInfo[i].stuNo)
	     {
	         for(;i<sum-1;i++)
             {
		     stuGraInfo[i].stuNo=stuGraInfo[i+1].stuNo;
               stuGraInfo[i].totalGrade=stuGraInfo[i+1].totalGrade;
               stuGraInfo[i].triGrade=stuGraInfo[i+1].triGrade;
               stuGraInfo[i].examGrade=stuGraInfo[i+1].examGrade;
               stuGraInfo[i].finalCreHour=stuGraInfo[i+1].finalCreHour;

             }
	         printf("ɾ���ɹ�");
		  }
	  }
	   getch();
		save_file1(stuGraInfo,sum-1); //����ɾ�����ѧ����Ϣ��ԭ�ļ�
		return (sum-1) ;
}
void  sort0(Stulnfo  students[],int sum)/*������Ϣģ��*/
{
        int i,j,t,s,a;
        char m[20],x[2],dian[20];
        printf("\n\t\t\t\t\t\t================================================================================\n");
        printf("\n      ѧ����Ϣѧ����������:\n");
        printf("\n\t\t\t\t\t\t================================================================================\n");
        for(i=0;i<sum-1;i++)
	    for(j=i+1;j<sum;j++)
		{  if(students[i].stuNo>students[j].stuNo)
	      {t=students[i].stuNo;
	       students[i].stuNo=students[j].stuNo;
		   students[j].stuNo=t;
		   s=students[i].domNum;
	       students[i].domNum=students[j].domNum;
		   students[j].domNum=s;
		   a=students[i].age;
	       students[i].age=students[j].age;
		   students[j].age=a;
		   strcpy(m,students[i].name);
		    strcpy(students[i].name,students[j].name);
		    strcpy(students[j].name,m);
		    strcpy(x,students[i].sex);
		    strcpy(students[i].sex,students[j].sex);
		    strcpy(students[j].sex,x);
		    strcpy(dian,students[i].tel);
		    strcpy(students[i].tel,students[j].tel);
		    strcpy(students[j].tel,dian);
	       }
      }
      printf("\n\t\t\t\t\t\t================================================================================\n");
   	  printf("\n\t\t\t\t\t\tѧ��         ����     �Ա�    �����       �绰����        ����\n");
   	  for(i=0;i<sum;i++)
      printf("\t\t\t\t\t\t%5ld     %5s    %5s     %5d     %5s     %5d\n",
		     students[i].stuNo,students[i].name,students[i].sex,students[i].domNum,students[i].tel,students[i].age);
      printf("\n\t\t\t\t\t\t================================================================================\n");/*���������ѧ����Ϣ*/
      getch();
      save_file(students,sum);/*����������ѧ����Ϣ���ļ���*/
	}
void  sort1(StuGraInfo  stuGraInfo[],int sum)//����ɼ���Ϣģ��ѧ������
{
	     int i,j;
	     long a,b,c;
	     float t,g;
        printf("\n\t\t\t\t\t\t================================================================================\n");
        printf("\n\t\t\t\t\t\t===============================ѧ���ɼ���ѧ����������===========================\n");
        printf("\n\t\t\t\t\t\t================================================================================\n");
       for(i=0;i<sum-1;i++)//ð�ݷ�����
       {
	    for(j=i+1;j<sum;j++)
		{
		    if(stuGraInfo[i].stuNo>stuGraInfo[j].stuNo)
	       {
	           t=stuGraInfo[i].totalGrade;
               stuGraInfo[i].totalGrade=stuGraInfo[j].totalGrade;
               stuGraInfo[j].totalGrade=t;
               a=stuGraInfo[i].stuNo;
               stuGraInfo[i].stuNo=stuGraInfo[j].stuNo;
               stuGraInfo[j].stuNo=a;
               b=stuGraInfo[i].triGrade;
               stuGraInfo[i].triGrade=stuGraInfo[j].triGrade;
               stuGraInfo[j].triGrade=b;
               c=stuGraInfo[i].examGrade;
               stuGraInfo[i].examGrade=stuGraInfo[j].examGrade;
               stuGraInfo[j].examGrade=c;
               g=stuGraInfo[i].finalCreHour;
               stuGraInfo[i].finalCreHour=stuGraInfo[j].finalCreHour;
               stuGraInfo[j].finalCreHour=g;
	       }
        }
       }
        printf("\n\t\t\t\t\t\t================================================================================\n");
		printf("\n\t\t\t\t\t\tѧ��     �γ̱��     �γ�����   ѧ��      ƽʱ�ɼ�     ����ɼ�    �ۺϳɼ�     ʵ��ѧ��\n");
		printf("\n");
        for(i=0;i<sum;i++)
		{
		    printf("\n\t\t\t\t\t\t%5ld   %5d       %5s    %5d      %5d       %5d        %5.2f       %5.2f \n",stuGraInfo[i].stuNo,stuGraInfo[i].courseNo,stuGraInfo[i].courseName,stuGraInfo[i].creditHour,stuGraInfo[i].triGrade,stuGraInfo[i].examGrade,stuGraInfo[i].totalGrade,stuGraInfo[i].finalCreHour);
            printf("\n");
		 }
        printf("\n\t\t\t\t\t\t================================================================================\n");
        printf("\n�밴������������˵�");
		getch();
        save_file1(stuGraInfo,sum);  //����������ѧ����Ϣ���ļ���
	}
void  sort2(StuGraInfo  stuGraInfo[],int sum)//���ۺϳɼ���������
{
	     int i,j;
	     long a,b,c;
	     float t,g;
        printf("\n\t\t\t\t\t\t================================================================================\n");
        printf("\n\t\t\t\t\t\t===========================ѧ���ɼ����ۺϳɼ���������===========================\n");
        printf("\n\t\t\t\t\t\t================================================================================\n");
        for(i=0;i<sum-1;i++)//ð�ݷ�����
	    for(j=i+1;j<sum;j++)
		{  if(stuGraInfo[i].totalGrade<stuGraInfo[j].totalGrade)
	      {
	           t=stuGraInfo[i].totalGrade;
               stuGraInfo[i].totalGrade=stuGraInfo[j].totalGrade;
               stuGraInfo[j].totalGrade=t;
               a=stuGraInfo[i].stuNo;
               stuGraInfo[i].stuNo=stuGraInfo[j].stuNo;
               stuGraInfo[j].stuNo=a;
               b=stuGraInfo[i].triGrade;
               stuGraInfo[i].triGrade=stuGraInfo[j].triGrade;
               stuGraInfo[j].triGrade=b;
               c=stuGraInfo[i].examGrade;
               stuGraInfo[i].examGrade=stuGraInfo[j].examGrade;
               stuGraInfo[j].examGrade=c;
               g=stuGraInfo[i].finalCreHour;
               stuGraInfo[i].finalCreHour=stuGraInfo[j].finalCreHour;
               stuGraInfo[j].finalCreHour=g;
	       }
      }
		printf("\n\t\t\t\t\t\t================================================================================\n");
   	    printf("\n\t\t\t\t\t\tѧ��     �γ̱��     �γ�����   ѧ��      ƽʱ�ɼ�     ����ɼ�    �ۺϳɼ�     ʵ��ѧ��\n");
		printf("                \n");
        for(i=0;i<sum;i++)
		{
		    printf("\n\t\t\t\t\t\t%5ld   %5d       %5s    %5d      %5d       %5d        %5.2f       %5.2f \n",stuGraInfo[i].stuNo,stuGraInfo[i].courseNo,stuGraInfo[i].courseName,stuGraInfo[i].creditHour,stuGraInfo[i].triGrade,stuGraInfo[i].examGrade,stuGraInfo[i].totalGrade,stuGraInfo[i].finalCreHour);
            printf("\n");
		 }
        printf("\n\t\t\t\t\t\t================================================================================\n");/*���������ѧ����Ϣ*/
		printf("\n��������������˵�");
		getch();
        save_file1(stuGraInfo,sum);//����������ѧ����Ϣ���ļ���
	}
void pailie()//����ʽ
{
    int x;
    //Stulnfo students[MAX];
	StuGraInfo stuGraInfo[MAX];
    int sum1=read_file1(stuGraInfo);//,x,choice,flag;
    printf("\n\t\t\t\t\t\t==========================��ӭʹ��ѧ��ѧ����Ϣ����ϵͳ==========================\n\n");
    printf("\t\t\t\t\t\t================================================================================\n\n");
    printf("\n\t\t\t\t\t\t==================================��ѡ�����з�ʽ��==============================\n");
    printf("\n\t\t\t\t\t\t===============================1.��ѧ��ѧ����������==============================\n");
    printf("\n\t\t\t\t\t\t===============================2.���ۺϳɼ���������==============================\n");
    printf("\n\n\t\t\t\t\t\t================================================================================\n");
    printf("��ѡ�����з�ʽ(1-2):");
    scanf("%d",&x);
    switch(x)
    {
        case 1:sort1(stuGraInfo,sum1);break;
        case 2:sort2(stuGraInfo,sum1);break;
    }
}
int append(Stulnfo  students[],int sum)/*��ӻ�����Ϣģ��*/
{
	int i=sum,flag=0;/*���Ѿ������ѧ��β�����*/
    char choice	;
	sum=read_file(students);
    printf("\n\t\t\t\t\t\t================================================================================\n");
	printf("\n\t\t\t\t\t\t===================================���ѧ����Ϣ=================================\n");
    do
	{
	if(i<MAX)/*�Ѿ������ѧ��������Ҫ��ӵ�ѧ������֮��ҪС�ڶ����ѧ���������ֵ*/
		{
			printf("\n\t\t\t\t\t\t==================================�����ѧ��ѧ�ţ�");
		    scanf("%ld",&students[i].stuNo);getchar();
		    printf("\n\t\t\t\t\t\t==================================������");
		    scanf("%s",students[i].name);getchar();
		    printf("\n\t\t\t\t\t\t==================================�Ա�");/*�������ѧ���Ļ�����Ϣ*/
		    scanf("%s",students[i].sex);getchar();
		    printf("\n\t\t\t\t\t\t==================================���䣺");
		    scanf("%d",&students[i].age);getchar();
		    printf("\n\t\t\t\t\t\t==================================����ţ�");
		    scanf("%d",&students[i].domNum);getchar();
		    printf("\n\t\t\t\t\t\t==================================�绰���룺");
		    scanf("%s",students[i].tel);getchar();
		     i++;
		}
		 printf("\n�Ƿ�������?(Y/N)");
         choice=getch();
		 if(choice=='Y'||choice=='y')
		 {  flag=1;
		    printf("\n������\n");/*�Ƿ�Ҫ�������*/
		 }
		 else flag=0;
		  save_file(students,i); /*������ӵ�ѧ����Ϣ��ԭ�ļ�*/
	}while(flag==1);;
	  printf("\n�밴������������˵���");
	  getch();
	  return i; /*�����ļ���ѧ������ֵ*/
}
int append1(StuGraInfo stuGraInfo[],int sum)/*���ѧ���ɼ�������Ϣģ��*/
{
	int i=sum,flag=0;/*���Ѿ������ѧ��β�����*/
    char choice	;
	sum=read_file1(stuGraInfo);
    printf("\n\t\t\t\t\t\t================================================================================\n");
	printf("\n\t\t\t\t\t\t================================���ѧ���ɼ�������Ϣ============================\n");
    do
	{
	if(i<MAX)/*�Ѿ������ѧ��������Ҫ��ӵ�ѧ������֮��ҪС�ڶ����ѧ���������ֵ*/
		{
         printf("\n\t\t\t\t\t\t==================================ѧ��ѧ��:");
		 scanf("%ld",&stuGraInfo[i].stuNo);getchar();
		 printf("\n\t\t\t\t\t\t==================================�γ̱��:");
		 scanf("%d",&stuGraInfo[i].courseNo);getchar();
		 printf("\n\t\t\t\t\t\t==================================�γ�����:");
		 scanf("%s",stuGraInfo[i].courseName);getchar();
		 printf("\n\t\t\t\t\t\t==================================ѧ��:");
		 scanf("%d",&stuGraInfo[i].creditHour);getchar();
		 printf("\n\t\t\t\t\t\t==================================ƽʱ�ɼ���");
		 scanf("%d",&stuGraInfo[i].triGrade);getchar();
		 printf("\n\t\t\t\t\t\t==================================����ɼ�:");
		 scanf("%d",&stuGraInfo[i].examGrade);getchar();
		 stuGraInfo[i].totalGrade=(float)(stuGraInfo[i].examGrade)*0.5+(float)(stuGraInfo[i].triGrade)*0.5;
		 stuGraInfo[i].finalCreHour=stuGraInfo[i].totalGrade*0.01*stuGraInfo[i].creditHour;
		 printf("\n\t\t\t\t\t\t==================================�ۺϳɼ���");
		 printf("%5.2f",stuGraInfo[i].totalGrade);getchar();
		 printf("\n\t\t\t\t\t\t==================================ʵ��ѧ�֣�");
		 printf("%5.2f",stuGraInfo[i].finalCreHour);getchar();
		     i++;
		}
		 printf("\n�Ƿ������ӣ�(Y/N)");
        choice=getch();
		 if(choice=='Y'||choice=='y')
		 {  flag=1;
		    printf("\n������\n"); /*�Ƿ�Ҫ�������*/
		 }
		 else flag=0;
		 save_file1(stuGraInfo,i); /*������ӵ�ѧ����Ϣ��ԭ�ļ�*/
	}while(flag==1);;
	  printf("\n��������������˵�!");
	  getch();
	  return i; /*�����ļ���ѧ������ֵ*/
}
int main()//������
{
	Stulnfo students[MAX];
	StuGraInfo stuGraInfo[MAX];
    int choice,sum,sum1;
    int x,op1;
    char mima,zhanghao;
    char a[9],b[10];
    int i;
    printf("\n");
    printf("\n");
    printf("\t\t\t\t\t\t==========================��ӭʹ��ѧ��ѧ����Ϣ����ϵͳ==========================");
    printf("\n\n\t\t\t\t\t\t==================================��ѡ������==================================");
    printf("\n\n\n\n\t\t\t\t\t\t\t    \t\t\t1��ѧ�����\t\t\t\t    \n");
    printf("\n\n\n\t\t\t\t\t\t\t    \t\t\t2����ʦ���\t\t\t\t    \n");
    printf("\n\n\n\n\t\t\t\t\t\t================================================================================\n");
    printf("\n��ѡ����ݣ�1-2��:");
    scanf("%d",&x);
   printf("                 ��ӭ����ѧ��ѧ����Ϣ����ϵͳ          \n");
    printf("                    ����������˺�(7λ):");
    for(i=0;i<7;i++)
    {
        zhanghao=getchar();
        b[i]=zhanghao;
    }
    printf("\n");
     printf("\n");
    printf("                    �������������(6λ):");
    for(i=0;i<6;i++)
    {
        mima=getch();
        printf("*");
        a[i]=mima;
    }
    printf("\n");

    if(!(strcmp(a,"123456")))
    {

         printf("\n\n\n\n\n\n              �ɹ���½!");
    }
    else
    {
        printf("\n\n\n\n\n\n\n\n\n          �������,����Ȩʹ�ø�ϵͳ!\n\n");
        exit(1);
    }
    sum=read_file(students);
    sum1=read_file1(stuGraInfo);
    if(!sum)
	{
	     printf("¼�������Ϣ!\n");
      getch();
	  sum=input(students);/*¼��ѧ����Ϣ*/
   }
   if(!sum1)
	{
	     printf("¼��ɼ���Ϣ!\n");
      getch();
	  sum1=input1(stuGraInfo);/*¼��ѧ���ɼ���Ϣ*/
   }
   if(x==2)
   {
       do
       {
            mainmenu();
            printf("��ѡ��鿴����Ϣ��0-2����");
            scanf("%d",&op1);
              if(op1==1)
              {

                  do{
                      message();
                      printf("\n��ѡ��ִ�еĹ���(0-5)��");
                      scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1: sum=append(students,sum);break;
                        case 2: sum=del(students,sum);break;
                        case 3: inquire(students,sum); break;
                        case 4: sort0(students,sum); break;
                        case 5:output(students,sum);   break;
                        case 0:  break;
                    }
                  }while(choice!=0);
              }
              else if(op1==2)
              {
                  do{
                        score();
                        printf("\n��ѡ��ִ�еĹ���(0-5)��");
                        scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1: sum1=append1(stuGraInfo,sum1);break;
                        case 2: sum1=del1(stuGraInfo,sum1);break;
                        case 3: inquire1(stuGraInfo,sum1); break;
                        case 4: pailie();break;
                        case 5: output1(stuGraInfo,sum1);   break;
                        case 0:  break; /*ִ�����ģ���0�˳�ϵͳ*/
                    }
                  }while(choice!=0);
              }
       }while(op1!=0);
        save_file(students,sum);
        save_file1(stuGraInfo,sum);/*����ִ�����ģ����ѧ����Ϣ*/
   }
    if(x==1)
    {
       do
       {
          printf("\n\t\t\t\t\t\t================================================================================\n");
          printf("\n\t\t\t\t\t\t==========================��ӭʹ��ѧ��ѧ����Ϣ����ϵͳ==========================\n\n");
          printf("\n\t\t\t\t\t\t\t====\t\t\t1����ѯ������Ϣ\t\t\t\t====\n");
          printf("\n\t\t\t\t\t\t\t====\t\t\t2����ѯ���˳ɼ�������Ϣ\t\t====\n");
          printf("\n\t\t\t\t\t\t\t====\t\t\t0���˳�ϵͳ\t\t\t\t====\n");
          printf("\n\n\t\t\t\t\t\t================================================================================\n");
          printf("\n��ѡ��ִ�еĹ���(0-2)��");
          scanf("%d",&choice);
          switch(choice)
          {
             case 1: inquire(students,sum); break;
             case 2:inquire1(stuGraInfo,sum);break;
             case 0:   break;/*ִ�����ģ���0�˳�ϵͳ*/
          }
        }while(choice!=0);
        save_file(students,sum);
        save_file1(stuGraInfo,sum1);/*����ִ�����ģ����ѧ����Ϣ*/
    }
    return 0;
}
