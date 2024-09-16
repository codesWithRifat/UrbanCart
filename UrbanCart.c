#include<windows.h>
#include<stdio.h>
                 //  Struct declaration

struct product{
    int p_code;
    char name[20];
    char amount[10];
    int qty;
    float price;
};
struct cart{
    int p_code;
    char name[20];
    int qty;
    float price;
};
struct invoice{
    char c_name[10];
    struct cart c1[50];
};

                        // global variable

struct product fruit[]={
                        {101,"Mango   "," 1kg ",30,180},
                        {102,"apple   "," 1Kg ",30,320},
                        {103,"Grape   "," 1Kg ",30,400},
                        {104,"Banana  ","12pis",30,150}
                         };
struct product drinks[]={
                         {201,"CocaCola","250ml",24,25 },
                         {202,"Pepsi   ","250ml",24,20 },
                         {203,"DrinkO  ","250ml",24,35 },
                         {204,"FanTa   ","250ml",24,20 }
                           };
struct product chips[]={
                         {301,"Mr.Twist","250gm",24,15 },
                         {302,"Alooz   ","250gm",24,15 },
                         {303,"Ruchi   ","250gm",24,10 },
                         {304,"Sun     ","250gm",24,20 }
                           };
int len1=4,len2=4,len3=4;
int cou=0,count=0,m_buy=0;
struct invoice in1[10];
float sale=0.0;
                        //title
void title();
                       // customer
void customer();
void print(struct product pri1[10],int len);
void buy(struct product b[10]);
void invo();
void in_pri(struct product pri[10],int i,int a);
void restock(struct product pri1[10],int len);
                      // manager
void manager();
void inventory();
void m_print(struct product pri1[10],int len);
void add(struct product pri1[10],int len,int a);
void sales(float sale);
                     //  color
void bg_red();
void bg_blue();
void fg_blue();
void bg_white();
void bg_reset();
                    //   main body
int main()
{
    int n,user,pass;
    char menu='y';
    while(menu=='y'){
    system("cls");
    title();
    printf("\t\t Enter as:                                     \n\n");
    printf("\t\t 1.customer                                      \n");
    printf("\t\t 2.manager                                     \n\n");
    printf("\t\t Input the number co-responding to your choice:");
    scanf("%d",&user);
    if(user==1){
        system("cls");
        customer();
    }
    // manager log in start
    else if(user==2){
        printf("\n\n");
        printf("\t\tEnter password: ");
        scanf("%d",&pass);
    }else{
        printf("Invalid user.Give proper input.\n");
    }
    if(pass==123){
        system("cls");
        manager();
    }
    printf("Go back to cover page?[y/n]: ");
    scanf("%s",&menu);
    }
    // manager log in end
return 0;
}
                       //title
void title(){
    bg_blue();
    printf("\t                       Urban Cart                             \n");
    printf("\t--------------------------------------------------------------\n");
    bg_reset();
}
              //    customer section

void customer()
{
        int section;
        char menu='y',in;
        while(menu=='y'){
        system("cls");
        title();
        bg_red();
        printf("\t                      welcome to the shop                     \n");
        printf("\t--------------------------------------------------------------\n");
        bg_reset();
        printf("\t\t\tProduct sections:\n");
        printf("\n\t\t\t1.fruit");
        printf("\n\t\t\t2.Drinks");
        printf("\n\t\t\t3.Chips\n");
        printf("\n\t\tInput the number co-responding to your choice: ");
        scanf("%d",&section);
        system("cls");
        switch(section){
        case 1:
        print(fruit,len1);
        buy(fruit);
        break;
        case 2:
        print(drinks,len2);
        buy(drinks);
        break;
        case 3:
        print(chips,len3);
        buy(chips);
        break;
    }
    printf("Continue shopping[y/n]:");
    scanf("%s",&menu);
    }
    printf("Get invoice[y/n]:");
    scanf("%s",&in);
    if(in=='y'){
    invo();
    }
}

                          // customer print

