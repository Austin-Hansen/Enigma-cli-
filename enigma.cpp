#include "enigma.h"
//#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <iostream>
//#include <gtkmm.h>
#include "dialogs.h"


Enigma::Enigma() { }

Machine machine;
View view;
//Type type;

int Enigma::get_int(std::string prompt,std::string title){
    while(true) {
          try {
              std::string s;
             // s=Dialogs::input(prompt,title);
              std::getline(std::cin,s);
              if(s == ""||s== "CANCEL") break;

              std::istringstream iss{s};
              int d;
              iss >>d;
              return d;
             }catch(std::runtime_error e) {
                std::cerr << "# Error: Invalid Input: "<< e.what() << std::endl;
          }
       }
     throw std::runtime_error{prompt + " was not entered"};
}


void Enigma::execute_cmd(int cmd){
      switch(cmd){
           case 42: test_setup_run(); break;
           case 4: view.history(); break;
           case 1:  process(); break;
       //    case 2: type.set_rotors_type(1);
           case 3: view.help(); break;
         //  case 8: type.set_rotors_type(0);
     }
   }

void Enigma::cli(){
        while(true){
            try{
               //std::cout<<"MEMES";
               view.main_menu();
               int cmd = get_int("Command","ENIGMA");
               if(cmd == 0) break;
               execute_cmd(cmd);
              }catch (std::runtime_error e) {
                 std::cerr << "Error"<<std::endl;
              }
           }
        }

void Enigma::test_setup_run(){

  machine.setRot(0,1,2);
  machine.setRotpos(1,1,1);
  //std::cout<<machine.runmach('E')<<" ";
  //std::cout<<machine.runmach('N');
  stream_vector(machine.word("ENIGMA"));

}

void Enigma::stream_vector(std::vector<char> out){

for (int i=0; i <out.size(); ++i){

    std::cout << out[i] << ' ';

   }

 }

void Enigma::process(){
  // std::string str;
     std::string str;
   //std::cin>>str;
   std::getline(std::cin,str);
  // for(int i=0; str[i] != '\0'; i++){
    //    word[i]=str[i];
      // }
   //vector<char> temp(str.begin(),str.end());
  //stream_vector(machine.word(str));
 //std::cout<< machine.runmach(str);
 machine.setRot(0,1,2);
  machine.setRotpos(1,1,1);
  stream_vector(machine.word(str));
}
