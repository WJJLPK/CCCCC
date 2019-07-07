#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define MAX 100
typedef struct
{
    long stuNo;//学号 int改为long
    char name[20];//姓名
    char sex[2];//性别
    int domNum;//宿舍号
    char tel[20];//电话号码
    int age;//年龄 新增
}Stulnfo;//学生基本信息结构体
typedef struct
{
  long stuNo;//学号
  int courseNo;//课程编号 char改为int
  char courseName[20];//课程名称 改为数组
  int creditHour;//学分
  int triGrade;//平时成绩
  int examGrade;//卷面成绩
  float totalGrade;//综合成绩
  float finalCreHour;//实得学分
}StuGraInfo; //学生成绩基本信息结构体
void mainmenu()
{
    printf("\n\n\t\t\t\t\t\t==========================欢迎使用学生学籍信息管理系统==========================\n\n");
    printf("\n\t\t\t\t\t\t=================================请选择执行的功能===============================\n\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t1：查看学生个人信息\t\t\t\t====\n\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t2：查看学生成绩信息\t\t\t\t====\n\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t0：退出\t\t\t\t\t\t====\n\n");
    printf("\n\n\t\t\t\t\t\t================================================================================\n");
}
void message()
{
    printf("\n\n\t\t\t\t\t\t==========================欢迎使用学生学籍信息管理系统==========================\n\n");
    printf("\n\t\t\t\t\t\t=================================请选择执行的功能===============================\n\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t1：添加学生个人信息\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t2：删除学生个人信息\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t3：查询学生个人信息\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t4：学生排序\t\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t5：打印学生个人信息\t\t\t\t=====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t0：退出系统\t\t\t\t\t====\n");
    printf("\n\n\t\t\t\t\t\t================================================================================\n");
}
void score()
{
    printf("\n\n\t\t\t\t\t\t==========================欢迎使用学生学籍信息管理系统==========================\n\n");
    printf("\n\t\t\t\t\t\t=================================请选择查看的信息===============================\n\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t1：添加学生成绩\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t2：删除学生成绩\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t3：查询学生成绩\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t4：学生成绩排序\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t5：打印学生成绩\t\t\t\t====\n");
    printf("\n\t\t\t\t\t\t\t====\t\t\t0：退出系统\t\t\t\t====\n");
    printf("\n\n\t\t\t\t\t\t================================================================================\n");
}
int read_file(Stulnfo students[])//读取基本信息
{
    FILE *fp;
    int  i=0;
	if((fp=fopen("stu.txt","rt"))==NULL)//判断文件是否成功打开
	{
	    printf("\n\n*****没有成功打开");
	    exit(0);
        }
    while((fread(&students[i],sizeof(Stulnfo),1,fp))==1)//创建成功
    {
         i++;
    }
    fclose(fp);
    return i;
}
int read_file1(StuGraInfo stuGraInfo[])//读取成绩基本信息
{
     FILE *fp1;

    int  i=0;
	if((fp1=fopen("stu1.txt","rt"))==NULL)              //判断文件是否成功打开
	{
	    printf("\n\n*****库存文件不存在！请创建");
	    exit(0);
	}
    while((fread(&stuGraInfo[i],sizeof(StuGraInfo),1,fp1))==1)
    {
         i++;
    }
     fclose(fp1);
    return i;
}
void save_file(Stulnfo students[],int sum)//保存基本信息
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
void save_file1(StuGraInfo stuGraInfo[],int sum)//保存成绩基本信息
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
int input(Stulnfo students[])//输入基本信息
{
      int i=0,t;
      printf("\n\t\t\t\t\t\t================================================================================\n");
      printf("\n请输入学生个数(最多%d个)：",MAX);
      getchar();
      scanf("%d",&t);
	  printf("\n\t\t\t\t\t\t================================================================================\n");
	  do
	  {
	     printf("\n\t\t\t\t\t\t==================================第%d个学生的学号：",i+1);
		 scanf("%ld",&students[i].stuNo);
		 if(students[i].stuNo==0)
            break;
		 printf("请输入学生的基本信息\n");
		 printf("\n\t\t\t\t\t\t==================================姓名：");
		 scanf("%s",students[i].name);getchar();
		 printf("\n\t\t\t\t\t\t==================================性别：");
		 scanf("%s",students[i].sex);getchar();
		 printf("\n\t\t\t\t\t\t==================================宿舍号：");
		 scanf("%d",&students[i].domNum);getchar();
		 printf("\n\t\t\t\t\t\t==================================电话号码：");
		 scanf("%s",students[i].tel);getchar();
		 printf("\n\t\t\t\t\t\t==================================年龄：");
		 scanf("%d",&students[i].age);getchar();
		 i++;
	 }while(i<t);
	   save_file(students,t);//保存输入的学生信息
	   printf("\n%d个学生信息录入完毕!\n",t);
	   getch();
       return t;//返回输入学生的个数值
}
int input1(StuGraInfo stuGraInfo[])//输入成绩基本信息
{
     int i=0,m;
     printf("\n\t\t\t\t\t\t================================================================================\n");                                               /*定义要输入学生的个数*/
	 printf("\n请输入录入学生个数(最多%d个)：\n",MAX);
	 getchar();
	 scanf("%d",&m);
	 printf("\n\t\t\t\t\t\t================================================================================\n");
	 do
	 {
	     printf("\n\t\t\t\t\t\t==================================第%d个学生的学号：",i+1);
		 scanf("%ld",&stuGraInfo[i].stuNo);
		 if(stuGraInfo[i].stuNo==0)   break;
		 printf("\n请输入学生的基本信息\n");
		 printf("\n\t\t\t\t\t\t==================================课程编号：");
		 scanf("%d",&stuGraInfo[i].courseNo);getchar();
		 printf("\n\t\t\t\t\t\t==================================课程名称：");
		 scanf("%s",stuGraInfo[i].courseName);getchar();
		 printf("\n\t\t\t\t\t\t==================================学分：");
		 scanf("%d",&stuGraInfo[i].creditHour);getchar();
		 printf("\n\t\t\t\t\t\t==================================平时成绩：");
		 scanf("%d",&stuGraInfo[i].triGrade);getchar();
		 printf("\n\t\t\t\t\t\t==================================卷面成绩：");
		 scanf("%d",&stuGraInfo[i].examGrade);getchar();
		 stuGraInfo[i].totalGrade=(float)(stuGraInfo[i].examGrade)*0.5+(float)(stuGraInfo[i].triGrade)*0.5;
		 stuGraInfo[i].finalCreHour=stuGraInfo[i].totalGrade*0.01*stuGraInfo[i].creditHour;
		 printf("\n\t\t\t\t\t\t==================================综合成绩：");
		 printf("%5.2f",stuGraInfo[i].totalGrade);getchar();
		 printf("\n\t\t\t\t\t\t==================================实得学分：");
		 printf("%5.2f",stuGraInfo[i].finalCreHour);getchar();
		 i++;
	 }while(i<m);
	   save_file1(stuGraInfo,m);//保存输入的学生信息
	   printf("\n%d个学生信息录入完毕!   \n",m);
	   getch();
       return m;//返回输入学生的个数值
  }
