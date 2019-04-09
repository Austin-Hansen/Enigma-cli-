
Crypt::crypt() { }

       const std::vector<char> alphabet = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        //Need to think of rotors as 3 strings of letters
       const std::vector<std::array<char>> rotors =
             {
               //Theses are the rotors on Enigma I
               //rotor I
              {{"EKMFLGDQVZNTOWYHXUSPAIBRCJ"},
               //rotor II
               {"AJDKSIRUXBLHWTMCQGZNPYFVOE"},
               //rotor III
               {"BDFHJLCPRTXVZNYEIWGAKMUSQO"}}
             };
        const std::vector<char> reflector = {"YRUHQSLDPXNGOKMIEBFZCWVJAT"};
        //65,66,67,These are part of the formula in the .h file, need lower number...
        const std::vector<char> start_perm = {"ABC"};

     //need modular function to turn wheels back, not sure how to fully implement
      int modulus_alph(int m){
        int mod;
     //26 letters
           mod= m%26;
         return (mod);
       }
       //
     int index(char letter){
        //all start at A, or 65
        char i;
          i=l-'A';

       }
       int index_of_rot(std::vector<char>array, int l){
           return(array.at(l))
       }

   std::string encrypt(std::vector<char> msg){
      //Permutation formula E=PRMLUL^-1M^-1R^-1P^-1
     //P is the plugboard, U is the reflector so E=RMLUL^-1M^-1R^-1
      int L=index(start_perm.at(0));
      int M=index(start_perm.at(1));
      int R=index(start_perm.at(2));
      //need to do turning
      std::string out;
      for(int i=0;i<msg.size();i++){
         //Set R for rotation (go up 1 rotation)
            R=modulus_alph(R+1);
         // need to add if for M and R
         //probably above the loop,something like if(R>msg.size()), loop for M ++
           char r = rotors.at(2).at(modulus_alph(R+index(msg.at(i))));
           char m = rotors.at(1).at(modulus_alph(M+index(a)-R));
           char l = rotors.at(0).at(modulus_alph(L+index(b)-M));
         //U, reflector
         char reflect = reflector.at(modulus_alph(index(l)-L))
         // pass through rotors again to complete circuit(L^-1M^-1R^-1P^-1), confusing
         // I need to verify these formulas, msg->r->m->l->reflector->l->m->r-> letter, full msg
        // int Linv = modulus_alph(index_of_rot(rotors.at(0), alphabet.at(modulus_alph(index(ref)+L))))
        // int Minv = modulus_alph(index_of_rot(rotors.at(1),alphabet.at(modulus_alph(d+M))-M))
        // char final_let = modulus_alph(index_of_rot(rotors.at(1),alphabet.at(modulus_alph(e+M))-R))

         out = out +final_let

     }

   }
