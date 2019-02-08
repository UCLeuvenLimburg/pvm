class OilTank {
  int contents, capacity;

public:
  int `\pgfmark{oiltank getContents start}`getContents()`\pgfmark{oiltank getContents end}``\only<3->{ \tt\bfseries\color{red} const}`;
  int `\pgfmark{oiltank getCapacity start}`getCapacity()`\pgfmark{oiltank getCapacity end}``\only<3->{ \tt\bfseries\color{red} const}`;
  int `\pgfmark{oiltank getFreeCapacityLeft start}`getFreeCapacityLeft()`\pgfmark{oiltank getFreeCapacityLeft end}``\only<3->{ \tt\bfseries\color{red} const}`;

  void `\pgfmark{oiltank fill start}`fill(int amount)`\pgfmark{oiltank fill end}`;
  void `\pgfmark{oiltank drain start}`drain(int amount)`\pgfmark{oiltank drain end}`;
  void `\pgfmark{oiltank transfer start}`transfer(OilTank&, int amount)`\pgfmark{oiltank transfer end}`;
};
