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
    void tulostaPaivays() const;
};
