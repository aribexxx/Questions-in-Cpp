#include <iostream>



int findLen(int a[]){
    int i=0;
    while(a[i]!='\0'){
        i++;
    }
    return i;
}
void replaceSpace (char str[],int length) {
    int stringlen=0;
    int numOfSpace=0;
    int i=0;
    while(str[i]!='\0'){
        if(str[i]==' '){
            numOfSpace++;
        }
        stringlen++;
        i++;
    }

    int newlen=stringlen+2*numOfSpace;
    if(newlen>length){
        return;
    }
    int indexOfOrigin=stringlen;
    int indexOfNew=newlen;

    while(indexOfOrigin<indexOfNew&&indexOfOrigin>=0){
       if(str[indexOfOrigin]==' '){
           str[indexOfNew--]='0';
           str[indexOfNew--]='2';
           str[indexOfNew--]='%';
          // indexOfNew--;
       }
       else{
           str[indexOfNew--]=str[indexOfOrigin];

       }
       indexOfOrigin--;
    }

};
 void printArray(int arr[]){
     for(int i=0;i<findLen(arr);++i) {
         printf("%i,",arr[i]);
     }

     printf("\n");
 }

void insertBtoA_sorted(int a[],int b[]){
    int a_len= findLen(a);
    int b_len=findLen(b);
    int olda=a_len-1;
    int bptr=b_len-1;
    int newa=a_len+b_len;
    a[newa]='\0';
    newa--;
    while(olda<newa&& bptr>=0){
        if(b[bptr]>a[olda]){
            a[newa]=b[bptr];
            bptr--;
            newa--;
        }
        else{
            a[newa]=a[olda];
            olda--;
            newa--;
        }

    }


}



int main() {
    //Q5 TESTING
    char str[30]="we are happy";
    replaceSpace(str,30);
    printf("%s",str);

    //  Q5_2 testing
    int a[100]={1,2,3,5,7,9,23};
    int b[20]={2,4,6,8,10,20};
    printf("before");
    printArray(a);
    insertBtoA_sorted(a,b);
    printf("after");
    printArray(a);

    return 0;
}