void output(Stulnfo students[],int sum)//输出基本模块
{
	    int i;
	    printf("\n\t\t\t\t\t\t================================================================================\n");
        printf("\n\t\t\t\t\t\t=============================学生的基本信息如下：===============================\n");
        printf("\n\t\t\t\t\t\t学号         姓名     性别    宿舍号       电话号码        年龄\n");
        for(i=0;i<sum;i++)    //输出学生的信息
		{
		    printf("\t\t\t\t\t\t%5ld     %5s    %5s     %5d     %5s     %5d\n",
                    students[i].stuNo,students[i].name,students[i].sex,students[i].domNum,students[i].tel,students[i].age);
            printf("\n\t\t\t\t\t\t================================================================================\n");
		 }
	    getch();
        save_file(students,sum);
  }
void output1(StuGraInfo stuGraInfo[],int sum)//输出成绩基本模块
{
	    int i;
        printf("\n\t\t\t\t\t\t================================================================================\n");
        printf("\n\t\t\t\t\t\t================================添加学生成绩基本信息============================\n");
        printf("\n\t\t\t\t\t\t================================================================================\n");
        printf("\n\t\t\t\t\t\t学号     课程编号     课程名称   学分      平时成绩     卷面成绩    综合成绩     实得学分\n");
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
void inquire(Stulnfo students[],int sum)//查询信息模块
{
		int i,flag;
		long inquire_stoNo;
		char choice;
        sum=read_file(students);//读取文件
        printf("%d\n",sum);
   do
    {
       printf("\n\t\t\t\t\t\t================================================================================\n");
       printf("\n输入要查询的学生学号：");
       scanf("%ld",&inquire_stoNo); //输入要查询的学生学号
       for(i=0;i<sum;i++)
       {
           if(students[i].stuNo==inquire_stoNo)
           {
               printf("\n\t\t\t\t\t\t=================================此学生基本信息为：=============================\n");
               printf("\n\t\t\t\t\t\t================================================================================\n");
               printf("\n\t\t\t\t\t\t学号         姓名     性别    宿舍号       电话号码        年龄\n");
               printf("\n");
               printf("\t\t\t\t\t\t%5ld     %5s    %5s     %5d     %5s     %5d\n",
                    students[i].stuNo,students[i].name,students[i].sex,students[i].domNum,students[i].tel,students[i].age);
               printf("\n\t\t\t\t\t\t================================================================================\n");
                  break;
           }
       }
       if(i==sum)
       {
            printf("\n 未找到此学生信息！\n");
            getch();
       }
        printf("\n\n是否继续?(Y/N)");
        choice=getch();
        if(choice=='Y'||choice=='y')
        {
            flag=1;
            printf("\n继续!\n"); /*是否要继续*/
        }
        else
            flag=0;
   }while(flag==1);
    printf("\n按任意键返回主菜单!");
    getch();
}
void inquire1(StuGraInfo stuGraInfo[],int sum)//查询学生成绩基本信息模块
{
		int i,flag,inquire_stuNo;
		char choice;
	     sum=read_file1(stuGraInfo);//读取文件
		 printf("%d\n",sum);
	 do
	   {
       printf("\n\t\t\t\t\t\t================================================================================\n");
       printf("\n输入要查询的学生学号：");
       scanf("%d",&inquire_stuNo); //输入要查询的学生学号
        for(i=0;i<sum;i++)
	   if(stuGraInfo[i].stuNo==inquire_stuNo)
	   {
	       printf("\n\t\t\t\t\t\t=============================此学生成绩基本信息为：=============================\n");
	       printf("\n\t\t\t\t\t\t================================================================================\n");
   	       printf("\n\t\t\t\t\t\t学号     课程编号     课程名称   学分      平时成绩     卷面成绩    综合成绩     实得学分\n");
           printf("\n");
           printf("\n\t\t\t\t\t\t%5ld   %5d       %5s    %5d      %5d       %5d        %5.2f       %5.2f \n",stuGraInfo[i].stuNo,stuGraInfo[i].courseNo,stuGraInfo[i].courseName,stuGraInfo[i].creditHour,stuGraInfo[i].triGrade,stuGraInfo[i].examGrade,stuGraInfo[i].totalGrade,stuGraInfo[i].finalCreHour);
           printf("\n\t\t\t\t\t\t================================================================================\n");
	          break;
	   }
	      if(i==sum)
		  {
		       printf("\n未找到此学生信息    \n");
		      getch();
		  }
		   printf("\n\n是否继续?(Y/N)");
		   choice=getch();
		   if(choice=='Y'||choice=='y')
		   {
		       flag=1;
		      printf("\n继续。\n");
		   }
		    else
                flag=0;
   }while(flag==1);
	     printf("\n按任意键返回主菜单。");
         getch();
}
int del(Stulnfo students[],int sum)//删除信息模块
{
	   int i,del_num;
      printf("\n\t\t\t\t\t\t================================================================================\n");
      printf("请输入要删除的学生学号：");
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
	         printf("删除成功");
		  }
	  }
	   getch();
		save_file(students,sum-1);//保存删除后的学生信息到原文件
		return (sum-1) ;
	}
