#pragma once
class Heuristic
{
public:
	static Heuristic* GetInstance() {
		if (!instance) {
			instance = new Heuristic();
		}
		return instance;
	}

	static const enum ScoreValues
	{
		JewelSucked = -8,
		PoussiereCleared = 8,
		JewelPicked = -2,
		Moved = -1
	};
	static const enum CaseValues
	{
		EmptyCase = Moved,
		PoussiereOnly = (PoussiereCleared+Moved),
		JewelOnly = Moved,
		JewelAndPoussiere = (PoussiereCleared+Moved+JewelPicked)
	};
	static const int maxScore = PoussiereOnly;
	int const getScore() { return score; }
	void updateScore(int _score) { score += _score; }
	void resetScore() { score = 0; }
private:
	int score;
	Heuristic();
	~Heuristic();
	static Heuristic* instance;
};