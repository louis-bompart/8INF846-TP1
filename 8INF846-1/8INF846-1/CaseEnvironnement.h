#pragma once
class CaseEnvironnement {
public:
    CaseEnvironnement();
    ~CaseEnvironnement();

    int Poussiere() const
    {
        return poussiere;
    }
    void Poussiere(int val)
    {
        poussiere = val;
    }
    int Jewels() const
    {
        return jewels;
    }
    void Jewels(int val)
    {
        jewels = val;
    }

private:
    int poussiere;
    int jewels;
};

