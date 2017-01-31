#pragma once
class Environnement {
public:
    Environnement();
    ~Environnement();

    std::vector<std::vector<CaseEnvironnement>> getEnv();

private:
    std::vector<std::vector<CaseEnvironnement>> cases;
};

