#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<string>
#include<algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> availableSupplies;
        unordered_map<string, int> recipe2idx;
        unordered_map<string, vector<string>> dependencyGraph; // Ingredient to recipy dependency

        // Add Available Supplies to our list.
        for(string& supply : supplies){
            availableSupplies.emplace(supply);
        }

        // Recipes to idx mapping
        for(int idx = 0; idx < recipes.size(); ++idx){
            recipe2idx[recipes[idx]] = idx;
        }

        // Count of non-supply items for a recipe
        vector<int> inDegree(recipes.size(), 0);

        // Build Dependencies graph
        for(int recipeIdx = 0; recipeIdx < recipes.size(); ++recipeIdx){
            for(string& ingredient : ingredients[recipeIdx]){
                if(availableSupplies.find(ingredient) == availableSupplies.end()){
                    // Not found
                    inDegree[recipeIdx]++;
                    dependencyGraph[ingredient].push_back(recipes[recipeIdx]);
                }
            }
        }

        // Start making stuff with things that only need insupply items.
        queue<int> queue;
        for (int recipeIdx = 0; recipeIdx < recipes.size(); ++recipeIdx){
            if(inDegree[recipeIdx] == 0){
                queue.push(recipeIdx);
            }
        }

        // Process queries in topological order.
        vector<string> createdRecipes;
        while(!queue.empty()){
            int recipyIdx = queue.front();
            queue.pop();
            string recipe = recipes[recipyIdx];
            createdRecipes.push_back(recipe);

            if(dependencyGraph.find(recipe) == dependencyGraph.end()) continue;

            for(string& dependentRecipe : dependencyGraph[recipe]){
                if(--inDegree[recipe2idx[dependentRecipe]] == 0){

                    queue.push(recipe2idx[dependentRecipe]);
                }
            }
        }
        return createdRecipes;
    }
};

int main(){
    Solution solution;
    vector<string> recipes = {"bread","sandwich"};
    vector<vector<string>> ingredients = {{"yeast","flour"},{"bread","meat"}};
    vector<string> supplies = {"yeast","flour","meat"};
    vector<string> answer = solution.findAllRecipes(recipes, ingredients, supplies);
    cout << "Answer: " << endl;
    printVector(answer);
}