int del1(StuGraInfo stuGraInfo[],int sum)//删除学生成绩基本信息模块
{
	   int i,del_num;
      printf("\n\t\t\t\t\t\t================================================================================\n");
      printf("请输入要删除的学生学号");
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
	         printf("删除成功");
		  }
	  }
	   getch();
		save_file1(stuGraInfo,sum-1); //保存删除后的学生信息到原文件
		return (sum-1) ;
}
void  sort0(Stulnfo  students[],int sum)/*排序信息模块*/
{
        int i,j,t,s,a;
        char m[20],x[2],dian[20];
        printf("\n\t\t\t\t\t\t================================================================================\n");
        printf("\n      学生信息学号升序排序:\n");
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
   	  printf("\n\t\t\t\t\t\t学号         姓名     性别    宿舍号       电话号码        年龄\n");
   	  for(i=0;i<sum;i++)
      printf("\t\t\t\t\t\t%5ld     %5s    %5s     %5d     %5s     %5d\n",
		     students[i].stuNo,students[i].name,students[i].sex,students[i].domNum,students[i].tel,students[i].age);
      printf("\n\t\t\t\t\t\t================================================================================\n");/*输出排序后的学生信息*/
      getch();
      save_file(students,sum);/*保存排序后的学生信息到文件中*/
	}
