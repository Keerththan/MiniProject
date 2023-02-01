#include<stdio.h>
int main() {
   int option;
   printf("Please select Your Option \n");
   scanf("%d",&option);
  switch(option)
    {
        case 1:new_accounts();
        break;
        case 2:update();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:deleted();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;

    }
  
   
   return 0;
}