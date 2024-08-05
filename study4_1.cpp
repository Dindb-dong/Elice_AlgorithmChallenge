#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Pokedex
{
private:
    vector<string> numberToName;
    vector<pair<string, int>> nameToNumber;

public:
    void addPokemon(const string &name, int number)
    {
        numberToName.push_back(name);
        nameToNumber.push_back({name, number});
    }

    void sortNameToNumber()
    {
        sort(nameToNumber.begin(), nameToNumber.end());
    }

    string getPokemonInfo(const string &query) const
    {
        auto it = lower_bound(nameToNumber.begin(), nameToNumber.end(), make_pair(query, 0));
        if (it != nameToNumber.end() && it->first == query)
        {
            return to_string(it->second);
        }
        return "Not found";
    }

    string getPokemonInfo(int number) const
    {
        if (number > 0 && number <= numberToName.size())
        {
            return numberToName[number - 1];
        }
        return "Not found";
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    Pokedex pokedex;

    for (int i = 1; i <= N; ++i)
    {
        string name;
        cin >> name;
        pokedex.addPokemon(name, i);
    }

    // 정렬 필요
    pokedex.sortNameToNumber();

    for (int i = 0; i < M; ++i)
    {
        string query;
        cin >> query;
        if (isdigit(query[0]))
        {
            int number = stoi(query);
            cout << pokedex.getPokemonInfo(number) << "\n";
        }
        else
        {
            cout << pokedex.getPokemonInfo(query) << "\n";
        }
    }

    return 0;
}