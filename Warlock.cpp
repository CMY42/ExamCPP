#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) :
_name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
	//_SpellBook.clear(); (EX01)
}

std::string const & Warlock::getName() const
{
	return _name;
}
std::string const & Warlock::getTitle() const
{
	return _title;
}
void Warlock::setTitle(std::string const &title)
{
	_title = title;
}
void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", "<< _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    _SpellBook.learnSpell(spell); // (EX02)

	//_SpellBook[spell->getName()] = spell->clone(); (EX01)

	/*spell->getName() :

    spell est un pointeur vers un objet ASpell ou une classe dérivée.
    getName() est une méthode de ASpell qui renvoie le nom du sort sous forme de std::string.
    Ainsi, spell->getName() retourne le nom du sort.

spells[spell->getName()] :

    spells est une std::map où chaque clé est un std::string (le nom du sort) et chaque valeur est un ASpell* (un pointeur vers un sort).
    L'opérateur [] de std::map est utilisé ici pour accéder ou insérer un élément dans la map.
    Si un élément avec la clé spell->getName() existe déjà dans la map, spells[spell->getName()] renverra un pointeur vers l'objet ASpell correspondant.
    Si cet élément n'existe pas, il est automatiquement créé avec une valeur par défaut (dans ce cas, nullptr puisque c'est un pointeur) avant d'être assigné.

spell->clone() :

    clone() est une méthode virtuelle pure dans ASpell. Cette méthode est censée créer et renvoyer un nouvel objet qui est une copie de l'objet actuel (spell).
    Par exemple, si spell est un pointeur vers un objet Fwoosh, spell->clone() renverra un nouveau pointeur vers un objet Fwoosh qui est une copie de l'objet original.
    Cela permet de copier dynamiquement un sort sans connaître son type exact à l'avance (polymorphisme).

spells[spell->getName()] = spell->clone(); :

    Cette ligne assigne le résultat de spell->clone() à l'entrée correspondante dans la std::map avec la clé spell->getName().
    Si un sort avec le même nom (même clé) existait déjà, il sera remplacé par cette nouvelle copie.
    Si le sort n'existait pas auparavant dans la std::map, une nouvelle entrée est créée avec spell->getName() comme clé et le pointeur renvoyé par spell->clone() comme valeur.*/
}
void Warlock::forgetSpell(std::string SpellName)
{
    _SpellBook.forgetSpell(SpellName); // (EX02)

	//if (_SpellBook.find(SpellName) != _SpellBook.end()) (EX01)
		//_SpellBook.erase(_SpellBook.find(SpellName));

    /*Déroulement de la fonction :

    Recherche du sort :
        _SpellBook est une std::map qui stocke les sorts connus par le Warlock, avec le nom du sort comme clé.
        La méthode find(SpellName) cherche dans la map _SpellBook une entrée dont la clé est SpellName.
        Si le sort est trouvé, find() retourne un itérateur pointant vers cet élément.
        Si le sort n'est pas trouvé, find() retourne un itérateur égal à _SpellBook.end(), ce qui signifie que l'élément n'existe pas dans la map.

    Vérification de l'existence du sort :
        La condition if (_SpellBook.find(SpellName) != _SpellBook.end()) vérifie si le sort existe dans la map.
        Si le sort existe (find() ne retourne pas end()), on passe à l'étape suivante.

    Suppression du sort :
        _SpellBook.erase(_SpellBook.find(SpellName)); supprime le sort de la map.
        erase prend un itérateur comme argument, et supprime l'élément pointé par cet itérateur.
        Cela signifie que le Warlock oublie ce sort, il n'est plus dans sa collection de sorts connus.*/
}
void Warlock::launchSpell(std::string SpellName, ATarget &target)
{
    if (_SpellBook.createSpell(SpellName))
        _SpellBook.createSpell(SpellName) -> launch(target); // (EX02)

	//if (_SpellBook.find(SpellName) != _SpellBook.end()) (EX01)
		//_SpellBook[SpellName]->launch(target);

    /*Explication :

    Objectif : Cette fonction permet au Warlock de lancer un sort spécifique sur une cible (target).
    Paramètres :
        SpellName : Un std::string représentant le nom du sort à lancer.
        target : Une référence à un objet ATarget, représentant la cible sur laquelle le sort sera lancé.

Déroulement de la fonction :

    Recherche du sort :
        De la même manière que dans forgetSpell, _SpellBook.find(SpellName) cherche dans la map _SpellBook une entrée dont la clé est SpellName.
        Si le sort est trouvé, find() retourne un itérateur pointant vers cet élément. Sinon, find() retourne _SpellBook.end().

    Vérification de l'existence du sort :
        La condition if (_SpellBook.find(SpellName) != _SpellBook.end()) vérifie si le sort existe dans la map.
        Si le sort existe, on passe à l'étape suivante. Sinon, la fonction ne fait rien (le sort n'est pas connu par le Warlock, donc il ne peut pas être lancé).

    Lancement du sort :
        _SpellBook[SpellName]->launch(target);
        Ici, _SpellBook[SpellName] accède au sort correspondant à SpellName dans la map.
        La méthode launch(target) est ensuite appelée sur ce sort.
        launch est une méthode de la classe ASpell qui prend un objet ATarget et applique les effets du sort sur la cible (dans ce cas, la méthode getHitBySpell du target est appelée).*/
}