void  sort1(StuGraInfo  stuGraInfo[],int sum)//排序成绩信息模块学号升序
{
	     int i,j;
	     long a,b,c;
	     float t,g;
        printf("\n\t\t\t\t\t\t================================================================================\n");
        printf("\n\t\t\t\t\t\t===============================学生成绩按学号升序排序===========================\n");
        printf("\n\t\t\t\t\t\t================================================================================\n");
       for(i=0;i<sum-1;i++)//冒泡法升序
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
		printf("\n\t\t\t\t\t\t学号     课程编号     课程名称   学分      平时成绩     卷面成绩    综合成绩     实得学分\n");
		printf("\n");
        for(i=0;i<sum;i++)
		{
		    printf("\n\t\t\t\t\t\t%5ld   %5d       %5s    %5d      %5d       %5d        %5.2f       %5.2f \n",stuGraInfo[i].stuNo,stuGraInfo[i].courseNo,stuGraInfo[i].courseName,stuGraInfo[i].creditHour,stuGraInfo[i].triGrade,stuGraInfo[i].examGrade,stuGraInfo[i].totalGrade,stuGraInfo[i].finalCreHour);
            printf("\n");
		 }
        printf("\n\t\t\t\t\t\t================================================================================\n");
        printf("\n请按任意键返回主菜单");
		getch();
        save_file1(stuGraInfo,sum);  //保存排序后的学生信息到文件中
	}
void  sort2(StuGraInfo  stuGraInfo[],int sum)//按综合成绩降序排列
{
	     int i,j;
	     long a,b,c;
	     float t,g;
        printf("\n\t\t\t\t\t\t================================================================================\n");
        printf("\n\t\t\t\t\t\t===========================学生成绩按综合成绩降序排序===========================\n");
        printf("\n\t\t\t\t\t\t================================================================================\n");
        for(i=0;i<sum-1;i++)//冒泡法降序
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
   	    printf("\n\t\t\t\t\t\t学号     课程编号     课程名称   学分      平时成绩     卷面成绩    综合成绩     实得学分\n");
		printf("                \n");
        for(i=0;i<sum;i++)
		{
		    printf("\n\t\t\t\t\t\t%5ld   %5d       %5s    %5d      %5d       %5d        %5.2f       %5.2f \n",stuGraInfo[i].stuNo,stuGraInfo[i].courseNo,stuGraInfo[i].courseName,stuGraInfo[i].creditHour,stuGraInfo[i].triGrade,stuGraInfo[i].examGrade,stuGraInfo[i].totalGrade,stuGraInfo[i].finalCreHour);
            printf("\n");
		 }
        printf("\n\t\t\t\t\t\t================================================================================\n");/*输出排序后的学生信息*/
		printf("\n按任意键返回主菜单");
		getch();
        save_file1(stuGraInfo,sum);//保存排序后的学生信息到文件中
	}
