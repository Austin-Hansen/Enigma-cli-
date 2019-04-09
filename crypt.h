#include <vector>

//Permutation formula E=PRMLUL^-1M^-1R^-1P^-1
//P is the plugboard, U is the reflector so E=RML L^-1M^-1R^-1
class Crypt {
      public:
            Crypt();
             const std::vector<char> alphabet;
             //Need to think of rotors as 3 strings of letters
             const std::vector<std::vector<char>> rotors;
             const std::vector<char>reflector;
             //trying to use a simple form to start with
             const std::vector<char> start_perm;

           //will private arrays later
            std::string encrypt(std::vector<char> msg);
            int modulus_alph(int m);
            int index(char letter);
            int index_of_rot(char array,int l);
            void turn_which_rotor();
};
