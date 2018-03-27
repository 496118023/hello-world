#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#define LEN sizeof(struct Student)
//定义结构体储存学生信息
struct Student  
{
	long num;
	char name[20];
	char age[5];
	char sex[5];
	char birth[20];
	char address[20];
	char tele[20];
	char email[40];
	struct Student*next;
};

//主函数             
int main()                                 
{   long a,number,numb;//a变量用于功能的选择 
    char name[20];
    int flag=1;
    struct Student *stu,*stud;
    struct Student *head=NULL;  
    //函数声明 
    void Mainmenueshow();   
    void Submenueshow();                             
    void printsepar();                                                   //定义分隔符
	struct Student*creat();                                              //1.信息录入 
    void print(struct Student *head);                                    //2.信息输出  
    struct Student *Deleterecord(struct Student *head,long number);      //3.信息删除
	struct Student *Addrecord(struct Student *head,struct Student *stud);//4.信息增加 
	void Numbfindrecord(struct Student *head,long numb);                 //5.1按学号查找
	void Namefindrecord(struct Student *head,char *name);                //5.2.按姓名查找
	void Saverecordshow(struct Student *head);                           //6.保存信息
	struct Student*Readrecord();                                         //7.读取 
	Mainmenueshow();
	printf("请输入所需功能前的数字（1~8）：");
	while(flag)
	{   
	    scanf("%d",&a);	    
		while(1)		
	    {	    	
	        if(a>0&&a<=8)
	        {
	   	    switch(a)
	        {  case 1:head=creat();break;                        
               case 2:print(head);break;
	           case 3:printf("请输入想要删除的学号：");
		              scanf("%ld",&number);
		              head=Deleterecord(head,number);break;                      
               case 4:stu=(struct Student*)malloc(LEN);
                      printf("请输入此学生的学号：");
	                  scanf("%ld",&stu->num);
	                  getchar();
               	      printf("请输入此学生的姓名：");
	                  scanf("%s",&stu->name);
	                  printf("请输入此学生的年龄：");
	                  scanf("%s",&stu->age);
	                  printf("请输入此学生的性别：");
	                  scanf("%s",&stu->sex);
                      printf("请输入此学生的出生年月：");
                      scanf("%s",&stu->birth);
	                  printf("请输入此学生的地址：");
	                  scanf("%s",&stu->address);
	                  printf("请输入此学生的电话：");
	                  scanf("%s",&stu->tele);
                      printf("请输入此学生的E-mail：");
	                  scanf("%s",&stu->email);
		              head=Addrecord(head,stu);
				      break; 
	           case 5:system("cls");Submenueshow();
	                  while(1)
	                  {  printf("请输入所需功能前的数字（1~2）：");
	             	     scanf("%d",&a);
	                     while(1)
	                    	{	                    		
	             	    	    if(a>0&&a<3)	             	    	    
	             	         	{  			                                        //调用内部两个函数 
	             		           if(a==1)
							       {      
							        printf("请输入查找学号：");
							        scanf("%d",&numb);							
							    	Numbfindrecord(head,numb);
							       }   
	             		           else
	             		           {
	             		   	        printf("请输入查找姓名：");
	             		   	        getchar();
	             		   	        scanf("%s",&name);
	             		     	    Namefindrecord(head,name); 
						           }						        
						        }    
						        else
	                            printf("输入错误！请重新输入！\n");
	                            break;	
					        }
						    	printf("是否继续？是Y否N:");
						        char p;
						        getchar();
						        p=getchar(); 
						        if(p=='n' ||p=='N')
						        {
						        	system("cls");
						        	Mainmenueshow();
						        	break;	
								}						        	
				      }break;			 
				 case 6:Saverecordshow(head);break;
				 case 7:head=Readrecord();;break;
				 case 8:flag=0;
	        }   
	        if(flag!=0) 
	        printf("请您输入所需功能前的数字（1~8）：");
	        break;
	        }
	    else
	    printf("输入错误！请重新输入！");
	    break;
        }
    }
	printf("已退出系统");
	printf("欢迎您再次使用");
	return 0; 
}

void printsepar()
{
	for(int i=0;i<80;i++)
	printf("*"); 
	printf("\n"); 
}

//定义显示主菜单函数
void Mainmenueshow() 
{
	printsepar();
	printf("*                   学  生  信  息  管  理  系  统                             *\n");
	printf("*                           1.学生信息录入                                     *\n");      
	printf("*                           2.学生信息排序并输出                               *\n");
	printf("*                           3.学生信息删除                                     *\n");
	printf("*                           4.学生信息增加                                     *\n");
	printf("*                           5.学生信息查找                                     *\n");
	printf("*                           6.保存录入学生信息                                 *\n");
	printf("*                           7.查看已有学生信息                                 *\n");
	printf("*                           8.退出系统                                         *\n");
	printsepar();
}

