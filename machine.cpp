
#include "machine.h"
#include "rotor.h"
#include <string>
#include <algorithm>

    Machine::Machine() { }

       // std::array<char,27> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
          std::array<char,27> alphabet = {'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};

       Rotor rotor1;
       Rotor rotor2;
       Rotor rotor3;
       Reflector reflector;


// sets the rotors buffer numbers, the alphabet encryption ring
 void Machine::setRot(int R,int M,int L){
        if (R != M && R!= L && M != L){
       rotor1= Rotor(R,1);
       rotor1.set_or_mov_rot(1);
       rotor2= Rotor(M,2);
       rotor3= Rotor(L,3);
         }
       }
//turns rotors like an odometer
 void Machine::turn(){
       rotor1.position++;
      if (rotor1.position == 26){
        rotor1.position = 0;
        rotor2.position+=1;
       if (rotor2.position == 26){
         rotor2.position = 0;
         rotor3.position+=1;
        if(rotor3.position == 26){
          rotor3.position = 0;
       }
      }
     }
   }

// begin encryption
char Machine::runmach(char in){
    int index;
    in=toupper(in);
    char *p;
    p = std::find(alphabet.begin(),alphabet.end(),in);

    for (int i=0;i<27;i++){
       if(in==alphabet.at(i)){
          std::cout<< *p << std::endl;
         index = i;
         break;
       }
    }
     int currentnum=index;

      currentnum = rotor1.current(currentnum,0);
      rotor2.set_or_mov_rot(2);
      currentnum = rotor2.current(currentnum,0);
      rotor3.set_or_mov_rot(3);
      currentnum = rotor3.current(currentnum,0);
      currentnum = reflector.cref(currentnum,2);
      currentnum = rotor3.current(currentnum,3);
      rotor2.set_or_mov_rot(2);
      currentnum = rotor2.current(currentnum,3);
      rotor1.set_or_mov_rot(3);
      currentnum = rotor1.current(currentnum,3);

     if(currentnum == index){
        std::cout<<index << rotor1.position;
      }
        turn();
      return alphabet.at(currentnum);
    }
       //process word
    std::vector<char> Machine::word(std::string input){
           char word[111];
           int i;
          //if it is a pure string get rid of null terminator
          for(i=0; input[i] != '\0'; i++){
           word[i]=input[i];
           }
          int size=i;
          char in;
         std::vector<char> output;
        for(i=0; i<size;i++){
//           std::cout<<word[i]<<" "<<input;
           in=runmach(word[i]);
//             std::cout<<word[i]<<" "<<in;
           output.push_back(in);
        }
         return output;
       }

       // sets the position of the rotors
    void Machine::setRotpos(int R,int M,int L){
       rotor1.position=R;
       rotor2.position=M;
       rotor3.position=L;
    }
