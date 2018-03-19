/*
 * DatabaseSorting.cpp
 *
 *  Created on: 2017-06-22
 *      Author: SaltOverflow
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const char *inputFilename = "food.csv";

struct Food {
	float houseWeight1;
	string houseWeightDesc1;
	int houseWeight2;
	string houseWeightDesc2;
	int alphaCarotene;
	float ash;
	int betaCarotene;
	int betaCryptoxanthin;
	int calcium;
	float carbohydrate;
	string category;
	int cholesterol;
	int choline;
	float copper;
	string description;
	float fiber;
	float iron;
	int kilocalories;
	int luteinAndZeaxanthin;
	int lycopene;
	int magnesium;
	float manganese;
	float monosaturatedFat;
	float niacin;
	int nutrientDataBankNumber;
	float pantothenicAcid;
	int phosphorus;
	float polysaturatedFat;
	int potassium;
	float protein;
	int refusePercentage;
	int retinol;
	float riboflavin;
	float saturatedFat;
	float selenium;
	int sodium;
	float sugarTotal;
	float thiamin;
	float totalLipid;
	int vitaminA_IU;
	int vitaminA_RAE;
	float vitaminB12;
	float vitaminB6;
	float vitaminC;
	float vitaminE;
	float vitaminK;
	float water;
	float zinc;
};

void getString(ifstream &fin, string &str) {
	string buffer;

	getline(fin, buffer, ',');
	if (buffer[0] == '"') {
		str = buffer.substr(1, buffer.size()) + ',';
		getline(fin, buffer, '"');
		str += buffer;
		char comma;
		fin.get(comma);
	} else {
		str = buffer;
	}
}

void getInput(vector<Food> &v, const char* inputFilename) {
	cout << "Getting input...\n";
	clock_t t = clock();

	ifstream fin(inputFilename);
	v.resize(100);
	int index = 0;
	string buffer;

	getline(fin, buffer);
	while (true) {
		if (index >= int(v.size())) {
			v.resize(index*2);
		}

		getline(fin, buffer, ',');
		v[index].houseWeight1 = atof(buffer.c_str());
		getString(fin, v[index].houseWeightDesc1);
		if (!fin.good())
			break;
		getline(fin, buffer, ',');
		v[index].houseWeight2 = atoi(buffer.c_str());
		getString(fin, v[index].houseWeightDesc2);
		getline(fin, buffer, ',');
		v[index].alphaCarotene = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].ash = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].betaCarotene = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].betaCryptoxanthin = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].calcium = atoi(buffer.c_str());
		getString(fin, v[index].category);
		getline(fin, buffer, ',');
		v[index].cholesterol = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].choline = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].copper = atof(buffer.c_str());
		getString(fin, v[index].description);
		getline(fin, buffer, ',');
		v[index].fiber = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].iron = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].kilocalories = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].luteinAndZeaxanthin = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].lycopene = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].magnesium = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].manganese = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].monosaturatedFat = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].niacin = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].nutrientDataBankNumber = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].pantothenicAcid = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].phosphorus = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].polysaturatedFat = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].potassium = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].protein = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].refusePercentage = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].retinol = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].riboflavin = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].saturatedFat = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].selenium = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].sodium = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].sugarTotal = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].thiamin = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].totalLipid = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].vitaminA_IU = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].vitaminA_RAE = atoi(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].vitaminB12 = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].vitaminB6 = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].vitaminC = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].vitaminE = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].vitaminK = atof(buffer.c_str());
		getline(fin, buffer, ',');
		v[index].water = atof(buffer.c_str());
		getline(fin, buffer);
		v[index].zinc = atof(buffer.c_str());

		index++;
	}

	v.resize(index);
	fin.close();

	t = clock() - t;
	cout << "Seconds taken: " << float(t)/CLOCKS_PER_SEC << "\n\n";
}

int compare(Food &a, Food &b, int var) {
	switch (var) {
	case 1:
		if (a.houseWeight1 > b.houseWeight1)
			return -1;
		else if (a.houseWeight1 < b.houseWeight1)
			return 1;
		else
			return 0;
	case 2:
		if (a.houseWeightDesc1 > b.houseWeightDesc1)
			return -1;
		else if (a.houseWeightDesc1 < b.houseWeightDesc1)
			return 1;
		else
			return 0;
	case 3:
		if (a.houseWeight2 > b.houseWeight2)
			return -1;
		else if (a.houseWeight2 < b.houseWeight2)
			return 1;
		else
			return 0;
	case 4:
		if (a.houseWeightDesc2 > b.houseWeightDesc2)
			return -1;
		else if (a.houseWeightDesc2 < b.houseWeightDesc2)
			return 1;
		else
			return 0;
	case 5:
		if (a.alphaCarotene > b.alphaCarotene)
			return -1;
		else if (a.alphaCarotene < b.alphaCarotene)
			return 1;
		else
			return 0;
	case 6:
		if (a.ash > b.ash)
			return -1;
		else if (a.ash < b.ash)
			return 1;
		else
			return 0;
	case 7:
		if (a.betaCarotene > b.betaCarotene)
			return -1;
		else if (a.betaCarotene < b.betaCarotene)
			return 1;
		else
			return 0;
	case 8:
		if (a.betaCryptoxanthin > b.betaCryptoxanthin)
			return -1;
		else if (a.betaCryptoxanthin < b.betaCryptoxanthin)
			return 1;
		else
			return 0;
	case 9:
		if (a.calcium > b.calcium)
			return -1;
		else if (a.calcium < b.calcium)
			return 1;
		else
			return 0;
	case 10:
		if (a.carbohydrate > b.carbohydrate)
			return -1;
		else if (a.carbohydrate < b.carbohydrate)
			return 1;
		else
			return 0;
	case 11:
		if (a.category > b.category)
			return -1;
		else if (a.category < b.category)
			return 1;
		else
			return 0;
	case 12:
		if (a.cholesterol > b.cholesterol)
			return -1;
		else if (a.cholesterol < b.cholesterol)
			return 1;
		else
			return 0;
	case 13:
		if (a.choline > b.choline)
			return -1;
		else if (a.choline < b.choline)
			return 1;
		else
			return 0;
	case 14:
		if (a.copper > b.copper)
			return -1;
		else if (a.copper < b.copper)
			return 1;
		else
			return 0;
	case 15:
		if (a.description > b.description)
			return -1;
		else if (a.description < b.description)
			return 1;
		else
			return 0;
	case 16:
		if (a.fiber > b.fiber)
			return -1;
		else if (a.fiber < b.fiber)
			return 1;
		else
			return 0;
	case 17:
		if (a.iron > b.iron)
			return -1;
		else if (a.iron < b.iron)
			return 1;
		else
			return 0;
	case 18:
		if (a.kilocalories > b.kilocalories)
			return -1;
		else if (a.kilocalories < b.kilocalories)
			return 1;
		else
			return 0;
	case 19:
		if (a.luteinAndZeaxanthin > b.luteinAndZeaxanthin)
			return -1;
		else if (a.luteinAndZeaxanthin < b.luteinAndZeaxanthin)
			return 1;
		else
			return 0;
	case 20:
		if (a.lycopene > b.lycopene)
			return -1;
		else if (a.lycopene < b.lycopene)
			return 1;
		else
			return 0;
	case 21:
		if (a.magnesium > b.magnesium)
			return -1;
		else if (a.magnesium < b.magnesium)
			return 1;
		else
			return 0;
	case 22:
		if (a.manganese > b.manganese)
			return -1;
		else if (a.manganese < b.manganese)
			return 1;
		else
			return 0;
	case 23:
		if (a.monosaturatedFat > b.monosaturatedFat)
			return -1;
		else if (a.monosaturatedFat < b.monosaturatedFat)
			return 1;
		else
			return 0;
	case 24:
		if (a.niacin > b.niacin)
			return -1;
		else if (a.niacin < b.niacin)
			return 1;
		else
			return 0;
	case 25:
		if (a.nutrientDataBankNumber > b.nutrientDataBankNumber)
			return -1;
		else if (a.nutrientDataBankNumber < b.nutrientDataBankNumber)
			return 1;
		else
			return 0;
	case 26:
		if (a.pantothenicAcid > b.pantothenicAcid)
			return -1;
		else if (a.pantothenicAcid < b.pantothenicAcid)
			return 1;
		else
			return 0;
	case 27:
		if (a.phosphorus > b.phosphorus)
			return -1;
		else if (a.phosphorus < b.phosphorus)
			return 1;
		else
			return 0;
	case 28:
		if (a.phosphorus > b.phosphorus)
			return -1;
		else if (a.phosphorus < b.phosphorus)
			return 1;
		else
			return 0;
	case 29:
		if (a.polysaturatedFat > b.polysaturatedFat)
			return -1;
		else if (a.polysaturatedFat < b.polysaturatedFat)
			return 1;
		else
			return 0;
	case 30:
		if (a.potassium > b.potassium)
			return -1;
		else if (a.potassium < b.potassium)
			return 1;
		else
			return 0;
	case 31:
		if (a.protein > b.protein)
			return -1;
		else if (a.protein < b.protein)
			return 1;
		else
			return 0;
	case 32:
		if (a.refusePercentage > b.refusePercentage)
			return -1;
		else if (a.refusePercentage < b.refusePercentage)
			return 1;
		else
			return 0;
	case 33:
		if (a.retinol > b.retinol)
			return -1;
		else if (a.retinol < b.retinol)
			return 1;
		else
			return 0;
	case 34:
		if (a.riboflavin > b.riboflavin)
			return -1;
		else if (a.riboflavin < b.riboflavin)
			return 1;
		else
			return 0;
	case 35:
		if (a.saturatedFat > b.saturatedFat)
			return -1;
		else if (a.saturatedFat < b.saturatedFat)
			return 1;
		else
			return 0;
	case 36:
		if (a.selenium > b.selenium)
			return -1;
		else if (a.selenium < b.selenium)
			return 1;
		else
			return 0;
	case 37:
		if (a.sodium > b.sodium)
			return -1;
		else if (a.sodium < b.sodium)
			return 1;
		else
			return 0;
	case 38:
		if (a.sugarTotal > b.sugarTotal)
			return -1;
		else if (a.sugarTotal < b.sugarTotal)
			return 1;
		else
			return 0;
	case 39:
		if (a.thiamin > b.thiamin)
			return -1;
		else if (a.thiamin < b.thiamin)
			return 1;
		else
			return 0;
	case 40:
		if (a.vitaminA_IU > b.vitaminA_IU)
			return -1;
		else if (a.vitaminA_IU < b.vitaminA_IU)
			return 1;
		else
			return 0;
	case 41:
		if (a.vitaminA_RAE > b.vitaminA_RAE)
			return -1;
		else if (a.vitaminA_RAE < b.vitaminA_RAE)
			return 1;
		else
			return 0;
	case 42:
		if (a.vitaminB12 > b.vitaminB12)
			return -1;
		else if (a.vitaminB12 < b.vitaminB12)
			return 1;
		else
			return 0;
	case 43:
		if (a.vitaminB6 > b.vitaminB6)
			return -1;
		else if (a.vitaminB6 < b.vitaminB6)
			return 1;
		else
			return 0;
	case 44:
		if (a.vitaminC > b.vitaminC)
			return -1;
		else if (a.vitaminC < b.vitaminC)
			return 1;
		else
			return 0;
	case 45:
		if (a.vitaminE > b.vitaminE)
			return -1;
		else if (a.vitaminE < b.vitaminE)
			return 1;
		else
			return 0;
	case 46:
		if (a.vitaminK > b.vitaminK)
			return -1;
		else if (a.vitaminK < b.vitaminK)
			return 1;
		else
			return 0;
	case 47:
		if (a.water > b.water)
			return -1;
		else if (a.water < b.water)
			return 1;
		else
			return 0;
	case 48:
		if (a.zinc > b.zinc)
			return -1;
		else if (a.zinc < b.zinc)
			return 1;
		else
			return 0;
	default:
		cerr << "Invalid member to compare\n";
		return 10;
	}
}

void printFood(vector<Food> &v, int var) {
	int n = v.size();

	switch (var) {
	case 1:
		for (int i=0; i<n; i++)
			cout << v[i].houseWeight1 << '\n';
		break;
	case 2:
		for (int i=0; i<n; i++)
			cout << v[i].houseWeightDesc1 << '\n';
		break;
	case 3:
		for (int i=0; i<n; i++)
			cout << v[i].houseWeight2 << '\n';
		break;
	case 4:
		for (int i=0; i<n; i++)
			cout << v[i].houseWeightDesc2 << '\n';
		break;
	case 5:
		for (int i=0; i<n; i++)
			cout << v[i].alphaCarotene << '\n';
		break;
	case 6:
		for (int i=0; i<n; i++)
			cout << v[i].ash << '\n';
		break;
	case 7:
		for (int i=0; i<n; i++)
			cout << v[i].betaCarotene << '\n';
		break;
	case 8:
		for (int i=0; i<n; i++)
			cout << v[i].betaCryptoxanthin << '\n';
		break;
	case 9:
		for (int i=0; i<n; i++)
			cout << v[i].calcium << '\n';
		break;
	case 10:
		for (int i=0; i<n; i++)
			cout << v[i].carbohydrate << '\n';
		break;
	case 11:
		for (int i=0; i<n; i++)
			cout << v[i].category << '\n';
		break;
	case 12:
		for (int i=0; i<n; i++)
			cout << v[i].cholesterol << '\n';
		break;
	case 13:
		for (int i=0; i<n; i++)
			cout << v[i].choline << '\n';
		break;
	case 14:
		for (int i=0; i<n; i++)
			cout << v[i].copper << '\n';
		break;
	case 15:
		for (int i=0; i<n; i++)
			cout << v[i].description << '\n';
		break;
	case 16:
		for (int i=0; i<n; i++)
			cout << v[i].fiber << '\n';
		break;
	case 17:
		for (int i=0; i<n; i++)
			cout << v[i].iron << '\n';
		break;
	case 18:
		for (int i=0; i<n; i++)
			cout << v[i].kilocalories << '\n';
		break;
	case 19:
		for (int i=0; i<n; i++)
			cout << v[i].luteinAndZeaxanthin << '\n';
		break;
	case 20:
		for (int i=0; i<n; i++)
			cout << v[i].lycopene << '\n';
		break;
	case 21:
		for (int i=0; i<n; i++)
			cout << v[i].magnesium << '\n';
		break;
	case 22:
		for (int i=0; i<n; i++)
			cout << v[i].manganese << '\n';
		break;
	case 23:
		for (int i=0; i<n; i++)
			cout << v[i].monosaturatedFat << '\n';
		break;
	case 24:
		for (int i=0; i<n; i++)
			cout << v[i].niacin << '\n';
		break;
	case 25:
		for (int i=0; i<n; i++)
			cout << v[i].nutrientDataBankNumber << '\n';
		break;
	case 26:
		for (int i=0; i<n; i++)
			cout << v[i].pantothenicAcid << '\n';
		break;
	case 27:
		for (int i=0; i<n; i++)
			cout << v[i].phosphorus << '\n';
		break;
	case 28:
		for (int i=0; i<n; i++)
			cout << v[i].polysaturatedFat << '\n';
		break;
	case 29:
		for (int i=0; i<n; i++)
			cout << v[i].potassium << '\n';
		break;
	case 30:
		for (int i=0; i<n; i++)
			cout << v[i].protein << '\n';
		break;
	case 31:
		for (int i=0; i<n; i++)
			cout << v[i].refusePercentage << '\n';
		break;
	case 32:
		for (int i=0; i<n; i++)
			cout << v[i].retinol << '\n';
		break;
	case 33:
		for (int i=0; i<n; i++)
			cout << v[i].riboflavin << '\n';
		break;
	case 34:
		for (int i=0; i<n; i++)
			cout << v[i].saturatedFat << '\n';
		break;
	case 35:
		for (int i=0; i<n; i++)
			cout << v[i].selenium << '\n';
		break;
	case 36:
		for (int i=0; i<n; i++)
			cout << v[i].sodium << '\n';
		break;
	case 37:
		for (int i=0; i<n; i++)
			cout << v[i].sugarTotal << '\n';
		break;
	case 38:
		for (int i=0; i<n; i++)
			cout << v[i].thiamin << '\n';
		break;
	case 39:
		for (int i=0; i<n; i++)
			cout << v[i].totalLipid << '\n';
		break;
	case 40:
		for (int i=0; i<n; i++)
			cout << v[i].vitaminA_IU << '\n';
		break;
	case 41:
		for (int i=0; i<n; i++)
			cout << v[i].vitaminA_RAE << '\n';
		break;
	case 42:
		for (int i=0; i<n; i++)
			cout << v[i].vitaminB12 << '\n';
		break;
	case 43:
		for (int i=0; i<n; i++)
			cout << v[i].vitaminB6 << '\n';
		break;
	case 44:
		for (int i=0; i<n; i++)
			cout << v[i].vitaminC << '\n';
		break;
	case 45:
		for (int i=0; i<n; i++)
			cout << v[i].vitaminE << '\n';
		break;
	case 46:
		for (int i=0; i<n; i++)
			cout << v[i].vitaminK << '\n';
		break;
	case 47:
		for (int i=0; i<n; i++)
			cout << v[i].water << '\n';
		break;
	case 48:
		for (int i=0; i<n; i++)
			cout << v[i].zinc << '\n';
		break;
	default:
		cerr << "Invalid member to compare\n";
	}
}

Food temp;
void swap(Food &a, Food &b) {
	temp = a;
	a = b;
	b = temp;
}

void showVariableLegend() {
	cout << "1. float houseWeight, 2. string houseWeightDesc1, "
			"3. int houseWeight2, 4. string houseWeightDesc2, "
			"5. int alphaCarotene, 6. float ash, 7. int betaCarotene, "
			"8. int betaCryptoxanthin, 9. int calcium, 10. float carbohydrate, "
			"11. string category, 12. int cholesterol, 13. int choline, "
			"14. float copper, 15. string description, 16. float fiber, "
			"17. float iron, 18. int kilocalories, 19. int luteinAndZeaxanthin, "
			"20. int lycopene, 21. int magnesium, 22. float manganese, "
			"23. float monosaturatedFat, 24. float niacin, "
			"25. int nutrientDataBankNumber, 26. float pantothenicAcid, "
			"27. int phosphorus, 28. float polysaturatedFat, 29. int potassium, "
			"30. float protein, 31. int refusePercentage, 32. int retinol, "
			"33. float riboflavin, 34. float saturatedFat, 35. float selenium, "
			"36. int sodium, 37. float sugarTotal, 38. float thiamin, "
			"39. float totalLipid, 40. int vitaminA_IU, 41. int vitaminA_RAE, "
			"42. float vitaminB12, 43. float vitaminB6, 44. float vitaminC, "
			"45. float vitaminE, 46. float vitaminK, 47. float water, "
			"48. float zinc\n\n";
}

void showOptionLegend() {
	cout << "Bubble sort\n";
	cout << "A sorting algorithm that steps through a list,"
			"compares each pair of adjacent items,"
			"and swaps them if they are out of order\n";
	cout << "Use: When an array is literally almost sorted, with no turtles\n";
	cout << "Worst-case performance: O(n^2)\n";
	cout << "Best-case performance: O(n)\n";
	cout << "Average performance: O(n^2)\n";
	cout << "Worst-case space complexity: O(1)\n\n";

	cout << "Cocktail sort\n";
	cout << "A variation of bubble sort that moves in both directions, "
			"which deals with the problem of turtles (small values near "
			"the end of the list that can only move one space every loop)\n";
	cout << "Use: Better version of bubble sort\n";
	cout << "Worst-case performance: O(n^2)\n";
	cout << "Best-case performance: O(n)\n";
	cout << "Average performance: O(n^2)\n";
	cout << "Worst-case space complexity: O(1)\n\n";

	cout << "Comb sort\n";
	cout << "A variation of bubble sort that changes the distance"
			"between the values being compared, solving the problem of turtles\n";
	cout << "Use: Faster than the quadratic sorts at sorting random arrays\n";
	cout << "Worst-case performance: O(n^2)\n";
	cout << "Best-case performance: O(n log n)\n";
	cout << "Average performance: BigOmega(n^2 / 2^p), where p is the"
			"number of increments (don't ask me what this is)\n";
	cout << "Worst-case space complexity: O(1)\n\n";

	cout << "Selection sort\n";
	cout << "A sorting algorithm that searches the unsorted part of the array, "
			"finds the smallest (or largest) value, "
			"and places it at the end of the sorted part of the array\n";
	cout << "Use: When you only need the smallest values of the array\n";
	cout << "Worst-case performance: O(n^2)\n";
	cout << "Best-case performance: O(n^2)\n";
	cout << "Average performance: O(n^2)\n";
	cout << "Worst-case space complexity: O(1)\n\n";

	cout << "Insertion sort\n";
	cout << "Builds a sorted list one element at a time, "
			"moving the next element in the unsorted array "
			"into its sorted position in the sorted array\n";
	cout << "Use: For small data sets, or if the array is almost sorted\n";
	cout << "Worst-case performance: O(n^2)\n";
	cout << "Best-case performance: O(n)\n";
	cout << "Average performance: O(n^2)\n";
	cout << "Worst-case space complexity: O(1)\n\n";

	cout << "Merge sort\n";
	cout << "A divide and conquer sorting algorithm that divides the list "
			"into the smallest unit (1 element), then compares each list "
			"with its pair to form a larger sorted list\n";
	cout << "Use: Has a better worst-case performance than quicksort, "
			"and can be used when you have additional memory\n";
	cout << "Worst-case performance: O(n log n)\n";
	cout << "Best-case performance: O(n log n) typical, "
			"O(n) natural variant (finds already sorted sections "
			"- not implemented)\n";
	cout << "Average performance: O(n log n)\n";
	cout << "Worst-case space complexity: O(n)\n";
	cout << "Further optimizations: Natural merge sort exploits any naturally "
			"occurring runs (already sorted sequences - exploited in Timsort)\n"
			"You can move around the link values (in this case, array indices) "
			"instead of the actual data\n\n";

	cout << "Quicksort\n";
	cout << "Another divide and conquer sorting algorithm that uses a pivot "
			"value to sort the left and right sides of an array, then breaks "
			"down the array into 2 subunits to recursively call itself\n";
	cout << "Use: One of the fastest sorts when implemented correctly\n";
	cout << "Worst-case performance: O(n^2)\n";
	cout << "Best-case performance: O(n log n)\n";
	cout << "Average performance: O(n log n)\n";
	cout << "Worst-case space complexity: O(n) naive, "
			"O(log n) when using tail call elimination (not implemented)\n\n";
	cout << "Analysis: On average, quicksort performs only 39% worse than "
			"the best case, with C(n) = 2n ln n =~ 1.39n log[2] n\n"
			"Note tha a comparison sort cannot use less than log[2] n! =~ "
			"n(log[2] n - log[2] e), so quicksort is pretty close to ideal\n";
	cout << "Further optimizations: Use the median of the first, middle and "
			"last elements\n"
			"Use insertion sort when the array is smaller than 10\n"
			"Tail call elimination: recurse the smaller array and remove "
			"the need to recurse again by using a while loop\n"
			"See: http://www.geeksforgeeks.org/quicksort-tail-call-optimization"
			"-reducing-worst-case-space-log-n/ \n\n";
}

void bubbleSort(vector<Food> &v, int var, float &time, int &comps, int &swaps) {
	cout << "Bubble sorting...\n";
	clock_t t = clock();

	int n = v.size()-1;
	comps = 0;
	swaps = 0;
	bool swapped;

	do {
		swapped = false;
		for (int i=0; i<n; i++) {
			if (compare(v[i], v[i+1], var) < 0) {
				swap(v[i], v[i+1]);
				swapped = true;
				swaps++;
			}
			comps++;
		}
		n--;
	} while (swapped);

	t = clock() - t;
	time = float(t)/CLOCKS_PER_SEC;
	cout << "Time taken: " << float(t)/CLOCKS_PER_SEC << '\n';
	cout << "Comparisons: " << comps << '\t' << "Swaps: " << swaps << '\n';
}

void cocktailSort(vector<Food> &v, int var, float &time, int &comps, int &swaps) {
	cout << "Cocktail sorting...\n";
	clock_t t = clock();

	int min = 0;
	int max = v.size()-1;
	comps = 0;
	swaps = 0;
	bool swapped;

	do {
		swapped = false;
		for (int i=min; i<max; i++) {
			if (compare(v[i], v[i+1], var) < 0) {
				swap(v[i], v[i+1]);
				swapped = true;
				swaps++;
			}
			comps++;
		}
		max--;

		if (!swapped)
			break;

		swapped = false;
		for (int i=max; i>min; i--) {
			if (compare(v[i-1], v[i], var) < 0) {
				swap(v[i-1], v[i]);
				swapped = true;
				swaps++;
			}
			comps++;
		}
		min++;
	} while (swapped);

	t = clock() - t;
	time = float(t)/CLOCKS_PER_SEC;
	cout << "Time taken: " << float(t)/CLOCKS_PER_SEC << '\n';
	cout << "Comparisons: " << comps << '\t' << "Swaps: " << swaps << '\n';
}

void combSort(vector<Food> &v, int var, float &time, int &comps, int &swaps) {
	cout << "Comb sorting...\n";
	clock_t t = clock();

	int gap = v.size();
	float shrink = 1.3;
	int n = v.size();
	comps = 0;
	swaps = 0;
	bool sorted;

	do {
		gap = int(gap/shrink);
		if (gap > 1) {
			sorted = false;
		} else {
			sorted = true;
		}

		for (int i=0; i<n-gap; i++) {
			if (compare(v[i], v[i+gap], var) < 0) {
				swap(v[i], v[i+gap]);
				swaps++;
			}
			comps++;
		}
	} while (!sorted);

	t = clock() - t;
	time = float(t)/CLOCKS_PER_SEC;
	cout << "Time taken: " << float(t)/CLOCKS_PER_SEC << '\n';
	cout << "Comparisons: " << comps << '\t' << "Swaps: " << swaps << '\n';
}

void selectionSort(vector<Food> &v, int var, float &time, int &comps, int &swaps) {
	cout << "Selection sorting...\n";
	clock_t t = clock();

	int n = v.size()-1;
	comps = 0;
	swaps = 0;
	int minIndex = 0;

	for (int i=0; i<n; i++) {
		minIndex = i;
		for (int j=i+1; j<=n; j++) {
			if (compare(v[j], v[minIndex], var) > 0)
				minIndex = j;
			comps++;
		}

		swap(v[i], v[minIndex]);
		swaps++;
	}

	t = clock() - t;
	time = float(t)/CLOCKS_PER_SEC;
	cout << "Time taken: " << float(t)/CLOCKS_PER_SEC << '\n';
	cout << "Comparisons: " << comps << '\t' << "Swaps: " << swaps << '\n';
}

void insertionSort(vector<Food> &v, int var, float &time, int &comps, int &moves) {
	cout << "Insertion sorting...\n";
	clock_t t = clock();

	int n = v.size();
	comps = 0;
	moves = 0;
	Food holder;

	for (int i=1; i<n; i++) {
		if (compare(v[i], v[i-1], var) > 0) {
			holder = v[i];
			v[i] = v[i-1];
			moves += 2;

			int dest = i-1;
			while (dest > 0 && compare(v[dest-1], holder, var) < 0) {
				comps++;
				dest--;
				v[dest+1] = v[dest];
				moves++;
			}
			comps++;

			v[dest] = holder;
			moves++;
		}
		comps++;
	}

	t = clock() - t;
	time = float(t)/CLOCKS_PER_SEC;
	cout << "Time taken: " << float(t)/CLOCKS_PER_SEC << '\n';
	cout << "Comparisons: " << comps << '\t' << "Moves: " << moves << '\n';
}

void mergeSort(vector<Food> &v, vector<Food> &buff, int var, int start, int len,
		int &comps, int &moves) {
	if (len <= 1) {
		return;
	}
	int middle = start+len/2;
	mergeSort(v, buff, var, start, len/2, comps, moves);
	mergeSort(v, buff, var, middle, len-len/2, comps, moves);

	int left = start;
	int right = middle;
cout << len << ' ';
cout << len+start << ' ';
	for (int i=start; i<start+len; i++) {
		cout << 'a';
		if (left >= middle) {
			buff[i] = v[right];
			right++;
			moves++;
		} else if (right >= len) {
			buff[i] = v[left];
			left++;
			moves++;
		}
cout << 'b';
		if (compare(v[left], v[right], var) < 0) {
			cout << 1;
			buff[i] = v[left];
			left++;
			moves++;
		} else {
			cout << 2;
			cout << i << ' ' << right;
			buff[i] = v[right];
			right++;
			moves++;
		}
		cout << 'c';
	}
cout << len << "  ";
	for (int i=start; i<start+len; i++) {
		v[i] = buff[i];
		moves++;
	}
}

void quickSort(vector<Food> &v, int var, int start, int len,
		int &comps, int &swaps) {
	if (len <= 1)
		return;

	int left = start;
	int right = start+len-1;
	int middle = start+len/2;
	Food pivot = v[middle];

	while (true) {
		while (compare(v[left], pivot, var) > 0) {
			left++;
			comps++;
		}
		while (compare(v[right], pivot, var) < 0) {
			right--;
			comps++;
		}
		comps += 2;
		if (left >= right)
			break;
		swap(v[left], v[right]);
		swaps++;
	}
cout << len << ' ';
	quickSort(v, var, start, len/2, comps, swaps);
	quickSort(v, var, middle, len-len/2, comps, swaps);
}

int min(int a[], int size) {
	int min = a[0];
	for (int i=0; i<size; i++)
		if (a[i] < min)
			min = a[i];

	return min;
}
float min(float a[], int size) {
	float min = a[0];
	for (int i=0; i<size; i++)
		if (a[i] < min)
			min = a[i];

	return min;
}

int max(int a[], int size) {
	int max = a[0];
	for (int i=0; i<size; i++)
		if (a[i] > max)
			max = a[i];

	return max;
}
float max(float a[], int size) {
	float max= a[0];
	for (int i=0; i<size; i++)
		if (a[i] > max)
			max = a[i];

	return max;
}

float average(int a[], int size) {
	float average = 0;
	for (int i=0; i<size; i++)
		average += a[i];
	average /= size;

	return average;
}
float average(float a[], int size) {
	float average = 0;
	for (int i=0; i<size; i++)
		average += a[i];
	average /= size;

	return average;
}

void setZero(int a[], int size) {
	for (int i=0; i<size; i++)
		a[i] = 0;
}

void sortData(vector<Food> &v, int var, int option, int tries) {
	float time[tries]; int comps[tries], swaps[tries], moves[tries];
	float minTime; int minComps, minSwaps, minMoves;
	float maxTime; int maxComps, maxSwaps, maxMoves;
	float avgTime = 0, avgComps = 0, avgSwaps = 0, avgMoves = 0;
	setZero(swaps, tries);
	setZero(moves, tries);
	vector<Food> vcopy;

	if (option == 1) {
		for (int i=0; i<tries; i++) {
			vcopy = v;
			bubbleSort(vcopy, var, time[i], comps[i], swaps[i]);
		}
	} else if (option == 2) {
		for (int i=0; i<tries; i++) {
			vcopy = v;
			cocktailSort(vcopy, var, time[i], comps[i], swaps[i]);
		}
	} else if (option == 3) {
		for (int i=0; i<tries; i++) {
			vcopy = v;
			combSort(vcopy, var, time[i], comps[i], swaps[i]);
		}
	} else if (option == 4) {
		for (int i=0; i<tries; i++) {
			vcopy = v;
			selectionSort(vcopy, var, time[i], comps[i], swaps[i]);
		}
	} else if (option == 5) {
		for (int i=0; i<tries; i++) {
			vcopy = v;
			insertionSort(vcopy, var, time[i], comps[i], moves[i]);
		}
/*	} else if (option == 6) {
		for (int i=0; i<tries; i++) {
			vcopy = v;
			comps[i] = 0;
			moves[i] = 0;

			cout << "Merge sorting...\n";
			clock_t t = clock();
			vector<Food> buff(vcopy.size());
			mergeSort(vcopy, buff, var, 0, vcopy.size(), comps[i], moves[i]);
			cout << "success";
			t = clock() - t;
			time[i] = float(t)/CLOCKS_PER_SEC;
			cout << "Time taken: " << float(t)/CLOCKS_PER_SEC << '\n';
			cout << "Comparisons: " << comps[i] << '\t'
					<< "Moves: " << moves[i] << '\n';
		}
	} else if (option == 7) {
		for (int i=0; i<tries; i++) {
			vcopy = v;
			comps[i] = 0;
			moves[i] = 0;

			cout << "Quick sorting...\n";
			clock_t t = clock();
			quickSort(vcopy, var, 0, vcopy.size(), comps[i], swaps[i]);
			t = clock() - t;
			time[i] = float(t)/CLOCKS_PER_SEC;
			cout << "Time taken: " << float(t)/CLOCKS_PER_SEC << '\n';
			cout << "Comparisons: " << comps[i] << '\t'
					<< "Swaps: " << swaps[i] << '\n';
		}
*/	} else {
		cerr << "Invalid option\n\n";
		return;
	}

	minTime = min(time, tries);
	maxTime = max(time, tries);
	avgTime = average(time, tries);

	minComps = min(comps, tries);
	maxComps = max(comps, tries);
	avgComps = average(comps, tries);

	minSwaps = min(swaps, tries);
	maxSwaps = max(swaps, tries);
	avgSwaps = average(swaps, tries);

	minMoves = min(moves, tries);
	maxMoves = max(moves, tries);
	avgMoves = average(moves, tries);

	cout << "Min Time: " << minTime << "\tMax Time: " << maxTime
			<< "\tAvg Time: " << avgTime << '\n';
	cout << "Min Comps: " << minComps << "\tMax Comps: " << maxComps
			<< "\tAvg Comps : " << avgComps << '\n';
	if (option <= 4 || option >= 7)
		cout << "Min Swaps: " << minSwaps << "\tMax Swaps: " << maxSwaps
				<< "\tAvg Swaps: " << avgSwaps << '\n';
	if (option == 5 || option == 6)
		cout << "Min Moves: " << minMoves << "\tMax Moves: " << maxMoves
				<< "\tAvg Moves: " << avgMoves << '\n';

	cout << "Print variable? (y/n) ";
	char yesno = 'y';
	cin.ignore(50, '\n');
	cin.get(yesno);
	cin.ignore(50, '\n');
	if (yesno == 'y' || yesno == 'Y') {
		printFood(vcopy, var);
	}

	cout << "Save to original vector? (y/n) ";
	cin.get(yesno);
	cin.ignore(50, '\n');
	if (yesno == 'y' || yesno == 'Y') {
		v = vcopy;
		cout << "Sorted vector saved to original vector\n";
	}

	cout << '\n';
}