//定义显示子菜单函数
void Submenueshow()                                                 
{
	printsepar();
	printf("*                             学生信息查找                                     *\n");
	printf("*                           1.按学生学号查找                                   *\n");
	printf("*                           2.按学生姓名查找                                   *\n");
	printsepar();
}

//定义录入学生信息函数
struct Student*creat() 
{  
    int n;
	struct Student*head,*p1,*p2;
	n=0;
	head=NULL;
	p1=p2=(struct Student*) malloc (LEN);
	printf("请录入第1个学生的学号：");
	scanf("%ld",&p1->num);
	getchar();
	printf("请录入第1个学生的姓名：");
	scanf("%s",&p1->name);
	printf("请录入第1个学生的年龄：");
	scanf("%s",&p1->age);
	printf("请录入第1个学生的性别：");
	scanf("%s",&p1->sex);
	printf("请录入第1个学生的出生年月：");
	scanf("%s",&p1->birth);
	printf("请录入第1个学生的地址：");
	scanf("%s",&p1->address);
	printf("请录入第1个学生的电话：");
	scanf("%s",&p1->tele);
	printf("请录入第1个学生的E-mail：");
	scanf("%s",&p1->email);
while(1)//定义死循环，当满足条件时跳出 
	{   
		n=n+1;
		if(n==1)head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct Student*)malloc(LEN);
        printf("请录入第%d个学生的学号：",n+1);
     	scanf("%ld",&p1->num);
     	if(p1->num==0)
		 {
		 	printf("输入结束！\n");
		    break;               //约定输入学号为0则退出 
		 }
	    printf("请录入第%d个学生的姓名:",n+1);
    	scanf("%s",&p1->name);
	    printf("请录入第%d个学生的年龄:",n+1);
    	scanf("%s",&p1->age);
    	printf("请录入第%d个学生的性别:",n+1);
    	scanf("%s",&p1->sex);
    	printf("请录入第%d个学生的出生年月:",n+1);
    	scanf("%s",&p1->birth);
	    printf("请录入第%d个学生的地址:",n+1);
    	scanf("%s",&p1->address);
    	printf("请录入第%d个学生的电话:",n+1);
    	scanf("%s",&p1->tele);
    	printf("请录入第%d个学生的E-mail:",n+1);
    	scanf("%s",&p1->email);
  	}
	p2->next=NULL;
	return head;
}

//排序 
struct Student*sort(struct Student *head)
{
	int count=0,i,j,temp;
	struct Student *p1,*p2;
	if(head!=NULL)
	{
	p1=head;
	//count为链表节点数
	while(p1)
	{
		count++;
		p1=p1->next;
	}
    //开辟动态数组，将链表中的数据储存到动态数组中去
    p2=(struct Student *)malloc(count*sizeof(struct Student));
    p1=head;//p1重新指向头指针
	for(i=0;i<count;i++)
	{
		p2[i].num=p1->num;
		strcpy(p2[i].name ,p1->name );
		strcpy(p2[i].age ,p1->age );
		strcpy(p2[i].sex ,p1->sex );
		strcpy(p2[i].birth ,p1->birth );
		strcpy(p2[i].address ,p1->address);
		strcpy(p2[i].tele ,p1->tele );
		strcpy(p2[i].email ,p1->email );
		p1=p1->next;
	}
	//数组中利用冒泡法进行排序
	for(i=0;i<count-1;i++)
	{
		for(j=0;j<count-1-i;j++)
		{
			if(p2[j].num >p2[j+1].num )//升序 
			{
				temp=p2[j].num ;
		     	p2[j].num=p2[j+1].num;
	    		p2[j+1].num=temp;
			}
		}
	}	
	//将数组中排号序的元素放回链表中去
	p1=head;//p1重新指向头指针
	for(i=0;i<count;i++)
    {
    	p1->num=p2[i].num;
		strcpy( p1->name,p2[i].name );
		strcpy(p1->age ,p2[i].age );
		strcpy( p1->sex,p2[i].sex );
		strcpy(p1->birth, p2[i].birth );
		strcpy( p1->address,p2[i].address);
		strcpy(p1->tele ,p2[i].tele );
		strcpy( p1->email, p2[i].email);
		p1=p1->next;
			
    }
    }
	return head;	 
}

