#include <cinttypes>
class Paivays {
  private:
    int paiva;
    int kuukausi;
    int vuosi;

  public:
    void setPaiva(int paiva);
    void setKuukausi(int kuukausi);
    void setVuosi(int vuosi);
    int getPaiva() const;
    int getKuukausi() const;
    int getVuosi() const;
    void setAllFromUser();
    void addPaiva();
    void tulostaPaivays() const;
    Paivays();
    Paivays(int paiva, int kuukausi, int vuosi);
};
