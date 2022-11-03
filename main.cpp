#include <iostream>


#include "funcs.h"

int main()
{
  std::cout << "\nencryptCaesar() function:\nplaintext: This is a really difficult assignment in my opinion. \nShift: 10\n";
  std::cout << encryptCaesar("This is a really difficult assignment in my opinion.", 10);
  std::cout << "\n---\n";
  
  std::cout << "\ndecryptCaesar() function:\nciphertext: Drsc sc k bokvvi nsppsmevd kccsqxwoxd sx wi yzsxsyx. \nShift:\n";
  std::cout << decryptCaesar("Drsc sc k bokvvi nsppsmevd kccsqxwoxd sx wi yzsxsyx.", 10);
  std::cout << "\n------------------\n";

  std::cout << "\nencryptCaesar() function:\nplaintext: I really enjoy simulation-based sports games where you become a general manager. \nShift: 23\n";
  std::cout << encryptCaesar("I really enjoy simulation-based sports games where you become a general manager.", 23);
  std::cout << "\n---\n";
  
  std::cout << "\ndecryptCaesar() function:\nciphertext: F obxiiv bkglv pfjrixqflk-yxpba pmloqp dxjbp tebob vlr ybzljb x dbkboxi jxkxdbo.\n";
  std::cout << decryptCaesar("F obxiiv bkglv pfjrixqflk-yxpba pmloqp dxjbp tebob vlr ybzljb x dbkboxi jxkxdbo.", 23);
  std::cout << "\n------------------\n";
  return 0;
}
