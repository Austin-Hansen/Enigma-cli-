#include "view.h"
#include <sstream>
#include <iostream>
#include <string>

View::View() { }

void View::main_menu(){

std::string raw_strp=R"(         
                        ****************
                        *    Enigma    *
                        ****************


    )";

std::cout<<raw_strp<<std::endl;

std::string raw_str= R"( 

(1) Encryption          (3) Help         (7)About
(2) Set Rotors to       (4) History      (8)Set Rotors to Default

)";

std::cout<<raw_str<<std::endl;

}

void View::help(){
std::string raw_strp=R"( 
  Encryption: Encrypts your message
  
  Set Rotors to: Changes your rotor to a different one, ex: I to III

  Help: prints this screen

  History: prints a small blurb about the early history of the first enigma machines

  About: Talks about your rotor types

  Set Rotors to default: sets rotors to I=R, II=M, III=L
)";
std::cout<<raw_strp<<std::endl;

}

void View::history(){

std::string raw_str= R"( 
Enigma is a type of substitution cypher used by  Germany from the 1920s to
 late world war 2, It is not a computer but an electro mechanical rotor
cipher machine. It came in at least 12 official forms, the first one being
 made in 1918. The first progress in cracking the code was achieved by
Marian Rejewski,a Polish mathematician and cryptanalyst, using the theory
of permutations. The Poles managed to solve the plugboard portion of the
code after some good guess work, and getting a key from a French spy.
Using bombes,a type of proto computer, they were able to figure out part
of the enigma used by the diplomats of Germany, however the war caught up
to them, and they and their techniques were extradited to the United Kingdom,
where they shared their techniques, and where turing would build the first
real computer.
    )";
       std::cout<<raw_str<<std::endl;
}
