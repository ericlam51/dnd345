#include <string>

using namespace std;

class ViewHelper {
public:
	static void printDelimiter();
	static bool readBooleanInput(char input);
	static bool isInputInValidRange(int input, int min, int max);
	static void printErrorMessage();
private:
	static const string DELIMITER;
	static const string INVALID_INPUT;
};