#include <iostream>


#include "funcs.h"

int main()
{
  std::cout << "\nencryptCaesar() function:\nplaintext: This is a really difficult assignment in my opinion. \nShift: 10\n";
  std::cout << encryptCaesar("This is a really difficult assignment in my opinion.", 10);
  std::cout << "\n---\n";
  
  std::cout << "\nsolve() function:\nciphertext: Drsc sc k bokvvi nsppsmevd kccsqxwoxd sx wi yzsxsyx.\n";
  std::cout << solve("Drsc sc k bokvvi nsppsmevd kccsqxwoxd sx wi yzsxsyx.");
  std::cout << "\n------------------\n";

  std::cout << "\nencryptCaesar() function:\nplaintext: I really enjoy simulation-based sports games where you become a general manager. \nShift: 23\n";
  std::cout << encryptCaesar("I really enjoy simulation-based sports games where you become a general manager.", 23);
  std::cout << "\n---\n";
  
  std::cout << "\nsolve() function:\nciphertext: F obxiiv bkglv pfjrixqflk-yxpba pmloqp dxjbp tebob vlr ybzljb x dbkboxi jxkxdbo.\n";
  std::cout << solve("F obxiiv bkglv pfjrixqflk-yxpba pmloqp dxjbp tebob vlr ybzljb x dbkboxi jxkxdbo.");
  std::cout << "\n------------------\n";
  return 0;
}
