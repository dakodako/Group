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
#include <math.h>
struct node {
    double value;
    struct node *next;
};

typedef struct node node_t;
typedef  node_t *list;
long double calculateTemperature(double R){
    long double T;
    T = 25.5 * exp(-6.807*pow(10, -5)*R) + 76.82 * exp(-0.0003327* R); // not sure about the +1.4
    return T;
}
double calculateVoltageAcrossRt(double value){
    return ((value*1.0)*255)/1024;
}
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
void fprint_list(list L, FILE *myFile){
    while(L != NULL){
        fprintf(myFile, "%.2f,",L->value);
        L = L -> next;
    }
}
void fprint_list_for_temperature(list L,FILE *myFile){
    while(L != NULL){
        long double T = calculateTemperature( L -> value);
        fprintf(myFile, "%.2Lf,",T);
        L = L ->next;
    }
}
void fprint_list_for_voltageRt(list L, FILE *myFile){
    while(L != NULL){
        double V = calculateVoltageAcrossRt(L -> value);
        fprintf(myFile, "%.2f,",V);
        L = L -> next;
    }
}
void fprint_list_for_Rt(list L, FILE *myFile){
    while(L != NULL){
        double V = calculateVoltageAcrossRt(L -> value);
        double R = (V*1.0)/((5 - V)/60000);
        fprintf(myFile, "%.2f,",R);
        L  = L->next;
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
    FILE *myFile = fopen("../../0.6Aheating.txt","r");
    FILE *outputFileT = fopen("outputTemperature.txt","a");
   // FILE *outputFileTRt = fopen("outputTemperatureRt.txt","a");
    FILE *outputFileVRt = fopen("outputVRt.txt","a");
    FILE *outputFileRt = fopen("outputRt.txt","a");
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
            Rt = list_insert(Rt, value/10);
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
            Rt= list_insert(Rt, value/10);
            

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
   // printf("\n");
    //printf("voltageAD590: ");
    //print(voltageAD590);
    
    //printf("\n");
    //printf("Rt: ");
    //print(Rt);
   // printf("T\n");
    print(temperature);
    //print(Rt);
    fprint_list(temperature, outputFileT);
    fprint_list_for_voltageRt(VRt, outputFileVRt);
    fprint_list_for_Rt(VRt, outputFileRt);
   // fprint_list(Rt, outputFileTRt);
    //fprint_list(temperature, outputFileTRt);
    //fprint_list_for_temperature(Rt, outputFileTRt);
    
    //printf("\n");
    
    
    
    return 0;
}
