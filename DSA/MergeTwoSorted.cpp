#include<iostream> 
#include"Node.cpp"
using namespace std;
Node *mergeTwoSortedLinkedLists(Node *h1, Node *h2)
{
    if(h1!=NULL&&h2==NULL) return h1;
    if(h1==NULL&&h2!=NULL) return h2;
    if(h1!=NULL&&h2!=NULL){
        Node* fH= NULL;
        Node* fT =NULL;
        if(h1->data>=h2->data){
            fH=new Node(h2->data);
            h2=h2->next;
        }else{
            fH=new Node(h1->data);
            h1=h1->next;
        }
        fT=fH;
        while(h2!=NULL&&h1!=NULL){
            if(h1->data>=h2->data){
                
              fT->next=h2;
                fT = fT->next;
                h2=h2->next;
            }else if(h1->data<h2->data){
                fT->next=h1;
                fT=fT->next;
                h1=h1->next;
            }     
        }
        while (h2!=NULL)
        {
            
            fT->next=h2;
            fT = fT->next;
            h2=h2->next;
        }

        while (h1!=NULL)
        {
            fT->next=h1;
            fT = fT->next;
            h1=h1->next;
        }
        return fH;
   }
   return NULL;
}
int main(){

    

    return 0;
}