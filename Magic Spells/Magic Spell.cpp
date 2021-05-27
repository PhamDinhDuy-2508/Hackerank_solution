#include iostream
#include vector
#include string
using namespace std;

class Spell { 
    private
        string scrollName;
    public
        Spell() scrollName() { }
        Spell(string name) scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball  public Spell { 
    private int power;
    public
        Fireball(int power) power(power) { }
        void revealFirepower(){
            cout  Fireball   power  endl;
        }
};

class Frostbite  public Spell {
    private int power;
    public
        Frostbite(int power) power(power) { }
        void revealFrostpower(){
            cout  Frostbite   power  endl;
        }
};

class Thunderstorm  public Spell { 
    private int power;
    public
        Thunderstorm(int power) power(power) { }
        void revealThunderpower(){
            cout  Thunderstorm   power  endl;
        }
};

class Waterbolt  public Spell { 
    private int power;
    public
        Waterbolt(int power) power(power) { }
        void revealWaterpower(){
            cout  Waterbolt   power  endl;
        }
};

class SpellJournal {
    public
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournaljournal = ;

void counterspell(Spell spell) {
 

Fireballfireball;
  Thunderstormthunderstorm;
  Waterboltwater;
  Frostbite frostbite;
  SpellJournal_Spell;
  if (fireball = dynamic_castFireball(spell)) {
    fireball-revealFirepower();
  }
  else if (thunderstorm = dynamic_castThunderstorm(spell)) {
    thunderstorm-revealThunderpower();
  }
  else if (water = dynamic_castWaterbolt(spell)) {
    water-revealWaterpower();
  }
  else if (frostbite = dynamic_castFrostbite(spell)) {
    frostbite-revealFrostpower();
  } 
  else { 
      vectorstring_Scroll = { spell-revealScrollName() , _Spell-read() };
    int count = 0;
    string str1;               
    int n = spell-revealScrollName().length() +1 ;    
    int m = _Spell-read().length() +1  ;         
    vectorvectorint  vec; 
    vec.resize(m);
    for (int i = 0; i  m; i++)
      vec[i].resize(n);
    int i, j;
    for (i = 0; i = _Spell-read().length(); i++)
    {
      for (j = 0; j = spell-revealScrollName().length(); j++)
      {
        if (i == 0  j == 0)
          vec[i][j] = 0;
        else if (_Spell-read()[i - 1] == spell-revealScrollName()[j - 1])
          vec[i][j] = vec[i - 1][j - 1] + 1;
        else
          if (vec[i - 1][j]  vec[i][j - 1]) {
            vec[i][j] = vec[i - 1][j];
          }
          else {
            vec[i][j] = vec[i][j - 1];
          }
      }
    }
    cout  vec[_Spell-read().size() ][spell-revealScrollName().size()]  endl;
  }
  

}

class Wizard {
    public
        Spell cast() {
            Spell spell;
            string s; cin  s;
            int power; cin  power;
            if(s == fire) {
                spell = new Fireball(power);
            }
            else if(s == frost) {
                spell = new Frostbite(power);
            }
            else if(s == water) {
                spell = new Waterbolt(power);
            }
            else if(s == thunder) {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin  SpellJournaljournal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin  T;
    Wizard Arawn;
    while(T--) {
        Spell spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}