void pailie()//排序方式
{
    int x;
    //Stulnfo students[MAX];
	StuGraInfo stuGraInfo[MAX];
    int sum1=read_file1(stuGraInfo);//,x,choice,flag;
    printf("\n\t\t\t\t\t\t==========================欢迎使用学生学籍信息管理系统==========================\n\n");
    printf("\t\t\t\t\t\t================================================================================\n\n");
    printf("\n\t\t\t\t\t\t==================================请选择排列方式：==============================\n");
    printf("\n\t\t\t\t\t\t===============================1.按学生学号升序排列==============================\n");
    printf("\n\t\t\t\t\t\t===============================2.按综合成绩降序排列==============================\n");
    printf("\n\n\t\t\t\t\t\t================================================================================\n");
    printf("请选择排列方式(1-2):");
    scanf("%d",&x);
    switch(x)
    {
        case 1:sort1(stuGraInfo,sum1);break;
        case 2:sort2(stuGraInfo,sum1);break;
    }
}
int append(Stulnfo  students[],int sum)/*添加基本信息模块*/
{
	int i=sum,flag=0;/*从已经输入的学生尾部添加*/
    char choice	;
	sum=read_file(students);
    printf("\n\t\t\t\t\t\t================================================================================\n");
	printf("\n\t\t\t\t\t\t===================================添加学生信息=================================\n");
    do
	{
	if(i<MAX)/*已经输入的学生个数和要添加的学生个数之和要小于定义的学生个数最大值*/
		{
			printf("\n\t\t\t\t\t\t==================================新添加学生学号：");
		    scanf("%ld",&students[i].stuNo);getchar();
		    printf("\n\t\t\t\t\t\t==================================姓名：");
		    scanf("%s",students[i].name);getchar();
		    printf("\n\t\t\t\t\t\t==================================性别：");/*输入添加学生的基本信息*/
		    scanf("%s",students[i].sex);getchar();
		    printf("\n\t\t\t\t\t\t==================================年龄：");
		    scanf("%d",&students[i].age);getchar();
		    printf("\n\t\t\t\t\t\t==================================宿舍号：");
		    scanf("%d",&students[i].domNum);getchar();
		    printf("\n\t\t\t\t\t\t==================================电话号码：");
		    scanf("%s",students[i].tel);getchar();
		     i++;
		}
		 printf("\n是否继续添加?(Y/N)");
         choice=getch();
		 if(choice=='Y'||choice=='y')
		 {  flag=1;
		    printf("\n继续。\n");/*是否要继续添加*/
		 }
		 else flag=0;
		  save_file(students,i); /*保存添加的学生信息到原文件*/
	}while(flag==1);;
	  printf("\n请按任意键返回主菜单。");
	  getch();
	  return i; /*返回文件中学生个数值*/
}
int append1(StuGraInfo stuGraInfo[],int sum)/*添加学生成绩基本信息模块*/
{
	int i=sum,flag=0;/*从已经输入的学生尾部添加*/
    char choice	;
	sum=read_file1(stuGraInfo);
    printf("\n\t\t\t\t\t\t================================================================================\n");
	printf("\n\t\t\t\t\t\t================================添加学生成绩基本信息============================\n");
    do
	{
	if(i<MAX)/*已经输入的学生个数和要添加的学生个数之和要小于定义的学生个数最大值*/
		{
         printf("\n\t\t\t\t\t\t==================================学生学号:");
		 scanf("%ld",&stuGraInfo[i].stuNo);getchar();
		 printf("\n\t\t\t\t\t\t==================================课程编号:");
		 scanf("%d",&stuGraInfo[i].courseNo);getchar();
		 printf("\n\t\t\t\t\t\t==================================课程名称:");
		 scanf("%s",stuGraInfo[i].courseName);getchar();
		 printf("\n\t\t\t\t\t\t==================================学分:");
		 scanf("%d",&stuGraInfo[i].creditHour);getchar();
		 printf("\n\t\t\t\t\t\t==================================平时成绩：");
		 scanf("%d",&stuGraInfo[i].triGrade);getchar();
		 printf("\n\t\t\t\t\t\t==================================卷面成绩:");
		 scanf("%d",&stuGraInfo[i].examGrade);getchar();
		 stuGraInfo[i].totalGrade=(float)(stuGraInfo[i].examGrade)*0.5+(float)(stuGraInfo[i].triGrade)*0.5;
		 stuGraInfo[i].finalCreHour=stuGraInfo[i].totalGrade*0.01*stuGraInfo[i].creditHour;
		 printf("\n\t\t\t\t\t\t==================================综合成绩：");
		 printf("%5.2f",stuGraInfo[i].totalGrade);getchar();
		 printf("\n\t\t\t\t\t\t==================================实得学分：");
		 printf("%5.2f",stuGraInfo[i].finalCreHour);getchar();
		     i++;
		}
		 printf("\n是否继续添加？(Y/N)");
        choice=getch();
		 if(choice=='Y'||choice=='y')
		 {  flag=1;
		    printf("\n继续。\n"); /*是否要继续添加*/
		 }
		 else flag=0;
		 save_file1(stuGraInfo,i); /*保存添加的学生信息到原文件*/
	}while(flag==1);;
	  printf("\n按任意键返回主菜单!");
	  getch();
	  return i; /*返回文件中学生个数值*/
}
int main()//主函数
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
    printf("\t\t\t\t\t\t==========================欢迎使用学生学籍信息管理系统==========================");
    printf("\n\n\t\t\t\t\t\t==================================请选择的身份==================================");
    printf("\n\n\n\n\t\t\t\t\t\t\t    \t\t\t1：学生入口\t\t\t\t    \n");
    printf("\n\n\n\t\t\t\t\t\t\t    \t\t\t2：老师入口\t\t\t\t    \n");
    printf("\n\n\n\n\t\t\t\t\t\t================================================================================\n");
    printf("\n请选择身份（1-2）:");
    scanf("%d",&x);
   printf("                 欢迎来到学生学籍信息管理系统          \n");
    printf("                    请输入你的账号(7位):");
    for(i=0;i<7;i++)
    {
        zhanghao=getchar();
        b[i]=zhanghao;
    }
    printf("\n");
     printf("\n");
    printf("                    请输入你的密码(6位):");
    for(i=0;i<6;i++)
    {
        mima=getch();
        printf("*");
        a[i]=mima;
    }
    printf("\n");

    if(!(strcmp(a,"123456")))
    {

         printf("\n\n\n\n\n\n              成功登陆!");
    }
    else
    {
        printf("\n\n\n\n\n\n\n\n\n          密码错误,您无权使用该系统!\n\n");
        exit(1);
    }
    sum=read_file(students);
    sum1=read_file1(stuGraInfo);
    if(!sum)
	{
	     printf("录入基本信息!\n");
      getch();
	  sum=input(students);/*录入学生信息*/
   }
   if(!sum1)
	{
	     printf("录入成绩信息!\n");
      getch();
	  sum1=input1(stuGraInfo);/*录入学生成绩信息*/
   }
   if(x==2)
   {
       do
       {
            mainmenu();
            printf("请选择查看的信息（0-2）：");
            scanf("%d",&op1);
              if(op1==1)
              {

                  do{
                      message();
                      printf("\n请选择执行的功能(0-5)：");
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
                        printf("\n请选择执行的功能(0-5)：");
                        scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1: sum1=append1(stuGraInfo,sum1);break;
                        case 2: sum1=del1(stuGraInfo,sum1);break;
                        case 3: inquire1(stuGraInfo,sum1); break;
                        case 4: pailie();break;
                        case 5: output1(stuGraInfo,sum1);   break;
                        case 0:  break; /*执行完各模块后按0退出系统*/
                    }
                  }while(choice!=0);
              }
       }while(op1!=0);
        save_file(students,sum);
        save_file1(stuGraInfo,sum);/*保存执行完各模块后的学生信息*/
   }
    if(x==1)
    {
       do
       {
          printf("\n\t\t\t\t\t\t================================================================================\n");
          printf("\n\t\t\t\t\t\t==========================欢迎使用学生学籍信息管理系统==========================\n\n");
          printf("\n\t\t\t\t\t\t\t====\t\t\t1：查询个人信息\t\t\t\t====\n");
          printf("\n\t\t\t\t\t\t\t====\t\t\t2：查询个人成绩基本信息\t\t====\n");
          printf("\n\t\t\t\t\t\t\t====\t\t\t0：退出系统\t\t\t\t====\n");
          printf("\n\n\t\t\t\t\t\t================================================================================\n");
          printf("\n请选择执行的功能(0-2)：");
          scanf("%d",&choice);
          switch(choice)
          {
             case 1: inquire(students,sum); break;
             case 2:inquire1(stuGraInfo,sum);break;
             case 0:   break;/*执行完各模块后按0退出系统*/
          }
        }while(choice!=0);
        save_file(students,sum);
        save_file1(stuGraInfo,sum1);/*保存执行完各模块后的学生信息*/
    }
    return 0;
}
