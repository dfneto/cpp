#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"


int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  // delete(fwoosh); //se eu adicionar o spell direto ao inves de um clone (em Warlock::learnSpell),
  // deletar o fwoosh e depois lancar richard.launchSpell("Fwoosh", bob); da segfault
  // porque assim eu estaria adicionando o ponteiro diretamente ao inves de adicionar uma copia sua

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);

  return (0);
}