#ifndef __ENIGMA_H
#define __ENIGMA_H
//#include "type.h"
#include <string>
#include "machine.h"
#include "view.h"

class Enigma{
 public:
   Enigma();
//  friend std::ostream& operator<<(std::ostream& ost, const Enigma& po);
  void cli();
  void execute_cmd(int cmd);
  void test_setup_run();
  int get_int(std::string name,std::string title);
  void process();
  void stream_vector(std::vector<char> out);


//private:

//initialize using type
//spit the results of type out to the screen
//build menu (cli to full baby menu to full)
// have the overloaded streaming operator for the vector of chars
// have save file, using cds format
// have load file ready.
// have execute_cmd

};
#endif