//定义输出学生信息函数
void print(struct Student *head) 
{   
    struct Student *sort(struct Student*head);//声明排序函数 
    int s=1; 
	struct Student*p;
	p=sort(head);
	if(head!=NULL)
	{
	printf("\n以下是所有的学生信息:\n");
	printf("学号       姓名   年龄 性别     出生年月           地址        电话             E-mail\n");
	do
	{  
		printf("%ld%8s%4s%4s%15s%15s%15s%25s\n"
		,p->num,p->name,p->age,p->sex,p->birth,p->address,p->tele,p->email);
		p=p->next;
		s++; 
	} while(p!=NULL);
	}
	else
	{
		printf("\n暂无学生信息，请先输入学生信息！\n");
	}	
}

//定义学生信息删除函数
struct Student *Deleterecord(struct Student *head,long number) 
{   
	struct Student *p1,*p2;
	if(head==NULL)
	{
		printf("\n暂无学生信息，无法删除！请先输入学生信息！\n");
		return head;
	}
	p1=head;
	while(number!=p1->num && p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(number==p1->num)
	{
		if(p1==head)head=p1->next;
		else p2->next=p1->next;
		printf("已删除该学号为%d的学生！\n",number);
	}
	else
	printf("该学生不存在！\n");
	return head;
} 

//定义学生信息增加函数 
struct Student *Addrecord(struct Student *head,struct Student *stud) 
{

	stud->next=head;
    head=stud;
	return head;
}

//定义用学号查找的函数 
void Numbfindrecord(struct Student *head,long numb)
{   
    struct Student *p1;
	p1=head;
    if(head==NULL)printf("暂无学生信息可供查询！\n");
    else
    {
    	while((p1->num)!=numb && (p1->next)!=NULL)
	    {
		    p1=p1->next;
		}
	    if(p1->num==numb)
		{
			printf("查询学生信息如下：\n");
	        printf("学号       姓名   年龄 性别     出生年月           地址        电话             E-mail\n");
	        printf("%ld%8s%4s%4s%15s%15s%15s%25s\n"
	        ,p1->num,p1->name,p1->age,p1->sex,p1->birth,p1->address,p1->tele,p1->email);
		}
	    else
	    printf("无该学生记录\n");	
	}	
} 

//定义用姓名查找的函数 
void Namefindrecord(struct Student *head,char *name)  
{	
	struct Student *p1;
	p1=head;
    if(head==NULL)
	printf("暂无学生信息可供查询！\n");
    else
    {
    	while(strcmp(p1->name,name)!=0 && (p1->next) != NULL)    
	    {	
	        p1=p1->next;                                                    
	    }
	    if(strcmp(p1->name,name)==0)
	    {
	     	printf("查询学生信息如下：\n");
	        printf("学号       姓名   年龄 性别     出生年月           地址        电话             E-mail\n");
	        printf("%ld%8s%4s%4s%15s%15s%15s%25s\n"
	        ,p1->num,p1->name,p1->age,p1->sex,p1->birth,p1->address,p1->tele,p1->email);
	    }
	    else
	    printf("无该学生记录！\n");
	}
}

//保存函数 
void Saverecordshow(struct Student *head)
{
	FILE *fp;
	struct Student *p1=head;
	char filename[20];
	if(head==NULL)
	printf("没有学生记录！无法保存！\n");
	else
	{   
		printf("请输入文件名：");
		getchar(); //吸收回车符 
     	gets(filename);
    	if((fp=fopen(filename,"wb"))==NULL)
    	{
	    	printf("文件打开失败!");
	    	exit(1);
    	}
    	else
    	{  
    		while(p1)
	        {   
	    	    fwrite(p1,sizeof(struct Student),1,fp);
	    	    p1=p1->next;	    	
    	    }
     	    printf("保存完毕！\n");
    	    fclose(fp); //关闭文件 	
		}	    
	}	
}

//读取已有学生信息 
struct Student *Readrecord()
{
	void print(struct Student *head);
	struct Student *sort(struct Student*head);
	char filename[20];
	FILE * fp;
	struct Student*head,*p1,*p2;
	head=NULL;
	printf("请输入文件名：");
	getchar(); //吸收回车符              
	gets(filename);
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("无法打开文件！\n");
		return NULL;
	}
	else
	{
		p1=(struct Student*)malloc(LEN);
    	while(fread(p1,sizeof(struct Student),1,fp))
    	{			    
         if(!head)//头指针为空时，将头指针指向刚开辟的结点 
         {
         	head=p2=p1;
		 }
		 else//开辟之后的结点连接到链表 
		 {
		    p2->next=p1;
		    p2=p1;
		 }
		 p1=(struct Student*)malloc(LEN);
    	}
	}	
	fclose(fp);//关闭文件 
	sort(head); 
	print(head);//输出链表 
	return head;
}
