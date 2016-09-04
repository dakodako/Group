//
//  main.c
//  readingData
//
//  Created by Didi Chi on 3/09/2016.
//  Copyright © 2016 dako. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node {
    double value;
    struct node *next;
};

typedef struct node node_t;
typedef  node_t *list;

list list_insert(list L, double value){
    //printf("insert happening\n");
    
    node_t *newListNode = (node_t*)malloc(sizeof(newListNode));
    newListNode -> value = value;
    if(L == NULL){
        //  printf("starts to build a list\n");
        L = newListNode;
        L ->next = NULL;
    } else {
        //printf("add a node\n");
        newListNode->next = L;
        L = newListNode;
    }
    
    return L;
}

void print(list L){
    while(L != NULL){
        printf("%.2f,",L->value);
        L = L -> next;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    printf("Hello, World!\n");
    list voltageAD590;
    list current;
    list temperature;
    list VRt;
    list Rt;
    FILE *myFile = fopen("../../0.2Aheating.txt","r");
    int k = 0;
    char *num = (char*)malloc(100*sizeof(char));
    size_t characters;
    size_t bufsize = 100;
    characters = getline(&num, &bufsize, myFile);
    while(characters != -1){
        if(num[strlen(num)-1] == '\n'){
            num[strlen(num)-1] = '\0';
        }
        printf("k = %d\n",k);
        //printf("%s\n",num);
        if(k == 1){
            double value;
            sscanf(num, "%lf",&value);
            voltageAD590 = list_insert(voltageAD590, value);
        } else if(k == 3) {
            double value;
            sscanf(num,"%lf",&value);
            temperature = list_insert(temperature, value);
            
        } else if(k == 5){
            double value;
            sscanf(num, "%lf",&value);
            VRt = list_insert(VRt, value);
        } else if (k == 7){
            double value;
            sscanf(num,"%lf",&value);
            Rt = list_insert(Rt, value);
        } else {
            k = k + 1;
            if(k == 8){
                k = 0;
            }
            characters = getline(&num, &bufsize, myFile);
         continue;
        }
        
        
        
        
        
       /* if(k == 1){
            //double value = atoi(num);
            double value;
            sscanf(num, "%lf",&value);
            printf("value = %f\n",value);
            voltageAD590 = list_insert(voltageAD590, value);
        } else if(k == 3){
            double value = atoi(num);
            sscanf(num, "%lf",&value);
            current = list_insert(current, value);
        } else if (k == 5){
            double value = atoi(num);
            sscanf(num, "%lf",&value);
            temperature = list_insert(temperature, value);
        } else if(k == 7) {
            double value = atoi(num);
            sscanf(num, "%lf",&value);
            VRt = list_insert(VRt, value);
        } else if(k == 9){
            double value = atoi(num);
            sscanf(num, "%lf",&value);
            Rt= list_insert(Rt, value);
            

        } else {
            k = k + 1;
            if(k == 10){
                k = 0;
            }
            characters = getline(&num, &bufsize, myFile);
            continue;
        }*/
        //int number = atoi(num);
        
        //printf("number = %d\n",number);
        k = k + 1;
        if(k == 8){
            k = 0;
        }
        characters = getline(&num, &bufsize, myFile);
    }
    //printf("voltageAD590:");
    //print(voltageAD590);
    printf("\n");
    printf("voltageAD590: ");
    print(voltageAD590);
    printf("\n");
    printf("VRt: ");
    print(VRt);
    //printf("\n");
    
    
    
    return 0;
}