int main() {
	vector<Food> v;
	getInput(v, inputFilename);
	int option;
	int sortVariable;
	int tries;

	while (true) {
		cout << "Select sorting variable:\n";
		cout << "-1. Quit, 0. Legend, 1-48. variables\n";
		cin >> sortVariable;

		if (sortVariable < 0) {
			break;
		} else if (sortVariable == 0) {
			showVariableLegend();
			continue;
		} else if (sortVariable > 48) {
			cout << "Invalid sorting variable\n\n";
			continue;
		}

		cout << "\nSelect option:\n";
/*		cout << "-1. Quit, 0. Legend, 1. Bubble Sort, 2. Cocktail Sort, "
				"3.Comb Sort, 4. Selection Sort, 5. Insertion Sort, "
				"6. Merge Sort, 7. Quick Sort\n";*/
		cout << "-1. Quit, 0. Legend, 1. Bubble Sort, 2. Cocktail Sort, "
				"3.Comb Sort, 4. Selection Sort, 5. Insertion Sort\n";
		cin >> option;

		if (option < 0) {
			break;
		} else if (option == 0) {
			showOptionLegend();
			continue;
		} else if (option > 0 && option <= 5) { //c
			do {
				cout << "Number of tries: ";
				cin >> tries;
				if (tries <= 0) {
					cout << "Invalid number\n";
					continue;
				}
			} while (tries <= 0);
			sortData(v, sortVariable, option, tries);
		} else if (option > 5) { //c
			cout << "Invalid option\n\n";
			continue;
		}

	}
}