void print(struct product pri1[10],int len)
{
      int i,j;
      title();
      bg_red();
      printf("\t             These are our fruit collection                   \n");
      printf("\t------------------------------------------------------------- \n");
      printf("\tSL.No    Name             Amount             Price(Taka)      \n");
      printf("\t------------------------------------------------------------- \n");
      for(i=0;i<len;i++){
        fg_blue();
        printf("\t %d       %s          %s              %.2f       \n",pri1[i].p_code,pri1[i].name,pri1[i].amount,pri1[i].price);
      };
      bg_reset();
}

               //       buy

void buy(struct product b[10]){
    int n,a,i,d,j;
    float sum=0,sum1;
    int c[10];
    char e[10];
    printf("How many would you like to buy: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter Product code: ");
        scanf("%d",&a);
        printf("Enter quantity: ");
        scanf("%d",&d);
        for(j=0;j<10;j++){
            if(a==b[j].p_code){
            sum+=(b[j].price*d);
            b[j].qty-=d;
            }
        }
        in1[count].c1[cou].qty=d;
        in1[count].c1[cou].price=sum;
        sum=0;
        in1[count].c1[cou].p_code=a;
        cou++;
        m_buy++;
    }
}
void invo(){
    int i,a;
    float total=0.0;
    printf("Enter customer name: ");
    scanf("%s",&in1[count].c_name);
    system("cls");
    title();
    bg_white();
    printf("\t\t ==============invoice================ \n");
    printf("\t\t Name:%s                            \n",in1[count].c_name);
    printf("\t\t ===================================== \n");
    printf("\t\t P-code  P-name       Qty     Price    \n");
    printf("\t\t ===================================== \n");
    for(i=0;i<20;i++){
     a=((in1[count].c1[i].p_code)%10)-1;
    switch(in1[count].c1[i].p_code/100){
    case 1:
        in_pri(fruit,i,a);
    break;
    case 2:
        in_pri(drinks,i,a);
    break;
    case 3:
        in_pri(chips,i,a);
    break;
    }
    total+=in1[count].c1[i].price;
    }
    printf("\t\t ===================================== \n");
    printf("\t\t Total                          %.2f \n",total);
    bg_reset();
    count++;
}
void in_pri(struct product pri[10],int i,int a){
    printf("\t\t %d     %s      %d        %.2f \n",in1[count].c1[i].p_code,pri[a].name,in1[count].c1[i].qty,in1[count].c1[i].price);
}

                                // manager section

void manager()
{
    int n,i;
    char cont='y';
    while(cont=='y'){
    system("cls");
    title();
    printf("\n");
    printf("\t\t   Welcome home chief\n");
    printf("\t\t ========================\n");
    printf("\t\t     1.Inventory\n");
    printf("\t\t     2.Sales\n");
    printf("\t\t     select your option: ");
    scanf("%d",&n);
    switch(n){
        case 1:
            system("cls");
            inventory();
        break;
        case 2:
            system("cls");
            sales(sale);
        break;
    }
    printf("\n\n\tWould you like to go back?[y/n]: ");
    scanf("%s",&cont);
    }
}

                         // inventory

void inventory()
{
    int section;
        title();
        bg_red();
        printf("\t                        Inventory                             \n");
        printf("\t--------------------------------------------------------------\n");
        bg_reset();
        printf("\t\tProduct sections:\n");
        printf("\t\t1.fruit\n");
        printf("\t\t2.Drinks\n");
        printf("\t\t3.Chips\n");
        printf("\tInput the number co-responding to your choice: ");
        scanf("%d",&section);
        system("cls");
        switch(section){
        case 1:
        m_print(fruit,len1);
        restock(fruit,len1);
        break;
        case 2:
        m_print(drinks,len2);
        restock(drinks,len2);
        break;
        case 3:
        m_print(chips,len3);
        restock(chips,len3);
        break;
    }
}

                    //  manager print

