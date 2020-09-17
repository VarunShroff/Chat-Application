/******************************************************************************
Author : Varun Shroff
Project Name : Chat Application
Project Description : A Simple 2 Person Chat Program That Simulates A Chat Room Between
Both People Are Stores Their Converstaion In A Text File.
Project Date : 04/21/2020

*******************************************************************************/

// Including Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Users Chatting
char Person1[50];
char Person2[50];

// Function Initilization
void *store_message_function( void *ptr );
void Registration();
void Person1Msgs();
void Person2Msgs();

// File Declaration
FILE *fptr;

void Registration() { // Startup Function 
    
    printf("********** Welcome To The Chat Room **********\n");
    printf("Enter Your Name Person1 : ");
    scanf("%s", Person1);
    printf("%s Entered The Chat Room....\n",Person1); 
    printf("Enter Your Name Person2 : ");
    scanf("%s", Person2);
    printf("%s Entered The Chat Room....\n",Person2);
    printf("********** Chat Registration Completed **********\n");
    printf(  "   Enter quit anytime to close the chatroom    \n  ");
    
}

int main() {
    
    Registration(); // Calling Registration Function
    
   

    // opening file in writing mode
    fptr = fopen("MsgLogs.txt", "w");
    fprintf(fptr," Message Logs \n");

    // exiting program 
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    
    while(1) { // While Loop That Continues The Chat Untill Quit Is Entered
    
    Person1Msgs(); // Calling Messaging Function, Allows Person1 To MSG OR QUIT
    Person2Msgs(); // Calling Messaging Function, Allows Person2 To MSG OR QUIT
    
    }
    fclose(fptr); // CLoses File And Saves Information
    return 0;
}


void Person1Msgs() {  // Messaging Function
    
     char Messages[1000]; // Variable That Temporarily Stores Messages
    printf("[ %s ] Enter Your Message : ",Person1);
    getchar();
    scanf("%[^\n]",Messages);
    fprintf(fptr, " %s : %s\n",Person1 ,Messages); // Writes The Messages Into A File
    if (strcmp(Messages,"quit") == 0) { // Closes The CHat If Quit Is Entered
        fprintf(fptr," Person1 Closed The Chat \n");
        exit(0);
        
    }
    
    
}

void Person2Msgs() {  // Messaging Function
    
     char Messages[1000]; // Variable That Temporarily Stores Messages
    printf("[ %s ] Enter Your Message : ",Person2); 
    getchar();
    scanf("%[^\n]",Messages);
    fprintf(fptr, " %s : %s\n",Person2 ,Messages); // Writes The Messages Into A File
    if (strcmp(Messages,"quit") == 0) {  // Closes The CHat If Quit Is Entered
        fprintf(fptr," Person2 Closed The Chat \n");
        exit(0);
        
    }
    
    
}


void *send_messages_function( void *ptr ) { // This Function Is Not In Use For This Program Yet, This Program Sends The Text File Through The Serial Port Communcation Protocol

    
     
     
}