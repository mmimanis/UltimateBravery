#include <iostream>
#include <stdio.h>		
#include <stdlib.h>		
#include <time.h>       
#include <chrono>
#include <thread>

int
main ()
{
  int i;
  
  using namespace std::this_thread; 
  using namespace std::chrono; 

  // Roles
  const char *lane[5] =
  {"Top", "Jungle", "Mid", "Support", "Bottom"};
  
  // Čempioni
  const char *champion[156] =
  { "Aatrox", "Ahri", "Akali", "Akshan", "Alistar", "Amumu", "Anivia",
"Annie", "Aphelios", "Ashe", "Aurelion Sol", "Azir", "Bard", "Blitzcrank", "Brand", "Braum",
"Caitlyn", "Camille", "Cassiopeia", "Cho'Gath", "Corki", "Darius", "Diana", "Dr.Mundo", "Draven",
"Ekko", "Elise", "Evelynn", "Ezreal", "Fiddlesticks", "Fiora", "Fizz", "Galio", "Gangplank",
"Garen", "Gnar", "Gragas", "Graves", "Gwen", "Hecarim", "Heimerdinger", "Illaoi", "Irelia", "Ivern",
"Janna", "Jarvan IV", "Jax", "Jayce", "Jhin", "Jinx", "Kai'Sa", "Kalista", "Karma", "Karthus",
"Kassadin", "Katarina", "Kayle", "Kayn", "Kennen", "Kha'Zix", "Kindred", "Kled", "Kog'Maw",
"LeBlanc", "Lee Sin", "Leona", "Lillia", "Lissandra", "Lucian", "Lulu", "Lux", "Malphite",
"Malzahar", "Maokai", "Master Yi", "Miss Fortune", "Mordekaiser", "Morgana", "Nami", "Nasus",
"Nautilus", "Neeko", "Nidalee", "Nocturne", "Nunu & Willump", "Olaf", "Orianna", "Ornn", "Pantheon",
"Poppy", "Pyke", "Qiyana", "Quinn", "Rakan", "Rammus", "Rek'Sai", "Rell", "Renekton", "Rengar",
"Riven", "Rumble", "Ryze", "Samira", "Sejuani", "Senna", "Seraphine", "Sett", "Shaco", "Shen",
"Shyvana", "Singed", "Sion", "Sivir", "Skarner", "Sona", "Soraka", "Swain", "Sylas", "Syndra",
"Tahm Kench", "Taliyah", "Talon", "Taric", "Teemo", "Thresh", "Tristana", "Trundle", "Tryndamere",
"Twisted Fate", "Udyr", "Urgot", "Varus", "Vayne", "Veigar", "Vel'Koz", "Vex", "Vi", "Viego",
"Viktor", "Vladimir", "Volibear", "Warwick", "Wukong", "Xayah", "Xerath", "Xin Zhao", "Yasuo",
"Yone", "Yorick", "Yuumi", "Zac", "Zed", "Ziggs", "Zilean", "Zoe", "Zyra" };
  
  // Mythic itemi
  const char *mythic[25] =
  { "Crown of the Shattered Queen", "Divine Sunderer",
"Duskblade of Draktharr", "Eclipse", "Evenshroud", "Everfrost", "Frostfire Gauntlet",
"Galeforce", "Goredrinker", "Hextech Rocketbelt", "Immortal Shieldbow", "Imperial Mandate",
"Kraken Slayer", "Liandry's Anguish", "Locket of the Iron Solari", "Luden's Tempest",
"Moonstone Renewer", "Night Harvester", "Prowler 's Claw", "Riftmaker",
"Shurelya' s Battlesong ", "Stridebreaker ", "Sunfire Aegis ", "Trinity Force ",
"Turbo Chemtank" };
  
  // Legendary itemi
  const char *legendary[72] =
    { "Abyssal Mask", "Anathemas Chains", "Archangel's staff",
"Ardent Censer ", "Axiom Arc", "Banshee's Veil", "Black Cleaver", "Black Mist Scythe",
"Blade of the Ruined King", "Bloodthirster", "Bulwark of the Mountain", "Chempunk Chainsword",
"Chemtech Putrifier", "Cosmic Drive", "Dead Man's Plate", "Death's Dance", "Demonic Embrace",
"Edge of Night", "Essence Reaver", "Fimbulwinter", "Force of Nature", "Frozen Heart",
"Gargoyle Stoneplate", "Guardian Angel", "Guinsoo's Rageblade", "Horizon Focus", "Hullbreaker",
"Infinity Edge", "Knight's Vow", "Lich Bane", "Lord Dominik's Regards", "Manamune",
"Maw of Malmortius", "Mejai's Soulstealer", "Mercurial Scimitar", "Mikael's Blessing",
"Morellonomicon", "Mortal Reminder", "Muramana", "Nashor's Tooth", "Navori Quickblades",
"Pauldrons of Whiterock", "Phantom Dancer", "Rabadon's Deathcap", "Randuin's Omen",
"Rapid Firecannon", "Ravenous Hydra", "Redemption", "Runaan's Hurricane",
"Rylai's Crystal Scepter", "Seraph's Embrace", "Serpent's fang", "Serylda's Grudge",
"Shadowflame", "Shard of True Ice", "Silvermere Dawn", "Spirit Visage", "Staff of Flowing Water",
"Sterak's gage", "Stormrazor", "The Collector", "Thornmail", "Titanic Hydra", "Umbral Glaive",
"Vigilant Wardstone", "Void Staff", "Warmog's Armor", "Winter's Approach", "Wit's End",
"Youmuu's Ghostblade", "Zeke's Convergence", "Zhonya's Hourglass" };
  // Apavi
  
  const char *boots[7] =
  { "Berserker's Greaves", "Boots of Swiftness", "Ionian Boots of Lucidity",
"Mercury's Treads", "Mobility Boots", "Plated Steelcaps", "Sorcerer's Shoes" };
  
  /*Runes path
  const char *primary[5] = 
  {"Domination", "Precision", "Sorcery", "Resolve", "Inspiration"};

  // Domination path
  const char *Deystone[4] =
  {"Electrocute", "Predator", "Dark Harvest", "Hail of Blades"};
  
  const char *Dslot1[3] = 
  {"Cheap Shot", "Taste of Blood", "Sudden Impact"};
  
  const char *Dslot2[3] = 
  {"Zombie Ward", "Ghost Poro", "Eyeball Collection"};
  
  const char *Dslot3[4] = 
  {"Ravenous Hunter", "Ingenious Hunter", "Relentless Hunter", "Ultimate Hunter"};
  
  
  // Precision path
  const char *Peystone[4] = 
  {"Conqueror", "Press the Attack", "Lethal Tempo", "Fleet Footwork"};
  
  const char *Pslot1[3] = 
  {"Pressence of Mind", "Triumph", "Overheal"};
  
  const char *Pslot2[3] = 
  {"Legend: Alacrity", "Legend: Tenacity", "Legend: Bloodline"};
  
  const char *Pslot3[3] = 
  {"Coup De Grace", "Cut Down", "Last Stand"};
  
  
  // Sorcery path
  const char *Seystone[3] = 
  {"Summon Aery", "Arcane Comet", "Phase Rush"};
  
  const char *Sslot1[3] = 
  {"Nullifying Orb", "Manaflow Band", "Nimbus Cloak"};
  
  const char *Sslot2[3] = 
  {"Transendence", "Celerity", "Absolute Focus"};
  
  const char *Sslot3[3] = 
  {"Schorch", "Waterwalking", "Gathering Storm"};
  
  
  // Resolve path
  const char *Reystone[3] = 
  {"Grasp of the Undying", "Aftershock", "Guardian"};
  
  const char *Rslot1[3] = 
  {"Demolish", "Font of Life", "Shield Bash"};
  
  const char *Rslot2[3] = 
  {"Conditioning", "Bone Plating", "Second Wind"};
  
  const char *Rslot3[3] = 
  {"Unflinching", "Revitalize", "Overgrowth"};
  
  
  // Inspiration path
  const char *Ieystone[3] = 
  {"Glacial Augument", "Unsealed Spellbook", "First Strike"};
  
  const char *Islot1[3] = 
  {"Hextech Flashtraption", "Magical Footwear", "Perfect Timing"};
  
  const char *Islot2[3] = 
  {"Future's Market", "Minion Dematerializer", "Biscuit Delivery"};
  
  const char *Islot3[3] = 
  {"Cosmic Insight", "Approach Velocity", "Time Warp Tonic"};*/
  
 
  int champ;
  srand(time(NULL));
  champ = rand () % 156 + 1;
  std::cout << champion[champ] << std::endl;
  sleep_for(nanoseconds(1));
  sleep_until(system_clock::now() + seconds(1));

  int role;
  srand(time(NULL));
  role = rand () % 4 + 1;
  std::cout << lane[role] << std::endl;
  sleep_for(nanoseconds(1));
  sleep_until(system_clock::now() + seconds(1));
  
  int myth;
  srand(time(NULL));
  myth = rand () % 24 + 1;
  std::cout << mythic[myth] << std::endl;
  sleep_for(nanoseconds(1));
  sleep_until(system_clock::now() + seconds(1));
  
  
  for (i = 1; i <= 4; i++)
    {
      int legend;
      srand (time (NULL));
      legend = rand () % 72;

      std::cout << legendary[legend] << std::endl;
      sleep_for(nanoseconds(1));
      sleep_until(system_clock::now() + seconds(1));
    }
  int boot;
  srand(time(NULL));
  boot = rand () % 6 + 1;
  std::cout << boots[boot] << std::endl;
  sleep_for(nanoseconds(1));
  sleep_until(system_clock::now() + seconds(1));
  return 0;

}