void m_print(struct product pri1[10],int len)
{
   int i,j;
      system("cls");
      bg_red();
      printf("\t             These are our fruit collection                    \n");
      printf("\t---------------------------------------------------------------\n");
      printf("\tSL.No      Name          Unit          Amount     Price(Taka)  \n");
      printf("\t-------------------------------------------------------------- \n");
      for(i=0;i<len;i++){
        bg_blue();
        printf("\t %d       %s    %s            %d        %.2f       \n",pri1[i].p_code,pri1[i].name,pri1[i].amount,pri1[i].qty,pri1[i].price);
      };
      bg_reset();
}

                    //            change items in inventory

void restock(struct product pri1[10],int len){
    int n,a,b,c,i,j,e;
    float d;
    printf("\t1.Restock item\n");
    printf("\t2.change price\n");
    printf("\t3.Add product\n");
    printf("\tChoose opt: ");
    scanf("%d",&n);
    printf("\tNumber of product: ");
    scanf("%d",&a);
    for(i=1;i<=a;i++){
        if(n==1){
        printf("\tEnter product code: ");
        scanf("%d",&b);
        for(j=0;j<4;j++){
            if(b==pri1[j].p_code){
                printf("\tAmount of resupply: ");
                scanf("%d",&c);
                pri1[j].qty+=c;
            }
        }
        }else if(n==2){
            printf("\tEnter product code: ");
            scanf("%d",&b);
            for(j=0;j<4;j++){
            if(b==pri1[j].p_code){
                printf("\tNew price: ");
                scanf("%f",&d);
                pri1[j].price=0;
                pri1[j].price+=d;
        }
    }
 }
 }  if(n==3){
     add(pri1,len,a);
 }
}

           //        add  products

void add(struct product pri1[10],int len,int a){
    int i;
    for(i=len;i<len+a;i++){
        printf("\tEnter product code: ");
        scanf("%d",&pri1[i].p_code);
        printf("\tProduct name: ");
        scanf("%s",&pri1[i].name);
        printf("\tUnit: ");
        scanf("%s",&pri1[i].amount);
        printf("\tAmount: ");
        scanf("%d",&pri1[i].qty);
        printf("\tPrice: ");
        scanf("%f",&pri1[i].price);
        switch(pri1[i].p_code/100){
        case 1: len1++; break;
        case 2: len2++; break;
        case 3: len3++; break;
    }
    }
}

               //   sales

void sales(float sale){
    int i,j,a;
    float total=0.0;
    title();
    for(i=0;i<count;i++){
    bg_white();
    printf("\t\t ==============invoice================ \n");
    printf("\t\t Name:%s                            \n",in1[i].c_name);
    printf("\t\t ===================================== \n");
    printf("\t\t P-code  P-name       Qty     Price    \n");
    printf("\t\t ===================================== \n");
        for(j=0;j<=m_buy;j++){
           a=((in1[i].c1[j].p_code)%10)-1;
    switch(in1[i].c1[j].p_code/100){
    case 1:
        in_pri1(fruit,i,j,a);
    break;
    case 2:
        in_pri1(drinks,i,j,a);
    break;
    case 3:
        in_pri1(chips,i,j,a);
    break;
    }
    total+=in1[i].c1[j].price;
    }
    sale+=total;
    printf("\t\t ===================================== \n");
    printf("\t\t Total                          %.2f \n",total);
    bg_reset();
    total=0.0;
    printf("\n\n");
        }
    printf("\t\t ************************************** \n");
    printf("\t\t   Total sales is = %.2f           \n",sale);
    printf("\t\t ************************************** \n");
    }
void in_pri1(struct product pri[10],int i,int j,int a){
    printf("\t\t %d     %s      %d        %.2f \n",in1[i].c1[j].p_code,pri[a].name,in1[i].c1[j].qty,in1[i].c1[j].price);
}
                            // color

void bg_red(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),79);
}
void bg_blue(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),144);
}
void fg_blue(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),159);
}
void bg_white(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
}
void bg_reset(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED |FOREGROUND_GREEN);
}
