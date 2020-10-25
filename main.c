#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[]){

    string s = argv[1];  //getting input from the argument
    int n = strlen(s); //getting the length of the string
    char c; //we are gonna use it to loop through the string
    bool isValid = false; //use it to confirm that the user has inserted exactly 26 characters
    int valid; //use it to return the value from isalpha
    char extra;


    string ns; //use it to get the input string for plain text
    //int newnum; //getting the length of the string ns
    char c2; //use it to loop through ns


    //if the number of arguments is not 2
    if(argc != 2){
        printf("Usage: ./substitution key\n");
        return 1;
    }

// if there are two arguments check for the number of characters, make sure they're 26 alphabetical characters otherwise print an error message
    else if(argc == 2){

     if(n == 26){

         for(int i = 0; i < n; i++){

             c = s[i];
             valid = isalpha(c);

             if(valid != 0 ){

                 isValid = true;

             }

             else {
                 printf("Usage: ./substitution key\n");
                 isValid = false;
                 return 1;
             }

             //--
               for(int x = 0; x < i; x++){

                if( i == 0){

                }

                else {
                  extra = s[x];
                  if(extra == c){
                      printf("You cannot enter the same letter \n");
                      isValid = false;
                      return 1;
                  }
                }
             }

            //--

         }

     }

     else {
         printf("Usage: ./substitution key\n");
         isValid = false;
         return 1;
     }


    }

    else {

        printf("Usage: ./substitution key\n");

        return 1;
    }

    //---------------------------------------------------------------------------------------------------------------------------------------


   //get the input for plaintext from the user if the conditions are met

    if(isValid == true && argc == 2){

        ns = get_string("plaintext : \n");
        int newnum = strlen(ns);
        int num = 0;
        int num2 = 0;
        int diff = 0;

// Looping through every element of the text that needs to be encrypted

        for(int i = 0; i < newnum; i++){

           c2 = ns[i];


           if(isupper(c2)){

// Looping through the possible uppercase alphabetic letters that the character could be
            for(int x = 65; x <= 90; x++){

               //printf("%i \n", x);               -- for testing purposes


                 if(ns[i] == x){

                     diff = x - 65;
                     ns[i] = s[diff];
                     ns[i] = toupper(ns[i]);
                     x = 65;
                     break;
                 }

                 else {


                 }




            }

            //printf("%c", ns[i] );               -- for testing purposes


           }
// Looping through the possible lowercase alphabetic letters that the character could be
           else if (islower(c2)){

               for(int y = 97; y <= 122; y++){


                   if(ns[i] == y){

                       diff = y - 97;
                       ns[i] = s[diff];
                       ns[i] = tolower(ns[i]);
                       y = 97;
                       break;
                   }

                   else {

                   }
               }
           }

           else {
               ns[i] = ns[i];
           }

        }

//Finally we print the encrypted text

        printf("ciphertext: %s\n", ns);

    }

    else if(isValid == false){
        printf("Usage : ./substitution key \n");
        return 1;
    }



}
