#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#define LEN sizeof(struct Student)
//����ṹ�崢��ѧ����Ϣ
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

//������             
int main()                                 
{   long a,number,numb;//a�������ڹ��ܵ�ѡ�� 
    char name[20];
    int flag=1;
    struct Student *stu,*stud;
    struct Student *head=NULL;  
    //�������� 
    void Mainmenueshow();   
    void Submenueshow();                             
    void printsepar();                                                   //����ָ���
	struct Student*creat();                                              //1.��Ϣ¼�� 
    void print(struct Student *head);                                    //2.��Ϣ���  
    struct Student *Deleterecord(struct Student *head,long number);      //3.��Ϣɾ��
	struct Student *Addrecord(struct Student *head,struct Student *stud);//4.��Ϣ���� 
	void Numbfindrecord(struct Student *head,long numb);                 //5.1��ѧ�Ų���
	void Namefindrecord(struct Student *head,char *name);                //5.2.����������
	void Saverecordshow(struct Student *head);                           //6.������Ϣ
	struct Student*Readrecord();                                         //7.��ȡ 
	Mainmenueshow();
	printf("���������蹦��ǰ�����֣�1~8����");
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
	           case 3:printf("��������Ҫɾ����ѧ�ţ�");
		              scanf("%ld",&number);
		              head=Deleterecord(head,number);break;                      
               case 4:stu=(struct Student*)malloc(LEN);
                      printf("�������ѧ����ѧ�ţ�");
	                  scanf("%ld",&stu->num);
	                  getchar();
               	      printf("�������ѧ����������");
	                  scanf("%s",&stu->name);
	                  printf("�������ѧ�������䣺");
	                  scanf("%s",&stu->age);
	                  printf("�������ѧ�����Ա�");
	                  scanf("%s",&stu->sex);
                      printf("�������ѧ���ĳ������£�");
                      scanf("%s",&stu->birth);
	                  printf("�������ѧ���ĵ�ַ��");
	                  scanf("%s",&stu->address);
	                  printf("�������ѧ���ĵ绰��");
	                  scanf("%s",&stu->tele);
                      printf("�������ѧ����E-mail��");
	                  scanf("%s",&stu->email);
		              head=Addrecord(head,stu);
				      break; 
	           case 5:system("cls");Submenueshow();
	                  while(1)
	                  {  printf("���������蹦��ǰ�����֣�1~2����");
	             	     scanf("%d",&a);
	                     while(1)
	                    	{	                    		
	             	    	    if(a>0&&a<3)	             	    	    
	             	         	{  			                                        //�����ڲ��������� 
	             		           if(a==1)
							       {      
							        printf("���������ѧ�ţ�");
							        scanf("%d",&numb);							
							    	Numbfindrecord(head,numb);
							       }   
	             		           else
	             		           {
	             		   	        printf("���������������");
	             		   	        getchar();
	             		   	        scanf("%s",&name);
	             		     	    Namefindrecord(head,name); 
						           }						        
						        }    
						        else
	                            printf("����������������룡\n");
	                            break;	
					        }
						    	printf("�Ƿ��������Y��N:");
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
	        printf("�����������蹦��ǰ�����֣�1~8����");
	        break;
	        }
	    else
	    printf("����������������룡");
	    break;
        }
    }
	printf("���˳�ϵͳ");
	printf("��ӭ���ٴ�ʹ��");
	return 0; 
}

void printsepar()
{
	for(int i=0;i<80;i++)
	printf("*"); 
	printf("\n"); 
}

//������ʾ���˵�����
void Mainmenueshow() 
{
	printsepar();
	printf("*                   ѧ  ��  ��  Ϣ  ��  ��  ϵ  ͳ                             *\n");
	printf("*                           1.ѧ����Ϣ¼��                                     *\n");      
	printf("*                           2.ѧ����Ϣ�������                               *\n");
	printf("*                           3.ѧ����Ϣɾ��                                     *\n");
	printf("*                           4.ѧ����Ϣ����                                     *\n");
	printf("*                           5.ѧ����Ϣ����                                     *\n");
	printf("*                           6.����¼��ѧ����Ϣ                                 *\n");
	printf("*                           7.�鿴����ѧ����Ϣ                                 *\n");
	printf("*                           8.�˳�ϵͳ                                         *\n");
	printsepar();
}

