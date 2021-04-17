#include<stdio.h>
int main() {
   int m, n;
   scanf("%d%d", &n, &m);

   int prev_exit=0;   //  End Path of 0 for Prev Rows 
   int curr_exit;     //  End Path of 0 for Current Rows
   int end_Flag=0; //Flag that tells if we have reached end of path in the current row
   int diag_flag=0; //Flag to remember if diagonal movement is req in new row
   int score=0;
   int c;
   for(int i = 0; i < n; ++i) {
       curr_exit=-1;
       diag_flag=0;
       end_Flag=0;
       for(int j = 0; j < m; ++j) {
           scanf("%d", &c);
           if(j==prev_exit) {
               if(c==1){
                   if(j==m-1){
                       printf("WRONG MAZE\n"); //Last column case
                       return 0;
                   }
                   else {
                       diag_flag=1; //Tells diagonal req in this row
                   }
               }
               else {
                   curr_exit=j;
               }
           }
           else if(j==prev_exit+1 && diag_flag==1){
               if(c==1){
                   printf("WRONG MAZE\n");//Entry in this row not possible
                   return 0;
               }
               else {
                   diag_flag=0; //got diagonal entry
                   curr_exit=j;
               }
           }
           if(curr_exit!=-1 && c!=1 && end_Flag==0) {
               curr_exit = j; //Going along path
           }
           else {
               if(curr_exit!=-1 && c==1 && end_Flag==0) {
                   end_Flag = 1; //Reached end of path
               }
           }
       }
       score=score+curr_exit; // Increase score
       prev_exit = curr_exit;
   }
   printf("%d\n",score);
   return 0;
}