//������ʾ�Ӳ˵�����
void Submenueshow()                                                 
{
	printsepar();
	printf("*                             ѧ����Ϣ����                                     *\n");
	printf("*                           1.��ѧ��ѧ�Ų���                                   *\n");
	printf("*                           2.��ѧ����������                                   *\n");
	printsepar();
}

//����¼��ѧ����Ϣ����
struct Student*creat() 
{  
    int n;
	struct Student*head,*p1,*p2;
	n=0;
	head=NULL;
	p1=p2=(struct Student*) malloc (LEN);
	printf("��¼���1��ѧ����ѧ�ţ�");
	scanf("%ld",&p1->num);
	getchar();
	printf("��¼���1��ѧ����������");
	scanf("%s",&p1->name);
	printf("��¼���1��ѧ�������䣺");
	scanf("%s",&p1->age);
	printf("��¼���1��ѧ�����Ա�");
	scanf("%s",&p1->sex);
	printf("��¼���1��ѧ���ĳ������£�");
	scanf("%s",&p1->birth);
	printf("��¼���1��ѧ���ĵ�ַ��");
	scanf("%s",&p1->address);
	printf("��¼���1��ѧ���ĵ绰��");
	scanf("%s",&p1->tele);
	printf("��¼���1��ѧ����E-mail��");
	scanf("%s",&p1->email);
while(1)//������ѭ��������������ʱ���� 
	{   
		n=n+1;
		if(n==1)head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct Student*)malloc(LEN);
        printf("��¼���%d��ѧ����ѧ�ţ�",n+1);
     	scanf("%ld",&p1->num);
     	if(p1->num==0)
		 {
		 	printf("���������\n");
		    break;               //Լ������ѧ��Ϊ0���˳� 
		 }
	    printf("��¼���%d��ѧ��������:",n+1);
    	scanf("%s",&p1->name);
	    printf("��¼���%d��ѧ��������:",n+1);
    	scanf("%s",&p1->age);
    	printf("��¼���%d��ѧ�����Ա�:",n+1);
    	scanf("%s",&p1->sex);
    	printf("��¼���%d��ѧ���ĳ�������:",n+1);
    	scanf("%s",&p1->birth);
	    printf("��¼���%d��ѧ���ĵ�ַ:",n+1);
    	scanf("%s",&p1->address);
    	printf("��¼���%d��ѧ���ĵ绰:",n+1);
    	scanf("%s",&p1->tele);
    	printf("��¼���%d��ѧ����E-mail:",n+1);
    	scanf("%s",&p1->email);
  	}
	p2->next=NULL;
	return head;
}

//���� 
struct Student*sort(struct Student *head)
{
	int count=0,i,j,temp;
	struct Student *p1,*p2;
	if(head!=NULL)
	{
	p1=head;
	//countΪ����ڵ���
	while(p1)
	{
		count++;
		p1=p1->next;
	}
    //���ٶ�̬���飬�������е����ݴ��浽��̬������ȥ
    p2=(struct Student *)malloc(count*sizeof(struct Student));
    p1=head;//p1����ָ��ͷָ��
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
	//����������ð�ݷ���������
	for(i=0;i<count-1;i++)
	{
		for(j=0;j<count-1-i;j++)
		{
			if(p2[j].num >p2[j+1].num )//���� 
			{
				temp=p2[j].num ;
		     	p2[j].num=p2[j+1].num;
	    		p2[j+1].num=temp;
			}
		}
	}	
	//���������ź����Ԫ�طŻ�������ȥ
	p1=head;//p1����ָ��ͷָ��
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

//�������ѧ����Ϣ����
void print(struct Student *head) 
{   
    struct Student *sort(struct Student*head);//���������� 
    int s=1; 
	struct Student*p;
	p=sort(head);
	if(head!=NULL)
	{
	printf("\n���������е�ѧ����Ϣ:\n");
	printf("ѧ��       ����   ���� �Ա�     ��������           ��ַ        �绰             E-mail\n");
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
		printf("\n����ѧ����Ϣ����������ѧ����Ϣ��\n");
	}	
}

//����ѧ����Ϣɾ������
struct Student *Deleterecord(struct Student *head,long number) 
{   
	struct Student *p1,*p2;
	if(head==NULL)
	{
		printf("\n����ѧ����Ϣ���޷�ɾ������������ѧ����Ϣ��\n");
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
		printf("��ɾ����ѧ��Ϊ%d��ѧ����\n",number);
	}
	else
	printf("��ѧ�������ڣ�\n");
	return head;
} 

//����ѧ����Ϣ���Ӻ��� 
struct Student *Addrecord(struct Student *head,struct Student *stud) 
{

	stud->next=head;
    head=stud;
	return head;
}

//������ѧ�Ų��ҵĺ��� 
void Numbfindrecord(struct Student *head,long numb)
{   
    struct Student *p1;
	p1=head;
    if(head==NULL)printf("����ѧ����Ϣ�ɹ���ѯ��\n");
    else
    {
    	while((p1->num)!=numb && (p1->next)!=NULL)
	    {
		    p1=p1->next;
		}
	    if(p1->num==numb)
		{
			printf("��ѯѧ����Ϣ���£�\n");
	        printf("ѧ��       ����   ���� �Ա�     ��������           ��ַ        �绰             E-mail\n");
	        printf("%ld%8s%4s%4s%15s%15s%15s%25s\n"
	        ,p1->num,p1->name,p1->age,p1->sex,p1->birth,p1->address,p1->tele,p1->email);
		}
	    else
	    printf("�޸�ѧ����¼\n");	
	}	
} 

//�������������ҵĺ��� 
void Namefindrecord(struct Student *head,char *name)  
{	
	struct Student *p1;
	p1=head;
    if(head==NULL)
	printf("����ѧ����Ϣ�ɹ���ѯ��\n");
    else
    {
    	while(strcmp(p1->name,name)!=0 && (p1->next) != NULL)    
	    {	
	        p1=p1->next;                                                    
	    }
	    if(strcmp(p1->name,name)==0)
	    {
	     	printf("��ѯѧ����Ϣ���£�\n");
	        printf("ѧ��       ����   ���� �Ա�     ��������           ��ַ        �绰             E-mail\n");
	        printf("%ld%8s%4s%4s%15s%15s%15s%25s\n"
	        ,p1->num,p1->name,p1->age,p1->sex,p1->birth,p1->address,p1->tele,p1->email);
	    }
	    else
	    printf("�޸�ѧ����¼��\n");
	}
}

//���溯�� 
void Saverecordshow(struct Student *head)
{
	FILE *fp;
	struct Student *p1=head;
	char filename[20];
	if(head==NULL)
	printf("û��ѧ����¼���޷����棡\n");
	else
	{   
		printf("�������ļ�����");
		getchar(); //���ջس��� 
     	gets(filename);
    	if((fp=fopen(filename,"wb"))==NULL)
    	{
	    	printf("�ļ���ʧ��!");
	    	exit(1);
    	}
    	else
    	{  
    		while(p1)
	        {   
	    	    fwrite(p1,sizeof(struct Student),1,fp);
	    	    p1=p1->next;	    	
    	    }
     	    printf("������ϣ�\n");
    	    fclose(fp); //�ر��ļ� 	
		}	    
	}	
}

//��ȡ����ѧ����Ϣ 
struct Student *Readrecord()
{
	void print(struct Student *head);
	struct Student *sort(struct Student*head);
	char filename[20];
	FILE * fp;
	struct Student*head,*p1,*p2;
	head=NULL;
	printf("�������ļ�����");
	getchar(); //���ջس���              
	gets(filename);
	if((fp=fopen(filename,"rb"))==NULL)
	{
		printf("�޷����ļ���\n");
		return NULL;
	}
	else
	{
		p1=(struct Student*)malloc(LEN);
    	while(fread(p1,sizeof(struct Student),1,fp))
    	{			    
         if(!head)//ͷָ��Ϊ��ʱ����ͷָ��ָ��տ��ٵĽ�� 
         {
         	head=p2=p1;
		 }
		 else//����֮��Ľ�����ӵ����� 
		 {
		    p2->next=p1;
		    p2=p1;
		 }
		 p1=(struct Student*)malloc(LEN);
    	}
	}	
	fclose(fp);//�ر��ļ� 
	sort(head); 
	print(head);//������� 
	return head;
}
